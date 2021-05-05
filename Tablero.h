//
// Created by Facundo Lorenzo on 29/04/2021.
//
#import "Posicion.h"
#ifndef CODIGO_TABLERO_H
#define CODIGO_TABLERO_H

class Tablero {
public:
    Tablero();//Constructor por defecto
    void setDisparo(int, int);
    void printDisparos();
    bool disparosAnotados[10][10];
};
#endif //CODIGO_TABLERO_H
