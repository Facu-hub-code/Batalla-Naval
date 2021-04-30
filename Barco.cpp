//
// Created by patri on 29/04/2021.
//

#include "Barco.h"

void Barco::setPos(Posicion pos, int a){
     posBarco[a]=pos;
}

const Posicion *Barco::getPosBarco() const {
    return posBarco;
}

char Barco::getTipo() const {
    return tipo;
}

char Barco::getEstado() const {
    return estado;
}

void Barco::setTipo(char tipo) {
    Barco::tipo = tipo;
}

void Barco::setEstado(char estado) {
    Barco::estado = estado;
}
