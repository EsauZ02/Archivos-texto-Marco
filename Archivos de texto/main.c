/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 


void Nuevo();
void EscribirN();
void Agregar();
void Leer();

 

FILE*archivo;

 

int main() {
    int numero=0;
    while(numero!=5){
        opciones:
        printf("¿Que es lo que desea relizar?\n");
        printf("1. Creacion de archivo\n");
        printf("2. Escritura en archivo nuevo\n");
        printf("3. Escritura al final en archivo existente\n");
        printf("4. Lectura de archivo\n");
        printf("5. Salir\n");
        scanf("%d",&numero);
        
        if((numero<=0) || (numero>5)){
            printf("Esta no es una opción valida\n\n");
            goto opciones;
        }
        
        switch(numero){
            case 1: Nuevo(); break;
            case 2: EscribirN(); break;
            case 3: Agregar(); break;
            case 4: Leer(); break;
        }
    }
    return 0;
}

 


void Nuevo(){
    archivo=fopen("texto.txt","w");
    if(archivo==NULL){
        printf("Hubo un problema al crear su archivo\n");
    }else{
        printf("Su archivo se ha creado con éxito\n");
    }
    fclose(archivo);
}

 


void EscribirN(){
    char letra;
    archivo=fopen("texto.txt","w");
    if(archivo==NULL){
        printf("\nHubo un problema al abrir su archivo\n");
    }else{
        printf("\nEscriba lo que desea escribir\n");
        printf("Para indicar que ya acabó de escribir, ponga un punto \".\"\n");
        scanf("%c",&letra);
        while(letra!= '.'){
            scanf("%c",&letra);
            fprintf(archivo,"%c",letra);
        }
    }
    fclose(archivo);
}

 


void Agregar(){
    char letra;
    archivo=fopen("texto.txt","a");
    if(archivo==NULL){
        printf("\nHubo un problema al abrir su archivo\n");
    }else{
        printf("\nEscriba lo que desea escribir\n");
        printf("Para indicar que ya acabó de escribir, ponga un punto al final de su texto\".\"\n\n");
        fprintf(archivo," ");
        scanf("%c",&letra);
        while(letra!= '.'){
            scanf("%c",&letra);
            fprintf(archivo,"%c",letra);
        }
    }
    fclose(archivo);
}

 

void Leer(){
    char letra;
    archivo=fopen("texto.txt","r");
    if(archivo==NULL){
        printf("\nHubo un error al abrir el archivo\n");
    }else{
        printf("\n");
        while((letra=fgetc(archivo))!=EOF){
            printf("%c", letra); 
        }
        printf("\n\n");
    }
    fclose(archivo);
}