// -------------------------------
// --          NARANJA          --
// -------------------------------
class Sensor
{
  protected:
    float* ultimaMedida;
};

//----------------Faltaría revisar como pasar los datos registrados a "ultimaMedida"

class TempyHumedad: public Sensor{

  public:
  int pin;
  #define DHTTYPE DHT22
  DHT* dht;  
  TempyHumedad(int pin){
    this->pin = pin;
    this->dht = new DHT(this->pin, DHTTYPE);
  } 
  
  
  void begin(){
    this->dht->begin(); 
  }
  float MedirH(){
    return dht->readHumidity();
  }
  float MedirT(){
    return dht->readTemperature();
  }

}; 


class Anemometro : public Sensor
{ void Medir(){} };
