//
// Created by patri on 29/04/2021.
//
#include <iostream>
#ifndef CODIGO_COLADEPILAS_H
#define CODIGO_COLADEPILAS_H
#include "Posicion.h"
class Cola {
private:
    Posicion* primero ;
    Posicion* final;
public:
    Cola();
    Cola(Posicion*);
    void AgregarPosicion(Posicion*);
    void leerLista();
    bool esvacia();
    Posicion *getPrimero() const;
    Posicion *getFinal() const;

};





#endif //CODIGO_COLADEPILAS_H
