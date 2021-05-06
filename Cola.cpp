//
// Created by patri on 29/04/2021.
//

#include "Cola.h"
#include <iostream>
#include "Posicion.h"

Posicion *getFinal();

using namespace std;

//Constructor de la Cola.
Cola::Cola(Posicion* pos) {
    primero = pos;

}
void Cola::AgregarPosicion(Posicion* a){
    a->set_next(final);
    final = a;

}
Posicion *Cola::getPrimero() const {
    return primero;
}
bool Cola::esvacia(){
    return primero->es_vacio();
}

Posicion *Cola::getFinal() const{
    return final;
}