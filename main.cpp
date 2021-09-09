// Equipo 12
// SP TC1031
// 06 Sep 2021

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "Entrada.h"

using namespace std;

int date2Int(string date){
    int dateCode = 0;
    int aux = 0;
    int i = 0;
    while(date[i] != '-'){
        aux *= 10;
        aux += (date[i++] - '0');
    }
    dateCode += aux;

    string month = "";
    while(date[++i] != '-'){
        month += date[i];
    }
    int monthCode = 0;
    if(month == "jan"){
        monthCode = 1;
    } else if(month == "feb"){
        monthCode = 2;
    } else if(month == "mar"){
        monthCode = 3;
    } else if(month == "apr"){
        monthCode = 4;
    } else if(month == "may"){
        monthCode = 5;
    } else if(month == "jun"){
        monthCode = 6;
    } else if(month == "jul"){
        monthCode = 7;
    } else if(month == "aug"){
        monthCode = 8;
    } else if(month == "sep"){
        monthCode = 9;
    } else if(month == "oct"){
        monthCode = 10;
    } else if(month == "nov"){
        monthCode = 11;
    } else if(month == "dec"){
        monthCode = 12;
    }
    dateCode += (monthCode * 100);

    aux = 0;
    while(++i < date.length()){
        aux *= 10;
        aux += (date[i] - '0');
    }
    dateCode += (aux * 10000);

    return dateCode;
}

//funcion
bool comparaDate( Entrada x, Entrada y) // compara fecha por fecha
{
  if (x.getUbi() == y.getUbi()) // checar si hay empate, si hay empate ordena por fecha
  {
    return x.getFechaCode() < y.getFechaCode(); // cual de las dos fechas es más grande
  }
  //Si la fecha de x es más chica, regresa falso
  if(x.getUbi() < y.getUbi())
  {
    return false;
  }
  //Si la fecha de y es más chica, regresa verdadero
  else
  {
    return true;
  }
  //return (x.getUbi().compare(x,y) < 0); //Esto ya se puede borrar
}




int main(){
    //Entrada* listaEntradas[50];
    int contadorEntrada, fechaCode;
    string fecha, ubi, hora;
    char puntoEntrada;

    ifstream archivoSuez;

    archivoSuez.open("suez.txt");

    
    vector<Entrada> mivect;
    Entrada *objAuxiliar; //Crear variable que guarde el objeto fuera del ciclo
    while (archivoSuez >> fecha >> hora >> puntoEntrada >> ubi)
    {
        //Hay que definir fecha code antes de meterlo al constructor
        //fechaCode = date2int(fecha);
        objAuxiliar = new Entrada(fecha, fechaCode, hora, puntoEntrada, ubi); //Igualas la variable al objAuxiliar
        mivect.push_back(objAuxiliar);  //push_back() es el metodo que guarda los valore de un vector en el
    }

    /*
    ====Anterior====
    while (archivoSuez >> fecha >> hora >> puntoEntrada >> ubi)
    {
        listaEntradas[contadorEntrada] = new Entrada(fecha,hora,puntoEntrada,ubi);
        contadorEntrada++;  

    }
    */
    
    // using function as comp
    sort(mivect.begin(), mivect.end(), comparaDate);
  /*

    [..., ... , ... , , , , , , , ,] arreglo
    [] vector.push_back() -> [... , ] vector.push_back() -> [..., ..., ]


    */

    /*
      Cuando quieras checar la fecha, utilizas metodo comparaDate
      ¿De donde saco los metodos de tipo "Entrada"? Del vector "mivect"
      comparaDate(mivect[0], mivect[1]);
    */

    //sort(listaEntradas.begin(), listaEntradas.end(), comparaDate);
}

