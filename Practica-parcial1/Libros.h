typedef struct
{
    int codigoLibro;
    char titulo[31];
    eAutor codigoAutor;
    int isEmpty;

} eLibro;

void viewLibro(eLibro list,eAutor listAutor[],int lenAutor);
void viewLibros(eLibro list[],int len,eAutor listAutor[],int lenAutor);
void hardcodeoLibros(eLibro* list);
int findLibroById(eLibro list[], int len, int id);
