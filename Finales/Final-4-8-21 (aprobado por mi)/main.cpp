#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "string.h"
#include "stdio.h"


using namespace std;

const double LARGO_ENEMIGO = 1;
const double PASO = 0.0001;
const double VEL_PERSONAJE = 1;

vector<string> split(string linea, string delimitador){
    size_t posInicio = 0, posFin, delimLen = delimitador.length();
    string campo;
    vector <string> resultado;
    while((posFin = linea.find(delimitador,posInicio)) != string::npos){
        campo = linea.substr(posInicio,posFin-posInicio);
        posInicio = posFin + delimLen;
        resultado.push_back(campo);
    }
    resultado.push_back(linea.substr(posInicio));
    return resultado;
}

struct Personaje{
    string id;
    double xInicio;
    char tipo = 'P';
    int nivel;
    bool eliminado = false;
    double distHorizontal = 0;
};

struct Enemigo{
    string id;
    double xIzq;
    double xDer;
    char tipo = 'E';
    int nivel;
};

struct Desplazamiento{
    double tiempo;
    string idPers;
    int nivelAlQueSalta;
    bool aptoUso = false;
};

int cantPersonajes = 0;
int cantEnemigos = 0;
int cantDesplazamientos = 0;

int personajesDesaparecidos = 0;
double tiempoActual = 0;

double posXEnemigoMasAlaDerecha = 0;
int nivelEnemigoMasAlaDerecha = 0;

bool ejecutando = true;



void cargarEntidades(Personaje* p, Enemigo* e){
    ifstream archivo;
    archivo.open("../entidades.txt");
    string delimitador = " ";
    string linea;
    while(getline(archivo,linea)){
        if(linea == "") break;
        vector<string> data = split(linea,delimitador);
        if(data[2].compare("P") == 0){
            if(p){
                p[cantPersonajes].id = data[0];
                p[cantPersonajes].xInicio = stod(data[1]);
                p[cantPersonajes].nivel = stoi(data[3]);
                cantPersonajes++;
            }
        }
        else{
            if(e){
                e[cantEnemigos].id = data[0];
                e[cantEnemigos].xIzq = stod(data[1]);
                e[cantEnemigos].nivel = stoi(data[3]);
                e[cantEnemigos].xDer = e[cantEnemigos].xIzq + 1;
                if(e[cantEnemigos].xDer > posXEnemigoMasAlaDerecha){
                    posXEnemigoMasAlaDerecha = e[cantEnemigos].xDer;
                    nivelEnemigoMasAlaDerecha = e[cantEnemigos].nivel;
                }
                cantEnemigos++;
            }
        }
    }
}

void cargarDesplazamientos(Desplazamiento* despl){
    ifstream archivo;
    archivo.open("../comandos.txt");
    string delimitador = " ";
    string linea;
    while(getline(archivo,linea)) {
        if(linea == "") break;
        vector<string> data = split(linea,delimitador);
        despl[cantDesplazamientos].tiempo = stod(data[0]);
        despl[cantDesplazamientos].idPers = data[1];
        despl[cantDesplazamientos].nivelAlQueSalta = stoi(data[2]);
        cantDesplazamientos++;
    }
}

void moverPersonajeVertical(Personaje& pers,int nivelAlQuePasa){
    if(!pers.eliminado){
        pers.nivel = nivelAlQuePasa;
    }
}

void verificarDesplazamientosVerticales(Personaje*& pers, Desplazamiento*& despl){
    for(int i = 0; i < cantDesplazamientos; i++){
        if(!despl[i].aptoUso){
            if(tiempoActual >= despl[i].tiempo){
                for(int j = 0; j < cantPersonajes; j++){
                    if(!pers[j].eliminado && (pers[j].id == despl[i].idPers)){
                        if(despl[i].nivelAlQueSalta <= 3 && (despl[i].nivelAlQueSalta >= 0)) {
                            despl[i].aptoUso = true;
                            moverPersonajeVertical(pers[j], despl[i].nivelAlQueSalta);
                        }
                    }
                }
            }
        }
    }
}

void moverPersonajesHorizontal(Personaje*& pers){
    for(int i = 0; i < cantPersonajes; i++){
        if(!pers[i].eliminado) {
            pers[i].xInicio += VEL_PERSONAJE * PASO;
            pers[i].distHorizontal += VEL_PERSONAJE * PASO;
        }
    }
}

void verificarColisiones(Personaje*& pers, Enemigo* e){
    for(int i = 0; i < cantPersonajes; i++){
        if(!pers[i].eliminado){
            for(int j = 0; j < cantEnemigos; j++){
                if(pers[i].nivel == e[j].nivel) {
                    if ((pers[i].xInicio >= e[j].xIzq && pers[i].xInicio <= e[j].xDer)) {
                        pers[i].eliminado = true;
                        personajesDesaparecidos++;
                        cout << pers[i].id << endl;
                        cout << pers[i].distHorizontal << endl;
                        cout << endl;
                    }
                }
            }
        }
    }
}

bool verificarNivelVacioAmiDerecha(Personaje* pers){
    int cant = 0;
    for(int i = 0; i < cantPersonajes - personajesDesaparecidos; i++){
        if(!pers[i].eliminado){
            if(pers[i].xInicio > posXEnemigoMasAlaDerecha && pers[i].nivel == nivelEnemigoMasAlaDerecha) cant++;
        }
    }
    return cant > 0;
}
void run(Personaje* pers, Enemigo* e, Desplazamiento* despl){


    while(ejecutando){
        verificarColisiones(pers,e);
        verificarDesplazamientosVerticales(pers,despl);
        moverPersonajesHorizontal(pers);
        if(personajesDesaparecidos == cantPersonajes || verificarNivelVacioAmiDerecha(pers)){
            ejecutando = false;
        }

        tiempoActual += PASO;
    }
}
int main() {

    Personaje personajes[50];
    cargarEntidades(personajes,nullptr);

    Enemigo enemigos[50];
    cargarEntidades(nullptr,enemigos);

    Desplazamiento desplazamientos[50];
    cargarDesplazamientos(desplazamientos);

    run(personajes,enemigos,desplazamientos);
    return 0;
}
