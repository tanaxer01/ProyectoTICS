//-----------------------------
//--         IMPORTS         --
//-----------------------------
// LIBS
#include <RF24.h>             //Interfaz
#include <RF24Network.h>      //Interfaz
#include <DHT.h>              //TempYHumedad

// FILES
#include "Measuring.h"
#include "Networking.h"

// Otros
#define DIRECCION 10

//-----------------------------
//--          AZUL           --
//-----------------------------
class SensorStation
{
    public:
        unsigned long sleepTime, lastTime; //Los ocupamos para saber cuando medir los datos

        int level; //Indica el nivel de peligro en el nodo

        TempyHumedad *tempYhumedad;   Anemometro *anemometro; //Sensores que se ocuparan
        Interfaz *interfaz;                                   //Interfaz de red

        SensorStation(unsigned long sleep, int constAnemometro){
        //|-------------- DEFINICION DE LOS TIEMPOS ----------------------------|
            this->sleepTime = sleep;    this->lastTime  = millis();
        //|-------------- NIVEL DE RIESGO INICIAL ----------------------------|
            this->level = 0;
        //|-------------- CEACION DE LOS OBJETOS SENSORES ----------------------------|
            this->tempYhumedad = new TempyHumedad();    this->anemometro = new Anemometro(constAnemometro);
        //|-------------- CREACION DEL OBJETO INTERFAZ DE RED -------------- --------------|
            this->interfaz = new Interfaz();
        }
        
        void checkMedidas(bool requested){
        //|-------------- SE HACEN LAS MEDICIONES EN LOS 2 SENSORES ---------------------------- |
            this->tempYhumedad->medir();  this->anemometro->medir();
        //|-------------- SE CALCULA EL NIVEL DE RIESGO ACTUAL
            this->level = this->tempYhumedad->Check() + this->anemometro->Check();
        //|------ SI LEVEL == 3 O ES PEDIDO POR LA RAIZ SE MANDAN LAS MEDIDAS -------------|
            if( this->level == 3 || requested){
              float payload[5] = { this->level, 
                                   this->tempYhumedad->ultimaMedida[0], 
                                   this->tempYhumedad->ultimaMedida[1],
                                   *this->anemometro->ultimaMedida };
                                   
              RF24NetworkHeader header(00); //La raiz siempre tendra direccion 00

              bool ok = this->interfaz->red->write(header, payload, sizeof(payload)); 
            }
        }

        void setConfig(float *arr){
        //-------------- CAMBIA LAS MAXIMAS MEDIDAS DE AMBOS SENSORES ----------------------------|
            float uno[] = {arr[0], arr[1]};
            float dos[] = { arr[3] }; 
            
            this->tempYhumedad->Config(uno);
            this->anemometro->Config(dos);
        }
        
};

//-----------------------------
//--          MAIN           --
//-----------------------------
SensorStation *Nodo = new SensorStation(1, 0.5);
bool first = true;

void setup()
{ 
//  |-------------------------------------------------------------------------------------|
//  | Preparacion. se configuran los sensores y el modulo de comunicacciones RF           |
//  |-------------------------------------------------------------------------------------|
  Nodo->tempYhumedad->dht->begin();
  analogReference(EXTERNAL);         // pone como referencia interna 1.1V
  Nodo->interfaz->radio->begin();
  Nodo->interfaz->red->begin(90, DIRECCION);
  
}
void loop(){
//  |-------------------------------------------------------------------------------------|
//  |  Paso 1. Si es la primera ejecucion, se pide la configuracion al server.            |
//  |  independiente del resultado, usa el update para hablar con los otros nodos         |
//  |-------------------------------------------------------------------------------------|   
    if ( first ){
        first = 0;
        
        float *res = Nodo->interfaz->getConfig();

        Nodo->setConfig(res);
    }
    
    Nodo->interfaz->red->update();  //Se comunica con la red constantemente

//  |-------------------------------------------------------------------------------------|
//  |  Paso 2. Revisar si se cumplio el sleepTime, de ser asi se checkean las Medidas     |
//  |-------------------------------------------------------------------------------------|
    if(Nodo->lastTime > millis()){ Nodo->lastTime = 0; } // Cuando millis() se desporda y parte de 0
    if( millis() - Nodo->lastTime <= Nodo->sleepTime )   // Es momento de medir el entorno ?
    {
        Nodo->checkMedidas(0);
        Nodo->lastTime = millis();
    }

//  |-------------------------------------------------------------------------------------|
//  |  Paso 3. Aqui necesitamos saber si hemos recibido algun mensaje, cuando             |
//  |  efectivamente nos llega un mensaje vemos que tipo de mensaje es y dependiendo      |
//  |  de esto hacemos cierta accion                                                      |
//  |-------------------------------------------------------------------------------------|
    while( Nodo->interfaz->red->available() ) // Hay algo listo para nosotros?
    {
        float* payload;

        RF24NetworkHeader header;
        Nodo->interfaz->red->read(header, payload, sizeof(payload));
        
        //|-------------- Si tiene 3 items significa que nos mandaron una nueva config --------------|
        if( sizeof(payload)/sizeof(float) == 3)
            Nodo->setConfig(payload);
        else 
        //|-------------- en otro caso, significa que tenemos que mandar las medidas del Nodo --------------|
            Nodo->checkMedidas(1);
    }
}
