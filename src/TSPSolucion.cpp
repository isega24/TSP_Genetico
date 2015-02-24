#include "TSPSolucion.h"
using namespace std;

TSPSolucion::TSPSolucion(vector<vector<double>>* matriz){
    this->distancias = matriz;
    vector<int> ciudades;
    /**
    Primero generamos un vector con todas las ciudades, del 0 al tamaño de la matriz.
    */
    for(int i = 0; i < (*matriz).size(); i++){
        ciudades.push_back(i);
    }
    int ciudad;
    this->distancia = 0;
    /**
    Despues vamos extrallendo las ciudades de tal vector aleatoriamente para inicializarla.
    Además aprovechamos para calcular la distancia.
    */
    for(int i = 0; i < (*matriz).size(); i++){
        ciudad = rand()%ciudades.size();
        if(i != 0){
            this->distancia+= (*distancias)[recorrido[recorrido.size()][ciudad]];
        }
        recorrido.push_back(ciudades[ciudad]);
        ciudades.erase(find(ciudades[ciudad]))
    }
    /*
    No hemos sumado las distancias de los extremos para no tener errores de segmentación.
    Las sumamos ahora.
    */
    this->distancia += (*distancias)[recorrido[0]][recorrido[1]] + (*distancias)[recorrido[0]][recorrido[recorrido.size()-1]];
    
}