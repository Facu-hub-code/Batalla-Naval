//
// Created by patri on 29/04/2021.
//

#include "Barco.h"
#include <iostream>
using namespace std;


Barco::Barco() {
    posBarco[0] =  Posicion();
    estado = 'i';
}

/*
 * Constructor con parametros de barco
 * @param: posInicial,t con la posicion inicial de referencia y el tipo de barco ya podemos construirlo.
*/
Barco::Barco(Posicion posInicial, char t) {
    posBarco[0] = posInicial;
    estado = 'i';
    tipo = t;
}

//Retorna la posicion indicada en el indice (los barcos tienen 4 posiciones).
Posicion Barco::getPosicion(int indice) {
    return posBarco[indice];
}

char Barco::getTipo() const {
    return tipo;
}

void Barco::setPos(Posicion pos, int a){
    posBarco[a]=pos;
}

void Barco::setTipo(char t) {
    tipo = t;
}

void Barco::printDePos() {
    //Recupero el tipo del barco.
    char tipoC = getTipo();
    switch (tipoC) {
        case 'D':
            cout<<"El destructor se encuentra hundido en: ";

            break;
        case 'C':
            cout<<"El crucero se encuentra hundido en: ";

            break;
        case 'c':
            cout<<"El canonero se encuentra hundido en: ";

            break;
        case 'S':
            cout<<"El submarino se encuentra hundido en: ";

            break;
    }
    for (int i = 0; i < 4; ++i) {
        Posicion aux = getPosicion(i);
        if(aux.getOcupado()) {
            cout<<aux.printPosicion()<<" ; ";


        }
    }
    cout<<endl;
}
