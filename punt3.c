#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Cinconombres 5
#define MaxCadena 100


char *cargarNombre(char *buff, int itera);
void cargarNombres(char **puntNombres, char *buff);
void mostrarNombres(char **puntNombres);
void liberarMemoria(char **puntNombres, char *buff);

int main() {

    char **puntNombres = (char **)malloc(sizeof(char *) *Cinconombres);
    char *buff = malloc(sizeof(char)*MaxCadena);

    cargarNombres(puntNombres, buff);
    mostrarNombres(puntNombres);
    liberarMemoria(puntNombres, buff);

    return 0;
}

char *cargarNombre(char *buff, int itera) {

    int lengthCadena = 0;
    char *nombre;
    printf("ingrese nombre - %d: ", itera+1);

    gets(buff);

    lengthCadena = strlen(buff);
    nombre = malloc(sizeof(char)*lengthCadena+1);

    strcpy(nombre, buff);

    return nombre;
}

void cargarNombres(char **puntNombres, char *buff) {
    
    for(int i = 0; i < Cinconombres; i++) {
        puntNombres[i] = cargarNombre(buff, i);
        printf("\n");
    }
}

void mostrarNombres(char **puntNombres) {

    for(int i = 0; i < Cinconombres; i++) {
        printf("Nombre - %d: %s \n", i+1, puntNombres[i]);
    }
}

void liberarMemoria(char **puntNombres, char *buff) {

    for(int i = 0; i < Cinconombres; i++) {
        free(puntNombres[i]);
    }
    
    free(puntNombres);
    free(buff);
}

