#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int MAX_PERSONAJES = 10;
const int MAX_ENEMIGOS = 15;
const int MAX_SALTOS = 50;
const double PASO = 0.01;
const double VEL_PERSONAJE = 1;
const double UNIDADES_SALTO_Y = 4;

bool ejecutando = true;

double tiempoActual = 0;
int cantPersonajes = 0;
int cantEnemigos = 0;
int cantSaltos = 0;

int personajesDesaparecidos = 0;
double posEnemigoMasALaDerecha = 0;


struct Personaje{
    string id;
    double xi;
    double xd;
    double yd;
    char tipo = 'P';
    double momentoImpacto;
    bool eliminado;
    double distanciaSalto;
};

struct Enemigo{
    string id;
    double xi;
    double xd;
    double yd;
    char tipo = 'E';
};

struct Salto{
    double tiempo;
    string id;
    bool aptoUso;
    bool ejecutado;
};

vector<string> split(string linea,string delim){
    size_t posInicio = 0, posFin, delimLen = delim.length();
    string token;
    vector<string> resultado;
    while((posFin = linea.find(delim,posInicio)) != string::npos){
        token = linea.substr(posInicio, posFin - posInicio);
        posInicio = posFin + delimLen;
        resultado.push_back(token);
    }
    resultado.push_back(linea.substr(posInicio));
    return resultado;
}

void cargarEntidades(Personaje* p, Enemigo* e){
    ifstream archivo("../entidades.txt");
    string delimitador = ",";
    string linea;
    while(getline(archivo,linea)){
        if(linea == "") break;
        vector<string> data = split(linea,delimitador);
        if(data[4].compare("P") == 0){
            if(p){ //p != NULL
                p[cantPersonajes].id = data[0];
                p[cantPersonajes].xi = stod(data[1]);
                p[cantPersonajes].xd = stod(data[2]);
                p[cantPersonajes].yd = stod(data[3]);
                p[cantPersonajes].eliminado = false;
                cantPersonajes++;
            }
        }
        else{
            if(e){
                e[cantEnemigos].id = data[0];
                e[cantEnemigos].xi = stod(data[1]);
                e[cantEnemigos].xd = stod(data[2]);
                e[cantEnemigos].yd = stod(data[3]);
                if(e[cantEnemigos].xd > posEnemigoMasALaDerecha){
                    posEnemigoMasALaDerecha = e[cantEnemigos].xd;
                }
                cantEnemigos++;

            }
        }
    }
}

void cargarSaltos(Salto* saltos){
    ifstream archivo("../saltos.txt");
    string delimiter = ",";
    string linea;
    while(getline(archivo,linea)){
        vector<string> data = split(linea,delimiter);
        saltos[cantSaltos].tiempo = stod(data[0]);
        saltos[cantSaltos].id = data[1];
        saltos[cantSaltos].ejecutado = false;
        saltos[cantSaltos].aptoUso = false;
        cantSaltos++;
    }
}
bool verificarPersonajeAlejadoDeEnemigos(Personaje* pers){
    int cant = 0;
    for(int i = 0; i < cantPersonajes; i++){
        if(pers[i].xi > posEnemigoMasALaDerecha){
            cant++;
        }
    }
    return cant > 0;
}

void saltar(Personaje pers){
    if(!pers.eliminado){
        pers.yd += 4;
        pers.distanciaSalto = pers.xd + 5;
    }
}

void validarSaltos(Salto*& saltos, Personaje* personajes){
    for(int i = 0; i < cantSaltos; i++){
        if(!saltos[i].aptoUso && !saltos[i].ejecutado){
            if(tiempoActual >= saltos[i].tiempo){
                for(int j = 0; j < cantPersonajes; j++){
                    if(saltos[i].id == personajes[j].id && !personajes[i].eliminado){
                        saltos[i].aptoUso = true;
                        saltar(personajes[j]);
                    }
                }
            }
        }
    }
}

void verificarChoquePersonajeYEnemigo(Personaje*& pers, Enemigo*& e){
    for(int i = 0; i < cantPersonajes; i++){
        if(!pers[i].eliminado){
            for(int j = 0; j < cantEnemigos; j++){
                if(pers[i].xd >= e[j].xi && pers[i].xi ){
                    pers[i].eliminado = true;
                    pers[i].momentoImpacto = tiempoActual;
                    personajesDesaparecidos++;
                    cout << pers[i].id << endl;
                    cout << pers[i].momentoImpacto << endl;
                }
            }
        }
    }
}
void moverPersonajes(Personaje*& pers){
    for(int i = 0; i < cantPersonajes; i++){
        if(!pers[i].eliminado){
            pers[i].xi += VEL_PERSONAJE*PASO;
            pers[i].xd += VEL_PERSONAJE*PASO;
            if(pers[i].xd >= pers[i].distanciaSalto){
                pers[i].yd -= 4;
            }
        }
    }
}


/*void moverPersonajes(Salto*& saltos, Personaje*& pers){
    for(int i = 0; i < cantPersonajes; i++){
        bool seMovioEnElAire = false;
        for(int j = 0; j < cantSaltos; j++){
            if(saltos[j].aptoUso && !saltos[j].ejecutado){
                double tiempoSalto = 0;
                pers[i].yd += 4;
                pers[i].xi += VEL_PERSONAJE*PASO;
                pers[i].xd += VEL_PERSONAJE*PASO;
                while(tiempoSalto <= 5) {
                    tiempoSalto += PASO;
                }
                pers[i].yd -= 4;
                saltos[j].ejecutado = true;
                seMovioEnElAire = true;
            }
        }
        if(!seMovioEnElAire){
            pers[i].xi += VEL_PERSONAJE*PASO;
            pers[i].xd += VEL_PERSONAJE*PASO;
        }
    }
}*/

void run(Personaje* pers, Enemigo* e, Salto* s){
    while(ejecutando){
        validarSaltos(s,pers);
        verificarChoquePersonajeYEnemigo(pers,e);
        moverPersonajes(pers);
        if(personajesDesaparecidos == cantPersonajes || verificarPersonajeAlejadoDeEnemigos(pers)){
            ejecutando = false;
        }
        tiempoActual += PASO;
    }
}
int main() {

    Personaje personajes[MAX_PERSONAJES];
    cargarEntidades(personajes, nullptr);

    Enemigo enemigos[MAX_ENEMIGOS];
    cargarEntidades(nullptr, enemigos);

    Salto saltos[MAX_SALTOS];
    cargarSaltos(saltos);

    run(personajes,enemigos,saltos);
    return 0;
}
