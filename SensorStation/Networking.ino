//-----------------------------
//--          VERDE          --
//-----------------------------

class Interfaz
{
  public:
    // RF24Network ya almacena esta variable / sacarla ?
    uint16_t id;
    uint16_t gateway;

    RF24* radio;
    RF24Network* red;

    Interfaz(uint16_t CE, uint16_t CSN)
    {
      this->radio = new RF24(CE, CSN);
      this->red   = new RF24Network(*this->radio);
    }


    // ** problema   
    // -> distribucion de los ids va a tener que ser "a mano" <-
    //  
    // la libreria requiere 5bytes por cada direccion guardada, 
    // cada direccion es de 2bytes por lo que tendremos un maximo 
    //
    // La topologia que se ocupa es de arbol
    // Cada nodo puede tener 5 hijos y el arbol puede tener un maximo de 5 niveles
    // 5^5 = 3125
    //    
    // ++ Beneficios -> Todo el tema de compartir info ya esta implementado
    void joinNet(uint16_t id)
    {
      this->id = id;
      
      this->radio->begin();
      this->red->begin(90, this->id);
    }

    bool calcPath(){ return 1; }
    // Listening() en vola no sea necesaria
    unsigned long getMedidas(uint16_t id){ return 1; }
    bool sendMedidas(uint16_t id, bool warning){ return 1; }
};
