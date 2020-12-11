//-----------------------------
//--          VERDE          --
//-----------------------------
class Interfaz
{
  public:
    //|-------------- ATRIBUTOS NECESARIOS PARA LA INTERFAZ ----------------------------|
    RF24 *radio;
    RF24Network *red;


    Interfaz(){
      //|-------------- INICIAMOS LOS OBJETOS DE LA INTERFAZ ----------------------------|
      this->radio = new RF24(10, 9);
      this->red   = new RF24Network(*this->radio);
    }

    float* getConfig(){
      float msg = 1111; //mensaje que indica una peticion de config

      RF24NetworkHeader header(00);//Nodo raiz siempre sera el 00

      bool ok = this->red->write(header, &msg, sizeof(msg));
      if(ok)
      {
        float* info;
        RF24NetworkHeader header;

        while( this->red->available() )
        {
          this->red->read(header, info, sizeof(info));

          //Descartara cualquier paquete que no sea la configuracion
          if(sizeof(info) == 3)
            return(info);
          
        }
      }else{
        float error[] = {0, 0, 0}; 
        return(error);
      }
    }
};
