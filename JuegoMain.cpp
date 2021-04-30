/*
 * El juego de la batalla naval consiste en un tablero de 10 x 10 casilleros donde uno dispone barcos y que el
 * contrincante debe “hundirlo” indicando las posiciones (fila,columna) donde lanza “bombas”.
 */
#include <iostream>
#include "Tablero.h"
#import "Barco.h"
#import "Cola.h"
using namespace std;

//Variables globales.
Tablero tablero = Tablero();
Barco barcos[10];
bool juegoFinalizado = false;

//Prototipos
void ini();
void inicializar();
void disparar();

//METODO PRINCIPAL
int main() {
    inicializar();
    for (int i = 0; i < 2; ++i) {
        barcos[i].printDeEstado();
    }
    //disparar();
    return 0;
}

/*
 * Este metodo inicializa 10 Barcos pidiendo por consola una POSICION de referencia, una DIRECCION y un TIPO de barco.
 * El algoritmo completa 4 lugares segun sea el tipo (ej el Destructor ocupa 4, y el submarino solo 1).
 * Dichas posiciones se completan segun se indique la direccion (ej char Direccion = U -> significa UP:Arriba).
 * Ej: si ingreso {[4 ; 4] ; U ; D} obtendre ocupadas las posiciones: [4,4] [4,5] [4,6] [4,7] por un DESTRUCTOR.
 */
void ini(){
    for (int i = 0; i < 2; ++i) {
        cout<<"Barco ["<<i<<"]"<<endl;

        //Obetenemos la posicion inicial de referencia.
        cout<<"Ingrese la coordenada de referencia inicial [X ; Y]\n (Ingrese X -> ENTER -> Y -> ENTER)"<<endl;
        int x,y;
        cin>>x>>y;
        Posicion posAux = Posicion(x,y);

        cout<<"Ingrese una direccion (para completar el barco). Pueden ser: [Up:U, Down:D, Left:L, Right:R]"<<endl;
        cout<<"Ingrese el tipo de Barco: [C:Crucero, D:Destructor, S:Submarino, c:Canonero]"<<endl;
        char direc;
        cin>>direc;
        char tipo;
        cin>>tipo;
        barcos[i] = Barco(posAux, tipo);

        //Decodificar tipo y Direccion.
            if(tipo == 'D') {
                switch (direc) {
                    case 'U':
                        for (int j = 0; j < 3; ++j) {
                            posAux.setY(posAux.getY() + 1);
                            barcos[i].setPos(posAux, i + 1);
                        }
                        break;
                    case 'D':
                        for (int j = 0; j < 3; ++j) {
                            posAux.setY(posAux.getY() - 1);
                            barcos[i].setPos(posAux, i + 1);
                        }
                        break;
                    case 'L':
                        for (int j = 0; j < 3; ++j) {
                            posAux.setX(posAux.getX() - 1);
                            barcos[i].setPos(posAux, i + 1);
                        }
                        break;
                    case 'R':
                        for (int j = 0; j < 3; ++j) {
                            posAux.setX(posAux.getX() + 1);
                            barcos[i].setPos(posAux, i + 1);
                        }
                        break;
                    default:
                        cout << "Se ingreso una direccion invalida." << endl;
                        break;
                }
            }else if(tipo == 'C') {
                switch (direc) {
                    case 'U':
                        for (int j = 0; j < 2; ++j) {
                            posAux.setY(posAux.getY() + 1);
                            barcos[i].setPos(posAux, i + 1);
                        }
                        break;
                    case 'D':
                        for (int j = 0; j < 2; ++j) {
                            posAux.setY(posAux.getY() - 1);
                            barcos[i].setPos(posAux, i + 1);
                        }
                        break;
                    case 'L':
                        for (int j = 0; j < 2; ++j) {
                            posAux.setX(posAux.getX() - 1);
                            barcos[i].setPos(posAux, i + 1);
                        }
                        break;
                    case 'R':
                        for (int j = 0; j < 2; ++j) {
                            posAux.setX(posAux.getX() + 1);
                            barcos[i].setPos(posAux, i + 1);
                        }
                        break;
                    default:
                        cout << "Se ingreso una direccion invalida." << endl;
                        break;
                }
            }else if(tipo == 'c') {
                switch (direc) {
                    case 'U':
                        for (int j = 0; j < 1; ++j) {
                            posAux.setY(posAux.getY()+1);
                            barcos[i].setPos(posAux, i+1);
                        }
                        break;
                    case 'D':
                        for (int j = 0; j < 1; ++j) {
                            posAux.setY(posAux.getY() - 1);
                            barcos[i].setPos(posAux, i + 1);
                        }
                        break;
                    case 'L':
                        for (int j = 0; j < 1; ++j) {
                            posAux.setX(posAux.getX() - 1);
                            barcos[i].setPos(posAux, i + 1);
                        }
                        break;
                    case 'R':
                        for (int j = 0; j < 1; ++j) {
                            posAux.setX(posAux.getX() + 1);
                            barcos[i].setPos(posAux, i + 1);
                        }
                        break;
                    default:
                        cout<<"Se ingreso una direccion invalida."<<endl;
                        break;
                }
        }else if (tipo == 'S'){break;}
            else{cout<<"Se ingreso un tipo invalido"<<endl;}
    }
}
void inicializar() {
    for (int i = 0; i < 2; ++i) {
        cout<<"Barco ["<<i<<"]"<<endl;

        //Obetenemos la posicion inicial de referencia.
        cout<<"Ingrese la coordenada de referencia inicial [X ; Y]\n (Ingrese X -> ENTER -> Y -> ENTER)"<<endl;
        int x,y;
        cin>>x>>y;
        Posicion posAux = Posicion(x,y);

        cout<<"Ingrese una direccion (para completar el barco)\n Pueden ser: [Up:U, Down:D, Left:L, Right:R]"<<endl;
        char direc;
        cin>>direc;

        cout<<"Ingrese el tipo de Barco: [C:Crucero, D:Destructor, S:Submarino, c:Canonero]"<<endl;
        char tipo;
        cin>>tipo;

        barcos[i] = Barco(posAux, tipo);

        //Decodificar tipo y Direccion.
        switch (tipo) {
            case 'D':
                switch (direc) {
                    case 'U':
                        for (int j = 0; j < 3; ++j) {
                            posAux.setY(posAux.getY()+1);
                            barcos[i].setPos(posAux, i+1);
                        }
                        break;
                    case 'D':
                        for (int j = 0; j < 3; ++j) {
                            posAux.setY(posAux.getY() - 1);
                            barcos[i].setPos(posAux, i + 1);
                        }
                        break;
                    case 'L':
                        for (int j = 0; j < 3; ++j) {
                            posAux.setX(posAux.getX() - 1);
                            barcos[i].setPos(posAux, i + 1);
                        }
                        break;
                    case 'R':
                        for (int j = 0; j < 3; ++j) {
                            posAux.setX(posAux.getX() + 1);
                            barcos[i].setPos(posAux, i + 1);
                        }
                        break;
                    default:
                        cout<<"Se ingreso una direccion invalida."<<endl;
                        break;
                }

            case 'C':
                switch (direc) {
                    case 'U':
                        for (int j = 0; j < 2; ++j) {
                            posAux.setY(posAux.getY()+1);
                            barcos[i].setPos(posAux, i+1);
                        }
                        break;
                    case 'D':
                        for (int j = 0; j < 2; ++j) {
                            posAux.setY(posAux.getY() - 1);
                            barcos[i].setPos(posAux, i + 1);
                        }
                        break;
                    case 'L':
                        for (int j = 0; j < 2; ++j) {
                            posAux.setX(posAux.getX() - 1);
                            barcos[i].setPos(posAux, i + 1);
                        }
                        break;
                    case 'R':
                        for (int j = 0; j < 2; ++j) {
                            posAux.setX(posAux.getX() + 1);
                            barcos[i].setPos(posAux, i + 1);
                        }
                        break;
                    default:
                        cout<<"Se ingreso una direccion invalida."<<endl;
                        break;
                }
            case 'c':
                switch (direc) {
                    case 'U':
                        for (int j = 0; j < 1; ++j) {
                            posAux.setY(posAux.getY()+1);
                            barcos[i].setPos(posAux, i+1);
                        }
                        break;
                    case 'D':
                        for (int j = 0; j < 1; ++j) {
                            posAux.setY(posAux.getY() - 1);
                            barcos[i].setPos(posAux, i + 1);
                        }
                        break;
                    case 'L':
                        for (int j = 0; j < 1; ++j) {
                            posAux.setX(posAux.getX() - 1);
                            barcos[i].setPos(posAux, i + 1);
                        }
                        break;
                    case 'R':
                        for (int j = 0; j < 1; ++j) {
                            posAux.setX(posAux.getX() + 1);
                            barcos[i].setPos(posAux, i + 1);
                        }
                        break;
                    default:
                        cout<<"Se ingreso una direccion invalida."<<endl;
                        break;
                }
            default:
                cout<<"Se ingreso un tipo invalido."<<endl;
                break;
        break;
        }
    }
}
void disparar(){

}
//TODO: para sumar puntos revisar los overflow del tablero.