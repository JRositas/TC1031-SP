#ifndef Entrada_h
#define Entrada_h 
#include <iostream>
/* #include <vector> */
/* #include <algorithm> */
#include <string>

class Entrada
{

  public:
    Entrada();
    Entrada(string _fecha, int _fechaCode, string _hora, char _entrada, string _ubi);

    // get
    string getFecha() { return fecha;}
    int getFechaCode() { return fechaCode;}
    string getHora() { return hora;}
    char getEntrada() { return entrada;}
    string getUbi() { return ubi;}

    //set 
    void setFecha(string _fecha) { fecha =  _fecha; }
    void setFechaCode(int _fechaCode) { fechaCode = _fechaCode; }
    void setHora( string _hora) { hora = _hora; }
    void setEntrada( char _entrada) { entrada = _entrada;}
    void setUbi(string _ubi) { ubi = _ubi; }

    // imprimir 
    void mostrar();

    private:
      string fecha;
      int fechaCode;
      string hora;
      char entrada;
      string ubi;
};

Entrada::Entrada()
{
  fecha = " ";
  fechaCode = 0;
  hora = " ";
  entrada = " ";
  ubi = " ";
}

Entrada::Entrada(string _fecha, int _fechaCode, string _hora, char _entrada, string _ubi)
{
  fecha =  _fecha;
  fechaCode = _fechaCode;
  hora = _hora;
  entrada = _entrada;
  ubi = _ubi;
}

void Entrada::mostrar()
{
  cout << fecha << " " << hora << " " << entrada << " " << ubi << endl;
}

#endif /* Entrada_h */


