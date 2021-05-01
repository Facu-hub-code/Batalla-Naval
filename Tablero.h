//
// Created by Facundo Lorenzo on 29/04/2021.
//
#import "Posicion.h"
#ifndef CODIGO_TABLERO_H
#define CODIGO_TABLERO_H

class Tablero {
public:
    Tablero();//constructor por defecto
    void printDisparos();
private:
    bool disparosAnotados[10][10];
};
#endif //CODIGO_TABLERO_H
