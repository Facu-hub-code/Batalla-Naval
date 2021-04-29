//
// Created by patri on 29/04/2021.
//

#ifndef CODIGO_PILADEPOS_H
#define CODIGO_PILADEPOS_H
#include "Posicion.h"

class PilaDePos {
private:
    Posicion* siguiente;
    Posicion alrederores[4];
public:
    PilaDePos(){

    }
};


#endif //CODIGO_PILADEPOS_H
