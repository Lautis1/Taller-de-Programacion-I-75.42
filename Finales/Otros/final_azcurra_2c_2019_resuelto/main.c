#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

// No hay problema con los hardcodes y cosas feas para el final.
// ¡Es para ahorrar tiempo!
#define MAX_CHAR 33
#define MAX_CANT 111

// Idem variables globales.
const char OBSTACULO = 'O';
const double DISCRET = 1000;
const double VEL_P = 1;
int c_p = 0;
int c_o = 0;
int c_m = 0;
double max_x_obs = -99999999;
double max_vel = VEL_P;

typedef struct entidad{
    char id[MAX_CHAR];
    double x;
    double dist;
    int z;
    bool colision;
} entidad_t;

typedef struct mov{
    char id_p[MAX_CHAR];
    double t;
    int z;
    bool hecho;
} mov_t;

void cargar_ents(entidad_t* pers, entidad_t* obs, char* ruta){
    char linea[MAX_CANT];
    FILE* archivo = fopen(ruta, "r");

    // fgets: forma recomendada (por el autor) para leer archivos.
    // feof a veces trae basura.
    while ( fgets(linea, sizeof(linea), archivo) ){
        char aux_id[MAX_CHAR];
        double aux_x0;
        int aux_z;
        char tipo;
        // Cuando el archivo está separado por algo que no es espacios, en vez de
        // %s para los strings se pone %[^CARACTER_SEPARADOR] (es una expresión regular),
        // seguido de los caracteres correspondientes con el formato de la linea.
        sscanf(linea, "%[^,], %lf, %c, %d", aux_id, &aux_x0, &tipo, &aux_z);
        // De hecho, sscanf puede usarse aunque la cantidad de elementos por línea sea variable
        // (No hace falta saber usar strtok): se usa una cantidad de variables auxiliares asociado
        // a una cota de la cantidad de elementos
        // y después con un for se verifica cuáles de esas variables fueron asignadas.

        if( tipo == OBSTACULO ){
            strcpy(obs[c_o].id, aux_id);
            obs[c_o].x = aux_x0;
            obs[c_o].z = aux_z;
            obs[c_o].colision = false;
            obs[c_o].dist = 0.0;

            // Forma rápida de tener una condición de corte:
            // ver cuál es el obstáculo más lejano.
            if(obs[c_o].x > max_x_obs){
                max_x_obs = obs[c_o].x;
            }

            c_o += 1;
        }

        else{
            strcpy(pers[c_p].id, aux_id);
            pers[c_p].x = aux_x0;
            pers[c_p].z = aux_z;
            pers[c_p].colision = false;
            pers[c_p].dist = 0.0;
            c_p += 1;
        }
    }

    fclose(archivo);
}

void cargar_movs(mov_t* movs, char* ruta){
    char linea[MAX_CANT];
    FILE* archivo = fopen(ruta, "r");

    while( fgets(linea, sizeof(linea), archivo) ){
        sscanf(linea, "%lf, %[^,], %d", &movs[c_m].t, movs[c_m].id_p, &movs[c_m].z);
        movs[c_m].hecho = false;
        c_m += 1;
    }

    fclose(archivo);
}

// Es recomendable primero ver si se está leyendo y asignando bien los elementos
// de los arreglos.
void mostrar(entidad_t* pers, entidad_t* obs, mov_t* movs){
    for(int i = 0; i < c_p; i += 1){
        printf("%s %lf %d \n", pers[i].id, pers[i].x, pers[i].z);
    }

    printf("=========");
    for(int i = 0; i < c_o; i += 1){
        printf("%s %lf %d \n", obs[i].id, obs[i].x, obs[i].z);
    }
    printf("=========");

    for(int i = 0; i < c_m; i += 1){
        printf("%s %lf \n", movs[i].id_p, movs[i].t);
    }
}

bool hay_obs(entidad_t* pers){
    for(int i = 0; i < c_p; i += 1){
        if( (!pers[i].colision) && (pers[i].x < max_x_obs) ){
            return true;
        }
    }
    return false;
}

bool hay_colision(entidad_t* p, entidad_t* o){
    // Todo esto podría ser un return, pero está bueno acostrumbrarse
    // a verificar un caso borde aparte con un if (para acordarse).
    // De última, siempre se puede cambiar.
    if( (p->colision) || (p->z != o->z) ){
        return false;
    }

    // El fabs se usa para calcular la distancia (unidimensional) entre el punto y el obstaculo.
    // Se dice que hay colisión si la distancia es menor o igual al factor de discretización
    // (es decir, de a cuánto se toman los avances). A menor factor, mayor precisión de los resultados.
    return ( fabs(p->x - o->x) <= ( 1 / (DISCRET * max_vel) ) );
}

void mover(entidad_t* p){
    if( p->colision ){
        return;
    }

    p->x += 1 / (DISCRET * max_vel);
    p->dist += 1 / (DISCRET * max_vel);
}

void ver_mov(mov_t* movs, entidad_t* p){
    for(int i = 0; i < c_m; i += 1) {
        // v = d /t  --> t = d/ v
        if( (! movs[i].hecho) && ( strcmp( movs[i].id_p, p->id) == 0 ) && ( fabs( ( p->dist / VEL_P ) - movs[i].t ) < ( 1 / (DISCRET * max_vel) ) ) ){
            movs[i].hecho = true;
            p->z = movs[i].z;
        }
    }
}

void actualizar(entidad_t* pers, entidad_t* obs, mov_t* movs){
    // Todos los ejercicios pueden hacerse a partir de un loop similar a este.
    while(hay_obs(pers)){
        for(int i = 0; i < c_p; i += 1){
            for(int j = 0; j < c_o; j += 1){
                if( hay_colision(&pers[i], &obs[j]) ){
                    pers[i].colision = true;
                }
            }
        }

        for(int i = 0; i < c_p; i += 1) {
            ver_mov(movs, &pers[i]);
            mover(&pers[i]);
        }
    }
}

// Para ordenar al revés, cambiar 1 por -1 y viceversa.
// Para ordenar por dos criterios, en vez de devolver 0, desempatar
// con el criterio secundario.
int comparar_per(const void* a, const void* b){
    entidad_t* p1 = (entidad_t*) a;
    entidad_t* p2 = (entidad_t*) b;

    if(p1->dist > p2->dist){
        return 1;
    }

    else if(p2->dist > p1->dist){
        return -1;
    }

    return 0;
}

void mostrar_muertos(entidad_t* pers){
    qsort(pers, c_p, sizeof(entidad_t), comparar_per);

    for (int i = 0; i < c_p; i += 1) {
        if (pers[i].colision) {
            printf("%s %lf \n", pers[i].id, pers[i].dist);
        }
    }
}

int main() {
    entidad_t pers[MAX_CANT];
    entidad_t obs[MAX_CANT];
    mov_t movs[MAX_CANT];

    cargar_ents(pers, obs, "entidades.txt");
    cargar_movs(movs, "desplazamientos.txt");

    // No hace falta chequear casos borde, es para debug:
    if( (c_o < 1) || (c_p < 1) || (c_m < 1) ){
        printf("Faltan personajes o desplazamientos. \n");
        return 1;
    }

    //mostrar(pers, obs, movs);
    actualizar(pers, obs, movs);
    mostrar_muertos(pers);
    return 0;
}
