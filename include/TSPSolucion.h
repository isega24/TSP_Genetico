#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;
#ifndef TSPSOLUCION
#define TSPSOLUCION
class TSPSolucion{
private:
    vector<int> recorrido;
    vector<vector<double> >* distancias;
    double distancia;


public:
    TSPSolucion();
    TSPSolucion(vector<vector<double> >* matriz);

    TSPSolucion(vector<vector<double> >* matriz, vector<int> camino);

    TSPSolucion procrear(TSPSolucion const & otro)const;

    TSPSolucion mutar();

    vector<int> getRecorrido(){return this->recorrido;}

    double getDistancia()const{return this->distancia;};

    TSPSolucion operator=(TSPSolucion const & otra){
        this->distancia = otra.distancia;
        this->recorrido = otra.recorrido;
        this->distancias = otra.distancias;
    }
};
#endif
