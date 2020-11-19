//-----------------------------
//--          VERDE          --
//-----------------------------

class Interfaz
{
// PUERTO 10, 9
  public:
    RF24* radio;
    RF24Network* red;

    Interfaz()
    {
      //setUp
      this->radio = new RF24(10, 9);
      this->red   = new RF24Network(*this->radio);

    }
    
    void joinNet(uint16_t id)
    {
      this->radio->begin();
      this->red->begin(90, id);
    }

    float* getConfig()
    { 
      unsigned long mensaje = 1111;
      RF24NetworkHeader header(this->red->parent());

      bool ok =  this->red->write(header,&mensaje,sizeof(mensaje));
      
      if(ok)
      {
        float* info;
        RF24NetworkHeader header;
        while( this->red->available() )
        {
          this->red->read(header,info, sizeof(info));
          break;
        }

        return info;
        
        
      }else{
        float no = 1;
        float* fail = &no;
      
        return(fail);
      }
    
    }

};
