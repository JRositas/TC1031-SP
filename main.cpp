// Equipo 12
// SP TC1031
// 06 Sep 2021

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "Entrada.h"

using namespace std;

int main(){
    Entrada entrada;
    Entrada* listaEntradas[50];
    int contadorEntrada;
    string fecha, ubi, hora;
    char puntoEntrada;

    ifstream archivoSuez;

    archivoSuez.open("suez.txt");

    while (archivoSuez >> fecha >> hora >> puntoEntrada >> ubi)
    {
        listaEntradas[contadorEntrada] = new Entrada(fecha,hora,puntoEntrada,ubi);
        contadorEntrada++;     
    }
}
