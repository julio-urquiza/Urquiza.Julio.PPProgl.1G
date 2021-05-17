#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
1.Crear una función llamada aplicarDescuento que reciba como parámetro el
precio de un producto y devuelva el valor del producto con un descuento
del 5%. Realizar la llamada desde el main. *

2. Crear una función que se llame contarCaracteres que reciba una cadena
de caracteres como primer parámetro y un carácter como segundo y devuelva
la cantidad de veces que ese carácter aparece en la cadena *

3. Dada la estructura Notebook(id, procesador, marca, precio) generar una
función que permita ordenar un array de dicha estructura por marca. Ante
igualdad de marca deberá ordenarse por precio. Hardcodear datos y mostrarlos desde el main. *
*/
#define TAM 10
#define TAMN 4

typedef struct{
int id;
char procesador[20];
char marca[20];
float precio;
}eNotebook;


float aplicarDescuento(float precioProducto);
int contarCaracteres(char cadena[],char caracter);
void ordenarNotebooksPorMarca(eNotebook notebook[],int tamN);

int main()
{
    //punto 1
    float precio=100;
    float nuevoPrecio;

    nuevoPrecio=aplicarDescuento(precio);
    printf("%.2f\n",nuevoPrecio);

    //punto 2
    char cadena[TAM]={"panceta"};
    int repetiones;

    repetiones=contarCaracteres(cadena,'a');
    printf("%d\n",repetiones);

    //punto 3
    eNotebook notebooks[TAMN]={
    {1,"i9","intel",50000},
    {1,"atlom","amd",70000},
    {1,"i7","intel",40000},
    {1,"ryzen 5","amd",55000}
    };

    ordenarNotebooksPorMarca(notebooks,TAMN);

    return 0;
}


float aplicarDescuento(float precioProducto)
{
    precioProducto*=1.05;
    return precioProducto;
}

int contarCaracteres(char cadena[],char caracter)
{
    int contador=0;
    for(int i=0;cadena[i]!='\0';i++)
    {
        if(cadena[i]==caracter)
        {
          contador++;
        }
    }
    return contador;
}


void ordenarNotebooksPorMarca(eNotebook notebook[],int tamN)
{
    eNotebook auxNotebook;
    for(int i=0; i<tamN-1; i++)
    {
        for(int j=i+1; j<tamN; j++)
        {
            //marcar alfaveticamente
            if((strcmp(notebook[i].marca,notebook[j].marca)>0) ||
               ((strcmp(notebook[i].marca,notebook[j].marca)==0) && notebook[i].precio>notebook[j].precio ))
            {
                auxNotebook=notebook[i];
                notebook[i]=notebook[j];
                notebook[j]=auxNotebook;
            }
        }
    }
}
