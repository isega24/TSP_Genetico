#include <vector>
using namespace std;
class TSPSolucion{
private:
    vector<int> recorrido;
    vector<vector<double>>* distancias;
    double distancia;


public:
    TSPSolucion(vector<vector<double>>* matriz);

    TSPSolucion(vector<vector<double>>* matriz, vector<int> camino);

    TSPSolucion procrear(TSPSolucion const & otro)const;

    TSPSolucion mutar();

    double getDistancia(){return this->distancia;}const;
};
/**
* Función a minimizar. Lo hacemos para poder generalizar la función a minimizar.
* Así no necesitamos que la clase asuma la función a minimizar como suya, podríamos tomar
* otra que nos inventemos, como inventarnos un peso para cada ciudad recorrida.
*/

double distancia(TSPSolucion solucion){return solucion.getDistancia();};