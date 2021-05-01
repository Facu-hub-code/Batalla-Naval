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
int const cantidadDeDisparos = 20;

//Prototipos
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

void inicializar() {
    for (int i = 0; i < 2; ++i) {
        cout<<"Barco ["<<i<<"]"<<endl;
        //Obetenemos la posicion inicial de referencia.
        cout<<"Ingrese la coordenada de referencia inicial [X ; Y]"<<endl;
        int x,y;
        cin>>x>>y;
        Posicion posAux = Posicion(x,y);
        cout<<"Ingrese una direccion (para completar el barco)\n Pueden ser: [Up:U, Down:D, Left:L, Right:R]"<<endl;
        char direc;
        cin>>direc;

        cout<<"Ingrese el tipo de Barco: [C:Crucero, D:Destructor, S:Submarino, c:Canonero]"<<endl;
        char tipo;
        cin>>tipo;
        Barco barAux(posAux, tipo);
        barcos[i] = barAux;

        //Decodificar tipo y Direccion.
        switch(tipo) {
            case 'D': //DESTRUCTOR
                switch (direc) {
                    case 'U'://UP
                        for (int j = 0; j < 3; ++j) {
                            posAux.setY(posAux.getY() + 1);
                            barcos[i].setPos(posAux, j + 1);
                        }
                        break;
                    case 'D'://DOWN
                        for (int j = 0; j < 3; ++j) {
                            posAux.setY(posAux.getY() - 1);
                            barcos[i].setPos(posAux, j + 1);
                        }
                        break;
                    case 'L'://LEFT
                        for (int j = 0; j < 3; ++j) {
                            posAux.setX(posAux.getX() - 1);
                            barcos[i].setPos(posAux, j + 1);
                        }
                        break;
                    case 'R'://RIGHT
                        for (int j = 0; j < 3; ++j) {
                            posAux.setX(posAux.getX() + 1);
                            barcos[i].setPos(posAux, j + 1);
                        }
                        break;
                }
                break;
            case 'C'://CRUCERO
                switch (direc) {
                    case 'U'://UP
                        for (int j = 0; j < 2; ++j) {
                            posAux.setY(posAux.getY() + 1);
                            barcos[i].setPos(posAux, j + 1);
                        }
                        break;
                    case 'D'://DOWN
                        for (int j = 0; j < 2; ++j) {
                            posAux.setY(posAux.getY() - 1);
                            barcos[i].setPos(posAux, j + 1);
                        }
                        break;
                    case 'L'://LEFT
                        for (int j = 0; j < 2; ++j) {
                            posAux.setX(posAux.getX() - 1);
                            barcos[i].setPos(posAux, j + 1);
                        }
                        break;
                    case 'R'://RIGHT
                        for (int j = 0; j < 2; ++j) {
                            posAux.setX(posAux.getX() + 1);
                            barcos[i].setPos(posAux, j + 1);
                        }
                        break;
                }
                break;
            case 'c':
                switch (direc) {
                    case 'U': //UP
                        for (int j = 0; j < 1; ++j) {
                            posAux.setY(posAux.getY() + 1);
                            barcos[i].setPos(posAux, j + 1);
                        }
                        break;
                    case 'D'://DOWN
                        for (int j = 0; j < 1; ++j) {
                            posAux.setY(posAux.getY() - 1);
                            barcos[i].setPos(posAux, j + 1);
                        }
                        break;
                    case 'L'://LEFT
                        for (int j = 0; j < 1; ++j) {
                            posAux.setX(posAux.getX() - 1);
                            barcos[i].setPos(posAux, j + 1);
                        }
                        break;
                    case 'R': //RIGHT
                        for (int j = 0; j < 1; ++j) {
                            posAux.setX(posAux.getX() + 1);
                            barcos[i].setPos(posAux, j + 1);
                        }
                        break;
                }
            break;
        }
    }
}
/*
 * Toma una posicion de la cola de posiciones.
 * La analiza y ve si sigue ahi cerca o se va a otra.
 */
void disparar(){
    int contador=0;
        while(!juegoFinalizado){
            int ranX = 1 + rand() % (10-1+1);
            int ranY = 1 + rand() % (10-1+1);
            Posicion posAux = Posicion();
            posAux.siguiente->setXY(ranX, ranY);
            Cola* colaPosiciones = new Cola(posAux.siguiente);

            //TODO: anotar los disparos en el tablero.
            cout<<"Disparo a la posicion: ["<<ranX<<" ; "<<ranY<<" ]"<<endl;
            cout<<"Fue un acierto? [Agua:a, Averiado:v, Hundido:h]"<<endl;
            char estado;
            cin>>estado;
            if(estado='v'){
                cout<<"Donde quiere hacer el proximo disparo: [U,D,L,R]"<<endl;
                char segundo;
                cin>>segundo;
                switch (segundo) {
                    case 'U':
                        posAux.siguiente->setXY(ranX, ranY+1);
                        //Cola* colaPosiciones = new Cola(posAux.siguiente);
                        break;
                    case 'D':
                        posAux.siguiente->setXY(ranX, ranY-1);
                        break;
                    case 'L':
                        posAux.siguiente->setXY(ranX-1, ranY);
                        break;
                    case 'R':
                        posAux.siguiente->setXY(ranX+1, ranY);
                        break;
                }
                for (int i = 0; i < 10; ++i) {
                    //reviso si le pegue a algun barco.
                    bool flag = false;
                    for (int j = 0; j < 4; ++j) {
                        //if(barcos[i].getPosicion(j) == posAux){}
                    }
                }
            }else if(estado == 'a'){
                cout<<"Se intentara otro disparo..."<<endl;
            }
            //Si no fue un acierto, cuento el disparo en el contado y vuelvo a ingresar al while.
            contador++;
            if(contador == 20){
                juegoFinalizado = true;
            }
        }
        cout<<"GAME OVER"<<endl;
}