//
// Created by patri on 29/04/2021.
//
#include <iostream>
#ifndef CODIGO_COLADEPILAS_H
#define CODIGO_COLADEPILAS_H
#include "PilaDePos.h"

class ColaDePilas {
public:
    ColaDePilas(){}
    void AgregarPila(int posX, int posY);
    void RetirarPila();
    void leerLista();
private:
    PilaDePos* primero = NULL;
    PilaDePos* siguiente= NULL;

};


#endif //CODIGO_COLADEPILAS_H
