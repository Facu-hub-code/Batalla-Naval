//
// Created by patri on 29/04/2021.
//
#include <iostream>
#ifndef CODIGO_COLADEPILAS_H
#define CODIGO_COLADEPILAS_H
#include "Pila.h"

class Cola {
public:
    Cola(){}
    void AgregarPila(int posX, int posY);
    void RetirarPila();
    void leerLista();
private:
    Pila* primero = NULL;
    Pila* final= NULL;

};


#endif //CODIGO_COLADEPILAS_H
