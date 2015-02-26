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
TSPSolucion::TSPSolucion(vector<vector<double>>* matriz, vector<int> camino){
    distancias = matriz;
    this->recorrido = camino;
    distancia = 0;
    for(int i = 0; i < recorrido.size(); i++){
        distancia+=distancias[i][(i+1)%camino.size()];
    }
}

TSPSolucion TSPSolucion::procrear(TSPSolucion const & otro)const{
    int indice = rand()%this->(*distancias).size();
    vector<int> hijo;
    for(int i = 0; i < (*distancias).size(); i++){
        hijo.push_back(-1);
    }
    

    for ( int i = indice; i != (indice+hijo.size()/2)%hijo.size(); i = (i+1)%hijo.size()){
        hijo[i] = this->recorrido[i];

    }
    int j = 0;
    for( int i = (indice+hijo.size()/2)%hijo.size(); i != indice; i = (i+1)%hijo.size()){
        while(find(hijo.begin(),hijo.end(),otro.recorrido[j]) !=hijo.end()){
            j++;
        }
        hijo[i] = otro.recorrido[j];
    }
    return TSPSolucion(this->distancias, hijo);
}

TSPSolucion TSPSolucion::mutar(){
    int indice1 = rand()%(*distancias).size();
    int indice2 = rand()%(*distancias).size();
    distancia -=(*distancias)[(indice1-1+(*distancias).size())%(*distancias).size()][indice1];
    distancia -=(*distancias)[(indice1+1)%(*distancias).size()][indice1];
    distancia -=(*distancias)[(indice2-1+(*distancias).size())%(*distancias).size()][indice2];
    distancia -=(*distancias)[(indice2+1)%(*distancias).size()][indice2];
    distancia +=(*distancias)[(indice2-1+(*distancias).size())%(*distancias).size()][indice1];
    distancia -=(*distancias)[(indice2+1)%(*distancias).size()][indice1];
    distancia -=(*distancias)[(indice1-1+(*distancias).size())%(*distancias).size()][indice2];
    distancia -=(*distancias)[(indice1+1)%(*distancias).size()][indice2];
    int aux = recorrido[indice1];
    recorrido[indice1] = recorrido[indice2];
    recorrido[indice2] = aux;
    return *this;
}