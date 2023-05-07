#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxCadena 100


char *cargarNombre(char *buff, int itera);
void cargarNombres(char **puntNombres, char *buff, int n);
void mostrarNombres(char **puntNombres, int n);
void liberarMemoria(char **puntNombres, char *buff, int n);

int main() {

    int n;
    printf("Ingrese el numero de nombres que ingresara: ");
    scanf("%d", &n);
    printf("\n");

    char **puntNombres = (char **)malloc(sizeof(char *) *n);
    char *buff = malloc(sizeof(char)*MaxCadena);

    cargarNombres(puntNombres, buff, n);
    mostrarNombres(puntNombres, n);
    liberarMemoria(puntNombres, buff, n);

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

void cargarNombres(char **puntNombres, char *buff, int n) {
    getchar();
    for(int i = 0; i < n; i++) {
        puntNombres[i] = cargarNombre(buff, i);
        printf("\n");
    }
}

void mostrarNombres(char **puntNombres, int n) {

    for(int i = 0; i < n; i++) {
        printf("Nombre - %d: %s \n", i+1, puntNombres[i]);
    }
}

void liberarMemoria(char **puntNombres, char *buff, int n) {

    for(int i = 0; i < n; i++) {
        free(puntNombres[i]);
    }
    
    free(puntNombres);
    free(buff);
}

