//
// Created by Facundo Lorenzo on 01/05/2021.
//

#ifndef CODIGO_PILA_H
#define CODIGO_PILA_H
#include "Posicion.h"


class Pila {
private:
    Posicion* comienzo;
public:
    Pila() { comienzo = new Posicion(); };
    Pila(Posicion* n) { comienzo= n; };
    void apilar(int, int, bool ); //sumar nodos a la lista
    void borrar();
    bool esvacia();
    void setComienzo(Posicion*);
    Posicion *getComienzo() const;

};


#endif //CODIGO_PILA_H
