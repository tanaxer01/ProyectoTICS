// -------------------------------
// --          NARANJA          --
// -------------------------------
class Sensor
{
  protected:
    float* ultimaMedida;
};

class TempyHumedad : public Sensor
{ void Medir(){} };

// --------------------------------------- LO QUE PUSO EL SEBA

#include "DHT.h"

//creo que no es necesario ocupar define 
#define DHTPIN 2     
#define DHTTYPE DHT22

//int puertoAnemometro = 3; // Pin donde está conectado el sensor: 3
//#define anemometro   // Define el tipo de anemometro

DHT dht(DHTPIN, DHTTYPE);

//void setup() {
//  Serial.begin(9600);
//  Serial.println("Iniciando...");
//  dht.begin();
//  // anemometro.begin();
//  
//}
//
//void loop() {
//  delay(20000);                       //Leemos cada 20000 milisegundos = 20 segundos
//
//  float h = dht.readHumidity();       //Leemos la Humedad
//  float t = dht.readTemperature();    //Leemos la temperatura en grados Celsius
//// float v = anemometro()             //Leemos los datos del anemometro
//
//  //--------Enviamos las lecturas por el puerto serial-------------
//  Serial.print("Humedad ");
//  Serial.print(h);
//  Serial.print(" %t");
//
//  Serial.print("Temperatura: ");
//  Serial.print(t);
//  Serial.print(" *C ");
//
//  // Serial.print("Viento: ");
//  // Serial.print(V);
//  // Serial.print(" *m/s ");
//}

// --------------------------------------- 



class Anemometro : public Sensor
{ void Medir(){} };
