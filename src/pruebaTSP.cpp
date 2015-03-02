#include <iostream>
#include <vector>
#include "Poblacion.h"
#include "TSPSolucion.h"
#include <fstream>
#include <cmath>
#include <cstdlib>

using namespace std;
#ifndef PROBMUTACION
#define PROBMUTACION 0.1
#endif
#ifndef PROBPROCREACION
#define PROBPROCREACION 0.9
#endif
#ifndef NUM_INDIVIDUOS
#define NUM_INDIVIDUOS 40
#endif
#ifndef GENERACIONES
#define GENERACIONES 20
#endif

double distancia(TSPSolucion solucion){return solucion.getDistancia();};

int main(int argc, char const *argv[]){

    if(argc != 2){
        cout << "\nIntroduzca un archivo del que leer."<<endl;
        return -1;
    }
    vector<pair<double,double> > ciudades;

    fstream f(argv[1]);

    double dato1,dato2;
    while(!f.eof()){
        f>>dato1;
        f>>dato1;
        f>>dato2;
        ciudades.push_back(pair<double,double>(dato1,dato2));
    }
    vector<vector<double> > distancias(ciudades.size());
    for(unsigned int j = 0; j < ciudades.size(); j++){
        distancias[j].resize(ciudades.size());
    }

    for(unsigned int i = 0; i < distancias.size(); i++){
        for(unsigned int j = i; j < distancias.size();j++){
            distancias[i][j] = sqrt((ciudades[i].first - ciudades[j].first)*(ciudades[i].first - ciudades[j].first) + (ciudades[i].second - ciudades[j].second)*(ciudades[i].second - ciudades[j].second));
            distancias[j][i] = distancias[i][j];

        }
    }
    for(unsigned int i = 0; i < distancias.size(); i++){
        for(unsigned int j = 0; j < distancias.size();j++){
            cout << distancias[i][j]<< " ";
        }
        cout << endl;
    }
    srand(time(NULL));

    TSPSolucion solucion(&distancias);
    TSPSolucion solucion2(&distancias);
    vector<int> recorrido = solucion.getRecorrido();
    cout << "\nRecorrido aleatorio:"<<endl;
    for ( unsigned int i = 0; i < recorrido.size(); i++){
        cout << recorrido[i]<< ",";
    }
    cout << endl;
    solucion.mutar();
    recorrido = solucion.getRecorrido();
    cout << "\nRecorrido aleatorio mutado:"<<endl;
    for ( unsigned int i = 0; i < recorrido.size(); i++){
        cout << recorrido[i]<< ",";
    }
    cout << endl;

    recorrido = solucion2.getRecorrido();
    cout << "\nRecorrido aleatorio 2:"<<endl;
    for ( unsigned int i = 0; i < recorrido.size(); i++){
        cout << recorrido[i]<< ",";
    }
    cout << endl;

    solucion = solucion.procrear(solucion2);

    recorrido = solucion.getRecorrido();
    cout << "\nRecorrido aleatorio procreado:"<<endl;
    for ( unsigned int i = 0; i < recorrido.size(); i++){
        cout << recorrido[i]<< ",";
    }
    cout << endl;
    

    
    return 0;
}