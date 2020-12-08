// -------------------------------
// --          NARANJA          --
// -------------------------------
class Sensor
{
  public:
    //se ocupan para almacenar medidas actuales y determinar si son anomalas
    float *ultimaMedida, *maximaMedida;

    //Permite modificar las medidas que el sensor considera Maximas
    void Config(float* medidas){ this->maximaMedida = medidas; }

    //Contrasta las medidas actuales con las maximas
    int  Check(){
      int res = 0;
      
      for(int i=0;i< sizeof(this->ultimaMedida)/sizeof(float);i++){
        if(this->ultimaMedida[i] > this->maximaMedida[i])
          res++; 
      }
      return res;
    }
};

class TempyHumedad: public Sensor{
  public:
    DHT* dht;  

    TempyHumedad(){ this->dht = new DHT(2, DHT22); }

   void medir(){
    float arr[] = {this->dht->readHumidity(), this->dht->readTemperature()};
    this->ultimaMedida = arr;
   }
}; 

class Anemometro : public Sensor
{ 
    
  public:
    float constante;  // Constante ocupada para calcular la velocidad del viento
  
    Anemometro(float constante){
      this->constante= constante;
    }

    void medir(){
      float v1 = (analogRead(3));              //Medicion recividad del motor
      float Medida[] = { v1*this->constante }; //calculamos la velocidad del viento

      this->ultimaMedida = Medida;
    } 
};
