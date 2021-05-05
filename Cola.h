//
// Created by patri on 29/04/2021.
//
#include <iostream>
#ifndef CODIGO_COLADEPILAS_H
#define CODIGO_COLADEPILAS_H
#include "Posicion.h"
class Cola {
public:
    Cola();
    Cola(Posicion*);
    void AgregarPosicion(int posX, int posY);
    void leerLista();
private:
    Posicion* primero = NULL;
    Posicion* final= NULL;
};

#endif //CODIGO_COLADEPILAS_H
