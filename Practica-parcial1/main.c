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

#define MAX 1001
#define MAXLIB 5
#define MAXAUT 5
#define MAXPRES 21
#define MAXF 1001

int main()
{

    ePrestamos prestamos[MAXPRES];
    eLibro libros[MAXLIB];
    eAutor autores[MAXAUT];

    hardcodeoLibros(libros);
    harcodeoAutores(autores);


    {
        char seguir='s';
        eSocios socios[MAX];
        initSocios(socios,MAX);
        initPrestamos(prestamos,MAXPRES);
        int flagSinAlta=0;



        do
        {

            switch (funcion_opciones())
            {
            case 1:
                addSocios(socios, MAX);
                flagSinAlta++;
                break;
            case 2:
                if (flagSinAlta == 0)
                {
                    printf("\nNO EXISTEN SOCIOS EN EL SISTEMA\n\n");
                    break;
                }
                else
                {
                    modifySocio(socios, MAX);
                };
                break;
            case 3:
                if (flagSinAlta == 0)
                {
                    printf("\nNO EXISTEN SOCIOS EN EL SISTEMA\n\n");
                    break;
                }
                else
                {
                    removeSocio(socios, MAX);
                };
                break;
            case 4:
                if (flagSinAlta == 0)
                {
                    printf("\nNO EXISTEN SOCIOS EN EL SISTEMA\n\n");
                    break;
                }
                else
                {
                    //sortemployees(employee,MAX);
                    viewSocios(socios, MAX);
                };

                break;
            case 5:
                if (flagSinAlta == 0)
                {
                    printf("\nNO EXISTEN SOCIOS EN EL SISTEMA\n\n");
                    break;
                }
                else
                {
                    viewAutores(autores,MAXAUT);
                    fflush(stdin);

                    system("cls");
                    viewLibros(libros,MAXLIB,autores,MAXAUT);

                    addPrestamo(socios,MAX,libros,MAXLIB,prestamos,MAXPRES,autores,MAXAUT);

                    //viewLunchs(almuerzo,MAXALM,employee,employee[index].file);
                };

                break;
            case 6:
                printf("Saliendo...");
                exit(-1);
                break;
            default:
                printf("\n\nOpcion ingresada incorrecta, por favor ingrese una opcion del 1 al 5\n\n");
                system("pause");
                break;

            }
            printf("\n Desea continuar? si/no \n\n");
            scanf("%c",&seguir);

            fflush(stdin);
            system("cls");


        }
        while (seguir == 's' || seguir == 'S');

        printf("\n\n Saliendo...\n\n");

    }
    return 0;
}
