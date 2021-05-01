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

    Barco(Posicion posBarco[4]);
    Barco(Posicion posInicial, char tipo);
    Posicion getPosicion(int );
    char getTipo() const;
    char getEstado() const;

    void setPos(Posicion pos, int a);
    void setTipo(char tipo);
    void setEstado(char estado);

    void printDeEstado();
private:
    Posicion posBarco[4];
    char tipo; //[Destructor, Submarino, Canonero, Crucero]
    char estado;//[Averiado: a, Intacto: i, Hundido: h]
};

#endif //CODIGO_BARCO_H
