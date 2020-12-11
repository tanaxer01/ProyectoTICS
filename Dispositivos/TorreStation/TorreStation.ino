//-----------------------------
//--         IMPORTS         --
//-----------------------------
// LIBS
#include <RF24.h>             //Interfaz
#include <RF24Network.h>      //Interfaz

// FILES
#include "Networking.h"

// Otros  
#define DIRECCION 00

// -------------------------------
// --            AZUL           --
// -------------------------------
class TorreStation
{
  public:
    unsigned long askingTime, lastTime; //Los ocupamos para saber cuando medir los datos

    int cont;
    uint16_t bufferIDs[3125];  // Buffer que almacenara las medidas no urgentes
    float   *bufferInfo[3125];     // hasta el momento de enviarlas.

    Interfaz *interfaz;                //Interfaz de red

    
    TorreStation(unsigned long askingTime)
    {
      //definicion tiempos
      this->askingTime = askingTime;
      this->lastTime   = millis();

      cont = 0;
      //constructor de la interfaz
      this->interfaz = new Interfaz();
    }
};

//-----------------------------
//--          MAIN           --
//-----------------------------
TorreStation *Nodo = new TorreStation(1);

void setup()
{
//  |-------------------------------------------------------------------------------------|
//  | Preparacion. se configura el modulo de comunicacciones RF                           |
//  |-------------------------------------------------------------------------------------|
  Nodo->interfaz->radio->begin();
  Nodo->interfaz->red->begin(90, DIRECCION);
}

void loop()
{
//  |-------------------------------------------------------------------------------------|
//  |  Paso1. Hacemos un update de la red.
//  |-------------------------------------------------------------------------------------|
  Nodo->interfaz->red->update();

//  |-------------------------------------------------------------------------------------|
//  |  Paso2. Vemos si el AskingTime se cumplio para empezar el proceso de medidas        |
//  |  en la red.                                                                         |
//  |-------------------------------------------------------------------------------------|
//  **********
  if(Nodo->lastTime > millis()){ Nodo->lastTime = 0; } // Cuando millis() se desborda y parte de 0
  if( millis() - Nodo->lastTime <= Nodo->askingTime )
  {
    unsigned long step = 60000;   // 1 min de espera
    int curr = 1;

    while(curr < 7)
    {
      if(millis() == Nodo->lastTime + step){
        Nodo->lastTime = millis();

        RF24NetworkHeader header;
        float msg = 1;
        bool ok = Nodo->interfaz->red->multicast(header,&msg,sizeof(msg),curr);

        float* payload;
        while( Nodo->interfaz->red->available() ){
            RF24NetworkHeader header;
            Nodo->interfaz->red->read(header,payload, sizeof(payload));

            //Almacenamos los mensajes entrantes en 2 buffers (uno para las ips y otro para la info)
            Nodo->bufferInfo[Nodo->cont] = payload;
            Nodo->bufferIDs[Nodo->cont]  = header.from_node;
        }
      
        curr++;
      }
    }

    
  }

//  |-------------------------------------------------------------------------------------|
//  |  Paso 3. Aqui necesitamos saber si hemos recibido algun mensaje, cuando             |
//  |  efectivamente nos llega un mensaje vemos que tipo de mensaje es y dependiendo      |
//  |  de esto hacemos cierta accion                                                      |
//  |-------------------------------------------------------------------------------------|
  while( Nodo->interfaz->red->available() )
  {
    RF24NetworkHeader header;
    float* payload;

    Nodo->interfaz->red->read(header, payload, sizeof(payload));
    if(payload == 1111){
      // PEDIR CONFIGURACION AL SERVIDOR

      RF24Network header(00);
      //payload = RESPUESTA DEL SERVIDOR 

      bool ok = Nodo->interfaz->red->write(header, &msg, sizeof(msg));
    }else{
      //SIGNIFICA QUE LLEGO UN WARNING
      //ENVIAR INFO HACIA EL SERVIDOR
    }

  }
}
