#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_ATAQUES 64
#define MAX_ID 64
#define PASO_X 0.001
#define ALTURA_SALTO 5
#define ALTURA_AGACH 10

#define ACC_NADA 'n'
#define ACC_SALTA 's'
#define ACC_AGACH 'a'
#define ACC_COMBI 'c'

typedef struct {
	double xi; //x izq
	double yb; //y base
	double xd; //x derecha
	double yh; //y altura
	double energia;
} personaje_t;

typedef struct {
	char id[MAX_ID];
	double xi; //x izq
	double yb; //Y base
	double xd; //x der
	double yh; //y altura
	double energia;
	char accion;
	double distancia;
	bool sigue_avanzando;
	bool puede_chocar;
} ataque_t;

int leer_personaje(personaje_t* personaje) {
	FILE* archivo = fopen("personaje0.txt", "r");
	if (!archivo) {
		fprintf(stderr, "No se encontro el archivo 'personaje.txt'");
		return -1;
	}
	int res_leer_linea = fscanf(archivo, "%lf %lf %lf", &(personaje->xi), &(personaje->xd), &(personaje->yh));
	if (res_leer_linea == EOF)
		return -1;
	personaje->yb = 0;
	personaje->energia = 100.0f;
	fclose(archivo);
	return 0;
}

int leer_ataques(ataque_t* ataques) {
	FILE* archivo = fopen("ataques0.txt", "r");
	if (!archivo) {
		fprintf(stderr, "No se encontro el archivo 'ataques.txt'");
		return -1;
	}
	int cant_ataques = 0;
	int res_leer_linea = 1;
	while (res_leer_linea != EOF && cant_ataques < MAX_ATAQUES) {
		res_leer_linea = fscanf(archivo, "%s  %lf %lf %lf %lf %lf %c", ataques[cant_ataques].id, &(ataques[cant_ataques].xi), &(ataques[cant_ataques].yb), &(ataques[cant_ataques].xd), &(ataques[cant_ataques].yh), &(ataques[cant_ataques].energia), &(ataques[cant_ataques].accion));
		ataques[cant_ataques].accion = tolower(ataques[cant_ataques].accion);
		
		if (res_leer_linea != EOF && ataques[cant_ataques].yb < ataques[cant_ataques].yh &&
			ataques[cant_ataques].xi < ataques[cant_ataques].xd && (ataques[cant_ataques].accion == ACC_NADA ||
							 										ataques[cant_ataques].accion == ACC_SALTA ||
									  								ataques[cant_ataques].accion == ACC_AGACH ||
															  		ataques[cant_ataques].accion == ACC_COMBI)) {
			ataques[cant_ataques].distancia = 0;
			ataques[cant_ataques].sigue_avanzando = true;
			++cant_ataques;
		}
			
	}
	fclose(archivo);
	return cant_ataques;
}

void verificar_choque_posible(personaje_t* personaje, ataque_t* ataque) {
	double yb_per_aux = ((ataque->accion == ACC_SALTA || ataque->accion == ACC_COMBI) ? ALTURA_SALTO + personaje->yb : personaje->yb);
	double yh_per_aux = ((ataque->accion == ACC_AGACH || ataque->accion == ACC_COMBI) ? yb_per_aux + personaje->yh - ALTURA_AGACH : yb_per_aux + personaje->yh);
	if (ataque->xi > personaje->xd || ataque->yh < yb_per_aux || ataque->yb > yh_per_aux)
		ataque->puede_chocar = false;
	else
		ataque->puede_chocar = true;
	
}

bool procesar_ataque(personaje_t* personaje, ataque_t* ataque) {
	if (!ataque->sigue_avanzando)
		return false;

	if (!ataque->puede_chocar || personaje->energia <= 0) {
		printf("ID: %s no colisiona\n", ataque->id);
		ataque->sigue_avanzando = false;
	} else if (personaje->xi > ataque->xd) {
		ataque->xi += PASO_X;
		ataque->xd += PASO_X;
		ataque->distancia += PASO_X;
	} else {
		//El proyectil esta alineado en x con el personaje
		personaje->energia -= ataque->energia;
		printf("ID: %s     D: %.3lf       E: %.3lf\n", ataque->id, ataque->distancia, personaje->energia);
		ataque->sigue_avanzando = false;
	}
	
	return ataque->sigue_avanzando;
}

void procesar(personaje_t* personaje, ataque_t* ataques, int cant_ataques) {
	for(int i = 0; i < cant_ataques; ++i) {
		verificar_choque_posible(personaje, &ataques[i]);
	}
	
	bool seguir_procesando;
	do {
		seguir_procesando = false;
		for(int i = 0; i < cant_ataques; ++i) {
			seguir_procesando |= procesar_ataque(personaje, &ataques[i]);
		}
	} while (seguir_procesando);
}

int main(void) {
	personaje_t personaje;
	if (leer_personaje(&personaje) < 0)
		return 1;
	ataque_t ataques[MAX_ATAQUES];
	int cant_ataques = leer_ataques(ataques);
	if (cant_ataques < 0)
		return 1;
	procesar(&personaje, ataques, cant_ataques);
	return 0;
}

