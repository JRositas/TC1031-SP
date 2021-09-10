#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<string> v;
    string busqueda;

    busqueda = "";

    v = {"V2L", "V2L", "D9A","D9A","D9A", "D9A"};
    cin >> busqueda;

    vector<string>::iterator inicioBuscado, finBuscado;

    inicioBuscado = lower_bound(v.begin(), v.end(), busqueda);
    finBuscado = upper_bound(v.begin(), v.end(), busqueda);

    cout << (inicioBuscado- v.begin()) << endl;
    cout << (finBuscado- v.begin()) << endl;
}