#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#include "Autores.h"
#include "Libros.h"


void viewLibro(eLibro list,eAutor listAutor[],int lenAutor)
{
    char apellido[31];
    char nombre[31];


    if(!obtenerAutor(listAutor,5,list.codigoAutor.codigoAutor,apellido,nombre))
    {
        strcpy(apellido,"Sin definir");
        strcpy(nombre,"Sin definir");
    }

    printf("\n%d\t%s\t%s\t%s\n",list.codigoLibro,list.titulo,apellido,nombre);

}

void viewLibros(eLibro list[],int len,eAutor listAutor[],int lenAutor)
{
    printf("\n\nCODIGO\tTITULO          APELLIDO    NOMBRE\n");
    printf("      \t                DEL AUTOR   DEL AUTOR\n\n");

    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            viewLibro(list[i],listAutor,lenAutor);
        }
    }
}


void hardcodeoLibros(eLibro* list)
{
    eLibro nuevosLibros[] =
    {
        {1,"Sudamericana 2017 ",{001,"Ariel        ","Holan   ",0},0},
        {2,"Premier Ligue 2018",{004,"Sergio       ","Aguero  ",0},0},
        {3,"Champions Ligue   ",{003,"Lionel       ","Messi   ",0},0},
        {4,"Libertadores      ",{005,"Ricardo      ","Bochini ",0},0},
        {5,"Como ser Dios     ",{002,"Diego Armando","Maradona",0},0},

    };
    for(int i = 0; i< 5; i++)
    {
        list[i] = nuevosLibros[i];
    }
}

int findLibroById(eLibro list[], int len, int id)
{

    for(int i=0; i < len; i++)
    {

        if( list[i].codigoLibro == id)
        {
            return i;
            break;
        }
    }
    return -1;

}
