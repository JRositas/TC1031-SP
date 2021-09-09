// Equipo 12
// SP TC1031
// 06 Sep 2021

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "Entrada.h"

using namespace std;

// Complejidad O(n) Lineal, dependiente del largo de "date"
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

// Complejidad: 0(1)
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
}
// Complejidad: log(n)
// utilizar lower_bound



int main(){
    int contadorEntrada, fechaCode;
    string fecha, ubi, hora;
    char puntoEntrada;

    ifstream archivoSuez;

    archivoSuez.open("suez.txt");

    vector<Entrada> mivect;
    Entrada *objAuxiliar; //Crear variable que guarde el objeto fuera del ciclo
    while (archivoSuez >> fecha >> hora >> puntoEntrada >> ubi)
    {
        fechaCode = date2Int(fecha);
        objAuxiliar = new Entrada(fecha, fechaCode, hora, puntoEntrada, ubi); //Igualas la variable al objAuxiliar
        mivect.push_back(*objAuxiliar);  //push_back() es el metodo que guarda los valores en el vector
    }
    
    sort(mivect.begin(), mivect.end(), comparaDate);
}
