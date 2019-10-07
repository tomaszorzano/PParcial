#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#include "Autores.h"
#include "Libros.h"
#include "Fecha.h"
#include "Socios.h"
#include "Prestamos.h"

int initPrestamos(ePrestamos list[], int len)
{
    int ret = 0;

    if(list != NULL && len > 0)
    {

        for(int i=0; i < len; i++)
        {

            list[i].isEmpty = 1;
        }
    }
    else
    {
        ret = -1;
    }

    return ret;

};

int searchEmptyPrestamo(ePrestamos list[],int len)
{
    int index = -1;
    for(int i=1; i<len ; i++)
    {
        if( list[i].isEmpty == 1)
        {
            index = i ;
            break;
        }
    }
    return index ;
};

int addPrestamo(eSocios listSocios[],int tamSoc,eLibro listLibros[],int tamLibro,ePrestamos listPrest[],int tamPrest,eAutor listAut[],int tamAuto)
{
    int ret,index,indexLibros,indexSocios;
    ePrestamos newPrestamo;
    char auxLibro[3];
    char auxSocioCod[4];
    char anio[5];
    char mes[5];
    char dia[5];


    if(listPrest != NULL && tamPrest > 0)
    {
        system("cls");
        fflush(stdin);
        index = searchEmptyPrestamo(listPrest,tamPrest);
        printf("\t\t***ALTA DE PRESTAMO***");
        if(index == -1)
        {
            printf("\nNo hay lugar en el sistema. \n") ;
            ret = -1 ;
            system("pause");

        }
        else
        {


            printf("\nNuevo prestamo, CODIGO numero %d. \n\n",index) ;


            do
            {
                printf("\nSeleccionar el libro correspondiente:\n");
                viewLibros(listLibros,tamLibro,listAut,tamAuto);
                while(!funcion_getStringNumeros("\n\nIngrese el numero de codigo del libro: ",auxLibro))
                {
                    printf("Error el codigo debe tener solo numeros.\n\n");
                    system("pause");
                }
                indexLibros = findLibroById(listLibros,tamLibro,atoi(auxLibro));
                if(indexLibros == -1)
                {
                    printf("\n***ERROR*** El codigo del libro es incorrecto");
                }
                else
                {
                    system("cls");
                    printf("\n\nEl libro seleccionado es:\n");
                    printf("\nCODIGO\tTITULO          APELLIDO    NOMBRE\n");
                    printf("      \t                DEL AUTOR   DEL AUTOR\n\n");
                    viewLibro(listLibros[indexLibros],listAut,tamAuto);
                }

            }
            while(indexLibros == -1);


            printf("\nSeleccionar socio:\n");
            viewSocios(listSocios,tamSoc);
            do
            {
                while(!funcion_getStringNumeros("\nIngrese el numero de codigo del socio/a: ",auxSocioCod))
                {
                    printf("\nError el codigo debe tener solo numeros.\n\n");
                    system("pause");
                }
                indexSocios = findSocio(listSocios,tamSoc,atoi(auxSocioCod));
                if(indexSocios == -1)
                {
                    printf("\n***ERROR*** Codigo incorrecto\n");
                    system("pause");
                }
                else
                {
                    printf("\nEl socio seleccionado es:\n");
                    viewSocio(listSocios[indexSocios]);
                }

            }
            while(indexSocios == -1);

            printf("****** Fecha de Prestamo ******\n\n");
                       while(!funcion_getStringNumeros("Ingrese dia: ", dia))
                        {
                            printf("ERROR- EL DIA TIENE QUE CONTENER SOLO NUMEROS \n\n");
                            system("pause");
                            system("cls");

                        };
                        while(!funcion_getStringNumeros("Ingrese mes: ", mes))
                        {
                            printf("ERROR- EL MES TIENE QUE CONTENER SOLO NUMEROS \n\n");
                            system("pause");
                            system("cls");

                        };
                        while(!funcion_getStringNumeros("Ingrese anio: ", anio))
                        {
                            printf("ERROR- EL ANIO TIENE QUE CONTENER SOLO NUMEROS \n\n");
                            system("pause");
                            system("cls");
                        };


            newPrestamo.codigoPrestamo = index;
            newPrestamo.prestamoLibro = listLibros[indexLibros];
            newPrestamo.prestamoSocio = listSocios[indexSocios];
            newPrestamo.fechaPrestamo.dia = atoi(dia);
            newPrestamo.fechaPrestamo.mes = atoi(mes);
            newPrestamo.fechaPrestamo.anio = atoi(anio);
            newPrestamo.isEmpty = 0;
            listPrest[index] = newPrestamo;
            system("cls");
            mostrarPrestamo(listPrest[index],tamPrest,listLibros,tamLibro,listSocios,tamSoc);
            printf("\n\n");


        }
    }
    else
    {
        ret = -1 ;
    }
    return ret;
};

void mostrarPrestamo(ePrestamos listPrest,int lenPrest,eLibro listLibros[],int lenLibros,eSocios listSocios[],int lenSocios)
{
    int indexLibro,indexSocio;

    printf("\t\t-PRESTAMO-\n\nCodigo del prestamo: %d\nFecha del prestamo: %d/%d/%d\n\n",listPrest.codigoPrestamo,listPrest.fechaPrestamo.dia,listPrest.fechaPrestamo.mes,listPrest.fechaPrestamo.anio);

    indexLibro = findLibroById(listLibros,lenLibros,listPrest.prestamoLibro.codigoLibro);
    printf("\t\t Libro \nTitulo: %s\nAutor: %s %s\n\n",listLibros[indexLibro].titulo,listLibros[indexLibro].codigoAutor.apellido,listLibros[indexLibro].codigoAutor.name);

    indexSocio = findSocio(listSocios,lenSocios,listPrest.prestamoSocio.file);
    printf("\t\t Socio \nApellido y nombre: %s %s\nCodigo de socio: %d",listSocios[indexSocio].lastName,listSocios[indexSocio].name,listSocios[indexSocio].file);

};
void mostrarPrestamos(ePrestamos listPrest[],int lenPrest,eLibro listLibros[],int lenLibros,eSocios listSocios[],int lenSocios)
{

    for(int i = 0; i < lenPrest; i++)
    {

        if(listPrest[i].isEmpty == 0)
        {
            printf("_________________________________________\n\n");
            mostrarPrestamo(listPrest[i],lenPrest,listLibros,lenLibros,listSocios,lenSocios);
            printf("\n");
        }
    }

};

int menuPrestamos()
{
    char auxOption[2];
    int option;
    system("cls") ;
    printf("\n\t\t*** MENU PRESTAMOS ***\n\n");
    printf("1-ALTAS \n");
    printf("2-LISTAR \n\n") ;
    printf("3-VOLVER AL MENU PRINCIPAL\n\n") ;
    while(!funcion_getStringNumeros("Ingresar opcion: ",auxOption))
    {
        printf("\n*** ERROR *** Debe ingresar un numero del 1 al 3. \n") ;
        system("pause") ;

    }
    option = atoi(auxOption) ;
    return option;
}


/*void hardcodeoPrestamos(ePrestamos* list)
{
    ePrestamos nuevosPrestamos[] =
    {
        {1,{1,"Volar       ",{1,"Neruda  ","Pablo",0},0},{4,"Joaquin","Nuñez","Masculino",1136823123,"joaconunez@gmail.com",{16,04,2019},0},{07,05,2019},0},
        {2,{3,"Biografia   ",{3,"Lombardo","Mauro",0},0},{2,"Palermo","Martin","Masculino",1135849813,"martin9@gmail.com",{12,12,2012},0},{01,05,2019},0},
        {3,{3,"Biografia   ",{3,"Lombardo","Mauro",0},0},{5,"Rosa","Duki","Femenino",1112345896,"rositaduko@gmail.com",{02,07,2019},0},{28,04,2019},0},
        {4,{2,"Saltar      ",{4,"Krupo   ","Matias",0},0},{4,"Joaquin","Nuñez","Masculino",1136823123,"joaconunez@gmail.com",{16,04,2019},0},{02,05,2018},0},
        {5,{5,"Trap        ",{2,"Ysy     ","Alejo",0},0},{2,"Palermo","Martin","Masculino",1135849813,"martin9@gmail.com",{12,12,2012},0},{10,10,2010},0},
    };
    for(int i = 0; i< 5; i++)
    {
        list[i] = nuevosPrestamos[i];
    }
}*/
