#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Autores.h"
#include "funciones.h"


void harcodeoAutores(eAutor* list)
{

    eAutor x[]={
    {001,"Ariel        ","Holan   ",0},
    {002,"Diego Armando","Maradona",0},
    {003,"Lionel       ","Messi   ",0},
    {004,"Sergio       ","Aguero  ",0},
    {005,"Ricardo      ","Bochini ",0},
    };
    for(int i = 0; i< 5;i++)
    {
        list[i] = x[i];
    }
};

void viewAutor(eAutor aAutor)
{
    printf(" \nCodigo:%d- Nombre:%s- Apellido:%s\n ",aAutor.codigoAutor,aAutor.name,aAutor.apellido);
};

void viewAutores(eAutor list[], int len)
{

    system("cls");

    for(int i=0; i < len; i++)
    {

        if( list[i].isEmpty == 0)
        {
            viewAutor(list[i]);
        }
    }

};

int obtenerAutor(eAutor list[], int len, int codigoAutor, char apellido[],char nombre[])
{

    int ret = 0;

    for(int i=0; i < len; i++)    {

        if(codigoAutor == list[i].codigoAutor)
        {

            strcpy(apellido, list[i].apellido);
            strcpy(nombre, list[i].name);
            ret = 1;
            break;
        }
    }

    return ret;
}
