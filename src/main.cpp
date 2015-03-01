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

    srand(time(NULL));


    vector<TSPSolucion> primera_generacion;
    for( int i = 0; i < NUM_INDIVIDUOS;i++){
        primera_generacion.push_back(TSPSolucion(&distancias));
    }
    Poblacion<TSPSolucion> poblacion(primera_generacion,PROBMUTACION,PROBPROCREACION,&distancia);

    for(unsigned int i = 0; i < GENERACIONES; i++){
        poblacion.paso_del_tiempo();
    }
    vector<vector<TSPSolucion> > evolucion = poblacion.getEvolucion();
    vector<double> mejores;

    for(unsigned int i = 0; i < evolucion.size();i++){
        mejores.push_back(evolucion[i][0].getDistancia());
        for(unsigned int j = 0; j < evolucion[i].size();j++){
            if(mejores[i] > evolucion[i][j].getDistancia()){
                mejores[i] = evolucion[i][j].getDistancia();
            }
        }
    }
    for(unsigned int i = 0; i < mejores.size(); i++){
        cout << "Generacion " << i << ", mejor distancia:"<<mejores[i]<<endl;
    }

    return 0;
}