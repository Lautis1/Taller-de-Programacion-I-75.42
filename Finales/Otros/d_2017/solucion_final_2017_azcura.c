#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <time.h>

// Define: solo para tamaños de arreglos
#define TAM_STR 256
#define CANT_MOSCAS 25
#define CANT_PERSONAJES 8

const unsigned int VELOCIDAD_MOSCA = 10;
const unsigned int SEGUNDOS_PROCESAMIENTO = 20;
const unsigned int LARGO_MOSCA = 1;
const unsigned int ITER_X_SEG = 1000000;

unsigned int c_p = 0;
unsigned int c_m = 0;

typedef struct personaje{
    char id[TAM_STR];
    double xi;
    double xd;
    double y0;
    double y1;
    double distancia;
    double vel;
    unsigned int vidas;
}personaje_t;

typedef struct mosca{
    double xi;
    double xd;
    double y0;
    double y1;
    bool viva;
}mosca_t;

bool abrir_archivo( char* n_archivo, void(*funcion)(void**, unsigned int, char*), void** arreglo ){
    char linea[TAM_STR];
    FILE* archivo = fopen(n_archivo, "r");

    if(!archivo){
        return false;
    }

    for( unsigned int i = 0; fgets( linea, sizeof(linea), archivo ); i += 1 ) {
        funcion(arreglo, i, linea);
    }

    fclose(archivo);
    return true;
}

void cargar_personajes_aux(personaje_t** p, unsigned int i, char* linea){
    p[i] = malloc( sizeof(personaje_t) );
    sscanf(linea,"%s %lf %lf %lf %lf %u\n", p[i]->id, &p[i]->xi, &p[i]->xd, &p[i]->y1, &p[i]->vel, &p[i]->vidas);

    p[i]->y0 = 0.0;
    p[i]->distancia = 0.0;
    c_p += 1;
}

bool cargar_personajes(char* n_archivo, personaje_t** p){
    return abrir_archivo(n_archivo, (void (*)(void **, unsigned int, char *)) cargar_personajes_aux, (void **) p);
}

void cargar_moscas_aux(mosca_t** m, unsigned int i, char* linea){
    m[i] = malloc( sizeof(mosca_t) );
    sscanf(linea,"%lf %lf", &m[i]->xi, &m[i]->y0);

    m[i]->xd = m[i]->xi + (double) LARGO_MOSCA;
    m[i]->y1 = m[i]->y0 + (double) LARGO_MOSCA;
    m[i]->viva = true;
    c_m += 1;
}

bool cargar_moscas(char* n_archivo, mosca_t** m){
    return abrir_archivo(n_archivo, (void (*)(void **, unsigned int, char *)) cargar_moscas_aux, (void **) m);
}

void liberar_memoria(personaje_t** p, mosca_t** m){
    for(unsigned int i = 0; i < c_p; i += 1){
        free(p[i]);
    }

    for(unsigned int i = 0; i < c_m; i += 1){
        free(m[i]);
    }

    free(p);
    free(m);
}

int comparar_personajes(const void * a, const void * b) {
    personaje_t* x = *(personaje_t**)a;
    personaje_t* y = *(personaje_t**)b;

    if ( x->distancia < y->distancia)
        return -1;

    else if (x->distancia > y->distancia)
        return 1;

    return 0;
}

void imprimir_muertos(personaje_t** p){
    qsort(p, c_p, sizeof(personaje_t*), comparar_personajes);

    for( unsigned int i = 0; i < c_p; i += 1 ){
        if( p[i]->vidas == 0 ){
            printf("Personaje: %s - Distancia: %lf \n", p[i]->id, p[i]->distancia);
        }
    }
}

void mover_personaje(personaje_t* p){
    if(p->vidas == 0){
        return;
    }

    double incremento = (double) ( p->vel / (double) ITER_X_SEG );
    p->xi += incremento;
    p->xd += incremento;
    p->distancia += incremento;
}

void mover_mosca(mosca_t* m){
    if(!m->viva){
        return;
    }

    double incremento = (double) (  (double) VELOCIDAD_MOSCA / (double) ITER_X_SEG );
    m->xi -= incremento;
    m->xd -= incremento;
}

bool hay_colision(personaje_t* p, mosca_t* m) {
    return   (  ( p->xd >= m->xi ) && ( p->xi <= m->xi )  && ( p->y1  >= m->y0 ) );
}

void actualizar(mosca_t** m, personaje_t** p){
    time_t ahora = time(NULL);
    time_t fin = ahora + (time_t) SEGUNDOS_PROCESAMIENTO - 1;

    // Durante el tiempo de procesamiento
    while(ahora < fin){
        // Durante 1000000 (aprox 1 segundo)
        for(unsigned int i = 0; i < ITER_X_SEG; i += 1){
            // Verificar colisiones
            for(unsigned int j = 0; j < c_p; j += 1){
                for(unsigned int k = 0; k < c_m; k += 1){
                    if ( p[j]->vidas && m[k]->viva && hay_colision(p[j], m[k]) ) {
                        p[j]->vidas -= 1;
                        m[k]->viva = false;
                    }
                }
            }

            // Mover personajes
            for(unsigned int j = 0; j < c_p; j += 1){
                mover_personaje( p[j] );
            }

            // Mover moscas
            for(unsigned int j = 0; j < c_m; j += 1){
                mover_mosca( m[j] );
            }

        }

        // Actualizar tiempo
        ahora = time(NULL);
    }
}

int main(int argc, char *argv[]){
    (void) argc;
    mosca_t** m = malloc( CANT_MOSCAS * sizeof(mosca_t) );
    personaje_t** p = malloc( CANT_PERSONAJES * sizeof(personaje_t) );

    if( !cargar_moscas(argv[1], m) || !cargar_personajes(argv[2], p)){
        printf("Archivo no encontrado.");
        return 1;
    }
    actualizar(m, p);

    imprimir_muertos(p);
    liberar_memoria(p, m);
    return 0;
}
