typedef struct
{
    int file;
    char name[51];
    char lastName[51];
    char gender[51];
    char telefono[21];
    char email[71];
    eFecha fechaSocios;
    int isEmpty;
} eSocios;

int initSocios(eSocios list[], int len);
int findEmpty(eSocios list[],int len);
int findSocio(eSocios list[],int len, int file);
void viewSocio(eSocios aSocios);
void viewSocios(eSocios list[], int len);
int addSocios(eSocios list[], int len);
int removeSocio(eSocios* list, int len);
int funcion_opciones();
int funcion_opcionesModificacion();
void modifySocio(eSocios list[], int len);

