#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MaxTiposProductos 5
#define maxCadena 100
#define maxClientes 5

typedef struct Producto {
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
}Producto;

typedef struct Cliente {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    struct Producto *Productos; //El tamaño de este arreglo depende de la variable
    // “CantidadProductosAPedir”
}Cliente;



int lengthChar(char *c);
char * getNombreAleatorio();
Producto cargarProducto(int itera);
Producto *cargarProductos(int n);
Cliente cargarCliente(int itera);
Cliente *cargarClientes(int n);
void mostrarProducto(Producto p);
void mostrarProductos(Producto *productos, int n);
void mostrarCliente(Cliente c);
void mostrarClientes(Cliente *c);
void liberarMemoria(Cliente *c);

int main() {

    srand(time(NULL));
    int n;

    printf("Ingrese la cantidad de clientes: ");
    scanf("%d", &n);

    Cliente *c = cargarClientes(n);

    mostrarClientes(c);
    liberarMemoria(c);
    
    
    return 0;
}

int lengthChar(char *c) {

    int length = 0;

    while(*c!='\0') {
        length++;
        c++;
    }
    
    return length;
}

char * getNombreAleatorio() {

    char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
    char *nombre;
    int posAleatoria = rand() % MaxTiposProductos;

    if(posAleatoria == 5) { //no se por que a veces sale el 5 -.-
        posAleatoria = 4; //solucionado :)
    }

    int length = lengthChar(&TiposProductos[posAleatoria][0]);
    length = length + 1;//una posicion mas para guardar el nulo
    nombre = malloc(sizeof(char) * length);

    
    for(int i = 0; i<length; i++) {
        nombre[i] = TiposProductos[posAleatoria][i];
    }
    
    return nombre;   
}

Producto cargarProducto(int itera) {


    Producto p;
    p.ProductoID = itera + 1;
    p.Cantidad = rand() % 10 + 1;
    p.PrecioUnitario = rand() % 90 + 10;

    p.TipoProducto = getNombreAleatorio();
    
    return p;
}

Producto *cargarProductos(int n) {

    Producto *p = malloc(sizeof(Producto)*n);

    for(int i = 0; i<n; i++) {
        p[i] = cargarProducto(i);
    }

    return p;
}

Cliente cargarCliente(int itera) {

    char *buff = malloc(sizeof(char)*maxCadena);
    
    Cliente c;

    c.ClienteID = itera+1;
    c.CantidadProductosAPedir = rand() % 5 + 1;
    getchar();
    
    printf("Ingrese nombre del cliente - %d: ", c.ClienteID);

    gets(buff);

    c.NombreCliente = malloc(sizeof(char)*strlen(buff));
    strcpy(c.NombreCliente, buff);
    
    c.Productos = cargarProductos(c.CantidadProductosAPedir);


    return c;
}

Cliente *cargarClientes(int n) {

    if(n>maxClientes) {
        printf("Puede ingresar hasta 5 clientes\n");
        return NULL;
    }

    Cliente *c = malloc(sizeof(Cliente)*n);

    for(int i = 0; i<n; i++) {
        c[i] = cargarCliente(i);
    }

    return c;
}

void mostrarProducto(Producto p) {

    printf("ProductoID: %d\n", p.ProductoID);
    printf("Cantidad: %d\n", p.Cantidad);
    printf("TipoProducto: %s\n", p.TipoProducto);
    printf("PrecioUnitario: %.2f\n", p.PrecioUnitario);
}

void mostrarProductos(Producto *productos, int n) {

    for(int i = 0; i<n; i++) {
        mostrarProducto(productos[i]);
        printf("\n");
    }
}   

void mostrarCliente(Cliente c) {

    printf("ClienteID: %d\n", c.ClienteID);
    printf("NombreCliente: %s\n", c.NombreCliente);
    printf("CantidadProductosAPedir: %d\n", c.CantidadProductosAPedir);
}

void mostrarClientes(Cliente *c) {

    if(c == NULL) {
        printf("No hay clientes para mostrar\n");
        return;
    }

    printf("\n\n");

    for(int i = 0; i<maxClientes; i++) {
        printf("--------- Cliente %d: ---------\n", i+1);
        mostrarCliente(c[i]);
        printf("--------- Productos ---------\n");
        mostrarProductos(c[i].Productos, c[i].CantidadProductosAPedir);
        printf("\n\n");
    }
}

void liberarMemoria(Cliente *c) {

    if(c == NULL) {
        printf("Error al liberar memoria\n");
        return;
    }

    for(int i = 0; i<maxClientes; i++) {
        
        free(c[i].NombreCliente);

        for(int j = 0; j<c[i].CantidadProductosAPedir; j++) {

            free(c[i].Productos[j].TipoProducto);
        }

        free(c[i].Productos);
    }

    free(c);
}