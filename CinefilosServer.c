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
void peliculasCienciaF(PGconn * conn);
void abonosFebrero(PGconn * conn);
void sociosRentas(PGconn * conn);
void peliculasRentadas_x_genero(PGconn * conn);

//renta
void menuRenta(PGconn * conn);
void altaRenta(PGconn * conn);
void ult_renta(PGconn * conn);
void mostrarlocal(PGconn * conn);
void socio_xrenta(PGconn * conn);
void devolverPelicula(PGconn * conn);

//apartado de pelicula
void menuPelicula(PGconn * conn);
void insertarP(PGconn * conn);
void MostrarPelicula(PGconn * conn);
void BuscarPelicula(PGconn * conn);
void EditarPelicula(PGconn * conn);
void bajaPelicula(PGconn * conn);
void editarGeneroPelicula(PGconn * conn);
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
void bajaSocio(PGconn * conn);
void EditarSocio(PGconn * conn);
void buscarSocio(PGconn * conn);
void idSocio(PGconn * conn);


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
         case 3:
            printf("\t editar GENERO Pelicula \n");
            editarGeneroPelicula(conn);
         break;
      }
   } while (opcionMenu != 4);
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
         bajaSocio(conn);
         break;

      }
   } while (opcionMenu != 6);
}


void menuRenta(PGconn * conn) {
   char instrucc[1000];

   fd = open("MIFIFO", O_RDONLY);
   read(fd, instrucc, sizeof(instrucc));
   close(fd);
   resultado = PQexec(conn, instrucc);
   int fil2 = PQntuples(resultado);
   printf("\t Filas: %d \n",fil2);
   
   if(fil2 > 0)
   {
      sprintf(instrucc, "llego");
      fd = open("MIFIFO", O_WRONLY);
      write(fd, instrucc, sizeof(instrucc));
      close(fd);

      idSocio(conn);


      do {       
            printf("\t Estas en submenu Renta \n");
            fd = open("MIFIFO", O_RDONLY);
            read(fd, opcionfifo, sizeof(opcionfifo));
            close(fd);
            opcionMenu = atoi(opcionfifo);

            switch (opcionMenu) {
               case 1:
                  printf("Alta renta\n");
                  altaRenta(conn);
               
                  break;

               case 2:
                  printf("renta 2\n");
                  devolverPelicula(conn);            
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
   sprintf(instrucc, "fallo");
   fd = open("MIFIFO", O_WRONLY);
   write(fd, instrucc, sizeof(instrucc));
   close(fd);
   printf("\n Llamando funcion insertar socio \n");
   insertarS(conn);
   }


}

void devolverPelicula(PGconn * conn){
   printf("nDEVOLVER PELIS YEIIIII\n");
   
   fd = open("MIFIFO", O_RDONLY);
   read(fd, data, sizeof(data));
   res = PQexec(conn, data);
   res = PQexec(conn, data);
   close(fd);
   sleep(2);
   fd = open("MIFIFO", O_RDONLY);
   read(fd, data, sizeof(data));
   res = PQexec(conn, data);
   close(fd);
   

}
void altaRenta(PGconn * conn){
   mostrarlocal(conn);

   fd = open("MIFIFO", O_RDONLY);
   read(fd, data, sizeof(data));
   res = PQexec(conn, data);
   close(fd);
    int parar;
   sleep(1);
   ult_renta(conn);
   do{
      MostrarPelicula(conn);
      fd = open("MIFIFO", O_RDONLY);
      read(fd, data, sizeof(data));
      res = PQexec(conn, data);
      close(fd);

      printf("\n");

      fd = open("MIFIFO", O_RDONLY);
      read(fd, data, sizeof(data));
      close(fd);
      parar = atoi(data);


   }while(parar!=0);
   

}
void ult_renta(PGconn * conn){
   
   // mostrarSocio(conn);
   char instrucc[500], filas[100], columnas[100];
   sprintf(instrucc, "select max(id_renta) from renta;");
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
         printf("\n____________________________________\n");
      }
   } else {
      printf("\nNo hay datos");
   }
   close(fd2);
}
void mostrarlocal(PGconn * conn){
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
         printf("\n______________\n");
      }
   }
   close(fd2);


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
   sprintf(instrucc, "select * from socio where statusm=1;");
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

void idSocio(PGconn * conn) {
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
void bajaSocio(PGconn * conn) {
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
         printf("\n______________\n");
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
            peliculasCienciaF(conn);
            break;
         case 3:
            printf("\t|     3.  Total de abonos en el mes de febrero.|\n");
            // abonosFebrero(conn);
            break;
         case 4:
            printf("\t|     4.  Socios que han rentado               |\n");
            sociosRentas(conn);

            break;
         case 5:
            printf("\t|     5.- Peliculas de cada genero rentadas    |\n");
            peliculasRentadas_x_genero(conn);
   
            break;

      }
   } while (opcionMenu != 6);
}
void sociosSinRentas(PGconn * conn) {
   inicio = clock();
   time_spent = 0;
   char instrucc[100], filas[100], columnas[100];
   sprintf(instrucc, "SELECT t1.id_socio,t1.nombres,t1.apellidos FROM socio t1 LEFT JOIN renta t2 ON t2.id_socio = t1.id_socio WHERE t2.id_socio IS NULL");
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
void peliculasCienciaF(PGconn * conn) {
   inicio = clock();
   time_spent = 0;
   char instrucc[100], filas[100], columnas[100];
   sprintf(instrucc, "SELECT p.id_local,l.nombrelocal,l.direccion, p.titulo,g.nombreg FROM pelicula AS p INNER JOIN local AS l ON p.id_local = l.id_local INNER JOIN genero_pelicula as gp ON gp.id_pelicula = p.id_pelicula inner join genero as g on g.id_genero = gp.id_genero and nombreg = 'Ciencia Ficcion';");
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
void sociosRentas(PGconn * conn) {
   inicio = clock();
   time_spent = 0;
   char instrucc[100], filas[100], columnas[100];
   sprintf(instrucc, "SELECT t1.id_socio,t1.nombres,t1.apellidos,t1.direccion,p1.titulo,t3.fecha_salida FROM socio t1 inner join renta t2 ON t2.id_socio = t1.id_socio inner join det_renta t3 ON t3.id_renta = t2.id_renta inner join pelicula p1 on p1.id_pelicula = t3.id_pelicula;");
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
void peliculasRentadas_x_genero(PGconn * conn){
   inicio = clock();
   time_spent = 0;
   char instrucc[100], filas[100], columnas[100];
   sprintf(instrucc, "select count(nombreg),nombreg from pelicula p1 inner join det_renta dt on dt.id_pelicula = p1.id_pelicula inner join genero_pelicula gp on gp.id_pelicula = dt.id_pelicula inner join genero g on g.id_genero = gp.id_genero group by nombreg;");
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

void editarGeneroPelicula(PGconn * conn){
   inicio = clock();
   time_spent = 0;
   char instrucc[100], filas[100], columnas[100];

   sprintf(instrucc, "select pelicula.id_pelicula,pelicula.titulo,pelicula.director,pelicula.stock,genero.nombreg from pelicula,genero,genero_pelicula as gp where gp.id_pelicula=pelicula.id_pelicula and gp.id_genero=genero.id_genero and pelicula.status = 1 ORDER BY gp.id_genero;");
   
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
   mostrarGenero(conn);
   close(fd2);
   char tiempo[1000];
   fin = clock();
   time_spent += (double)(fin - inicio) / CLOCKS_PER_SEC;
   printf("\n El tiempo de ejecucion en servidor es : %.4f segundos", time_spent);


   fd = open("MIFIFO", O_RDONLY);
   read(fd, data, sizeof(data));
   res = PQexec(conn, data);
   close(fd);
   
   fin = clock();
   time_spent += (double)(fin - inicio) / CLOCKS_PER_SEC;
   printf("\n El tiempo de ejecucion en servidor es : %.4f segundos", time_spent);

   


}