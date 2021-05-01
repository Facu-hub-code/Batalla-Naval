//
// Created by patri on 29/04/2021.
//

#ifndef CODIGO_POSICION_H
#define CODIGO_POSICION_H
#include <iostream>

class Posicion {

private:
    int x,y;
    bool ocupado;
public:
    //Constructores
    Posicion(int , int , bool);
    Posicion();

    bool es_vacio() { return siguiente == NULL; }

    //Puntero
    Posicion* siguiente = NULL;
    void set_next(Posicion* n) { siguiente = n; };
    Posicion* get_next() { return siguiente; };

    //Getters
    int getX() const {return x;}
    int getY() const {return y;}
    bool getOcupado() const {return ocupado;}

    //Setters
    void setX(int cx) {x=cx;}
    void setY(int cy) {y=cy;}
    void setXY(int cx, int cy) {x = cx;y = cy;}
    void setOcupado(bool o) {ocupado=o;}

    //Print
    void printPosicion();
};
#endif //CODIGO_POSICION_H
