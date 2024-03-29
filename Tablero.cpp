//
// Created by Facundo Lorenzo on 29/04/2021.
//
#include <iostream>
#include "Tablero.h"
using namespace std;

/*
 * Inicializo el tablero sin disparos
 */
Tablero::Tablero() {
    for (int fila = 0; fila < 10; ++fila) {
        for (int columna = 0; columna < 10; ++columna) {
            disparosAnotados[fila][columna] = false;
        }
    }
}

void Tablero::setDisparo(int fila, int columna) {
    disparosAnotados[fila][columna] = true;
}

bool Tablero::getDisparo(int fila, int columna) {
    bool disparo = disparosAnotados[fila][columna];
    return disparo;
}

void Tablero::printDisparos() {
    for (int i = 0; i < 11; ++i) {
        for (int j = 0; j < 11; ++j) {
            if(getDisparo(j,i)){
                cout<<"\tX";
            }else{
                cout<<"\tO";
            }
        }
        cout<<endl;
        cout<<endl;
    }
}


