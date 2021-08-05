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
const int MAX_COMANDO_DISPAROS = 50;

const double PASO = 0.001;
const double VEL_PERSONAJE = 1;
const double VEL_ENEMIGO = 0.1;
const double VEL_DISPARO = 10;

bool keepRunning = true;

double tiempoActual = 0;
int cant_personajes = 0;
int cant_enemigos = 0;
int cant_disparos = 0;

int personajesDesaparecidos = 0;
int enemigoEliminados = 0;


struct Personaje {
    string id;
    double xi;
    double xd;
    double yd;
    char type = 'P';
    bool eliminado;
    double momento;
};

struct Enemigo{
    string id;
    double xi;
    double xd;
    double yd;
    char type = 'E';
    bool eliminado;
};

struct Disparo{
    double time;
    string id;
    bool eliminado;
    bool aptoUso;
    double x;
    double y;
};

vector<Personaje> desaparecidos;

vector<string> split(string linea,string delimitador){
    size_t pos_inicio = 0, pos_fin, delim_len = delimitador.length();
    string token;
    vector<string> resultado;

    while((pos_fin = linea.find(delimitador,pos_inicio)) != string::npos){
        token = linea.substr(pos_inicio,pos_fin-pos_inicio);
        pos_inicio = pos_fin+delim_len;
        resultado.push_back(token);
    }
    resultado.push_back(linea.substr(pos_inicio));
    return resultado;
}


void cargarEntidades(Personaje* personajes, Enemigo* enemigos){

    ifstream archivo("../personajes.txt");
    string delimiter = ",";
    string linea;
    int i=0;
    while(getline(archivo, linea)){
        vector<string> data = split(linea,delimiter);
        if (data[4].compare("P") == 0) {
            if(personajes) {
                personajes[i].id = data[0];
                personajes[i].xi = stod(data[1]);
                personajes[i].xd = stod(data[2]);
                personajes[i].yd = stod(data[3]);
                personajes[i].eliminado = false;
                i++;
                cant_personajes++;
            }
        }
        else{
            if(enemigos) {
                enemigos[i].id = data[0];
                enemigos[i].xi = stod(data[1]);
                enemigos[i].xd = stod(data[2]);
                enemigos[i].yd = stod(data[3]);
                enemigos[i].eliminado = false;
                i++;
                cant_enemigos++;
            }
        }
    }
}

void cargarDisparos(Disparo* disparos){

    ifstream archivo("../disparos.txt");
    string delimiter = ",";
    string linea;
    int i=0;
    while(getline(archivo, linea)) {
        vector<string> data = split(linea, delimiter);
        disparos[i].time = stod(data[0]);
        disparos[i].id = data[1];
        disparos[i].eliminado = false;
        disparos[i].aptoUso = false;
        cant_disparos++;
        i++;
    }
}

void colisionEntrePersonajeYEnemigo(Personaje*& personajes, Enemigo*& enemigos){
    for(int i = 0; i < cant_personajes; i++){
        if(personajes[i].eliminado == false) {
            for (int j = 0; j < cant_enemigos; j++) {
                if (enemigos[j].eliminado == false) {
                    if (personajes[i].xd >= enemigos[j].xi) {
                        personajes[i].eliminado = true;
                        personajes[i].momento = tiempoActual;
                        personajesDesaparecidos++;
                    }
                }
            }
        }
    }
}

void buscarDisparos(Disparo*& disparos, Personaje* personajes){
    for(int i = 0; i < cant_disparos; i++){
        if(disparos[i].aptoUso == false && disparos[i].eliminado == false) {
            if (tiempoActual >= disparos[i].time) {
                for (int j = 0; j < cant_personajes; j++) {
                    if (personajes[j].id == disparos[i].id && !personajes[j].eliminado) {
                        disparos[i].aptoUso = true;
                        disparos[i].x = personajes[j].xd;
                        disparos[i].y = personajes[j].yd;
                    }
                }
            }
        }
    }
}

void moverPersonaje(Personaje& personaje){
    if(!personaje.eliminado){
        double incremento = VEL_PERSONAJE*PASO;
        personaje.xd += incremento;
        personaje.xi += incremento;
    }
    else return;
}

void moverEnemigo(Enemigo& enemigo){
    if(!enemigo.eliminado){
        double incremento = VEL_ENEMIGO*PASO;
        enemigo.xi -= incremento;
        enemigo.xd -= incremento;
    }
    else return;
}

void moverDisparo(Disparo& disparo){
    if(!disparo.eliminado && disparo.aptoUso){
        disparo.x += VEL_DISPARO*PASO;
    }
}

void balaColisionaEnemigo(Disparo*& disparos, Enemigo*& enemigos){
    for(int i = 0; i < cant_disparos; i++){
        if(disparos[i].aptoUso == true && disparos[i].eliminado == false){
            for(int j = 0; j < cant_enemigos; j++){
                if(enemigos[j].eliminado == false) {
                    if (disparos[i].x >= enemigos[j].xi &&
                        enemigos[j].yd >= disparos[i].y){
                        enemigos[j].eliminado = true;
                        disparos[i].eliminado = true;
                        enemigoEliminados++;
                    }
                }
            }
        }
    }

}

void run(Personaje* pers, Enemigo* e, Disparo* d){

    while(keepRunning){
        buscarDisparos(d,pers);
        colisionEntrePersonajeYEnemigo(pers,e);
        balaColisionaEnemigo(d,e);
        for(int i = 0; i < cant_personajes; i++){
            moverPersonaje(pers[i]);
        }
        for(int j = 0; j < cant_enemigos; j++){
            moverEnemigo(e[j]);
        }
        for(int k = 0; k < cant_disparos; k++){
            moverDisparo(d[k]);
        }
        tiempoActual += PASO;
        if(personajesDesaparecidos == cant_personajes || enemigoEliminados == cant_enemigos){
            keepRunning = false;
        }
    }
}

int main(){

    Personaje personajes[MAX_PERSONAJES];
    cargarEntidades(personajes,nullptr);

    Enemigo enemigos[MAX_ENEMIGOS];
    cargarEntidades(nullptr, enemigos);

    Disparo disparos[MAX_COMANDO_DISPAROS];
    cargarDisparos(disparos);

    run(personajes,enemigos,disparos);
    return 0;
}

