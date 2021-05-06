//
// Created by patri on 29/04/2021.
//
#include <string>
#ifndef CODIGO_BARCO_H
#define CODIGO_BARCO_H
#include "Posicion.h"

class Barco {
public:
    Barco();
    Barco(Posicion posInicial, char tipo);
    Posicion getPosicion(int );
    char getTipo() const;

    void setPos(Posicion pos, int a);
    void setTipo(char tipo);


    void printDePos();
private:
    Posicion posBarco[4];
    char tipo; //[Destructor, Submarino, Canonero, Crucero]
};

#endif //CODIGO_BARCO_H
