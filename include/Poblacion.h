#include <cstdlib>
#include <cassert>
#include <vector>
#include <limits.h>
#include <cstdlib>
#ifndef POBLACION
#define POBLACION
using namespace std;

template <class individuo>

/**
* Para poder usar esta clase con un tipo de dato \e individuo, este debe poseer las funciones
* procrear(individuo otro) y la funcion muta(void)
*/

class Poblacion{
    /**
* @page repConjunto Rep del TDA Poblacion
*
* @section invConjunto Invariante de la representacion.
*
* Sea \e P una poblacion de \e individuos:
*       El último elemento de evolucion_individuos representa todos los
*       individuos vivos de la población actual. Cada componente de este
*       representa un momento del tiempo de la población anterior al actual,
*       de forma que un momento i es el momento anterior al i+1 y posterior
*       al i-1. 
* @section faConjunto Función de Abstracción:
*       Se representa cada individuo como un elemento de evolucion_individuos[j],
*       siendo j un momento del tiempo entre 0 y el momento actual.
*       
*/
private:
    /**
    *@brief evolucion_individuos.
    * En esta estructura, se guardan las distintas poblaciones de individuos en
    * distintos momentos del tiempo.
    */
    vector< vector<individuo> > evolucion_individuos;

    /**
    * Es la probabilidad de que dos individuos cualesquiera procreen.
    * Se asigna al inicializar la población.
    */

    double prob_procrear;

    /**
    * Probabilidad de que se produzca una mutación en el individuo en la siguiente generación.
    */

    double prob_mutacion;

    /**
    * Función que hay que minimizar. En el caso de querer maximizar, se le pasará como
    * argumento la función de sus inversos, es decir, 1/f(x), teniendo en cuenta que f
    * tomará siempre valores en los reales positivos.
    */

    double (*func)(individuo);

    individuo get_individuo();

public:
    Poblacion(vector<individuo> inicial,double prob_mutacion,double prob_procrear, double (*func)(individuo)){
        cout << "prob_mutacion:"<<prob_mutacion << " prob_procrear:"<< prob_procrear<<endl;
        assert(prob_mutacion <1 && prob_mutacion > 0 && prob_procrear > 0 && prob_procrear < 1);
        evolucion_individuos.push_back(inicial);
        this->prob_procrear = prob_procrear;
        this->prob_mutacion = prob_mutacion;
        this->func = func;
    }

    void paso_del_tiempo();

    vector<vector<individuo> > getEvolucion(){
        return this->evolucion_individuos;
    }
};
#include "Poblacion.cpp"
#endif