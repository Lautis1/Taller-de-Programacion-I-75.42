#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

const double VEL_MOSCA = 10;
const double PASO = 0.01;
const int MAX_MOSCAS = 25;
const int MAX_PERSONAJES = 8;
const double LARGO_MOSCA = 1;

int cantMoscas = 0;
int cantPersonajes = 0;

int personajesDesaparecidos = 0;
int moscasEliminadas = 0;

double posXMoscaMasAlejada = 0;

struct Mosca{
    double xi;
    double yi;
    double xd;
    bool eliminado = false;
};

struct Personaje{
    string id;
    double xi;
    double xd;
    double yd;
    int vel;
    int vidas;
    bool eliminado = false;
    double distanciaRecorrida = 0;
};

vector<string> split(string linea, string delimitador){
    size_t posInicio = 0, posFin, delimLen = delimitador.length();
    string campo;
    vector<string> resultado;
    while((posFin = linea.find(delimitador,posInicio)) != string::npos){
        campo = linea.substr(posInicio, posFin-posInicio);
        posInicio = posFin + delimLen;
        resultado.push_back(campo);
    }
    resultado.push_back(linea.substr(posInicio));
    return resultado;
}

void cargarEntidades(Personaje* pers, Mosca* moscas){
    ifstream archivo;
    if(pers) archivo.open("../personajes.txt");
    else archivo.open("../moscas.txt");
    string delim = " ";
    string linea;
    while(getline(archivo,linea)){
        if(linea == "") break;
        vector<string> data = split(linea,delim);
        if(pers){
            pers[cantPersonajes].id = data[0];
            pers[cantPersonajes].xi = stod(data[1]);
            pers[cantPersonajes].xd = stod(data[2]);
            pers[cantPersonajes].yd = stod(data[3]);
            pers[cantPersonajes].vel = stoi(data[4]);
            pers[cantPersonajes].vidas = stoi(data[5]);
            cantPersonajes++;
        }
        else{
            moscas[cantMoscas].xi = stod(data[0]);
            moscas[cantMoscas].yi = stod(data[1]);
            moscas[cantMoscas].xd = moscas[cantMoscas].xi + LARGO_MOSCA;
            if(moscas[cantMoscas].xd > posXMoscaMasAlejada){
                posXMoscaMasAlejada = moscas[cantMoscas].xd;
            }
            cantMoscas++;
        }
    }
}

void moverPersonaje(Personaje& pers){
    if(!pers.eliminado){
        pers.xi += pers.vel * PASO;
        pers.xd += pers.vel * PASO;
        pers.distanciaRecorrida += pers.vel * PASO;
    }
}

void moverMosca(Mosca& mosca){
    if(!mosca.eliminado){
        mosca.xi -= VEL_MOSCA * PASO;
        mosca.xd -= VEL_MOSCA * PASO;
    }
}

void verificarColision(Personaje*& pers, Mosca*& moscas){
    for(int i = 0; i < cantPersonajes; i++){
        for(int j = 0; j < cantMoscas; j++){
            if(!moscas[j].eliminado && !pers[i].eliminado){
                if((pers[i].xd >= moscas[j].xi) && (moscas[j].yi <= pers[i].yd) && (pers[i].xi <= moscas[j].xi)){
                    moscas[j].eliminado = true;
                    moscasEliminadas++;
                    pers[i].vidas--;
                    if(pers[i].vidas == 0){
                        pers[i].eliminado = true;
                        cout << pers[i].id << endl;
                        cout << pers[i].distanciaRecorrida << endl;
                        personajesDesaparecidos++;
                    }
                }
            }
        }
    }
}

bool verificarPersonajeAlejadoDeMoscas(Personaje* pers){
    int cant = 0;
    for(int i = 0; i < cantPersonajes; i++){
        if(pers[i].xi > posXMoscaMasAlejada) cant++;
    }
    return cant > 0;
}

void run(Personaje* pers, Mosca* moscas){

    while(true){
        verificarColision(pers,moscas);
        for(int i = 0; i < cantPersonajes; i++){
            moverPersonaje(pers[i]);
        }
        for(int j = 0; j < cantMoscas; j++){
            moverMosca(moscas[j]);
        }

        if(personajesDesaparecidos == cantPersonajes || moscasEliminadas == cantMoscas) return;
    }
}

int main() {

    Personaje personajes[MAX_PERSONAJES];
    cargarEntidades(personajes,nullptr);

    Mosca moscas[MAX_MOSCAS];
    cargarEntidades(nullptr,moscas);

    run(personajes,moscas);
    return 0;
}
