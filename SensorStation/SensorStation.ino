//-----------------------------
//--         IMPORTS         --
//-----------------------------
// LIBS
#include <RF24.h>             //Interfaz
#include <RF24Network.h>      //Interfaz
#include <DHT.h>              //TempYHumedad

// FILES
#include "Networking.h"
#include "Measuring.h"


//-----------------------------
//--          AZUL           --
//-----------------------------
class SensorStation
{
  public: 
    Interfaz* interfaz;
    uint16_t id;
    
    float* GPS;

    Sensor* sensor[2];
    int SleepTime;

    SensorStation(uint16_t id, int SleepTime)
    {
      this->interfaz  = new Interfaz(id);

      this->sensor[0] = new TempyHumedad();
      this->sensor[1] = new Anemometro();
      this->SleepTime = SleepTime;


      //this->GPS = ??
    }

    int checkMedidas()
    {
      int res = 0;
      
      for(int i=0;i<2;i++)
      { 
        this->sensor[i]->Medir();
        res += this->sensor[i]->Check();
      }

      return res;
    }

    void updateNet(uint16_t id)
    {
      if(this->id)
      {
        this->id = id;
        this->interfaz->red->up
        
      }

      
    }


    void updateNet()
    {
      if(!this->sensor[0]->Tope)
      {
        this
        
        float* medidas = this->interfaz->getConfig();
        float uno[] =  {medidas[0], medidas[1]};
        float dos = medidas[2];
        
        this->sensor[0]->Tope = uno;
        this->sensor[1]->Tope = &dos;
      }

      this->interfaz->red->update();
      
    }
};

//-----------------------------
//--          MAIN           --
//-----------------------------
SensorStation* Nodo;

void setup() {
  Nodo = new SensorStation(01, 10);

}

void loop() {
  Nodo->updateNet();
  
  // put your main code here, to run repeatedly:

}
