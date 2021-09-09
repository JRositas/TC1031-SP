#include <iostream>
// #include <vector> 
// #include <algorithm> 
#include <string>

#ifndef ENTRADA_H
#define ENTRADA_H 

class Entrada
{

  public:
    Entrada(string fecha, int fechaCode, string hora, char puntoEntrada, string ubi);
    Entrada();

    // get
    string getFecha() { return fecha;}
    int getFechaCode() { return fechaCode;}
    string getHora() { return hora;}
    char getPuntoEntrada() { return puntoEntrada;}
    string getUbi() { return ubi;}

    //set 
    void setFecha(string _fecha) { fecha =  _fecha; }
    void setFechaCode(int _fechaCode) { fechaCode = _fechaCode; }
    void setHora( string _hora) { hora = _hora; }
    void setPuntoEntrada( char _puntoEntrada) { puntoEntrada = _puntoEntrada;}
    void setUbi(string _ubi) { ubi = _ubi; }

    // imprimir 
    void mostrar();

    private:
      string fecha;
      int fechaCode;
      string hora;
      char puntoEntrada;
      string ubi;
};

Entrada::Entrada()
{
  fecha = " ";
  fechaCode = 0;
  hora = " ";
  puntoEntrada = 2;
  ubi = " ";
}

Entrada::Entrada(string _fecha, int _fechaCode, string _hora, char _puntoEntrada, string _ubi)
{
  fecha =  _fecha;
  fechaCode = _fechaCode;
  hora = _hora;
  puntoEntrada = _puntoEntrada;
  ubi = _ubi;
}

void Entrada::mostrar()
{
  cout << fecha << " " << hora << " " << puntoEntrada << " " << ubi << endl;
}

#endif // Entrada_h 


