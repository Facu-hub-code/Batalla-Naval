/*
 * El juego de la batalla naval consiste en un tablero de 10 x 10 casilleros donde uno dispone barcos y que el
 * contrincante debe “hundirlo” indicando las posiciones (fila,columna) donde lanza “bombas”.
 */
#include <iostream>
#include "Tablero.h"
#import "Barco.h"
#import "Cola.h"
#include "Pila.h"
using namespace std;


char estado;
bool juegoFinalizado = false;
int contadorIntentos=0;
int const cantidadDeBarcos = 10;
int contadorDeBarcosHundidos;


Tablero tablero = Tablero();
Barco barcos[cantidadDeBarcos];
Pila pilaPosiciones;

//Prototipos
void inicializarPorConsola();
void inicializarPorDefecto();
void jugar();
void primerDisparo();
void segundoDisparo();
void terceroDisparo();
void cuartoDisparo();
void revisarPosicionRepetida();


int main() {
    //Guardar los barcos en el juego
    inicializarPorDefecto();
    //inicializarPorConsola();
    //Realizar los disparos y sus siguientes.
    jugar();

    //Print la posicion de los barcos una vez que terminó el juego(todos los barcos hundidos).
    for (int i = 0; i < cantidadDeBarcos; ++i) {
        barcos[i].printDePos();
    }
    cout<<"\nSe termino el juego en "<<contadorIntentos<<" intentos"<<endl;
    return 0;
}

/*
 * Este metodo apunta a una posicion de la cola de posiciones para realizar un disparo.
 * Dependiendo de la respuesta del usuario calcula el siguiente disparo.
 */
void jugar() {
    while (!juegoFinalizado) { //Mientras el juego no este finalizado
        primerDisparo();
    }
    cout << "GAME OVER" << endl;
}

/*
 Revisa que no se dispare dos veces a la misma posicion
 */
bool posicionRepetida(int x, int y){
    if(!tablero.getDisparo(x,y)){
        tablero.setDisparo(x,y);
        return false;
    }else {
        return true;
    }
}

/*
 * Realiza el primer disparo a una posicion Random.
 */
void primerDisparo() {
    if (contadorDeBarcosHundidos >= cantidadDeBarcos) {
        juegoFinalizado = true;
    }
    else
    {

    cout << "Se intentara otro disparo..." << endl;

    //Tomo las coordenadaas.
    int ranX = 1 + rand() % (10 - 1 + 1);
    int ranY = 1 + rand() % (10 - 1 + 1);

    //Reviso que no haya disparado previamente a esa posicion.
    while(posicionRepetida(ranX, ranY) ){
        ranX = 1 + rand() % (10 - 1 + 1);
        ranY = 1 + rand() % (10 - 1 + 1);
    }


    Posicion *posAux = new Posicion(ranX, ranY, false);
    Cola *colaPosiciones = new Cola(posAux);

    //Apilo la primer POS a disparaar
    pilaPosiciones = Pila(posAux);

    //Imprimo
    cout << "Disparo a la posicion: [" << ranX << " ; " << ranY << " ]" << endl;
    contadorIntentos++;
    tablero.setDisparo(ranX, ranY);

    //Pregunto
    cout << "Fue un acierto? [Agua:a, Averiado:v, Hundido:h]" << endl;
    cin >> estado;

    //Evaluo estado
    switch (estado) {
        case 'a':
            cout<<"-.-"<<endl;
            primerDisparo();
            break;

        case 'h':
            cout<<"Submarino hundido"<<endl;
            contadorDeBarcosHundidos++;
            primerDisparo();
            break;
        case 'v':

            pilaPosiciones.add(ranX,ranY+1, false); //Arriba
            pilaPosiciones.add(ranX,ranY-1, false); //Abajo
            pilaPosiciones.add(ranX+1,ranY, false); // Derecha
            pilaPosiciones.add(ranX-1,ranY, false); //TOPE - Comienzo de la PILA - Izquierda
            segundoDisparo();
            break;
    }
  }
}
/*
 * Realiza el segundo disparo, con conocimientos de un primer acierto
 */
void segundoDisparo(){

    //Imprimo
    cout << "Disparo a la posicion: [" <<pilaPosiciones.getComienzo()->getX()<< " ; "<< pilaPosiciones.getComienzo()->getY() << " ]" << endl; //Disparo al TOPE de la Pila Actual.
    contadorIntentos++;
    tablero.setDisparo(pilaPosiciones.getComienzo()->getX(), pilaPosiciones.getComienzo()->getY()); //anoto el disparo en el arreglo de booleanos

    //Pregunto
    cout<<"Ingrese el estado del reciente disparo: [Agua:a, Averiado:v, Hundido:h]:_";
    cin>>estado;

    //Evaluo estado
    switch (estado) {
        case 'a':
            pilaPosiciones.borrar();
            segundoDisparo();
            break;
        case 'h':
            contadorDeBarcosHundidos++;
            cout<<"Cañonero"<<endl;
            primerDisparo();
            break;
        case 'v':
            terceroDisparo();
    }
}

/*
 * Realiza el tercer disparo, con conocimiento del primero y del segundo
 */

void terceroDisparo(){

    //recupero la 2da pos para buscar la direccion [HORIZONTAL VERTICAL] A Apilar.
    int ranX2 = pilaPosiciones.getComienzo()->getX(); //coordenadas del que quedo como tope de la pila (donde se acerto el 2do disparo)
    int ranY2 = pilaPosiciones.getComienzo()->getY();
    int ranX1,ranY1; //coordenadas del primer disparo/disparo base

    //recupero coordenadas del primer disparo
    bool flag= false;
    while(!flag){
        if(pilaPosiciones.getComienzo()->siguiente != NULL){
            pilaPosiciones.setComienzo(pilaPosiciones.getComienzo()->siguiente);
            flag = false;
        }else{
            ranX1 = pilaPosiciones.getComienzo()->getX(); //recupero las coordenadas del ultimo de la pila (disparo base)
            ranY1 = pilaPosiciones.getComienzo()->getY();
            flag = true;
        }
    }

    //Me fijo si esta horizontal
    int direccionX= ranX1 - ranX2; //coord x del disparo base - coord x del 2do disparo

    switch (direccionX) {
        case -1: //Se movio para la Derecha
            pilaPosiciones.add(ranX2+1,ranY2, false); //apilo con la pos movida a la derecha (respecto del 2do disparo) y pasa a ser el tope (apilo tercer disparo)

            //Imprimo el 3er disparo
            cout << "Disparo a la posicion: [" <<pilaPosiciones.getComienzo()->getX()<< " ; "<< pilaPosiciones.getComienzo()->getY() << " ]" << endl; //Disparo al TOPE de la Pila Actual. (3er disparo)
            contadorIntentos++;
            tablero.setDisparo(pilaPosiciones.getComienzo()->getX(), pilaPosiciones.getComienzo()->getY());

            cout<<"Ingrese el estado del reciente disparo: [Agua:a, Averiado:v, Hundido:h]:";
            cin>>estado;

            switch(estado){
                case 'h':
                    contadorDeBarcosHundidos++;
                    cout<<"Crucero Hundido"<<endl;
                    primerDisparo();
                    break;
                case 'a': //CASO ESPECIAL

                    pilaPosiciones.add(pilaPosiciones.getComienzo()->getX()-3, pilaPosiciones.getComienzo()->getY(), false); //Respecto del 3er disparo me muevo 3 lugares a la izquierda
                    cout << "Disparo a la posicion: [" <<pilaPosiciones.getComienzo()->getX()<< " ; "<< pilaPosiciones.getComienzo()->getY() << " ]" << endl; //Disparo al TOPE de la Pila Actual.
                    contadorIntentos++;
                    tablero.setDisparo(pilaPosiciones.getComienzo()->getX(), pilaPosiciones.getComienzo()->getY());
                    contadorDeBarcosHundidos++;
                    cout<<"Ingrese el estado del reciente disparo: [Agua:a, Averiado:v, Hundido:h]:_";
                    cin>>estado;

                    if(estado == 'h'){
                        contadorDeBarcosHundidos++;
                        cout<<"Crucero Hundido"<<endl;primerDisparo();}

                    if(estado == 'v'){
                        pilaPosiciones.add(pilaPosiciones.getComienzo()->getX()-1, pilaPosiciones.getComienzo()->getY(), false);
                        cout << "Disparo a la posicion: [" <<pilaPosiciones.getComienzo()->getX()<< " ; "<< pilaPosiciones.getComienzo()->getY() << " ]" << endl; //Disparo al TOPE de la Pila Actual.
                        tablero.setDisparo(pilaPosiciones.getComienzo()->getX(), pilaPosiciones.getComienzo()->getY());
                        contadorDeBarcosHundidos++;
                        cout<<"Destructor Hundido"<<endl;primerDisparo();
                    }
                    break;
                case 'v':
                    cuartoDisparo();
            }
            break;

        case 1: //Se movio para la Izquierda.
            //Apilo
            pilaPosiciones.add(ranX2-1,ranY2, false); //apilo (el 3er disparo) con la pos movida a la izquierda (respecto del disparo 2)
            //Imprimo el 3er disparo
            cout << "Disparo a la posicion: [" <<pilaPosiciones.getComienzo()->getX()<< " ; "<< pilaPosiciones.getComienzo()->getY() << " ]" << endl; //Disparo al TOPE de la Pila Actual.
            contadorIntentos++;
            tablero.setDisparo(pilaPosiciones.getComienzo()->getX(), pilaPosiciones.getComienzo()->getY());

            cout<<"Ingrese el estado del reciente disparo: [Agua:a, Averiado:v, Hundido:h]:_";
            cin>>estado;

            //Evaluo
            switch(estado){
                case 'h':
                    contadorDeBarcosHundidos++;
                    cout<<"Crucero Hundido"<<endl;
                    primerDisparo();
                    break;
                case 'a':
                    pilaPosiciones.add(pilaPosiciones.getComienzo()->getX()+3, pilaPosiciones.getComienzo()->getY(), false);
                    cout << "Disparo a la posicion: [" <<pilaPosiciones.getComienzo()->getX()<< " ; "<< pilaPosiciones.getComienzo()->getY() << " ]" << endl; //Disparo al TOPE de la Pila Actual.
                    contadorIntentos++;
                    tablero.setDisparo(pilaPosiciones.getComienzo()->getX(), pilaPosiciones.getComienzo()->getY());
                    cout<<"Ingrese el estado del reciente disparo: [Agua:a, Averiado:v, Hundido:h]:_";
                    cin>>estado;

                    if(estado == 'h'){
                        contadorDeBarcosHundidos++;
                        cout<<"Crucero Hundido"<<endl;primerDisparo();}

                    if(estado == 'v'){
                        pilaPosiciones.add(pilaPosiciones.getComienzo()->getX()+1, pilaPosiciones.getComienzo()->getY(), false); // -1?
                        cout << "Disparo a la posicion: [" <<pilaPosiciones.getComienzo()->getX()<< " ; "<< pilaPosiciones.getComienzo()->getY() << " ]" << endl; //Disparo al TOPE de la Pila Actual.
                        contadorIntentos++;
                        tablero.setDisparo(pilaPosiciones.getComienzo()->getX(), pilaPosiciones.getComienzo()->getY());
                        contadorDeBarcosHundidos++;
                        cout<<"Se ha descubirto la posicion del destructor"<<endl;
                        contadorIntentos++;
                        cout<<"Destructor Hundido"<<endl;primerDisparo();
                    }
                    break;
                case 'v':
                    cuartoDisparo();
            }
            break;

        case 0: //Se movio en vertical
            int direccionY = ranY1-ranY2;
            if(direccionY == -1){
                pilaPosiciones.add(ranX2,ranY2+1, false);
                //Imprimo el disparo
                cout << "Disparo a la posicion: [" <<pilaPosiciones.getComienzo()->getX()<< " ; "<< pilaPosiciones.getComienzo()->getY() << " ]" << endl; //Disparo al TOPE de la Pila Actual.
                contadorIntentos++;
                tablero.setDisparo(pilaPosiciones.getComienzo()->getX(), pilaPosiciones.getComienzo()->getY());
                //Pregunto por el 3ro
                cout<<"Ingrese el estado del reciente disparo: [Agua:a, Averiado:v, Hundido:h]:_";
                cin>>estado;

                switch(estado){
                    case 'h':
                        contadorDeBarcosHundidos++;
                        cout<<"Crucero Hundido"<<endl;
                        primerDisparo();
                        break;
                    case 'a':
                        pilaPosiciones.add(pilaPosiciones.getComienzo()->getX(), pilaPosiciones.getComienzo()->getY()-3, false);
                        cout << "Disparo a la posicion: [" <<pilaPosiciones.getComienzo()->getX()<< " ; "<< pilaPosiciones.getComienzo()->getY() << " ]" << endl; //Disparo al TOPE de la Pila Actual.
                        contadorIntentos++;
                        tablero.setDisparo(pilaPosiciones.getComienzo()->getX(), pilaPosiciones.getComienzo()->getY());
                        contadorDeBarcosHundidos++;
                        cout<<"Ingrese el estado del reciente disparo: [Agua:a, Averiado:v, Hundido:h]:_";
                        cin>>estado;
                        if(estado == 'h'){
                            contadorDeBarcosHundidos++;
                            cout<<"Crucero Hundido"<<endl;primerDisparo();}

                        if(estado == 'v'){
                            pilaPosiciones.add(pilaPosiciones.getComienzo()->getX()-1, pilaPosiciones.getComienzo()->getY(), false);
                            cout << "Disparo a la posicion: [" <<pilaPosiciones.getComienzo()->getX()<< " ; "<< pilaPosiciones.getComienzo()->getY() << " ]" << endl; //Disparo al TOPE de la Pila Actual.
                            tablero.setDisparo(pilaPosiciones.getComienzo()->getX(), pilaPosiciones.getComienzo()->getY());
                            contadorDeBarcosHundidos++;
                            contadorIntentos++;
                            cout<<"Se ha descubirto la posicion del destructor"<<endl;
                            cout<<"Destructor Hundido"<<endl;primerDisparo();
                        }
                        break;
                    case 'v':
                        cuartoDisparo();
                        break;
                }
            }
            if(direccionY == 1){
                pilaPosiciones.add(ranX2,ranY2-1, false);
                //Imprimo el 3er disparo
                cout << "Disparo a la posicion: [" <<pilaPosiciones.getComienzo()->getX()<< " ; "<< pilaPosiciones.getComienzo()->getY() << " ]" << endl; //Disparo al TOPE de la Pila Actual.
                contadorIntentos++;
                tablero.setDisparo(pilaPosiciones.getComienzo()->getX(), pilaPosiciones.getComienzo()->getY());
                //Pregunto por el 3ro

                cout<<"Ingrese el estado del reciente disparo: [Agua:a, Averiado:v, Hundido:h]:_";
                cin>>estado;

                switch(estado){
                    case 'h':
                        contadorDeBarcosHundidos++;
                        cout<<"Crucero Hundido"<<endl;
                        primerDisparo();
                        break;
                    case 'a':
                        pilaPosiciones.add(pilaPosiciones.getComienzo()->getX(), pilaPosiciones.getComienzo()->getY()+3, false);
                        cout << "Disparo a la posicion: [" <<pilaPosiciones.getComienzo()->getX()<< " ; "<< pilaPosiciones.getComienzo()->getY() << " ]" << endl; //Disparo al TOPE de la Pila Actual.
                        contadorIntentos++;
                        tablero.setDisparo(pilaPosiciones.getComienzo()->getX(), pilaPosiciones.getComienzo()->getY());
                        cout<<"Ingrese el estado del reciente disparo: [Agua:a, Averiado:v, Hundido:h]:_";
                        cin>>estado;

                        if(estado == 'h'){
                            contadorDeBarcosHundidos++;
                            cout<<"Crucero Hundido"<<endl;primerDisparo();}

                        if(estado == 'v'){
                            pilaPosiciones.add(pilaPosiciones.getComienzo()->getX()+1, pilaPosiciones.getComienzo()->getY(), false);
                            cout << "Disparo a la posicion: [" <<pilaPosiciones.getComienzo()->getX()<< " ; "<< pilaPosiciones.getComienzo()->getY() << " ]" << endl; //Disparo al TOPE de la Pila Actual.
                            contadorIntentos++;
                            tablero.setDisparo(pilaPosiciones.getComienzo()->getX(), pilaPosiciones.getComienzo()->getY());
                            contadorDeBarcosHundidos++;
                            cout<<"Se ha descubirto la posicion del destructor"<<endl;
                            cout<<"Destructor Hundido"<<endl;primerDisparo();
                        }
                        break;
                    case 'v':
                        cuartoDisparo();
                        break;
                }
            }
            break;
    }
}

/*
 * Cuarto disparo
 */
void cuartoDisparo(){
    //recupero la 3ra pos para buscar la direccion [HORIZONTAL VERTICAL] A Apilar.
    int ranX3 = pilaPosiciones.getComienzo()->getX();
    int ranY3 = pilaPosiciones.getComienzo()->getY();
    pilaPosiciones.borrar(); //debajo del comienzo tengo la 2da posicion, si borro queda en el TOPE
    //recupero la 2da posicion.
    int ranX2 = pilaPosiciones.getComienzo()->getX();
    int ranY2 = pilaPosiciones.getComienzo()->getY();

    //Me fijo si esta horizontal
    int direccionX= ranX2 - ranX3;
    switch (direccionX) {
        case -2: //Se movio para la Derecha
            pilaPosiciones.add(ranX3+1,ranY3, false); //apilo con la pos movida a la derecha
            //Imprimo el 4to disparo
            cout << "Disparo a la posicion: [" <<pilaPosiciones.getComienzo()->getX()<< " ; "<< pilaPosiciones.getComienzo()->getY() << " ]" << endl; //Disparo al TOPE de la Pila Actual.
            contadorIntentos++;
            tablero.setDisparo(pilaPosiciones.getComienzo()->getX(), pilaPosiciones.getComienzo()->getY());
            cout<<"Ingrese el estado del reciente disparo: [Agua:a, Averiado:v, Hundido:h]:_";
            cin>>estado;

            switch(estado){
                case 'h':
                    contadorDeBarcosHundidos++;
                    cout<<"Se ha descubirto la posicion del destructor"<<endl;
                    cout<<"Destructor Hundido"<<endl;
                    primerDisparo();
                    break;
                case 'a':
                    pilaPosiciones.add(pilaPosiciones.getComienzo()->getX()-4, pilaPosiciones.getComienzo()->getY(), false);
                    cout << "Disparo a la posicion: [" <<pilaPosiciones.getComienzo()->getX()<< " ; "<< pilaPosiciones.getComienzo()->getY() << " ]" << endl; //Disparo al TOPE de la Pila Actual.
                    contadorIntentos++;
                    tablero.setDisparo(pilaPosiciones.getComienzo()->getX(), pilaPosiciones.getComienzo()->getY());
                    contadorDeBarcosHundidos++;
                    cout<<"Destructor Hundido"<<endl;primerDisparo();
                case 'v':
                    cout<<"Imposible"<<endl;estado = 'h';
                    break;
            }
            break;
        case 2: //Se movio para la Izquierda.
            //Apilo
            pilaPosiciones.add(ranX3-1,ranY3, false); //apilo con la pos movida a la izquierda
            //Imprimo el 4to disparo
            cout << "Disparo a la posicion: [" <<pilaPosiciones.getComienzo()->getX()<< " ; "<< pilaPosiciones.getComienzo()->getY() << " ]" << endl; //Disparo al TOPE de la Pila Actual.
            tablero.setDisparo(pilaPosiciones.getComienzo()->getX(), pilaPosiciones.getComienzo()->getY());

            cout<<"Ingrese el estado del reciente disparo: [Agua:a, Averiado:v, Hundido:h]:_";
            cin>>estado;
            //Evaluo
            switch(estado){
                case 'h':
                    contadorDeBarcosHundidos++;
                    cout<<"Destructor Hundido"<<endl;
                    primerDisparo();
                    break;

                case 'a':
                    pilaPosiciones.add(pilaPosiciones.getComienzo()->getX()+4, pilaPosiciones.getComienzo()->getY(), false);
                    cout << "Disparo a la posicion: [" <<pilaPosiciones.getComienzo()->getX()<< " ; "<< pilaPosiciones.getComienzo()->getY() << " ]" << endl; //Disparo al TOPE de la Pila Actual.
                    contadorIntentos++;
                    tablero.setDisparo(pilaPosiciones.getComienzo()->getX(), pilaPosiciones.getComienzo()->getY());
                    contadorDeBarcosHundidos++;
                    cout<<"Destructor Hundido"<<endl;primerDisparo();
                case 'v':
                    cout<<"Imposible"<<endl;estado = 'h';
                    break;
            }
            break;
        case 0: //Se movio en vertical
            int direccionY = ranY2-ranY3;
            if(direccionY == -2){
                pilaPosiciones.add(ranX3,ranY3+1, false);
                //Imprimo el disparo
                cout << "Disparo a la posicion: [" <<pilaPosiciones.getComienzo()->getX()<< " ; "<< pilaPosiciones.getComienzo()->getY() << " ]" << endl; //Disparo al TOPE de la Pila Actual.
                contadorIntentos++;
                tablero.setDisparo(pilaPosiciones.getComienzo()->getX(), pilaPosiciones.getComienzo()->getY());

                //Pregunto por el 3ro
                cout<<"Ingrese el estado del reciente disparo: [Agua:a, Averiado:v, Hundido:h]:_";
                cin>>estado;

                switch(estado){
                    case 'h':
                        contadorDeBarcosHundidos++;
                        cout<<"Destructor Hundido"<<endl;
                        primerDisparo();
                        break;
                    case 'a':
                        pilaPosiciones.add(pilaPosiciones.getComienzo()->getX(), pilaPosiciones.getComienzo()->getY()-4, false);
                        cout << "Disparo a la posicion: [" <<pilaPosiciones.getComienzo()->getX()<< " ; "<< pilaPosiciones.getComienzo()->getY() << " ]" << endl; //Disparo al TOPE de la Pila Actual.
                        contadorIntentos++;
                        tablero.setDisparo(pilaPosiciones.getComienzo()->getX(), pilaPosiciones.getComienzo()->getY());
                        contadorDeBarcosHundidos++;
                        cout<<"Destructor Hundido"<<endl;primerDisparo();
                        break;
                    case 'v':
                        cout<<"Imposible"<<endl;primerDisparo();
                        break;
                }
            }
            if(direccionY == 2){
                pilaPosiciones.add(ranX3,ranY3-1, false);
                //Imprimo el 4to disparo
                cout << "Disparo a la posicion: [" <<pilaPosiciones.getComienzo()->getX()<< " ; "<< pilaPosiciones.getComienzo()->getY() << " ]" << endl; //Disparo al TOPE de la Pila Actual.
                contadorIntentos++;
                tablero.setDisparo(pilaPosiciones.getComienzo()->getX(), pilaPosiciones.getComienzo()->getY());
                //Pregunto por el 3ro
                cout<<"Ingrese el estado del reciente disparo: [Agua:a, Averiado:v, Hundido:h]:_";
                cin>>estado;

                switch(estado){
                    case 'h':
                        contadorDeBarcosHundidos++;
                        cout<<"Destructor Hundido"<<endl;
                        primerDisparo();
                        break;

                    case 'a':
                        pilaPosiciones.add(pilaPosiciones.getComienzo()->getX(), pilaPosiciones.getComienzo()->getY()+4, false);
                        cout << "Disparo a la posicion: [" <<pilaPosiciones.getComienzo()->getX()<< " ; "<< pilaPosiciones.getComienzo()->getY() << " ]" << endl; //Disparo al TOPE de la Pila Actual.
                        contadorIntentos++;
                        tablero.setDisparo(pilaPosiciones.getComienzo()->getX(), pilaPosiciones.getComienzo()->getY());
                        contadorDeBarcosHundidos++;
                        cout<<"Destructor Hundido"<<endl;primerDisparo();
                        break;
                    case 'v':
                        cout<<"imposible"<<endl;primerDisparo();
                        break;
                }
            }
            break;
    }
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
 * Este metodo inicializa los barcos por defecto en posiciones predefinidas.
 */
void inicializarPorDefecto(){
    //Canoneros
    // c0:pc00[1,1]  pc01[1,2]
    Posicion posc00 = Posicion(1, 1, true);
    Barco barcoc0 = Barco(posc00, 'c');
    Posicion posc01 = Posicion(1, 2,true);
    barcoc0.setPos(posc01, 1);
    barcos[0]=barcoc0;
    //c1:pc02[10,3]  pc03[10,4]
    Posicion posc02 = Posicion(10, 3,true);
    Barco barcoc1 = Barco(posc02, 'c');
    Posicion posc03 = Posicion(10,4,true);
    barcoc1.setPos(posc03, 1);
    barcos[1]=barcoc1;
    //c1:pc04[2,8] pc05[2,7]
    Posicion posc04 = Posicion(2, 7,true);
    Barco barcoc3 = Barco(posc02, 'c');
    Posicion posc05 = Posicion(1,7,true);
    barcoc1.setPos(posc03, 1);
    barcos[2]=barcoc1;

    //Submarinos
    //S1:[1,10]
    Posicion posS1 = Posicion(1,10,true);
    Barco barcoS1 = Barco(posS1, 'S');
    barcos[3]=barcoS1;
    //S2:[10,10]
    Posicion posS2 = Posicion(10,10,true);
    Barco barcoS2 = Barco(posS2, 'S');
    barcos[4]=barcoS2;
    // S3:[10,1]
    Posicion posS3 = Posicion(10,1,true);
    Barco barcoS3 = Barco(posS3, 'S');
    barcos[5]=barcoS3;

    // S4:[6,7]
    Posicion posS4 = Posicion(6,7,true);
    Barco barcoS4 = Barco(posS4, 'S');
    barcos[6]=barcoS4;
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
    barcos[7]=barcoD0;
    //Cruceros
    //C1:[6,3],[7,3],[8,3]
    Posicion posC1 = Posicion(6,3,true);
    Barco barcoC1 = Barco(posC1, 'C');
    Posicion posC2 = Posicion(7,3,true);
    barcoC1.setPos(posC2, 1);
    Posicion posC3 = Posicion(8,3,true);
    barcoC1.setPos(posC3, 2);
    barcos[8]=barcoC1;

    //C2:[7,9],[8,9],[9,9]
    Posicion posC01 = Posicion(7,9,true);
    Barco barcoC2 = Barco(posC01, 'C');
    Posicion posC02 = Posicion(8,9,true);
    barcoC2.setPos(posC02, 1);
    Posicion posC03 = Posicion(9,9,true);
    barcoC2.setPos(posC03, 2);
    barcos[9]=barcoC2;

    cout<<endl<<endl<<endl<<"~TABLERO~"<<endl<<endl;

    cout<<"   1   2   3   4   5   6   7   8   9   10"<<endl;
    cout<<"10 S   -   -   -   -   -   -   -   -   S"<<endl;
    cout<<"9  -   -   -   -   -   -   C   C   C   -"<<endl;
    cout<<"8  -   -   -   -   -   -   -   -   -   -"<<endl;
    cout<<"7  c   c   -   -   -   S   -   -   -   -"<<endl;
    cout<<"6  -   -   -   D   -   -   -   -   -   -"<<endl;
    cout<<"5  -   -   -   D   -   -   -   -   -   -"<<endl;
    cout<<"4  -   -   -   D   -   -   -   -   -   c"<<endl;
    cout<<"3  -   -   -   D   -   C   C   C   -   c"<<endl;
    cout<<"2  c   -   -   -   -   -   -   -   -   -"<<endl;
    cout<<"1  c   -   -   -   -   -   -   -   -   S"<<endl<<endl<<endl;
}
