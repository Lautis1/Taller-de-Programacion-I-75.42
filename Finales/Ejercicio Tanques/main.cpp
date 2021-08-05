#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

const int MAX_POZOS = 10;
const int MAX_TANQUES = 10;

int cantPozos = 0;
int cantTanques = 0;

bool keepRunning = true;
int tanquesCaidos = 0;
double bordeDerechoMasLejano = 0;

struct Pozo{
    string id;
    double xCentro;
    double yCentro;
    double radio;
};

struct Tanque{
    string id;
    double xInfIzq;
    double yInfIzq;
    double xSupDer;
    double ySupDer;
    double distanciaRecorrida;
    bool caido;
    string idPozoCai;
};

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

void cargarEntidades(Tanque* tanques, Pozo* pozos){

    fstream archivo;
    if(tanques) {
        archivo.open("../tanques.txt");
    }
    else{
        archivo.open("../pozos.txt");
    }
    string delimiter = " ";
    string linea;
    int i=0;
    while(getline(archivo, linea)){
        if(linea == "") break;
        vector<string> data = split(linea,delimiter);
        if(tanques){
            tanques[i].id = data[0];
            tanques[i].xInfIzq = stod(data[1]);
            tanques[i].yInfIzq = stod(data[2]);
            tanques[i].xSupDer = stod(data[3]);
            tanques[i].ySupDer = stod(data[4]);
            tanques[i].distanciaRecorrida = 0;
            tanques[i].caido = false;
            tanques[i].idPozoCai = "";
            cantTanques++;
            i++;
        }
        else{
            pozos[i].id = data[0];
            pozos[i].xCentro = stod(data[1]);
            pozos[i].yCentro = stod(data[2]);
            pozos[i].radio = stod(data[3]);
            cantPozos++;
            if((pozos[i].radio + pozos[i].xCentro) > bordeDerechoMasLejano){
                bordeDerechoMasLejano = pozos[i].radio + pozos[i].xCentro;
            }
            i++;
        }
    }
}

bool verticeDentroDePozo(double x, double y, Pozo pozo){
    bool valor = sqrt(pow(x-pozo.xCentro,2) + pow(y-pozo.yCentro,2)) <= pozo.radio;
    return valor;
}

void verificarTanqueDentroDePozo(Tanque*& tanques, Pozo*& pozos){
    for(int i = 0; i < cantTanques; i++){
        if(!tanques[i].caido){
            for(int j = 0; j < cantPozos; j++){
                if (verticeDentroDePozo(tanques[i].xInfIzq, tanques[i].yInfIzq, pozos[j]) &&
                    verticeDentroDePozo(tanques[i].xInfIzq, tanques[i].ySupDer, pozos[j]) &&
                    verticeDentroDePozo(tanques[i].xSupDer, tanques[i].yInfIzq, pozos[j]) &&
                    verticeDentroDePozo(tanques[i].xSupDer, tanques[i].ySupDer, pozos[j])){
                    tanquesCaidos++;
                    tanques[i].caido = true;
                    tanques[i].idPozoCai = pozos[j].id;
                    cout << tanques[i].id << endl;
                    cout << tanques[i].idPozoCai << endl;
                    cout << tanques[i].distanciaRecorrida << endl;
                }
            }
        }
    }
}

void moverTanque(Tanque& tanque){
    if(!tanque.caido){
        tanque.xInfIzq += 0.0001;
        tanque.xSupDer += 0.0001;
        tanque.distanciaRecorrida += 0.0001;
    }
    else return;
}

bool verificarTanquesMuyALaDerechaDePozos(Tanque* t){
    int cant = 0;
    for(int i = 0; i < cantTanques; i++){
        if(t[i].xInfIzq > bordeDerechoMasLejano){
            cant++;
        }
    }
    if(cant > 0) return true;
    else return false;
}

void run(Tanque* t, Pozo* p){
    while(keepRunning){
        verificarTanqueDentroDePozo(t,p);
        for(int i = 0; i < cantTanques; i++){
            moverTanque(t[i]);
        }
        if(tanquesCaidos == cantTanques || verificarTanquesMuyALaDerechaDePozos(t)){
            keepRunning = false;
        }
    }
}

int main() {

    Tanque tanques[MAX_TANQUES];
    cargarEntidades(tanques, nullptr);

    Pozo pozos[MAX_POZOS];
    cargarEntidades(nullptr, pozos);

    run(tanques,pozos);
    return 0;
}
