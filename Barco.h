//
// Created by patri on 29/04/2021.
//
#include <string>
#ifndef CODIGO_BARCO_H
#define CODIGO_BARCO_H
#include "Posicion.h"

class Barco {
public:
    Barco() {}
    void setPos(Posicion pos, int a);
private:
    Posicion posBarco[4];
    char tipo;//Crucero, submarino, etc
    char estado;//averiado, hundido, agua
};


#endif //CODIGO_BARCO_H
