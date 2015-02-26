#include "Poblacion.h"
using namespace std;

template<class individuo>
individuo Poblacion<individuo>::get_individuo(){
    return this->evolucion_individuos[evolucion_individuos.size()-1][rand()%evolucion_individuos.size()];
}

template<class individuo>
void Poblacion<individuo>::paso_del_tiempo(){
    
}