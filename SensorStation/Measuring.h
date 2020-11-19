// -------------------------------
// --          NARANJA          --
// -------------------------------
class Sensor
{
  public:
    float* ultimaMedida;
    float* Tope;

    void Medir();
    void Config();
    bool Check();
};

// LISTO !
class TempyHumedad: public Sensor{
// PUERTO 2 !
  public:
  DHT* dht;  

  TempyHumedad(){
    this->dht = new DHT(2, DHT22);
    
    this->dht->begin(); 
  }

  //LISTOCO
  void Medir(){
    float arr[] = {this->dht->readHumidity(), this->dht->readTemperature()};
    this->ultimaMedida = arr;
  }

  void Config(float* tope){ this->Tope = tope; }

  //LISTOCO
  bool Check(){
      for(int i=0;i< sizeof(this->Tope)/sizeof(float);i++)
      {
        if(this->ultimaMedida[i] > this->Tope[i])
          return 1; 
      }
      return 0;
  }

}; 


class Anemometro : public Sensor
{ 
  void Medir(){} 
  void Config(){}
  bool Check(){}
};
