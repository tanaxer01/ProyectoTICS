


// -------------------------------
// --          NARANJA          --
// -------------------------------

// status: READY
class Sensor{ protected: float* ultimaMedida; };

// status: FALTA MEDIR
class TempYHumedad: public Sensor{ void Medir(){ return(this->ultimaMedida); } };

// status: FALTA MEDIR
class Anemometro:   public Sensor{ void Medir(){ return(this->ultimaMedida); } };
//class GPS: public Sensor {};


/////////////////////
///CODIGO SENSORES///
/////////////////////

#include "DHT.h"  // Incluye la libreria DHT

#define DHTPIN 2     // Pin donde está conectado el sensor: Pin 2
#define DHTTYPE DHT22  // Define el tipo de sensor : DHT22

//int puertoAnemometro = 3; // Pin donde está conectado el sensor: 3
//#define anemometro   // Define el tipo de anemometro

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("Iniciando...");
  dht.begin();
  // anemometro.begin();
  
}

void loop() {
  delay(20000);                       //Leemos cada 20000 milisegundos = 20 segundos

  float h = dht.readHumidity();       //Leemos la Humedad
  float t = dht.readTemperature();    //Leemos la temperatura en grados Celsius
// float v = anemometro()             //Leemos los datos del anemometro

  //--------Enviamos las lecturas por el puerto serial-------------
  Serial.print("Humedad ");
  Serial.print(h);
  Serial.print(" %t");

  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.print(" *C ");

  // Serial.print("Viento: ");
  // Serial.print(V);
  // Serial.print(" *m/s ");

}



// -------------------------------
// --           VERDE           --
// -------------------------------
class Network 
{
  private:
    char **Vecinos;
    char *toGateway;

  public:
// status: FALTA
    bool joinNet(){  return 1;}
// status: FALTA
    bool calcPath(){ return 1;}
    
// que retornaran ?? revisar libreria
// Listening() 
// getMedidas(string destino){}
// sendMedidas(string destino{})
};

// -------------------------------
// --            AZUL           --
// -------------------------------
class SensorStation
{
  private:
    //vars de dispositivo
    char* Identifier;
    Network interfaz;

    // GPS
    float* coordenadas;

    //vars especificas
    Sensor sensor[3];
    int SleepTime;


  public:
// status: FALTA
    SensorStation(){}
// status: FALTA
    void getGPS(){}
};


// status: FALTA
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
}
// status: FALTA
void loop() {
   digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);    

}
