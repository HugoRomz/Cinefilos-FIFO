#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <time.h>

// variables
int opcionMenu;
char opcionfifo[1];
int fd;

// variables Pelicula
int stockP;
int precioP;
int id_local;

char tituloP[60], directorP[60];
char data[1000];
// reportes
void menuReporte();
void sociosSinRentas();

// apartado de pelicula
void menuPelicula();
void insertarPeliculas();
void MostrarPeliculas();
void consultarPelicula();
void actualizarPelicula();
void bajaPelicula();
// genero
void insertarGenero();
void buscarGenero();
void consultarGenero();
void actualizarGenero();
void bajaGenero();
// apartado de socio
void insertarSocio();
void menuSocio();
int buscarSocio();
void EliminarSocio();
void actualizarSocio();
void consultarSocio();
// renta
void menuRenta();
void altaRenta();
void devolverRenta();
void mostrarRentas();

// clock_t begin,end;
int main()
{

    // begin = time(NULL);
    mkfifo("MIFIFO", 0666);

    do
    {
        printf("\t===========================================\n");
        printf("\t|             °°° CINEFILOS °°°           |\n");
        printf("\t===========================================\n");
        printf("\t|                BIENVENIDOS              |\n");
        printf("\t===========================================\n");
        printf("\t|             SOCIO:  'Mensual'           |\n");
        printf("\t===========================================\n");
        printf("\t|    1.- Rentas.     |   2.- Peliculas.   |\n");
        printf("\t|    3.- Socio.      |   4.- Reportes.    |\n");
        printf("\t|-----------------------------------------|\n");
        printf("\t|               5.- Salir.                |\n");
        printf("\t===========================================\n");
        printf("\tElige tu Opcion: ");
        scanf("\t%d", &opcionMenu);
        printf("\t|-----------------------------------------|\n");

        fd = open("MIFIFO", O_WRONLY);
        sprintf(opcionfifo, "%d", opcionMenu);
        write(fd, opcionfifo, sizeof(opcionfifo));
        close(fd);
        switch (opcionMenu)
        {
        case 1:
            menuRenta();
            break;
        case 2:
            menuPelicula();
            break;
        case 3:
            menuSocio();
            break;
        case 4:
            menuReporte();
            break;
        }

    } while (opcionMenu != 5);
    system("clear");
    printf("\t========================================\n");
    printf("\t|   Disfruta de tu pelicula favorita   |\n");
    printf("\t|--------------------------------------|\n");
    printf("\t|           ¡Vuelve Pronto!            |\n");
    printf("\t========================================\n");
    return 0;
}
void menuPelicula()
{
    do
    {
        printf("\t============================================\n");
        printf("\t|             °°° CINEFILOS °°°            |\n");
        printf("\t============================================\n");
        printf("\t|    1.  Peliculas.   |   2.  Generos.     |\n");
        printf("\t|------------------------------------------|\n");
        printf("\t|               3.- Regresar.              |\n");
        printf("\t============================================\n");
        printf("\tElige tu Opcion: ");
        scanf("\t%d", &opcionMenu);
        printf("\t--------------------------------------------\n");

        fd = open("MIFIFO", O_WRONLY);
        sprintf(opcionfifo, "%d", opcionMenu);
        write(fd, opcionfifo, sizeof(opcionfifo));
        close(fd);

        switch (opcionMenu)
        {
        case 1:
            do
            {

                printf("\t============================================\n");
                printf("\t|              ** PELICULAS **             |\n");
                printf("\t============================================\n");
                printf("\t|               1.  Mostrar                |\n");
                printf("\t|     2.  Insertar.        3.  Buscar.     |\n");
                printf("\t|     4.  Editar.          5.  Eliminar.   |\n");
                printf("\t|------------------------------------------|\n");
                printf("\t|              6.- Regresar.               |\n");
                printf("\t============================================\n");
                printf("\tElige tu Opcion: ");
                scanf("\t%d", &opcionMenu);
                printf("\t--------------------------------------------\n");

                fd = open("MIFIFO", O_WRONLY);
                sprintf(opcionfifo, "%d", opcionMenu);
                write(fd, opcionfifo, sizeof(opcionfifo));
                close(fd);

                switch (opcionMenu)
                {
                    // MOSTRAR
                case 1:
                    MostrarPeliculas();
                    break;

                    // INSERTAR
                case 2:
                    insertarPeliculas();
                    break;
                    // BUSCAR
                case 3:
                    consultarPelicula();
                    break;
                    // EDITAR
                case 4:
                    actualizarPelicula();
                    break;
                    // ELIMINAR
                case 5:
                    bajaPelicula();
                    break;
                }

            } while (opcionMenu != 6);
            break;

        case 2:
            do
            {

                printf("\t============================================\n");
                printf("\t|              **  GENEROS  **             |\n");
                printf("\t============================================\n");
                printf("\t|               1.  Mostrar                |\n");
                printf("\t|     2.  Insertar.        3.  Buscar.     |\n");
                printf("\t|     4.  Editar.          5.  Eliminar.   |\n");
                printf("\t|------------------------------------------|\n");
                printf("\t|              6.- Regresar.               |\n");
                printf("\t============================================\n");
                printf("\tElige tu Opcion: ");
                scanf("\t%d", &opcionMenu);
                printf("\t--------------------------------------------\n");

                fd = open("MIFIFO", O_WRONLY);
                sprintf(opcionfifo, "%d", opcionMenu);
                write(fd, opcionfifo, sizeof(opcionfifo));
                close(fd);

                switch (opcionMenu)
                {
                    // MOSTRAR
                case 1:
                    buscarGenero();
                    break;
                    // INSERTAR
                case 2:
                    insertarGenero();
                    break;
                    // BUSCAR
                case 3:
                    consultarGenero();
                    break;
                    // EDITAR
                case 4:
                    actualizarGenero();
                    break;
                    // ELIMINAR
                case 5:
                    bajaGenero();
                    break;
                }

            } while (opcionMenu != 6);
            break;
        }
    } while (opcionMenu != 3);
}
void menuSocio()
{
    do
    {
        printf("\t============================================\n");
        printf("\t|              ** SOCIO **                 |\n");
        printf("\t============================================\n");
        printf("\t|               1.  Mostrar                |\n");
        printf("\t|     2.  Insertar.        3.  Buscar.     |\n");
        printf("\t|     4.  Editar.          5.  Eliminar.   |\n");
        printf("\t|------------------------------------------|\n");
        printf("\t|              6.- Regresar.               |\n");
        printf("\t============================================\n");
        printf("\tElige tu Opcion: ");
        scanf("\t%d", &opcionMenu);
        printf("\t--------------------------------------------\n");

        fd = open("MIFIFO", O_WRONLY);
        sprintf(opcionfifo, "%d", opcionMenu);
        write(fd, opcionfifo, sizeof(opcionfifo));
        close(fd);

        switch (opcionMenu)
        {
        case 1:
            // begin = clock();
            buscarSocio();
            break;
        case 2:
            insertarSocio();
            // clock_t end = clock();
            break;
        case 3:
            consultarSocio();
            break;
        case 4:
            actualizarSocio();
            // clock_t end = clock();
            break;
        case 5:
            EliminarSocio();
            // clock_t end = clock();
            break;
        }
    } while (opcionMenu != 6);
}
void menuRenta()
{
    char opSocio[50], nombres[50], telefono[100];

    printf("\t=====================================================\n");
    printf("\t|                  ** Bienvenidos **                |\n");
    printf("\t=====================================================\n");
    printf("--------------------------------------------------------------------------------- \n");
    printf("\n ¿Se encuentra registrado? si / no \n");
    scanf("\t%s", &opSocio);
    printf("--------------------------------------------------------------------------------- \n");

    int resultado = strcmp(opSocio, "si");

    if (resultado == 0)
    {

        sprintf(data, "si");
        fd = open("MIFIFO", O_WRONLY);
        write(fd, data, sizeof(data));
        close(fd);

        fflush(stdin);
        puts("Ingresa tu nombre con el que estas registrado ");
        scanf("%*c%[^\n]", nombres);
        fflush(stdin);
        puts("ingrese su numero de telefono :");
        scanf("%s", &telefono);
        fflush(stdin);
        sprintf(data, "select * from socio where nombres = '%s' and telefono = '%s';", nombres, telefono);
        fd = open("MIFIFO", O_WRONLY);
        write(fd, data, sizeof(data));
        close(fd);

        fd = open("MIFIFO", O_RDONLY);
        read(fd, data, sizeof(data));
        close(fd);

        int resultado = strcmp(data, "ok");

        if (resultado == 0)
        {

            printf("\t Comprobacion de usuario completada \n");
        }
            do
            {

                printf("\t=====================================================\n");
                printf("\t|                   ** Rentas **                    |\n");
                printf("\t=====================================================\n");
                printf("\t|                      1.  Alta                     |\n");
                printf("\t|     2.  Devolver pelicula.        3.  Mostrar.    |\n");
                printf("\t|     4.  Editar.                   5.  Buscar.     |\n");
                printf("\t|---------------------------------------------------|\n");
                printf("\t|                    6.- Regresar.                  |\n");
                printf("\t=====================================================\n");
                printf("\tElige tu Opcion: ");
                scanf("\t%d", &opcionMenu);
                printf("\t--------------------------------------------\n");

                fd = open("MIFIFO", O_WRONLY);
                sprintf(opcionfifo, "%d", opcionMenu);
                write(fd, opcionfifo, sizeof(opcionfifo));
                close(fd);

                switch (opcionMenu)
                {
                case 1:
                    // begin = clock();
                    printf("renta Alta\n");
                    break;
                case 2:
                    printf("renta Devolver\n");
                    // clock_t end = clock();
                    break;
                case 3:
                    printf("renta Mostrar\n");
                    break;
                case 4:
                    printf("renta Editar\n");
                    // clock_t end = clock();
                    break;
                case 5:
                    printf("renta Buscar\n");
                    // clock_t end = clock();
                    break;
                }
            } while (opcionMenu != 6);
        
    }
    else
    {

        int resultado = strcmp(opSocio, "no");

        if (resultado == 0)
        {

            sprintf(data, "no");
            fd = open("MIFIFO", O_WRONLY);
            write(fd, data, sizeof(data));
            close(fd);
        }
        else
        {
            printf("\n Opcion no es valida o no existe \n ");
            sprintf(data, "salir");
            fd = open("MIFIFO", O_WRONLY);
            write(fd, data, sizeof(data));
            close(fd);
        }
    }
}

void altaRenta()
{
    printf("aqui deberia estar el codigo de alta renta y det_renta, pero no mas no hay no existe\n");
}
void devolverRenta()
{
    printf("aqui deberia estar el codigo de devolver renta y det_renta, pero no mas no hay no existe\n");
}
void mostrarRentas()
{
    printf("aqui deberia estar el codigo de mostrar renta y det_renta, pero no mas no hay no existe\n");
}

///
void insertarPeliculas()
{
    char fil[1000], col[1000], cad[1000];
    int id_local;
    fflush(stdin);
    puts("Titulo de la pelicula :");
    scanf("%*c%[^\n]", tituloP);
    fflush(stdin);
    puts("Nombre del Director :");
    fflush(stdin);
    scanf("%*c%[^\n]", directorP);
    puts("Cantidad en Almacen :");
    scanf("%d", &stockP);
    puts("Precio de Renta :");
    scanf("%d", &precioP);
    printf("\n--------------------------------------------------------------------------------- \n");

    sprintf(data, "select * from local");
    fd = open("MIFIFO", O_WRONLY);
    write(fd, data, sizeof(data));
    close(fd);

    int fd2 = open("MIFIFO", O_RDONLY);
    read(fd2, fil, sizeof(fil));
    read(fd2, col, sizeof(col));

    int filas = atoi(fil);
    int columnas = atoi(col);

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            read(fd2, cad, sizeof(cad));
            printf("%s\t|   ", cad);
        }
        printf("\n");
        printf("--------------------------------------------------------------------------------- \n");
    }
    close(fd2);

    puts("Ingresa el id del local :");
    scanf("%d", &id_local);

    sprintf(data, "INSERT INTO pelicula(titulo, director, stock, precio, id_local, status) VALUES ('%s','%s',%d,%d,%d,1)", tituloP, directorP, stockP, precioP, id_local);
    fd = open("MIFIFO", O_WRONLY);
    write(fd, data, sizeof(data));
    close(fd);
    //    end = time(NULL);
    //     // calcular el tiempo transcurrido encontrando la diferencia (end - begin)
    //     printf("Tiempo de conexecion de ejecucion del cliente : %d seconds", (end - begin));
}
void MostrarPeliculas()
{

    char fil[100], col[100], cad[1000];
    int fd2 = open("MIFIFO", O_RDONLY);
    read(fd2, fil, sizeof(fil));
    read(fd2, col, sizeof(col));

    int filas = atoi(fil);
    int columnas = atoi(col);

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            read(fd2, cad, sizeof(cad));
            printf("%-5s\t|   ", cad);
        }
        printf("\n");
        printf("--------------------------------------------------------------------------------- \n");
    }
    // close(fd);
    close(fd2);
}
void consultarPelicula()
{
    char fil[1000], col[1000], cad[1000], nombre[200];
    printf("--------------------------------------------------------------------------------- \n");
    printf("Ingresando a la opcion de buscar en una tabla \n");

    printf("--------------------------------------------------------------------------------- \n");
    printf("\n Ingresa el titulo de la pelicula que quieras buscar: ");
    scanf("%*c%[^\n]", nombre);
    printf("--------------------------------------------------------------------------------- \n");
    sprintf(data, "select * from pelicula where titulo = '%s'", nombre);
    fd = open("MIFIFO", O_WRONLY);
    write(fd, data, sizeof(data));
    close(fd);
    int fd2 = open("MIFIFO", O_RDONLY);
    read(fd2, fil, sizeof(fil));
    read(fd2, col, sizeof(col));

    int filas = atoi(fil);
    int columnas = atoi(col);

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            read(fd2, cad, sizeof(cad));
            printf("%s\t|   ", cad);
        }
        printf("\n");
        printf("--------------------------------------------------------------------------------- \n");
    }

    close(fd2);
}

void actualizarPelicula()
{
    int id_pelicula, Ndato;
    float Ndatof;
    char atributo[200], NdatoC[200];

    MostrarPeliculas();
    printf("--------------------------------------------------------------------------------- \n");
    printf("\n Ingresando a la opcion de actualizar datos de las peliculas \n");
    printf("--------------------------------------------------------------------------------- \n");
    printf("\n Ingresa el ID del dato que quieras actualizar: ");
    scanf("%d", &id_pelicula);

    printf("\t====================  ATRIBUTOS  ==========================\n");
    printf("\t|                       1. titulo                       |\n");
    printf("\t|     2. director                      3. precio        |\n");
    printf("\t|                       4. stock                        |\n");
    printf("\t===========================================================\n");
    printf("--------------------------------------------------------------------------------- \n");
    printf("\n Ingresa el atributo que desees actualizar: ");
    scanf("%s", &atributo);

    printf("--------------------------------------------------------------------------------- \n");

    int resultado2 = strcmp(atributo, "stock");

    if (resultado2 == 0)
    {

        printf("--------------------------------------------------------------------------------- \n");

        printf("\n Ingresa el nuevo dato del atributo %s: ", atributo);
        scanf("%d", &Ndato);

        printf("--------------------------------------------------------------------------------- \n");

        sprintf(data, "update pelicula set %s = %d where id_pelicula = %d ", atributo, Ndato, id_pelicula);
        fd = open("MIFIFO", O_WRONLY);
        write(fd, data, sizeof(data));
        close(fd);
        // end = time(NULL);
        // // calcular el tiempo transcurrido encontrando la diferencia (end - begin)
        // printf("Tiempo de conexion de ejecucion del cliente : %d seconds", (end - begin));
    }
    else
    {

        int resultado3 = strcmp(atributo, "precio");

        if (resultado3 == 0)
        {

            printf("--------------------------------------------------------------------------------- \n");

            printf("\n Ingresa el nuevo dato del atributo %s: ", atributo);
            scanf("%f", &Ndatof);

            printf("--------------------------------------------------------------------------------- \n");

            sprintf(data, "update pelicula set %s = %.2f where id_pelicula = %d ", atributo, Ndatof, id_pelicula);
            fd = open("MIFIFO", O_WRONLY);
            write(fd, data, sizeof(data));
            close(fd);
        }
        else
        {

            printf("--------------------------------------------------------------------------------- \n");

            fflush(stdin);
            printf("\n Ingresa el nuevo dato del atributo %s: ", atributo);
            scanf("%*c%[^\n]", NdatoC);
            fflush(stdin);

            printf("--------------------------------------------------------------------------------- \n");

            sprintf(data, "update pelicula set %s = '%s' where id_pelicula = %d ", atributo, NdatoC, id_pelicula);
            fd = open("MIFIFO", O_WRONLY);
            write(fd, data, sizeof(data));
            close(fd);
            // end = time(NULL);
            // // calcular el tiempo transcurrido encontrando la diferencia (end - begin)
            // printf("Tiempo de conexecion de ejecucion del cliente : %d seconds", (end - begin));
        }
    }
}

void bajaPelicula()
{
    int id_pelicula;
    char opcion[50];
    char fil[1000], col[1000], cad[1000];

    printf("\t========================  OPCIONES  ======================\n");
    printf("\t|            habilitar                deshabilitar       |\n");
    printf("\t==========================================================\n");
    printf("--------------------------------------------------------------------------------- \n");
    printf("\n Ingresa la opcion que desees realizar: ");
    scanf("%s", &opcion);
    printf("--------------------------------------------------------------------------------- \n");

    int resultado2 = strcmp(opcion, "habilitar");

    if (resultado2 == 0)
    {

        sprintf(data, "select * from pelicula where status = 0;");
        fd = open("MIFIFO", O_WRONLY);
        write(fd, data, sizeof(data));
        close(fd);

        int fd2 = open("MIFIFO", O_RDONLY);
        read(fd2, fil, sizeof(fil));
        read(fd2, col, sizeof(col));

        int filas = atoi(fil);
        int columnas = atoi(col);

        for (int i = 0; i < filas; i++)
        {
            for (int j = 0; j < columnas; j++)
            {
                read(fd2, cad, sizeof(cad));
                printf("%s\t|   ", cad);
            }
            printf("\n");
            printf("--------------------------------------------------------------------------------- \n");
        }
        close(fd2);

        printf("--------------------------------------------------------------------------------- \n");
        printf("\n Ingresando a la opcion de habilitar peliculas \n");
        printf("--------------------------------------------------------------------------------- \n");
        printf("\n Ingresa el ID de la pelicula: ");
        scanf("%d", &id_pelicula);

        sprintf(data, "update pelicula set status = 1 where id_pelicula = %d ", id_pelicula);
        fd = open("MIFIFO", O_WRONLY);
        write(fd, data, sizeof(data));
        close(fd);
    }
    else
    {

        int resultado2 = strcmp(opcion, "deshabilitar");

        if (resultado2 == 0)
        {

            sprintf(data, "select * from pelicula where status = 1;");
            fd = open("MIFIFO", O_WRONLY);
            write(fd, data, sizeof(data));
            close(fd);

            int fd2 = open("MIFIFO", O_RDONLY);
            read(fd2, fil, sizeof(fil));
            read(fd2, col, sizeof(col));

            int filas = atoi(fil);
            int columnas = atoi(col);

            for (int i = 0; i < filas; i++)
            {
                for (int j = 0; j < columnas; j++)
                {
                    read(fd2, cad, sizeof(cad));
                    printf("%s\t|   ", cad);
                }
                printf("\n");
                printf("--------------------------------------------------------------------------------- \n");
            }
            close(fd2);

            printf("--------------------------------------------------------------------------------- \n");
            printf("\n Ingresando a la opcion de deshabilitar peliculas \n");
            printf("--------------------------------------------------------------------------------- \n");
            printf("\n Ingresa el ID de la pelicula: ");
            scanf("%d", &id_pelicula);

            sprintf(data, "update pelicula set status = 0 where id_pelicula = %d ", id_pelicula);
            fd = open("MIFIFO", O_WRONLY);
            write(fd, data, sizeof(data));
            close(fd);
            // end = time(NULL);
            // // calcular el tiempo transcurrido encontrando la diferencia (end - begin)
            // printf("Tiempo de conexecion de ejecucion del cliente : %d seconds", (end - begin));
        }
        else
        {
            printf("\n Opcion no es valida o no existe \n ");
            sprintf(data, "salir");
            fd = open("MIFIFO", O_WRONLY);
            write(fd, data, sizeof(data));
            close(fd);
        }
    }
}
void insertarSocio()
{
    char nombres[50], apellidos[50], curp[50], direccion[100], tipo[50], telefono[100];
    fflush(stdin);
    puts("ingrese los nombres del socio :");
    scanf("%*c%[^\n]", nombres);
    fflush(stdin);
    puts("ingrese los apellidos del socio :");
    scanf("%*c%[^\n]", &apellidos);
    fflush(stdin);
    puts("ingrese la curp del socio :");
    scanf("%s", &curp);
    fflush(stdin);
    puts("ingrese el telefono del socio :");
    scanf("%s", &telefono);
    fflush(stdin);
    puts("ingrese la direccion del socio :");
    scanf("%*c%[^\n]", direccion);
    fflush(stdin);
    puts("ingrese el tipo de socio :");
    scanf("%*c%[^\n]", &tipo);
    fflush(stdin);
    sprintf(data, "insert into socio(nombres,apellidos,curp,telefono,direccion,tipo,statusm)values('%s','%s','%s','%s', '%s','%s',1);", nombres, apellidos, curp, telefono, direccion, tipo);
    fd = open("MIFIFO", O_WRONLY);
    write(fd, data, sizeof(data));
    close(fd);
    // end = time(NULL);
    // // calcular el tiempo transcurrido encontrando la diferencia (end - begin)
    // printf("Tiempo de conexecion de ejecucion del cliente : %d seconds", (end - begin));
}
int buscarSocio()
{

    char fil[100], col[100], cad[1000];
    int fd2 = open("MIFIFO", O_RDONLY);
    read(fd2, fil, sizeof(fil));
    read(fd2, col, sizeof(col));

    int filas = atoi(fil);
    int columnas = atoi(col);

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            read(fd2, cad, sizeof(cad));
            printf("%-5s\t|   ", cad);
        }
        printf("\n");
        printf("--------------------------------------------------------------------------------- \n");
    }
    // close(fd);
    close(fd2);

    return 0;
}

void EliminarSocio()
{
    int id_socio;
    char instrucc[100];
    buscarSocio();
    printf("--------------------------------------------------------------------------------- \n");
    printf("\n Ingresando a la opcion de eliminar socios \n");
    printf("--------------------------------------------------------------------------------- \n");
    printf("\n Ingresa el ID del SOCIO que se desee eliminar: ");
    scanf("%d", &id_socio);
    printf("--------------------------------------------------------------------------------- \n");
    sprintf(instrucc, "delete from socio where id_socio = %d ", id_socio);
    fd = open("MIFIFO", O_WRONLY);
    write(fd, instrucc, sizeof(instrucc));
    close(fd);
}
void actualizarSocio()
{
    int id_socio, Ndato;
    char atributo[200], NdatoC[200];
    buscarSocio();
    printf("--------------------------------------------------------------------------------- \n");
    printf("\n Ingresando a la opcion de actualizar datos del socio \n");
    printf("--------------------------------------------------------------------------------- \n");
    printf("\n Ingresa el ID del dato que quieras actualizar: ");
    scanf("%d", &id_socio);

    printf("\t====================  ATRIBUTOS  ==========================\n");
    printf("\t|                       1.  nombre                      |\n");
    printf("\t|     2.  apellidos            3.  curp.                |\n");
    printf("\t|     4.  telefono.            5.  direccion.           |\n");
    printf("\t|     6.  tipo                 7.  statusm              |\n");
    printf("\t|    ===============================================    |\n");
    printf("--------------------------------------------------------------------------------- \n");
    printf("\n Ingresa el atributo que desees actualizar: ");
    scanf("%s", &atributo);

    printf("--------------------------------------------------------------------------------- \n");

    int resultado2 = strcmp(atributo, "statusm");

    if (resultado2 == 0)
    {

        printf("--------------------------------------------------------------------------------- \n");

        printf("\n Ingresa el nuevo dato del atributo %s: ", atributo);
        scanf("%d", &Ndato);

        printf("--------------------------------------------------------------------------------- \n");

        sprintf(data, "update socio set %s = %d where id_socio = %d ", atributo, Ndato, id_socio);
        fd = open("MIFIFO", O_WRONLY);
        write(fd, data, sizeof(data));
        close(fd);
        // end = time(NULL);
        // // calcular el tiempo transcurrido encontrando la diferencia (end - begin)
        // printf("Tiempo de conexecion de ejecucion del cliente : %d seconds", (end - begin));
    }
    else
    {

        printf("--------------------------------------------------------------------------------- \n");

        printf("\n Ingresa el nuevo dato del atributo %s: ", atributo);
        scanf("%s", &NdatoC);

        printf("--------------------------------------------------------------------------------- \n");

        sprintf(data, "update socio set %s = '%s' where id_socio = %d ", atributo, NdatoC, id_socio);
        fd = open("MIFIFO", O_WRONLY);
        write(fd, data, sizeof(data));
        close(fd);
        // end = time(NULL);
        // // calcular el tiempo transcurrido encontrando la diferencia (end - begin)
        // printf("Tiempo de conexecion de ejecucion del cliente : %d seconds", (end - begin));
    }
}
void consultarSocio()
{
    char fil[1000], col[1000], cad[1000], nombre[200];
    printf("--------------------------------------------------------------------------------- \n");
    printf("Ingresando a la opcion de buscar en una tabla \n");
    printf("--------------------------------------------------------------------------------- \n");
    printf("\n Ingresa el nombre del socio que quieras buscar: ");
    scanf("%s", &nombre);
    printf("--------------------------------------------------------------------------------- \n");
    sprintf(data, "select * from socio where nombre = '%s'", nombre);
    fd = open("MIFIFO", O_WRONLY);
    write(fd, data, sizeof(data));
    close(fd);
    int fd2 = open("MIFIFO", O_RDONLY);
    read(fd2, fil, sizeof(fil));
    read(fd2, col, sizeof(col));

    int filas = atoi(fil);
    int columnas = atoi(col);

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            read(fd2, cad, sizeof(cad));
            printf("%s\t|   ", cad);
        }
        printf("\n");
        printf("--------------------------------------------------------------------------------- \n");
    }

    close(fd2);
    //     end = time(NULL);
    //     // calcular el tiempo transcurrido encontrando la diferencia (end - begin)
    //    printf("Tiempo de conexecion de ejecucion del cliente : %d seconds", (end - begin));
}

void insertarGenero()
{
    char nombre[100];
    fflush(stdin);
    puts("ingrese el nuevo tipo de genero:");
    scanf("%*c%[^\n]", nombre);
    fflush(stdin);
    sprintf(data, "insert into genero(nombreg)values('%s')", nombre);
    fd = open("MIFIFO", O_WRONLY);
    write(fd, data, sizeof(data));
    close(fd);
}
void buscarGenero()
{

    char fil[100], col[100], cad[1000];
    int fd2 = open("MIFIFO", O_RDONLY);
    read(fd2, fil, sizeof(fil));
    read(fd2, col, sizeof(col));

    int filas = atoi(fil);
    int columnas = atoi(col);

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            read(fd2, cad, sizeof(cad));
            printf("%-5s\t|   ", cad);
        }
        printf("\n");
        printf("--------------------------------------------------------------------------------- \n");
    }
    // close(fd);
    close(fd2);
}
void consultarGenero()
{
    char fil[1000], col[1000], cad[1000], nombre[200];
    printf("--------------------------------------------------------------------------------- \n");
    printf("Ingresando a la opcion de buscar en una tabla \n");

    printf("--------------------------------------------------------------------------------- \n");
    printf("\n Ingresa el nombre del genero que quieras buscar: ");
    scanf("%*c%[^\n]", nombre);
    printf("--------------------------------------------------------------------------------- \n");
    sprintf(data, "select * from genero where nombreg = '%s';", nombre);
    fd = open("MIFIFO", O_WRONLY);
    write(fd, data, sizeof(data));
    close(fd);
    int fd2 = open("MIFIFO", O_RDONLY);
    read(fd2, fil, sizeof(fil));
    read(fd2, col, sizeof(col));

    int filas = atoi(fil);
    int columnas = atoi(col);

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            read(fd2, cad, sizeof(cad));
            printf("%s\t|   ", cad);
        }
        printf("\n");
        printf("--------------------------------------------------------------------------------- \n");
    }

    close(fd2);
}

void actualizarGenero()
{
    int id_genero;
    char NdatoC[200], atributo[100];

    buscarGenero();
    printf("--------------------------------------------------------------------------------- \n");
    printf("\n Ingresando a la opcion de actualizar datos de los generos \n");
    printf("--------------------------------------------------------------------------------- \n");
    printf("\n Ingresa el ID del dato que quieras actualizar: ");
    scanf("%d", &id_genero);

    printf("\t====================  ATRIBUTOS  ==========================\n");
    printf("\t|                        nombre                           |\n");
    printf("\t===========================================================\n");
    printf("--------------------------------------------------------------------------------- \n");
    printf("\n Ingresa el atributo que desees actualizar: ");
    scanf("%s", &atributo);

    printf("--------------------------------------------------------------------------------- \n");

    int resultado2 = strcmp(atributo, "nombre");

    if (resultado2 == 0)
    {

        printf("--------------------------------------------------------------------------------- \n");

        printf("\n Ingresa el nuevo dato del atributo %s: ", atributo);
        scanf("%s", &NdatoC);

        printf("--------------------------------------------------------------------------------- \n");

        sprintf(data, "update genero set nombreg = '%s' where id_genero = %d ", NdatoC, id_genero);
        fd = open("MIFIFO", O_WRONLY);
        write(fd, data, sizeof(data));
        close(fd);
        // end = time(NULL);
        // // calcular el tiempo transcurrido encontrando la diferencia (end - begin)
        // printf("Tiempo de conexion de ejecucion del cliente : %d seconds", (end - begin));
    }
    else
    {

        printf("\n Opcion no es valida o no existe \n ");
        sprintf(data, "salir");
        fd = open("MIFIFO", O_WRONLY);
        write(fd, data, sizeof(data));
        close(fd);
    }
}

void bajaGenero()
{
    int id_genero;
    char opcion[50];
    buscarGenero();
    printf("--------------------------------------------------------------------------------- \n");
    printf("\n Ingresando a la opcion de habilitar y deshabilitar peliculas \n");
    printf("--------------------------------------------------------------------------------- \n");
    printf("\n Ingresa el ID del genero: ");
    scanf("%d", &id_genero);

    printf("\t========================  OPCIONES  ======================\n");
    printf("\t|            habilitar                deshabilitar       |\n");
    printf("\t==========================================================\n");
    printf("--------------------------------------------------------------------------------- \n");
    printf("\n Ingresa la opcion que desees realizar: ");
    scanf("%s", &opcion);
    printf("--------------------------------------------------------------------------------- \n");

    int resultado2 = strcmp(opcion, "habilitar");

    if (resultado2 == 0)
    {

        sprintf(data, "update genero set statusg = 1 where id_genero = %d ", id_genero);
        fd = open("MIFIFO", O_WRONLY);
        write(fd, data, sizeof(data));
        close(fd);
    }
    else
    {

        int resultado2 = strcmp(opcion, "deshabilitar");

        if (resultado2 == 0)
        {

            sprintf(data, "update genero set statusg = 0 where id_genero = %d ", id_genero);
            fd = open("MIFIFO", O_WRONLY);
            write(fd, data, sizeof(data));
            close(fd);
            // end = time(NULL);
            // // calcular el tiempo transcurrido encontrando la diferencia (end - begin)
            // printf("Tiempo de conexecion de ejecucion del cliente : %d seconds", (end - begin));
        }
        else
        {
            printf("\n Opcion no es valida o no existe \n ");
            sprintf(data, "salir");
            fd = open("MIFIFO", O_WRONLY);
            write(fd, data, sizeof(data));
            close(fd);
        }
    }
}

// REPORTES

void menuReporte()
{
    do
    {
        printf("\t=================================================\n");
        printf("\t|                 ** REPORTES **               |\n");
        printf("\t================================================\n");
        printf("\t|     1.  Socios que no han rentado            |\n");
        printf("\t|     2.  Peliculas de ciencis f.              |\n");
        printf("\t|     3.  Total de abonos en el mes de febrero.|\n");
        printf("\t|     4.  Socios que han rentado               |\n");
        printf("\t|     5.- Peliculas de cada genero rentadas    |\n");
        printf("\t|----------------------------------------------|\n");
        printf("\t|              6.- Regresar.               |\n");
        printf("\t============================================\n");
        printf("\tElige tu Opcion: ");
        scanf("\t%d", &opcionMenu);
        printf("\t--------------------------------------------\n");

        fd = open("MIFIFO", O_WRONLY);
        sprintf(opcionfifo, "%d", opcionMenu);
        write(fd, opcionfifo, sizeof(opcionfifo));
        close(fd);

        switch (opcionMenu)
        {
            case 1:
                // begin = clock();
                printf("\t|     1.  Socios que no han rentado            |\n");
                sociosSinRentas();
                break;
            case 2:
                printf("\t|     2.  Peliculas de ciencis f.              |\n");
                // clock_t end = clock();
                break;
            case 3:
                printf("\t|     3.  Total de abonos en el mes de febrero.|\n");
                break;
            case 4:
                printf("\t|     4.  Socios que han rentado               |\n");
                // clock_t end = clock();
                break;
            case 5:
                printf("\t|     5.- Peliculas de cada genero rentadas    |\n");
                // clock_t end = clock();
                break;
        }
    } while (opcionMenu != 6);
}

void sociosSinRentas()
{

    char fil[100], col[100], cad[1000];
    int fd2 = open("MIFIFO", O_RDONLY);
    read(fd2, fil, sizeof(fil));
    read(fd2, col, sizeof(col));

    int filas = atoi(fil);
    int columnas = atoi(col);

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            read(fd2, cad, sizeof(cad));
            printf("%-5s\t|   ", cad);
        }
        printf("\n");
        printf("--------------------------------------------------------------------------------- \n");
    }
    // close(fd);
    close(fd2);
}