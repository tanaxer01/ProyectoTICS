class Interfaz 
{
  public:
    //Objetos necesarios para poder ocupar el modulo RF
    RF24 *radio;
    RF24Network *red;


    Interfaz()
    {
      //con esto indicamos que pines utilizara el modulo y que modulo ocupara la libreria
      this->radio = new RF24(10, 9);
      this->red   = new RF24Network(*this->radio);
    }
};
