#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PERSONAJES 10
#define MAX_ENEMIGOS 9990
#define TAM_STR 256
#define LARGO_M 100

const int PASO_P = 1;

typedef struct personaje{
    char id[TAM_STR];
    int x;
    int y;
    double energia;
    double escudo;
    int recorrido;
    int ciclos;
    bool moverse;
} personaje_t;

typedef struct enemigo{
    int x;
    int y;
    double ataque;
    int alcance;
} enemigo_t;

int cant_p = 0;
int cant_e = 0;

void cargar_personajes_aux(char* linea, personaje_t** p, int i){
    p[i] = malloc( sizeof(personaje_t) );
    sscanf(linea, "%s %d %d %lf %lf", p[i]->id, &p[i]->x, &p[i]->y, &p[i]->energia, &p[i]->escudo);
    p[i]->recorrido = 0;
    p[i]->ciclos = 1;
    cant_p += 1;
    p[i]->moverse = true;
}

void cargar_enemigos_aux(char* linea, enemigo_t** e, int i){
    e[i] = malloc( sizeof(enemigo_t) );
    sscanf(linea, "%d %d %lf %d", &e[i]->x, &e[i]->y, &e[i]->ataque, &e[i]->alcance);
    cant_e += 1;
}

bool abrir_archivo( char* n_archivo, void** a, void(*funcion)(char*, void**, int) ){
    char linea[TAM_STR];
    FILE* archivo = fopen(n_archivo, "r");

    if(!archivo){
        return false;
    }

    for(int i = 0; fgets(linea, sizeof(linea), archivo); i += 1 ){
        funcion(linea, a, i);
    }

    fclose(archivo);
    return true;
}

bool cargar_personajes(char* n_archivo, personaje_t** p){
    return abrir_archivo(n_archivo, (void**) p, (void (*)(char*, void**, int)) cargar_personajes_aux);
}

bool cargar_enemigos(char* n_archivo, enemigo_t** e){
    return abrir_archivo(n_archivo, (void**) e, (void (*)(char*, void**, int)) cargar_enemigos_aux);
}

void liberar_memoria(personaje_t** p, enemigo_t** e, bool** m){
    for(int i = 0; i < cant_p; i += 1){
        free(p[i]);
    }

    for(int i = 0; i < cant_e; i += 1){
        free(e[i]);
    }

    for(int i = 0; i < LARGO_M; i += 1){
        free(m[i]);
    }

    free(p);
    free(e);
    free(m);
}

int comparar_p(const void* i, const void* j){
    personaje_t* a = *( (personaje_t**) i);
    personaje_t* b = *( (personaje_t**) j);

    if(a->ciclos > b->ciclos){
        return 1;
    }

    if(a->ciclos < b->ciclos){
        return -1;
    }

    return 0;
}

void imprimir_muertos(personaje_t** p){
    qsort(p, (size_t) cant_p, sizeof(personaje_t*), comparar_p);

    for(int i = 0; i < cant_p; i += 1){
        if(p[i]->energia <= 0){
            printf("%s %d %d \n", p[i]->id, p[i]->recorrido, p[i]->ciclos);
        }
    }
}

bool moviendose(personaje_t** p){
    for(int i = 0; i < cant_p; i += 1){
        if( p[i]->moverse ){
            return true;
        }
    }

    return false;
}

bool esta_en_alcance(enemigo_t* e, personaje_t* p){
    if(p->energia <= 0){
        return false;
    }

    // Casos borde
    int sup_x = e->x + e->alcance;
    if(sup_x == LARGO_M){
        sup_x =  e->x;
    }

    int sup_y = e->y + e->alcance;
    if(sup_y == LARGO_M){
        sup_y = e->y;
    }

    int inf_x = e->x;
    if(inf_x != 0){
        inf_x -= e->alcance;
    }

    int inf_y = e->y;
    if(inf_y != 0){
        inf_y -= e->alcance;
    }

    return (p->x >= inf_x) && (p->x <= sup_x) && (p->y >= inf_y) && (p->y <= sup_y);
}

void atacar(enemigo_t* e, personaje_t* p){
    if(p->escudo >= e->ataque){
        return;
    }

    p->energia -= e->ataque - p->escudo;
}

void mover_p(personaje_t* p, bool** m){
    const int x = p->x + PASO_P;
    const int y = p->y;

    if(p->energia > 0){
        p->ciclos += 1;
    }

    else{
        p->moverse = false;
        return;
    }

    // Si está vivo
    // y todavía puede avanzar
    // y en la celda que viene no hay un enemigo.
    if(( x < LARGO_M ) && ( !m[x][y] ) ){
        p->x += PASO_P;
        p->recorrido += PASO_P;
        p->moverse = true;
        return;
    }

    p->moverse = false;
}

void actualizar(personaje_t** p, enemigo_t** e, bool** m){
    while( moviendose(p) ){
        for(int i = 0; i < cant_e; i += 1){
            for(int j = 0; j < cant_p; j += 1){
                if( esta_en_alcance( e[i], p[j] ) ){
                    atacar(e[i], p[j]);
                }
            }
        }

        for(int i = 0; i < cant_p; i += 1){
            mover_p( p[i], m );
        }
    }
}

void iniciar_matris(bool** m, enemigo_t** e){
    for(int i = 0; i < LARGO_M; i += 1){
        m[i] = malloc( sizeof(int) * LARGO_M );
    }

    for(int i = 0; i < LARGO_M; i += 1){
        for(unsigned int j = 0; j < LARGO_M; j += 1){
            m[i][j] = false;
        }
    }

    for(int i = 0; i < cant_e; i += 1){
        const int x = e[i]->x;
        const int y = e[i]->y;
        m[x][y] = true;
    }
}

int main(int argc, char* argv[]){
    (void) argc;
    personaje_t** p = malloc( sizeof(personaje_t) * MAX_PERSONAJES );
    enemigo_t**  e = malloc( sizeof(enemigo_t)   * MAX_ENEMIGOS );
    bool** m  = malloc( sizeof(int) * LARGO_M );

    // Se reciben los valores por parámetro (consola).
    if( !cargar_personajes(argv[1], p) || !cargar_enemigos(argv[2], e) ){
        printf("Archivo no encontrado.\n");
        return 1;
    };

    iniciar_matris(m, e);

    actualizar(p, e, m);
    imprimir_muertos(p);

    liberar_memoria(p, e, m);
    return 0;
}
