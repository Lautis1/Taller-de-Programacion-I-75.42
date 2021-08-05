#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define TOPE_DERECHO 100	//Rango X: [1..100]
#define TOPE_SUPERIOR 99	//Rango Y: [0..99]
#define TOPE_IZQUIERDO 1
#define TOPE_INFERIOR 0
#define MAX_ID 64
#define VEL_PERSONAJE 1
#define MAX_PERSONAJES 10
#define MAX_ENEMIGOS (TOPE_DERECHO * TOPE_SUPERIOR - MAX_PERSONAJES)

typedef struct {
	char id[MAX_ID];
	int pos_x;
	int pos_y;
	double energia;
	double escudo;
	int celdas_recorridas;
	int ciclos_vivo;
} personaje_t;

typedef struct {
	int pos_x;
	int pos_y;
	double ataque;
	int alcance;
} enemigo_t;

typedef struct {
	personaje_t *personajes;
	int cant_personajes;
	enemigo_t *enemigos;
	int cant_enemigos;
} tablero_t;

int leer_personajes(personaje_t *pers);
int leer_enemigos(enemigo_t *enemigos);
void inicializar_tablero(tablero_t *this, personaje_t *p, int cant_p, enemigo_t *e, int cant_e);
bool intentar_atacar(enemigo_t *enemigo, personaje_t *per);
bool actualizar_personaje(personaje_t *per, enemigo_t *enemigos, int cant_e);
bool avanzar_iteracion(tablero_t *tablero);
void procesar(tablero_t *tablero);
int comparar(const void *personaje_1, const void *personaje_2);
void imprimir_resultado(personaje_t *p, int cant_p);


int leer_personajes(personaje_t *pers){
	FILE* archivo;
	if(!(archivo = fopen("personajes.txt", "r"))){
        fprintf(stderr, "No se encontro el archivo de input de personajes 'personajes.txt'\n");
		return -1;
	}
	int res_leer_linea = 1;
	int personajes_leidos = 0;
	while (res_leer_linea != EOF && personajes_leidos < MAX_PERSONAJES) {
		memset(pers[personajes_leidos].id, 0, MAX_ID);
		res_leer_linea = fscanf(archivo, "%s %d %d %lf %lf", pers[personajes_leidos].id, &(pers[personajes_leidos].pos_x), &(pers[personajes_leidos].pos_y), &(pers[personajes_leidos].energia), &(pers[personajes_leidos].escudo));
		if (res_leer_linea != EOF && pers[personajes_leidos].pos_x <= TOPE_DERECHO && pers[personajes_leidos].pos_x >= TOPE_IZQUIERDO && pers[personajes_leidos].pos_y <= TOPE_SUPERIOR && pers[personajes_leidos].pos_y >= TOPE_INFERIOR) {
			pers[personajes_leidos].celdas_recorridas = 0;
			pers[personajes_leidos].ciclos_vivo = 0;
			personajes_leidos += 1;
		}
		
	}

	fclose(archivo);
	return personajes_leidos;
}

int leer_enemigos(enemigo_t *enemigos) {
	FILE *archivo;
	if (!(archivo = fopen("enemigos.txt", "r"))) {
		fprintf(stderr, "No se encontro el archivo de input de enemigos 'enemigos.txt'\n");
		return -1;
	}
	int res_leer_linea = 1;
	int enemigos_leidos = 0;
	while (res_leer_linea != EOF && enemigos_leidos < MAX_ENEMIGOS) {
		res_leer_linea = fscanf(archivo, "%d %d %lf %d", &(enemigos[enemigos_leidos].pos_x), &(enemigos[enemigos_leidos].pos_y), &(enemigos[enemigos_leidos].ataque), &(enemigos[enemigos_leidos].alcance));
		enemigos_leidos += (res_leer_linea != EOF ? 1 : 0);
	}
	fclose(archivo);
	return enemigos_leidos;
}	

void inicializar_tablero(tablero_t *this, personaje_t *p, int cant_p, enemigo_t *e, int cant_e) {
	this->personajes = p;
	this->cant_personajes = cant_p;
	this->enemigos = e;
	this->cant_enemigos = cant_e;
}

//Devuelve true si el enemigo le pudo sacar vida al personaje
bool intentar_atacar(enemigo_t *enemigo, personaje_t *per) {
	bool perdio_vida = false;
	bool interseccion_horizontal = (per->pos_x >= enemigo->pos_x - enemigo->alcance && per->pos_x <= enemigo->pos_x + enemigo->alcance);
	bool interseccion_vertical = (per->pos_y >= enemigo->pos_y - enemigo->alcance && per->pos_y <= enemigo->pos_y + enemigo->alcance);
	if (interseccion_horizontal && interseccion_vertical) {
		perdio_vida = enemigo->ataque - per->escudo > 0;
		double energia_perdida = (perdio_vida ? enemigo->ataque - per->escudo : 0);	
		per->energia -= energia_perdida;
	}
	return perdio_vida;
}

//Devuelve true el personaje pueda moverse o esta pegado a un enemigo perdiendo vida (es decir, que sea posible una siguiente iteracion)
bool actualizar_personaje(personaje_t *per, enemigo_t *enemigos, int cant_e) {
	bool puede_moverse = true;
	bool esta_perdiendo_vida = false;
	if (per->pos_x == TOPE_DERECHO)
		puede_moverse = false;
	for (int enem = 0; enem < cant_e; ++enem) {
		//true | false == true, si perdio vida con un enemigo anterior entonces esta variable ya queda en true
		esta_perdiendo_vida |= intentar_atacar(&(enemigos[enem]), per);
		if (puede_moverse && per->pos_x + VEL_PERSONAJE == enemigos[enem].pos_x && per->pos_y == enemigos[enem].pos_y)
			puede_moverse = false;
	}	
	if (puede_moverse && per->energia > 0) {
		per->pos_x += VEL_PERSONAJE;
		per->celdas_recorridas += VEL_PERSONAJE;
	}
	return (puede_moverse | esta_perdiendo_vida);
}

//Devuelve true si queda algun personaje que pueda moverse o algun personaje pegado a un enemigo perdiendo vida (es decir, que sea posible una siguiente iteracion)
bool avanzar_iteracion(tablero_t *tablero) {
	bool hay_sig_iteracion = false;
	for (int per = 0; per < tablero->cant_personajes; ++per) {
		if (tablero->personajes[per].energia > 0) {
			tablero->personajes[per].ciclos_vivo += 1;
			//true | false == true, si algun personaje puede moverse o esta recibiendo daño entonces puedo seguir iterando
			hay_sig_iteracion |= actualizar_personaje(&(tablero->personajes[per]), tablero->enemigos, tablero->cant_enemigos);
		}
	}
	return hay_sig_iteracion;
}	

//Los enemigos atacan en todas las direcciones con su alcance, quitandoles a los personajes (ataque-escudo) vida (si es mayor a 0)
//Los personajes se mueven 1 lugar a la derecha en cada ciclo si no estan en el borde derecho o no esta pegado a un enemigo
void procesar(tablero_t *tablero) {
	bool hay_sig_iteracion = true;
	while(hay_sig_iteracion) {
		hay_sig_iteracion = avanzar_iteracion(tablero);
	}
}

//True si per_1 > per_2, para ordenar lista de personajes de forma ascendente
int comparar(const void *personaje_1, const void *personaje_2) {
	//positive if p1_dist > p2_dist
	personaje_t *p1 = (personaje_t *)personaje_1;
	personaje_t *p2 = (personaje_t *)personaje_2;
	return (int)(p1->ciclos_vivo > p2->ciclos_vivo);
}

// Muestra de forma listada de los personajes que desaparecieron (vida <= 0) el Id del personaje, cantidad de celdas
// recorridas, y la cantidad de ciclos que estuvieron en la partida y debe estar ordenado
// ascendentemente por este último campo
void imprimir_resultado(personaje_t *personajes, int cant_p){ 
	printf("Fin procesamiento\n");
	for (int per = 0; per < cant_p; ++per) 
		printf("Personaje %s, posX: %d, posY: %d, energia: %lf, escudo: %lf, celdas recorridas: %d, ciclos vivo: %d\n", personajes[per].id, personajes[per].pos_x, personajes[per].pos_y, personajes[per].energia, personajes[per].escudo, personajes[per].celdas_recorridas, personajes[per].ciclos_vivo);
	printf("\n");
	qsort(personajes, cant_p, sizeof(personaje_t), comparar);
	for (int per = 0; per < cant_p; ++per) {
		if (personajes[per].energia <= 0)
			fprintf(stdout, "%s: recorrio %d celdas y estuvo vivo %d ciclos\n", personajes[per].id, personajes[per].celdas_recorridas, personajes[per].ciclos_vivo);
	}

}

int main(void) {
	personaje_t pers[MAX_PERSONAJES];
	int cant_personajes = leer_personajes(pers);
	if (cant_personajes < 0)
		return -1;
	enemigo_t enemigos[MAX_ENEMIGOS];
	int cant_enemigos = leer_enemigos(enemigos);
	if (cant_enemigos < 0)
		return -1;

	printf("Leidos %d personajes y %d enemigos\n", cant_personajes, cant_enemigos);
	for (int per = 0; per < cant_personajes; ++per) 
		printf("Personaje %s, posX: %d, posY: %d, energia: %lf, escudo: %lf\n", pers[per].id, pers[per].pos_x, pers[per].pos_y, pers[per].energia, pers[per].escudo);
	printf("\n");
	for (int enem = 0; enem < cant_enemigos; ++enem) 
		printf("Enemigo %d, posX: %d, posY: %d, ataque: %lf, alcance: %d\n", enem + 1, enemigos[enem].pos_x, enemigos[enem].pos_y, enemigos[enem].ataque, enemigos[enem].alcance);
	printf("\n");

	tablero_t tablero;
	inicializar_tablero(&tablero, pers, cant_personajes, enemigos, cant_enemigos);
	procesar(&tablero);
	imprimir_resultado(pers, cant_personajes);
	return 0;
}