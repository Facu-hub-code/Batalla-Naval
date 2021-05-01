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
Barco barcos[9]; //se ejecuta el constructor por defecto de cada barco.
bool juegoFinalizado = false;
int const cantidadDeDisparos = 20;
int const cantidadDeBarcos = 10;

//Prototipos
void inicializarPorConsola();
void inicializarPorDefecto();
void disparar();

//METODO PRINCIPAL
int main() {
    //inicializarPorConsola();
    inicializarPorDefecto();
    for (int i = 0; i < cantidadDeBarcos; ++i) {
        barcos[i].printDeEstado();
    }
    //disparar();
    return 0;
}

/*
 * Este metodo inicializa los barcos por defecto en posiciones predefinidas.
 */
void inicializarPorDefecto(){
    //Canoneros
    // c0:pc00[1,1]  pc01[1,2]
    Posicion posc00 = Posicion(1, 1, true);
    Barco barcoc0 = Barco(posc00, 'c');
    Posicion posc01 = Posicion(1, 2,true);
    barcoc0.setPos(posc01, 1);
    //c1:pc02[3,8]  pc03[4,8]
    Posicion posc02 = Posicion(3, 8,true);
    Barco barcoc1 = Barco(posc02, 'c');
    Posicion posc03 = Posicion(4,8,true);
    barcoc1.setPos(posc03, 1);
    //Submarinos
    //S1:[1,10]
    Posicion posS1 = Posicion(1,10,true);
    Barco barcoS1 = Barco(posS1, 'S');
    //S2:[10,10]
    Posicion posS2 = Posicion(10,10,true);
    Barco barcoS2 = Barco(posS2, 'S');
    // S3:[10,1]
    Posicion posS3 = Posicion(10,1,true);
    Barco barcoS3 = Barco(posS3, 'S');
    //Destructor
    // [4,3], [4,4],[4,5],[4,6]
    Posicion posD0 = Posicion(4,3,true);
    Barco barcoD0 = Barco(posD0, 'D');
    Posicion posD1 = Posicion(4,4,true);
    barcoD0.setPos(posD1, 1);
    Posicion posD2 = Posicion(4,5,true);
    barcoD0.setPos(posD2, 2);
    Posicion posD3 = Posicion(4,6,true);
    barcoD0.setPos(posD3, 3);
    //Cruceros
    //C1:[6,3],[7,3],[8,3]
    Posicion posC1 = Posicion(6,3,true);
    Barco barcoC1 = Barco(posC1, 'C');
    Posicion posC2 = Posicion(7,3,true);
    barcoC1.setPos(posC2, 1);
    Posicion posC3 = Posicion(8,3,true);
    barcoC1.setPos(posC3, 2);
    //C2:[7,9],[8,9],[9,9]
    Posicion posC01 = Posicion(7,9,true);
    Barco barcoC2 = Barco(posC01, 'C');
    Posicion posC02 = Posicion(8,9,true);
    barcoC2.setPos(posC02, 1);
    Posicion posC03 = Posicion(9,9,true);
    barcoC2.setPos(posC03, 2);

}

/*
 * Este metodo inicializa 10 Barcos pidiendo por consola una POSICION de referencia, una DIRECCION y un TIPO de barco.
 * El algoritmo completa 4 lugares segun sea el tipo (ej el Destructor ocupa 4, y el submarino solo 1).
 * Dichas posiciones se completan segun se indique la direccion (ej char Direccion = U -> significa UP:Arriba).
 * Ej: si ingreso {[4 ; 4] ; U ; D} obtendre ocupadas las posiciones: [4,4] [4,5] [4,6] [4,7] por un DESTRUCTOR.
 */
void inicializarPorConsola() {
    for (int i = 0; i < cantidadDeBarcos; ++i) {
        cout<<"Barco ["<<i<<"]"<<endl;
        //Obetenemos la posicion inicial de referencia.
        cout<<"Ingrese la coordenada de referencia inicial [X ; Y]"<<endl;
        int x,y;
        cin>>x>>y;
        Posicion posAux = Posicion(x,y,true);
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
 * Este metodo apunta a una posicion de la cola de posiciones para realizar un disparo.
 * Dependiendo de la respuesta del usuario calcula el siguiente disparo.
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
            if(estado == 'v'){
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
