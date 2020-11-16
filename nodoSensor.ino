


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
