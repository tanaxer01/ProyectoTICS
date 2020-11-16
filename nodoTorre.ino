
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

// -------------------------------
// --            AZUL           --
// -------------------------------
class TorreStation
{
  private:
    //vars de dispositivo
    char* Identifier;
    Network interfaz;

    //GPS
    float* coordenadas;

    //vars especificas
    char* serverURL           // como vamos a mandar la info al server
    int   askingTime;
    float* infoBuffer;

  public:
// status: FALTA
    TorreStation(){}
// status: FALTA
    void getGPS(){}
// status: FALTA
    bool upload(){ return 1; } //definir como mandaremos la info
// status: FALTA
    void getAllmedidas(){}
// status: FALTA
    bool checkVision(){}
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