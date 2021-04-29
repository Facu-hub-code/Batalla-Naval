//
// Created by Facundo Lorenzo on 29/04/2021.
//
#include <iostream>
#include "Tablero.h"

/*
 * Inicializo el tablero vacio.
 */
Tablero::Tablero() {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            casilleros[i][j] = Posicion();
            disparosAnotados[i][j] = false;
        }
    }
}