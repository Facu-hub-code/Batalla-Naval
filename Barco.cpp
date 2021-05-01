//
// Created by patri on 29/04/2021.
//

#include "Barco.h"
#include <iostream>
using namespace std;

/*
 * Constructor con parametros de barco
 * @param: posInicial,t con la posicion inicial de referencia y el tipo de barco ya podemos construirlo.
*/
Barco::Barco(Posicion posInicial, char t) {
    posBarco[0] = posInicial;
    estado = 'i';
    tipo = t;
}

Barco::Barco() {
    posBarco[0] =  Posicion(0,0);
    estado = 'i';
}

//Retorna la posicion indicada en el indice (los barcos tienen 4 posiciones).
Posicion Barco::getPosicion(int indice) {
    return posBarco[indice];
}

char Barco::getTipo() const {
    return tipo;
}

char Barco::getEstado() const {
    return estado;
}

void Barco::setPos(Posicion pos, int a){
    posBarco[a]=pos;
}

void Barco::setTipo(char tipo) {
    Barco::tipo = tipo;
}

void Barco::setEstado(char estado) {
    Barco::estado = estado;
}

void Barco::printDeEstado() {
    //Recupero el tipo del barco.
    char tipoC = getTipo();
    string tipoS;
    switch (tipoC) {
        case 'D':
            tipoS = "Destructor";
            break;
        case 'C':
            tipoS = "Crucero";
            break;
        case 'c':
            tipoS = "Canonero";
            break;
        case 'S':
            tipoS = "Submarino";
            break;
    }
    //Recupero el estado del barco.
    char estadoC = getEstado();
    string estadoS;
    switch (estadoC) {
        case 'a':
            estadoS = "Averiado";
            break;
        case 'h':
            estadoS = "Hundido";
            break;
        case 'i':
            estadoS = "Intacto";
            break;
    }
    cout<<"El Barco "<<tipoS<<" se encuentra "<<estadoS<<" en las posiciones:"<<endl;
    for (int i = 0; i < 4; ++i) {
        Posicion aux = getPosicion(i);
        if(aux.getOcupado()) {
            aux.printPosicion();
        }
    }
}