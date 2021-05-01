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

void Posicion::printPosicion() {
    cout<<"[X = "<<getX()<<" ; "<<getY()<<" ]"<<endl;
}
