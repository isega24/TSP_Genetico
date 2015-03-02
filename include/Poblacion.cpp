#include "Poblacion.h"
using namespace std;

template<class individuo>
individuo Poblacion<individuo>::get_individuo(){
    return this->evolucion_individuos[rand()%evolucion_individuos.size()];
}

template<class individuo>
void Poblacion<individuo>::paso_del_tiempo(){
    /*
    El método para implementar el paso del tiempo será el siguiente:
    Primero creamos una nueva generación de individuos, a partir de procreacion
    y mutaciones asi:
        Para cada posible par de individuos:
        Seleccionamos dos individuos aleatoriamente. Vemos si procrean.
        Si no lo hacen, cambiamos de individuos.
        Si lo hacen, vemos si el hijo que producen muta o no.
        Insertamos tal posible hijo en la nueva seleccion de individuos.

    Una vez tenemos la seleccion de individuos nueva, ejercemos la`presión natural:
    Primero calculamos la suma de todas las 1/f(x), con f siendo la funcion a minimizar y x
    cada uno de los individuos. Despues:
        Rellenamos el vector aleatoriamente, generamos un numero real entre 0 y sum(f(x)),
        Vamos calculando la probabilidad acumulada desde el primer elemento hasta que nos pasemos del valor obtenido.
        Ese elemento es el que metemos en la siguiente generacion.

    */
    int i,j;
    vector<individuo> posibles_hijos;
    individuo hijo;
    cout << "Aqui" <<endl;
    while(posibles_hijos.size() < evolucion_individuos.size()){
            cout << "Aqui dentro" <<endl;

        i = rand()%evolucion_individuos.size();
        j = rand()%evolucion_individuos.size();
            cout << "Aqui dentro" <<endl;

        if(rand()*1.0/INT_MAX < prob_procrear){
                cout << "Aqui en el if?" <<endl;

            hijo = evolucion_individuos[i].procrear(evolucion_individuos[j]);
            cout << "Aqui en el procrear?" <<endl;
            if(rand()*1.0/INT_MAX < prob_mutacion){
                cout << "Aqui en el 2do if?" <<endl;
                hijo.mutar();
            }
            cout << "Aqui en el if por el pushback?" <<endl;
            posibles_hijos.push_back(hijo);
        }
    }
        cout << "Aqui" <<endl;

    double total = 0;
    for(int i = 0; i < evolucion_individuos.size(); i++){
        total += 1.0/func(posibles_hijos[i]);
    }
        cout << "Aqui" <<endl;

    double prob_acumulada, random;
    vector<individuo> prox_generacion;
    for( int i = 0; i < evolucion_individuos.size();i++){
        prob_acumulada = 0;
        j = 0;
        random = (rand()*1.0/INT_MAX)*total;
        cout << "Aqui en el for?" <<endl;
        while(prob_acumulada < random){
            prob_acumulada += 1.0/func(posibles_hijos[j]);
            j++;
        }
        cout << "Aqui en pushback" <<endl;
        prox_generacion.push_back(posibles_hijos[j]);
        cout << "Aqui en pushback no llega?" <<endl;

    }
        cout << "Aqui" <<endl;

    this->evolucion_individuos=prox_generacion;

}