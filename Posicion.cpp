//
// Created by patri on 29/04/2021.
//

#include "Posicion.h"
#include <iostream>
using namespace std;

Posicion::Posicion(int pos_x, int pos_y) {
    setXY(pos_x, pos_y);
    setOcupado(true);
}

Posicion::Posicion() {
    setXY(0,0);
    setOcupado(true);
}

void Posicion::printPosicion() {
    cout<<"[X = "<<getX()<<" ; "<<getY()<<" ]"<<endl;
}
