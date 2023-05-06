#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXGANANCIA 50000
#define MINGANANCIA 10000

void cargarMatriz(int matriz[5][12]);
void mostrarMatriz(int matriz[5][12]);
void proGananciaPorAnio(int matriz[5][12]);
void GananciaMaximaYMinima(int matriz[5][12]);

int main() {

    srand(time(NULL));
    int matriz[5][12];


    cargarMatriz(matriz);
    mostrarMatriz(matriz);
    proGananciaPorAnio(matriz);
    GananciaMaximaYMinima(matriz);

    


    return 0;
}

void cargarMatriz(int matriz[5][12]) {

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 12; j++) {
            matriz[i][j] = rand() % (MAXGANANCIA - MINGANANCIA) + MINGANANCIA;
        }
    }

}

void mostrarMatriz(int matriz[5][12]) {

    for(int i=0; i < 5; i++) {
        for(int j=0; j<12; j++) {
            printf("%d ", matriz[i][j]);
        }
        
        printf("\n");
    }
}

void proGananciaPorAnio(int matriz[5][12]) {

    int promedio = 0;

    for(int i=0; i < 5; i++) {
        for(int j=0; j<12; j++) {
            promedio+= matriz[i][j];
        }

        printf("promedio ganancia en el anio %d: %d", i+1, promedio/12);
        printf("\n");
    }
}

void GananciaMaximaYMinima(int matriz[5][12]) {

    int gananciaMaxima = MINGANANCIA;
    int gananciaMinima = MAXGANANCIA;
    int AnioGananciaMaxima = 0;
    int AnioGananciaMinima = 0;
    int MesGananciaMaxima = 0;
    int MesGananciaMinima = 0;
    
    for(int i=0; i < 5; i++) {
        for(int j=0; j<12; j++) {

            if(matriz[i][j] > gananciaMaxima) {
                gananciaMaxima = matriz[i][j];
                AnioGananciaMaxima = i+1;
                MesGananciaMaxima = j+1;
            }

            if(matriz[i][j] < gananciaMinima) {
                gananciaMinima = matriz[i][j];
                AnioGananciaMinima = i+1;
                MesGananciaMinima = j+1;
            }
            
        }
    }

    printf("La ganancia maxima de %d fue en el anio %d y mes %d \n", gananciaMaxima, AnioGananciaMaxima, MesGananciaMaxima);
    printf("La ganancia minima de %d fue en el anio %d y mes %d \n", gananciaMinima, AnioGananciaMinima, MesGananciaMinima);
}