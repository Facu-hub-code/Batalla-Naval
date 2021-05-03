//
// Created by Facundo Lorenzo on 29/04/2021.
//
#include <iostream>
#include "Tablero.h"
#include <iostream>
using namespace std;

/*
 * Inicializo el tablero sin disparos (todo en false)
 */
Tablero::Tablero() {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            disparosAnotados[i][j] = false;
        }
    }
}

void Tablero::setDisparo(int fila, int columna) {
    disparosAnotados[fila][columna] = true;
}

void Tablero::printDisparos() {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if(disparosAnotados[i][j]){
                cout<<"\tX\t";
            }else{
                cout<<"\tO\t";
            }
        }
        cout<<endl;
        cout<<endl;
    }
}