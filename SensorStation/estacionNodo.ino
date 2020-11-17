//-----------------------------
//--         IMPORTS         --
//-----------------------------
#include <RF24.h>             //Interfaz
#include <RF24Network.h>      //Interfaz

//-----------------------------
//--          AZUL           --
//-----------------------------
class SensorStation
{
  private: 
    uint16_t identifier;
    Interfaz* interfaz
    float* GPS;

    Sensor sensor[3];
    int SleepTime;

    SensorStation()
    {
      

      
    }
};

//-----------------------------
//--          MAIN           --
//-----------------------------
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
