//
// Created by patri on 29/04/2021.
//

#ifndef CODIGO_POSICION_H
#define CODIGO_POSICION_H


class Posicion {

private:
    int x;
    int y;
    bool ocupado;
public:
    Posicion(){}
    int getX() const {return x;}
    int getY() const {return y;}
    bool isOcupado() const {return ocupado;}
    void setX(int x) {Posicion::x = x;}
    void setY(int y) {Posicion::y = y;}
    void setOcupado(bool ocupado) {Posicion::ocupado = ocupado;}
};


#endif //CODIGO_POSICION_H
