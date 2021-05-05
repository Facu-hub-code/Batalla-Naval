//
// Created by patri on 29/04/2021.
//

#include "Posicion.h"
#include <iostream>
using namespace std;

Posicion::Posicion(int pos_x, int pos_y, bool ocupado) {
    setXY(pos_x, pos_y);
    setOcupado(ocupado);
}

Posicion::Posicion() {
    setXY(0,0);
    setOcupado(false);
}

string Posicion::printPosicion() {
    string cadena="";
    cadena.append("[ ");cadena.append(to_string(getX()));cadena.append(" ; "); cadena.append(to_string(getY()));cadena.append(" ]");

    return  cadena;
}
