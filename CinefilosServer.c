#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include </usr/include/postgresql/libpq-fe.h>
#include<time.h>

int fd;
char data[300], opcionfifo[2];
char cad[100], fil[50], col[50];
int opcionMenu;
PGconn * conn;
PGresult * resultado;
PGresult * res2;
PGresult * res;

void mostrarPeli_uno(PGconn * conn);
void mostrarPeli_dos(PGconn * conn);

//reportes
void menuReportes(PGconn * conn);
void sociosSinRentas(PGconn * conn);

//renta
void menuRenta(PGconn * conn);
//apartado de pelicula
void menuPelicula(PGconn * conn);
void insertarP(PGconn * conn);
void MostrarPelicula(PGconn * conn);
void BuscarPelicula(PGconn * conn);
void EditarPelicula(PGconn * conn);
void bajaPelicula(PGconn * conn);
//genero
void insertarGenero(PGconn * conn);
void mostrarGenero(PGconn * conn);
void buscarGenero(PGconn * conn);
void editarGenero(PGconn * conn);
void bajaGenero(PGconn * conn);
//apartado de socio
void menuSocio(PGconn * conn);
void insertarS(PGconn * conn);
void mostrarSocio(PGconn * conn);
void EliminarSocio(PGconn * conn);
void EditarSocio(PGconn * conn);
void buscarSocio(PGconn * conn);

//para cerrar conexion
void do_exit(PGconn * conn) {
   PQfinish(conn);
   exit(1);
}
double time_spent = 0.0;
time_t inicio, fin;
int main() {
   // double time_spent = 0.0;

   // begin = time(NULL);
   mkfifo("MIFIFO", 0666);
   conn = PQconnectdb("user=postgres dbname=cinefilos");

   if (PQstatus(conn) == CONNECTION_BAD) {

      printf("\n error al conectar a la base de datos\n\n");

      do_exit(conn);
   } else {
      printf("\t Estas en el servidor \n");
      do {
         printf("\t Menu principal\n");
         fd = open("MIFIFO", O_RDONLY);
         read(fd, opcionfifo, sizeof(opcionfifo));
         close(fd);
         opcionMenu = atoi(opcionfifo);

         switch (opcionMenu) {
         case 1:
            // system("clear");
            menuRenta(conn);
            break;
         case 2:
            // system("clear");
            menuPelicula(conn);
            break;
         case 3:
            // system("clear");
            menuSocio(conn);
            break;
         case 4:
            menuReportes(conn);
            // system("clear");
            break;
         }
      } while (opcionMenu != 5);
      PQfinish(conn);
   }
   return 0;
}
void menuPelicula(PGconn * conn) {
   do {
      printf("\t Estas en submenu pelicula \n");

      fd = open("MIFIFO", O_RDONLY);
      read(fd, opcionfifo, sizeof(opcionfifo));
      close(fd);
      opcionMenu = atoi(opcionfifo);

      switch (opcionMenu) {
      case 1:
         printf("\t Estas en menu pelicula1 \n");
         do {
            fd = open("MIFIFO", O_RDONLY);
            read(fd, opcionfifo, sizeof(opcionfifo));
            close(fd);
            opcionMenu = atoi(opcionfifo);

            switch (opcionMenu) {
               // MOSTRAR   
            case 1:
               printf("\t mostrar pelicula\n");
               MostrarPelicula(conn);
               break;

               //INSERTAR
            case 2:
               printf("\tinsertar pelicula\n");
               insertarP(conn);

               break;
               //BUSCAR
            case 3:
               printf("\t buscar por nombre pelicula\n");
               BuscarPelicula(conn);
               break;
               //EDITAR
            case 4:
               printf("\t Editar pelicula\n");
               EditarPelicula(conn);
               break;
               //ELIMINAR
            case 5:
               printf("\t ELiminar pelicula\n");
               bajaPelicula(conn);
               break;

            }

         } while (opcionMenu != 6);
         break;

      case 2:
         printf("\t Estas en menu genero_pelicula \n");
         do {
            fd = open("MIFIFO", O_RDONLY);
            read(fd, opcionfifo, sizeof(opcionfifo));
            close(fd);
            opcionMenu = atoi(opcionfifo);

            switch (opcionMenu) {
               // MOSTRAR   
            case 1:
               printf("\t MOSTRAR GENERO \n");
               mostrarGenero(conn);
               break;
               //INSERTAR
            case 2:
               printf("\t INSERTAR GENERO \n");
               insertarGenero(conn);
               break;
               //BUSCAR
            case 3:
               printf("\t BUSCAR POR Nombre GENERO \n");
               buscarGenero(conn);
               break;
               //EDITAR
            case 4:
               printf("\t EDITAR GENERO \n");
               editarGenero(conn);
               break;
               //ELIMINAR
            case 5:
               printf("\t ELIMINAR GENERO \n");
               bajaGenero(conn);
               break;

            }

         } while (opcionMenu != 6);
         break;
      }
   } while (opcionMenu != 3);
}
void menuSocio(PGconn * conn) {
   do {
      printf("\t Estas en submenu Socio \n");

      fd = open("MIFIFO", O_RDONLY);
      read(fd, opcionfifo, sizeof(opcionfifo));
      close(fd);
      opcionMenu = atoi(opcionfifo);

      switch (opcionMenu) {
      case 1:
         printf("mostrar socios\n");
         mostrarSocio(conn);
         break;

      case 2:
         printf("insertar socios\n");
         insertarS(conn);
         break;
      case 3:
         printf("buscar socio por nombre\n");
         buscarSocio(conn);
         break;

      case 4:
         printf("editar socios\n");
         EditarSocio(conn);
         break;
      case 5:
         printf("eliminar socios\n");
         EliminarSocio(conn);
         break;

      }
   } while (opcionMenu != 6);
}
//
void menuRenta(PGconn * conn) {

   fd = open("MIFIFO", O_RDONLY);
   read(fd, data, sizeof(data));
   close(fd);

   int resultado = strcmp(data, "si");

   if (resultado == 0) {
   printf("entraste a la comprobacion de cliente \n");

   char instrucc[1000], filas[1000], columnas[1000];
   fd = open("MIFIFO", O_RDONLY);
   read(fd, instrucc, sizeof(instrucc));
   close(fd);
   resultado = PQexec(conn, instrucc);
 

   if (resultado != NULL) {
      printf("entraste a la comprobacion de cliente ok \n");
      fd = open("MIFIFO", O_WRONLY);
      write(fd, data, sizeof(data));
      close(fd);

   }
   else {
      
      printf("entraste a la comprobacion de cliente fallo \n");

      sprintf(data,"no");
      fd = open("MIFIFO", O_WRONLY);
      write(fd, data, sizeof(data));
      close(fd);

   }

   //close(fd2);

      do {
         
         printf("\t Estas en submenu Renta \n");

         fd = open("MIFIFO", O_RDONLY);
         read(fd, opcionfifo, sizeof(opcionfifo));
         close(fd);
         opcionMenu = atoi(opcionfifo);

         switch (opcionMenu) {
            case 1:
               printf("Alta renta\n");
            
               break;

            case 2:
               printf("renta 2\n");
            
               break;
            case 3:
               printf("renta 2\n");
            
               break;

            case 4:
               printf("renta 2\n");
               
               break;
            case 5:
               printf("elimina\n");
            
               break;

         }
      } while (opcionMenu != 6);

   }
   else {

      int resultado = strcmp(data, "no");

      if (resultado == 0) {

      }
      else {


      }

   }
}

//
void insertarP(PGconn * conn) {
   inicio = clock();
   time_spent = 0;
   char instrucc[1000], filas[1000], columnas[1000];
   fd = open("MIFIFO", O_RDONLY);
   read(fd, instrucc, sizeof(instrucc));
   close(fd);
   resultado = PQexec(conn, instrucc);

   int fil2 = PQntuples(resultado);
   int col2 = PQnfields(resultado);
   sprintf(filas, "%d", fil2);
   sprintf(columnas, "%d", col2);

   int fd2 = open("MIFIFO", O_WRONLY);
   write(fd2, filas, sizeof(filas));
   write(fd2, columnas, sizeof(columnas));

   if (resultado != NULL) {
      char res[1000];
      for (int i = 0; i < PQntuples(resultado); i++) { //filas
         for (int j = 0; j < PQnfields(resultado); j++) { //columnas
            printf("%s\t|  ", PQgetvalue(resultado, i, j));
            sprintf(res, PQgetvalue(resultado, i, j));
            write(fd2, res, sizeof(res));
         }
         printf("\n____________________________________\n");
      }
   }
   close(fd2);

   fd = open("MIFIFO", O_RDONLY);
   read(fd, data, sizeof(data));
   res = PQexec(conn, data);
   close(fd);
   fin = clock();
   time_spent += (double)(fin - inicio) / CLOCKS_PER_SEC;
   printf("\n El tiempo de ejecucion en servidor es : %.4f segundos", time_spent);
}
void MostrarPelicula(PGconn * conn) {
   inicio = clock();
   time_spent = 0;
   // mostrarSocio(conn);
   char instrucc[500], filas[100], columnas[100];
   sprintf(instrucc, "select pelicula.id_pelicula,pelicula.titulo,pelicula.director,pelicula.stock,genero.nombreg from pelicula,genero,genero_pelicula as gp where gp.id_pelicula=pelicula.id_pelicula and gp.id_genero=genero.id_genero and pelicula.status = 1 ORDER BY gp.id_pelicula;");
   resultado = PQexec(conn, instrucc);
   int fil = PQntuples(resultado);
   int col = PQnfields(resultado);
   sprintf(filas, "%d", fil);
   sprintf(columnas, "%d", col);
   int fd2 = open("MIFIFO", O_WRONLY);
   write(fd2, filas, sizeof(filas));
   write(fd2, columnas, sizeof(columnas));
   if (resultado != NULL) {
      char res[1000];
      for (int i = 0; i < PQntuples(resultado); i++) { //filas
         for (int j = 0; j < PQnfields(resultado); j++) { //columnas
            printf("%-5s\t|", PQgetvalue(resultado, i, j));
            sprintf(res, PQgetvalue(resultado, i, j));
            write(fd2, res, sizeof(res));
         }
         printf("\n________________________________________________________________________________________________________\n");
      }
   } else {
      printf("\nNo hay datos");
   }
   close(fd2);
   char tiempo[1000];
   fin = clock();
   time_spent += (double)(fin - inicio) / CLOCKS_PER_SEC;
   printf("\n El tiempo de ejecucion en servidor es : %.4f segundos", time_spent);

}
void BuscarPelicula(PGconn * conn) {
   inicio = clock();
   time_spent = 0;
   char instrucc[1000], filas[1000], columnas[1000];
   fd = open("MIFIFO", O_RDONLY);

   read(fd, instrucc, sizeof(instrucc));
   close(fd);

   resultado = PQexec(conn, instrucc);

   int fil2 = PQntuples(resultado);
   int col2 = PQnfields(resultado);
   sprintf(filas, "%d", fil2);
   sprintf(columnas, "%d", col2);

   int fd2 = open("MIFIFO", O_WRONLY);
   write(fd2, filas, sizeof(filas));
   write(fd2, columnas, sizeof(columnas));

   if (resultado != NULL) {
      char res[1000];
      for (int i = 0; i < PQntuples(resultado); i++) { //filas
         for (int j = 0; j < PQnfields(resultado); j++) { //columnas
            printf("%s\t|  ", PQgetvalue(resultado, i, j));
            sprintf(res, PQgetvalue(resultado, i, j));
            write(fd2, res, sizeof(res));
         }
         printf("\n____________________________________\n");
      }
   }
   close(fd2);
   fin = clock();
   time_spent += (double)(fin - inicio) / CLOCKS_PER_SEC;
   printf("\n El tiempo de ejecucion en servidor es : %.4f segundos", time_spent);

}

void EditarPelicula(PGconn * conn) {
   time_spent = 0;
   inicio = clock();
   MostrarPelicula(conn);
   fd = open("MIFIFO", O_RDONLY);
   read(fd, data, sizeof(data));
   res = PQexec(conn, data);
   close(fd);
   fin = clock();
   time_spent += (double)(fin - inicio) / CLOCKS_PER_SEC;
   printf("\n El tiempo de ejecucion en servidor es : %.4f segundos", time_spent);
   
}

void bajaPelicula(PGconn * conn) {
   inicio = clock();
   time_spent = 0;
   char instrucc[1000], filas[1000], columnas[1000];
   fd = open("MIFIFO", O_RDONLY);
   read(fd, instrucc, sizeof(instrucc));
   close(fd);
   resultado = PQexec(conn, instrucc);

   int fil2 = PQntuples(resultado);
   int col2 = PQnfields(resultado);
   sprintf(filas, "%d", fil2);
   sprintf(columnas, "%d", col2);

   int fd2 = open("MIFIFO", O_WRONLY);
   write(fd2, filas, sizeof(filas));
   write(fd2, columnas, sizeof(columnas));

   if (resultado != NULL) {
      char res[1000];
      for (int i = 0; i < PQntuples(resultado); i++) { //filas
         for (int j = 0; j < PQnfields(resultado); j++) { //columnas
            printf("%s\t|  ", PQgetvalue(resultado, i, j));
            sprintf(res, PQgetvalue(resultado, i, j));
            write(fd2, res, sizeof(res));
         }
         printf("\n____________________________________\n");
      }
   }
   close(fd2);

   fd = open("MIFIFO", O_RDONLY);
   read(fd, data, sizeof(data));
   res = PQexec(conn, data);
   close(fd);
   fin = clock();
   time_spent += (double)(fin - inicio) / CLOCKS_PER_SEC;
   printf("\n El tiempo de ejecucion en servidor es : %.4f segundos", time_spent);
}

////
void insertarS(PGconn * conn) {
   inicio = clock();
   time_spent = 0;
   fd = open("MIFIFO", O_RDONLY);
   read(fd, data, sizeof(data));
   res = PQexec(conn, data);
   close(fd);
   fin = clock();
   time_spent += (double)(fin - inicio) / CLOCKS_PER_SEC;
   printf("\n El tiempo de ejecucion en servidor es : %.4f segundos", time_spent);
}

void mostrarSocio(PGconn * conn) {
   inicio = clock();
   time_spent = 0;
   char instrucc[100], filas[100], columnas[100];
   sprintf(instrucc, "select * from socio;");
   resultado = PQexec(conn, instrucc);
   int fil = PQntuples(resultado);
   int col = PQnfields(resultado);
   sprintf(filas, "%d", fil);
   sprintf(columnas, "%d", col);
   int fd2 = open("MIFIFO", O_WRONLY);
   write(fd2, filas, sizeof(filas));
   write(fd2, columnas, sizeof(columnas));
   if (resultado != NULL) {
      char res[1000];
      for (int i = 0; i < PQntuples(resultado); i++) { //filas
         for (int j = 0; j < PQnfields(resultado); j++) { //columnas
            printf("%-5s\t|", PQgetvalue(resultado, i, j));
            sprintf(res, PQgetvalue(resultado, i, j));
            write(fd2, res, sizeof(res));
         }
         printf("\n________________________________________________________________________________________________________\n");
      }
   } else {
      printf("\nNo hay datos");
   }
   close(fd2);
   char tiempo[1000];
   fin = clock();
   time_spent += (double)(fin - inicio) / CLOCKS_PER_SEC;
   printf("\n El tiempo de ejecucion en servidor es : %.4f segundos", time_spent);

}
void buscarSocio(PGconn * conn) {
   inicio = clock();
   time_spent = 0;
   char instrucc[1000], filas[1000], columnas[1000];
   fd = open("MIFIFO", O_RDONLY);

   read(fd, instrucc, sizeof(instrucc));
   close(fd);

   resultado = PQexec(conn, instrucc);

   int fil2 = PQntuples(resultado);
   int col2 = PQnfields(resultado);
   sprintf(filas, "%d", fil2);
   sprintf(columnas, "%d", col2);

   int fd2 = open("MIFIFO", O_WRONLY);
   write(fd2, filas, sizeof(filas));
   write(fd2, columnas, sizeof(columnas));

   if (resultado != NULL) {
      char res[1000];
      for (int i = 0; i < PQntuples(resultado); i++) { //filas
         for (int j = 0; j < PQnfields(resultado); j++) { //columnas
            printf("%s\t|  ", PQgetvalue(resultado, i, j));
            sprintf(res, PQgetvalue(resultado, i, j));
            write(fd2, res, sizeof(res));
         }
         printf("\n____________________________________\n");
      }
   }
   close(fd);
   fin = clock();
   time_spent += (double)(fin - inicio) / CLOCKS_PER_SEC;
   printf("\n El tiempo de ejecucion en servidor es : %.4f segundos", time_spent);

}
void EliminarSocio(PGconn * conn) {
   time_spent = 0;
   mostrarSocio(conn);
   inicio = clock();
   fd = open("MIFIFO", O_RDONLY);
   read(fd, data, sizeof(data));
   res = PQexec(conn, data);
   close(fd);
   fin = clock();
   time_spent += (double)(fin - inicio) / CLOCKS_PER_SEC;
   printf("\n El tiempo de ejecucion en servidor es : %.4f segundos", time_spent);

}
void EditarSocio(PGconn * conn) {
   time_spent = 0;
   inicio = clock();
   mostrarSocio(conn);
   fd = open("MIFIFO", O_RDONLY);
   read(fd, data, sizeof(data));
   res = PQexec(conn, data);
   close(fd);
   fin = clock();
   time_spent += (double)(fin - inicio) / CLOCKS_PER_SEC;
   printf("\n El tiempo de ejecucion en servidor es : %.4f segundos", time_spent);

}
void insertarGenero(PGconn * conn) {
   inicio = clock();
   time_spent = 0;
   fd = open("MIFIFO", O_RDONLY);
   read(fd, data, sizeof(data));
   res = PQexec(conn, data);
   close(fd);
   fin = clock();
   time_spent += (double)(fin - inicio) / CLOCKS_PER_SEC;
   printf("\n El tiempo de ejecucion en servidor es : %.4f segundos", time_spent);
}
void mostrarGenero(PGconn * conn) {
   inicio = clock();
   time_spent = 0;
   // mostrarSocio(conn);
   char instrucc[500], filas[100], columnas[100];
   sprintf(instrucc, "select * from genero;");
   resultado = PQexec(conn, instrucc);
   int fil = PQntuples(resultado);
   int col = PQnfields(resultado);
   sprintf(filas, "%d", fil);
   sprintf(columnas, "%d", col);
   int fd2 = open("MIFIFO", O_WRONLY);
   write(fd2, filas, sizeof(filas));
   write(fd2, columnas, sizeof(columnas));
   if (resultado != NULL) {
      char res[1000];
      for (int i = 0; i < PQntuples(resultado); i++) { //filas
         for (int j = 0; j < PQnfields(resultado); j++) { //columnas
            printf("%-5s\t|", PQgetvalue(resultado, i, j));
            sprintf(res, PQgetvalue(resultado, i, j));
            write(fd2, res, sizeof(res));
         }
         printf("\n________________________________________________________________________________________________________\n");
      }
   } else {
      printf("\nNo hay datos");
   }
   close(fd2);
   char tiempo[1000];
   fin = clock();
   time_spent += (double)(fin - inicio) / CLOCKS_PER_SEC;
   printf("\n El tiempo de ejecucion en servidor es : %.4f segundos", time_spent);

}
void buscarGenero(PGconn * conn) {
   inicio = clock();
   time_spent = 0;
   char instrucc[1000], filas[1000], columnas[1000];
   fd = open("MIFIFO", O_RDONLY);

   read(fd, instrucc, sizeof(instrucc));
   close(fd);

   resultado = PQexec(conn, instrucc);

   int fil2 = PQntuples(resultado);
   int col2 = PQnfields(resultado);
   sprintf(filas, "%d", fil2);
   sprintf(columnas, "%d", col2);

   int fd2 = open("MIFIFO", O_WRONLY);
   write(fd2, filas, sizeof(filas));
   write(fd2, columnas, sizeof(columnas));

   if (resultado != NULL) {
      char res[1000];
      for (int i = 0; i < PQntuples(resultado); i++) { //filas
         for (int j = 0; j < PQnfields(resultado); j++) { //columnas
            printf("%s\t|  ", PQgetvalue(resultado, i, j));
            sprintf(res, PQgetvalue(resultado, i, j));
            write(fd2, res, sizeof(res));
         }
         printf("\n____________________________________\n");
      }
   }
   close(fd);
   fin = clock();
   time_spent += (double)(fin - inicio) / CLOCKS_PER_SEC;
   printf("\n El tiempo de ejecucion en servidor es : %.4f segundos", time_spent);

}

void editarGenero(PGconn * conn) {
   time_spent = 0;
   inicio = clock();
   mostrarGenero(conn);
   fd = open("MIFIFO", O_RDONLY);
   read(fd, data, sizeof(data));
   res = PQexec(conn, data);
   close(fd);
   fin = clock();
   time_spent += (double)(fin - inicio) / CLOCKS_PER_SEC;
   printf("\n El tiempo de ejecucion en servidor es : %.4f segundos", time_spent);

}

void bajaGenero(PGconn * conn) {
   time_spent = 0;
   inicio = clock();
   mostrarGenero(conn);
   fd = open("MIFIFO", O_RDONLY);
   read(fd, data, sizeof(data));
   res = PQexec(conn, data);
   close(fd);
   fin = clock();
   time_spent += (double)(fin - inicio) / CLOCKS_PER_SEC;
   printf("\n El tiempo de ejecucion en servidor es : %.4f segundos", time_spent);
}


void mostrarPeli_dos(PGconn * conn) {
   inicio = clock();
   time_spent = 0;
   char instrucc[100], filas[100], columnas[100];
   sprintf(instrucc, "select * from pelicula where status = 0;");
   resultado = PQexec(conn, instrucc);
   int fil = PQntuples(resultado);
   int col = PQnfields(resultado);
   sprintf(filas, "%d", fil);
   sprintf(columnas, "%d", col);
   int fd2 = open("MIFIFO", O_WRONLY);
   write(fd2, filas, sizeof(filas));
   write(fd2, columnas, sizeof(columnas));
   if (resultado != NULL) {
      char res[1000];
      for (int i = 0; i < PQntuples(resultado); i++) { //filas
         for (int j = 0; j < PQnfields(resultado); j++) { //columnas
            printf("%-5s\t|", PQgetvalue(resultado, i, j));
            sprintf(res, PQgetvalue(resultado, i, j));
            write(fd2, res, sizeof(res));
         }
         printf("\n________________________________________________________________________________________________________\n");
      }
   } else {
      printf("\nNo hay datos");
   }
   close(fd2);
   char tiempo[1000];
   fin = clock();
   time_spent += (double)(fin - inicio) / CLOCKS_PER_SEC;
   printf("\n El tiempo de ejecucion en servidor es : %.4f segundos", time_spent);

}
///

void menuReportes(PGconn * conn) {
   do {
      printf("\t Estas en submenu REPORTES \n");

      fd = open("MIFIFO", O_RDONLY);
      read(fd, opcionfifo, sizeof(opcionfifo));
      close(fd);
      opcionMenu = atoi(opcionfifo);

      switch (opcionMenu) {
         case 1:
            printf("\t|     1.  Socios que no han rentado            |\n");
            sociosSinRentas(conn);
            break;
         case 2:
            printf("\t|     2.  Peliculas de ciencis f.              |\n");
            break;
         case 3:
            printf("\t|     3.  Total de abonos en el mes de febrero.|\n");
            break;
         case 4:
            printf("\t|     4.  Socios que han rentado               |\n");

            break;
         case 5:
          printf("\t|     5.- Peliculas de cada genero rentadas    |\n");
   
            break;

      }
   } while (opcionMenu != 6);
}
void sociosSinRentas(PGconn * conn) {
   inicio = clock();
   time_spent = 0;
   char instrucc[100], filas[100], columnas[100];
   sprintf(instrucc, "SELECT t1.id_socio,t1.nombre,t1.apellidos FROM socio t1 LEFT JOIN renta t2 ON t2.id_socio = t1.id_socio WHERE t2.id_socio IS NULL");
   resultado = PQexec(conn, instrucc);
   int fil = PQntuples(resultado);
   int col = PQnfields(resultado);
   sprintf(filas, "%d", fil);
   sprintf(columnas, "%d", col);
   int fd2 = open("MIFIFO", O_WRONLY);
   write(fd2, filas, sizeof(filas));
   write(fd2, columnas, sizeof(columnas));
   if (resultado != NULL) {
      char res[1000];
      for (int i = 0; i < PQntuples(resultado); i++) { //filas
         for (int j = 0; j < PQnfields(resultado); j++) { //columnas
            printf("%-5s\t|", PQgetvalue(resultado, i, j));
            sprintf(res, PQgetvalue(resultado, i, j));
            write(fd2, res, sizeof(res));
         }
         printf("\n________________________________________________________________________________________________________\n");
      }
   } else {
      printf("\nNo hay datos");
   }
   close(fd2);
   char tiempo[1000];
   fin = clock();
   time_spent += (double)(fin - inicio) / CLOCKS_PER_SEC;
   printf("\n El tiempo de ejecucion en servidor es : %.4f segundos", time_spent);

}