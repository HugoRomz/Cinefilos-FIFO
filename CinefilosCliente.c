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
char nombres[50], telefono[100];
char cad_id[1000];
int numero;

// variables Pelicula
int stockP;
int precioP;
int id_local;

char tituloP[60], directorP[60];
char data[1000];
// reportes
void menuReporte();
void sociosSinRentas();
void peliculasCienciaF();
void abonosFebrero();
void sociosRentas();
void peliculasRentadas_x_genero();

// apartado de pelicula
void menuPelicula();
void insertarPeliculas();
void MostrarPeliculas();
void consultarPelicula();
void actualizarPelicula();
void bajaPelicula();
void editarGeneroPelicula();
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
void idSocio();
// renta
void menuRenta();
void altaRenta();
void devolverRenta();
void mostrarRentas();
void mostrarulti_renta();
void mostrarlocal();

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
        printf("\t|       3. Editar genero de la pelicula    |\n");
        printf("\t|------------------------------------------|\n");
        printf("\t|               4.- Regresar.              |\n");
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
            case 3:
                editarGeneroPelicula();
            break;
        }
    } while (opcionMenu != 4);
}
void editarGeneroPelicula(){

    system("clear");

    char fil[100], col[100], cad[1000];
    int fd2 = open("MIFIFO", O_RDONLY);
    int id_peli;
    
    read(fd2, fil, sizeof(fil));
    read(fd2, col, sizeof(col));

    int filas = atoi(fil);
    int columnas = atoi(col);
    printf("\t-----------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            read(fd2, cad, sizeof(cad));
            printf("\t%-15s\t|   ", cad);
        }
    printf("\n");    
    printf("\t----------------------------------------------------------------------------------------------\n");
    }
    // close(fd);
    close(fd2);
    printf("\n");

  
    int id,nuevoGenero;
    printf("\t===============================================\n");
    puts("\tDame el id de la pelicula a cambiar de Genero: ");
    printf("\t");scanf("%d", &id);
    printf("\t===============================================\n");

    //MOSTRAR GENEROS
   
    buscarGenero();
    fflush(stdin);
    printf("\n\t===============================================\n");
    puts("\tIngresa el ID del Genero: ");
    printf("\t");scanf("%d", &nuevoGenero);
    printf("\t===============================================\n");
    
    sprintf(data, "UPDATE genero_pelicula SET id_genero= %d WHERE id_pelicula=%d",nuevoGenero,id);
    fd = open("MIFIFO", O_WRONLY);
    write(fd, data, sizeof(data));
    close(fd);


   
   

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
    char opSocio[50]; 

    
    printf("--------------------------------------------------------------------------------- \n");

        /*fflush(stdin);
        puts("Ingresa tu nombre con el que estas registrado ");
        scanf("%*c%[^\n]", nombres);
        fflush(stdin);
        puts("ingrese su numero de telefono :");
        scanf("%s", &telefono);
        fflush(stdin);
        sprintf(data, "select * from socio where nombres = '%s' and telefeno = '%s';", nombres, telefono);
        fd = open("MIFIFO", O_WRONLY);
        write(fd, data, sizeof(data));
        close(fd);

        fd = open("MIFIFO", O_RDONLY);
        read(fd, data, sizeof(data));
        close(fd);

        int resultado2 = strcmp(data,"ok");

        if (resultado2 == 0)
        {
             printf("\n Hola %s \n ", nombres);
        }
        else{
             printf("\n no se encontraron datos \n");
        }*/

        puts("Ingresa tu nombre con el que estas registrado ");
        scanf("%*c%[^\n]", nombres);
        puts("ingrese su numero de telefono :");
        scanf("%s", &telefono);
        sprintf(data, "select id_socio from socio where nombres = '%s' and telefono = '%s';", nombres, telefono);
        fd = open("MIFIFO", O_WRONLY);
        write(fd, data, sizeof(data));
        close(fd);

        fd = open("MIFIFO", O_RDONLY);
        read(fd, data, sizeof(data));
        close(fd);
        //printf("\tmensaje: %s", data);
        int resultado2 = strcmp(data,"llego");

        if (resultado2 == 0)
        {  
            idSocio();
            numero = atoi(cad_id);

             do{
                printf("\t=====================================================\n");
                printf("\t              ** Bienvenido %s **                 \n",nombres);
                printf("\t=====================================================\n");
                printf("\t                 ** Tu id es: %d **                 \n",numero);
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
                        altaRenta();
                        break;
                    case 2:
                        printf("renta Devolver\n");
                        devolverRenta();
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
        else{
            int resultado2 = strcmp(data,"fallo");

        if (resultado2 == 0)
        {
             printf("\n-----------------------------------------------\n");
             printf("\n No se encontro ningun usuario con ese nombre \n");
             printf("\n-----------------------------------------------\n");
             printf("\n Enviando a la funcion de insertar nuevo socio \n");
             printf("\n-----------------------------------------------\n");
             insertarSocio();
        }
        }
                
    }


void altaRenta()
{
    int id_socio,id_local;
    printf("ingrese el id del socio: ");
    scanf("%d", &id_socio);
    printf("\n--------------------------------------------------------------------------------- \n");
    mostrarlocal();
    printf("\n--------------------------------------------------------------------------------- \n");
    puts("Ingresa el id del local: ");
    scanf("%d", &id_local);
  
    sprintf(data, "insert into renta(id_socio,id_local,status)values(%d,%d,0);", id_socio, id_local);
    fd = open("MIFIFO", O_WRONLY);
    write(fd, data, sizeof(data));
    close(fd);
    int respuestaRenta;
    sleep(1);
    mostrarulti_renta();
    do{
        int id_renta,id_pelicula,cantidad;
        printf("ingrese el id de renta : ");
        scanf("%d", &id_renta);
        printf("\n--------------------------------------------------------------------------------- \n");
        MostrarPeliculas();
        printf("\n--------------------------------------------------------------------------------- \n");
        puts("Ingresa el id de la pelicula: ");
        scanf("%d", &id_pelicula);
        puts("Ingresa la cantidad : ");
        scanf("%d", &cantidad);
        // puts("Ingresa la fecha de salida : ");
        // scanf("%s", &fecha_salida);
        time_t t;
        struct tm *tm;
        char fecha[100];
        t=time(NULL);
        tm=localtime(&t);
        strftime(fecha, 100, "%Y-%m-%d", tm);
        // printf ("%s", fecha);

        sprintf(data, "insert into det_renta (id_renta,id_pelicula,cantidad,fecha_salida)values(%d,%d,%d,'%s');", id_renta, id_pelicula,cantidad,fecha);
        fd = open("MIFIFO", O_WRONLY);
        write(fd, data, sizeof(data));
        close(fd);
        
        printf("\t desea seguir rentando? si ( 1 ) o no ( 0 ):");
        scanf("%d",&respuestaRenta);
        sprintf(data,"%d",respuestaRenta);
        fd = open("MIFIFO", O_WRONLY);
        write(fd, data, sizeof(data));
        close(fd);
        
    }while(respuestaRenta != 0);
               

}
void mostrarlocal(){
    char fil[1000], col[1000], cad[1000];
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

}
void mostrarulti_renta()
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
            printf("ultimo id_renta:  %-5s\t|   ", cad);
        }
        printf("\n");
        printf("--------------------------------------------------------------------------------- \n");
    }
    // close(fd);
    close(fd2);

}
void devolverRenta()
{   
    char fil[1000],col[1000],cad[1000];
    printf("\t su ide es: %d \n",numero);
    int id_renta;
    char fecha_entrega[100];
    printf("\t Ingrese el id de renta: ");
    scanf("%d",&id_renta);
    printf("\t Ingrese la fecha entrega: ");
    scanf("%s",&fecha_entrega);

    printf("--------------------------------------------------------------------------------- \n");
    sprintf(data," update det_renta set fecha_entrada = '%s' where id_renta = %d;",fecha_entrega, id_renta);
    fd = open("MIFIFO", O_WRONLY);
    write(fd, data, sizeof(data));
    close(fd);
    sleep(2);
    sprintf(data," update renta set status = 1 where id_renta = %d;", id_renta);
    fd = open("MIFIFO", O_WRONLY);
    write(fd, data, sizeof(data));
    close(fd);
    
    
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


void idSocio()
{
    char fil[1000], col[1000];
    sprintf(data, "select id_socio from socio where nombres = '%s' and telefono = '%s';", nombres, telefono);
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
            read(fd2, cad_id, sizeof(cad_id));
            //printf("%s", cad);
        }
        printf("\n");
        printf("--------------------------------------------------------------------------------- \n");
    }

    close(fd2);
    //     end = time(NULL);
    //     // calcular el tiempo transcurrido encontrando la diferencia (end - begin)
    //    printf("Tiempo de conexecion de ejecucion del cliente : %d seconds", (end - begin));
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
    sprintf(data, "select * from socio where nombres = '%s'", nombre);
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
                peliculasCienciaF();
                // clock_t end = clock();
                break;
            case 3:
                printf("\t|     3.  Total de abonos en el mes de febrero.|\n");
                abonosFebrero();
                break;
            case 4:
                printf("\t|     4.  Socios que han rentado               |\n");
                
                sociosRentas();
                // clock_t end = clock();
                break;
            case 5:
                printf("\t|     5.- Peliculas de cada genero rentadas    |\n");
                peliculasRentadas_x_genero();
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
void peliculasCienciaF()
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
void abonosFebrero()
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
void sociosRentas()
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



void peliculasRentadas_x_genero()
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