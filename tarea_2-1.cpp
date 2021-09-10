/*
Programa de oredenación y búsqueda de datos utilizando diferentes algoritmos.
Daniel Evaristo Escalera Bonilla A00831289
05/09/2021
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Función que regresa la posición del datointroducido de un arreglo de datos, evaluando cada elemento de la lista hasta que lo encuentra.
// Complejidad: Mejor Caso O(1), Peor Caso O(n)
int busqSeceuncia(vector<int> &datos, int datoBusca){
    for (int i = 0; i < datos.size(); i++) {
        if(datos[i] == datoBusca){
            return i;
        }
    }
    return -1;
}

// Función que regresa la posición del datointroducido de un arreglo de datos, evaluando el elemento de enmedio, comparandolo con el buscado y buscado a la izquierda si es menor y a la derecha se es mayor.
// Complejidad: Mejor caso O(1), Peor Caso O(log n)
int busqBinaria(vector<int> &datos, int datoBusca, int &comBinaria){
    int ini = 0, fin = datos.size()-1;
    int mit;
    comBinaria = 0;
    while (ini <= fin) {
        mit = (ini + fin) / 2;
        comBinaria++;
        if (datos[mit] == datoBusca){
            return mit;
        }
        if (datos [mit] > datoBusca){
            fin = mit-1;
        }
        else{
            ini = mit+1;
        }
    }
    return -1;
}

// Función que ordena una lista de enteros otorgada de menor a mayor, eligiendo una posicion y comparandolo con las demás, si es mayor se intercambia regresa el número de comparaciones que realizó.
//Complejidad: Mejor caso: O(n^2) Peor caso: O(n^2)
int ordenaIntercambio(vector<int> &datos){
    int comp = 0, temp;
    for (int i = 0; i < datos.size()-1; i++){
        for(int j = i+1; j < datos.size(); j++){
            comp++;
            if (datos[i] > datos[j]){
                temp = datos[i];
                datos[i] = datos[j];
                datos[j] = temp;
            }
        }
    }
    return comp;
}

// Función que ordena una lista de enteros otorgada de menor a mayor, se aplica a traves de todo el arreglo, comparando dos números y llevando el mayor a la derecha, después compara ese con el de su derecha y así sucesivamente, regresa el número de comparaciones que realizó.
// Complejidad: Mejor Caso O(n) Peor caso O(n^2)
int ordenaBurbuja(vector<int> &datos) {
    bool interruptor = true;
    int temp, comp = 0;
    for (int pasada = 0; pasada<datos.size()-1 && interruptor; pasada ++){
        interruptor = false;
        for(int j=0; j<datos.size()-1-pasada; j++){
            comp++;
            if(datos[j + 1] < datos[j]){
                temp = datos[j + 1];
                datos[j + 1] = datos[j];
                datos[j] = temp;
                interruptor = true;
            }
        }
    }
    return comp;
}

//Complejidad: O(n)
void une(vector<int> &datos, int inicio, int mit, int fin, int &comp){
    vector<int> aux(datos.size()); // Requiere memoria adicional de tamaño n.
    int i = inicio, j = mit + 1, k = inicio;
    while (i <= mit && j <= fin){ //Mientras tenga datos que comparar de las dos mitades.
        comp++;
        if(datos[i] <= datos[j]){
            aux[k++] = datos[i++];
        }
        else{
            aux[k++] = datos[j++];
        }
    }
    if (i>mit){
        for (int a = j; a <= fin; a++){
            aux[k++] = datos[a];
        }      
    }    
    else{
        for (int a = i; a <= mit; a++){
            aux[k++] = datos[a];
        }
    }
    for (int a=inicio; a <= fin; a++){
        datos[a] = aux[a];
    }
}

// Función que ordena una lista de enteros otorgada de menor a mayor dividiendo el arreglo en arreglos mas pequeños para comparar ordenar y combinar los arreglos finales.
//Complejidad Mejor caso: O(nlog(n)) Peor caso: O(nlog(n))
void ordenaMerge(vector<int> &datos, int inicio, int fin, int &comp){
    if (inicio < fin){
        int mit = (inicio + fin) / 2;
        ordenaMerge(datos, inicio, mit, comp);
        ordenaMerge(datos, mit + 1, fin, comp);
        une(datos, inicio, mit, fin, comp);
    }
}

int main(){
    int n, q, datoLee, datoBusca;
    cin >> n;
    vector<int> datos1(n);
    vector<int> datos2(n);
    vector<int> datos3(n);

    for(int i = 0; i < n; i++){
        cin >> datoLee;
        datos1[i] = datoLee;
        datos2[i] = datoLee;
        datos3[i] = datoLee;
    }
 
    int compInter = ordenaIntercambio(datos1);
    int compBurb = ordenaBurbuja(datos2);
    int compMerge = 0;
    ordenaMerge(datos3, 0, n-1, compMerge);
    cout << compInter << " " << compBurb << " " << compMerge << endl;

    cin >> q;
    
    for(int i = 0; i < q; i++){
        cin >> datoBusca;
        int posSecuencial = busqSeceuncia(datos1, datoBusca);
        int comSecuencial = (posSecuencial == -1 ? datos1.size() : (posSecuencial+1));
        int comBinaria, posBinaria;
        posBinaria = busqBinaria(datos1, datoBusca, comBinaria);
        cout << posSecuencial << " " << comSecuencial  << " " << comBinaria << endl;
    }
}