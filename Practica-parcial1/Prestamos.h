
typedef struct
{
    int codigoPrestamo;
    eLibro prestamoLibro;
    eSocios prestamoSocio;
    eFecha fechaPrestamo;
    int isEmpty;

} ePrestamos;

int initPrestamos(ePrestamos list[], int len);
int searchEmptyPrestamo(ePrestamos list[],int len);
int addPrestamo(eSocios listSocios[],int tamSoc,eLibro listLibros[],int tamLibro,ePrestamos listPrest[],int tamPrest,eAutor listAut[],int tamAuto);
void mostrarPrestamo(ePrestamos listPrest,int lenPrest,eLibro listLibros[],int lenLibros,eSocios listSocios[],int lenSocios);
void mostrarPrestamos(ePrestamos listPrest[],int lenPrest,eLibro listLibros[],int lenLibros,eSocios listSocios[],int lenSocios);
int menuPrestamos();
//void hardcodeoPrestamos(ePrestamos* list);
