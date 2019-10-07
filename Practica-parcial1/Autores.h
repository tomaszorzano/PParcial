typedef struct
{
    int codigoAutor;
    char name[31];
    char apellido[31];
    int isEmpty;

} eAutor;

void harcodeoAutores(eAutor* list);
void viewAutor(eAutor aAutor);
void viewAutores(eAutor list[], int len);
int obtenerAutor(eAutor list[], int len, int codigoAutor, char apellido[],char nombre[]);
