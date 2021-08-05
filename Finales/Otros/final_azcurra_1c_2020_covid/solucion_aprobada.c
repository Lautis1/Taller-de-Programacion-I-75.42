#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ID 33
#define MAX_CANT 111
const double LARGO_NAVE = 1;
const double PASO = 0.001;

int c_n = 0;
int c_d = 0;
double min_x_n = 99999999;

typedef struct nave{
    char id[MAX_ID];
    double x0;
    double y0;
    double x1;
    double y1;
    bool eliminada;
    double momento;
} nave_t;

typedef struct disparo{
    char id[MAX_ID];
    double x;
    double y;
    bool eliminado;
} disparo_t;

void cargar_naves(nave_t* naves, char* ruta){
    char linea[MAX_CANT];
    FILE* archivo = fopen(ruta, "r");

    while( fgets( linea, sizeof(linea), archivo ) ){
        sscanf(linea, "%[^,],%lf,%lf", naves[c_n].id, &naves[c_n].x0, &naves[c_n].y0);
        naves[c_n].x1 = naves[c_n].x0 + LARGO_NAVE;
        naves[c_n].y1 = naves[c_n].y0 + LARGO_NAVE;
        naves[c_n].eliminada = false;
        naves[c_n].momento = 0.0;

        if(naves[c_n].x0 < min_x_n){
            min_x_n = naves[c_n].x0;
        }

        c_n += 1;
    }

    fclose(archivo);
}

void cargar_disparos(disparo_t* disparos, char* ruta){
    char linea[MAX_CANT];
    FILE* archivo = fopen(ruta, "r");

    while( fgets( linea, sizeof(linea), archivo ) ){
        sscanf(linea, "%[^,],%lf,%lf", disparos[c_d].id, &disparos[c_d].x, &disparos[c_d].y);
        disparos[c_d].eliminado = false;
        c_d += 1;
    }

    fclose(archivo);
}

bool hay_naves(disparo_t* disparos){
    for(int j = 0; j < c_d; j += 1){
        if( (! disparos[j].eliminado) && (disparos[j].x > min_x_n) ){
            return true;
        }
    }

    return false;
}

bool hay_colision(nave_t* n, disparo_t* d){
    return (! n->eliminada) && (! d->eliminado)
           && (d->x >= n->x0) && (d->x <= n->x1) && (d->y >= n->y0) && (d->y <= n->y1);
}

void actualizar(nave_t* naves, disparo_t* disparos) {
    while( hay_naves(disparos) ){
        for(int i = 0; i < c_n; i += 1){
            for(int j = 0; j < c_d; j += 1){
                if( hay_colision(&naves[i], &disparos[j]) ){
                    disparos[j].eliminado = true;
                    naves[i].eliminada = true;
                }
            }
        }

        for(int i = 0; i < c_n; i += 1){
            if(! naves[i].eliminada){
                naves[i].momento += PASO;
            }
        }

        for(int j = 0; j < c_d; j += 1){
            if(! disparos[j].eliminado){
                disparos[j].x -= PASO;
            }
        }

    }
}

int comparar_naves(const void* a, const void* b){
    return  (int) ( ( (nave_t*) a )->momento - ( (nave_t*) b )->momento );
}

void mostrar_muertas(nave_t* naves){
    qsort( naves, (size_t) c_n, sizeof(nave_t), comparar_naves );

    for(int i = 0; i < c_n; i += 1){
        if(naves[i].eliminada){
            printf("%s    %.2lf \n", naves[i].id, naves[i].momento);
        }
    }
}

int main(){
    nave_t naves[MAX_CANT];
    disparo_t disparos[MAX_CANT];

    cargar_naves(naves, "naves.csv");
    cargar_disparos(disparos, "disparos.csv");
    actualizar(naves, disparos);
    mostrar_muertas(naves);
    return 0;
}
