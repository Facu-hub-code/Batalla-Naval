//
// Created by Facundo Lorenzo on 01/05/2021.
//

#include "Pila.h"
#include "Posicion.h"
void Pila::add(int posX, int posY, bool ocupado){
    Posicion* nuevo = new Posicion(posX, posY, ocupado);
    nuevo->set_next(comienzo);
    comienzo = nuevo;
}

void Pila::borrar(){ //borra el nodo cabeza
    if (!this->esvacia()) {
        Posicion* tmp = comienzo;
        comienzo = comienzo->get_next();
        delete tmp;
    }
}

bool Pila::esvacia(){
    return comienzo->es_vacio();
}

Posicion *Pila::getComienzo() const {
    return comienzo;
}

void Pila::setComienzo(Posicion* comien){
    comienzo = comien;
}