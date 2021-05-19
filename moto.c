#include "moto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char colorDataware[5][15] = {"Gris","Negro", "Blanco", "Azul", "Rojo"};
char tipoDataware[4][15] = {"Enduro", "Chopera", "Scooter", "Ciclomotor"};
char serviciosDataware[4][15] = {"Limpieza", "Ajuste", "Balanceo" , "Cadena" };
int preciosDataware[4] = {250,300,17,190};



int menu(){
    int opcion;
    char ingreso[2];

    system("cls");
    printf("        *****************************\n");
    printf("        *****************************\n");
    printf("        *******    MOTOS      ******\n");
    printf("        *****************************\n");
    printf("        *****************************\n");
    printf(" 1. Alta de Moto  \n");
    printf(" 2. Modificar Moto  \n");
    printf(" 3. Baja de Moto  \n");
    printf(" 4. Listar Motos   \n");
    printf(" 5. Listar Tipos  \n");
    printf(" 6. Listar colores   \n");
    printf(" 7.  Listar servicios                \n");
    printf(" 8.  Alta de trabajos                 \n");
    printf(" 9.  Listar trabajos                  \n");
    printf(" 10. Ingrese para salir del menu \n");

    fflush(stdin);
    gets(ingreso);

    opcion = atoi(ingreso);

    return opcion;

}

void inicializarMoto(eMoto listaMotos[], int tamanioListaMotos){

    if(listaMotos != NULL && tamanioListaMotos > 0)
    {
        for(int i = 0; i < tamanioListaMotos; i++)
        {
        listaMotos[i].isEmpty = 1;
        }

    }
}

void cambiarFlagATrue(int* bandera){

     if(bandera != NULL)
     {
        *bandera = 1;
     }

}


int altaMoto(eMoto listaMotos[], int tamanioListaMotos, int* nextIdMoto)
{
    int todoOk = 0;
    eMoto auxiliar;
    int respuestaLibre;
    int devolucion;

    if(listaMotos != NULL && tamanioListaMotos > 0 && nextIdMoto > 0)
    {
        respuestaLibre = buscarMotoLibre(listaMotos, tamanioListaMotos);
        if(respuestaLibre == -1)
        {
           // no hay lugar
           printf("No tiene posiciones disponibles en el array\n");
        }
        printf("Ingrese marca de la moto\n");
        fflush(stdin);
        gets(auxiliar.marca);
        printf("Ingrese el tipo de moto 1.Enduro , 2.Chopera, 3.Scooter, 4.Ciclomotor\n");
        scanf("%d", &auxiliar.idTipo);
        while(auxiliar.idTipo < 0 || auxiliar.idTipo > 4)
        {
            printf("Error reIngrese el tipo de moto 1.Enduro , 2.Chopera, 3.Scooter, 4.Ciclomotor\n");
            scanf("%d", &auxiliar.idTipo);
        }
        printf("Ingrese la cilindrada de la moto 50, 125, 500, 600, 750\n");
        scanf("%d", &auxiliar.cilindrada);
        devolucion = validarCilindrada(auxiliar.cilindrada);
        while(devolucion == 0)
        {
            printf("Error, reIngrese la cilindrada de la moto 50, 125, 500, 600, 750\n");
            scanf("%d", &auxiliar.cilindrada);
            devolucion = validarCilindrada(auxiliar.cilindrada);
        }
        printf("Ingrese el id del color 1.Gris,2.Negro, 3.Blanco, 4.Azul, 5.Rojo \n");
        scanf("%d", &auxiliar.idColor);
        while(auxiliar.idColor < 0 || auxiliar.idColor > 5)
        {
            printf("Error, reIngrese el id del color 1.Gris,2.Negro, 3.Blanco, 4.Azul, 5.Rojo \n");
            scanf("%d", &auxiliar.idColor);
        }
        auxiliar.isEmpty = 0;
        auxiliar.id = *nextIdMoto;
        (*nextIdMoto) ++;
        listaMotos[respuestaLibre] = auxiliar;
       todoOk = 1;
    }
    return todoOk;
}

int buscarMotoLibre(eMoto listaMotos[], int tamanioListaMotos)
{
    int libre = -1;

    if(listaMotos != NULL && tamanioListaMotos > 0)
    {
        for(int i= 0; i < tamanioListaMotos; i ++)
        {
            if(listaMotos[i].isEmpty == 1)
            {
                libre = i;
                break;
            }
        }
    }
    return libre;
}

int bajaMoto(eMoto listaMotos[], int tamanioListaMotos, eColor listadoDeColores[], int tamanioListadoColores, eTipoMoto listadoDeTipos[], int tamanioListaTipos)
{
    int todoOk= -1;
    int idBaja;
    int indiceBaja;

    if(listaMotos != NULL && tamanioListaMotos > 0)
    {
        mostrarMotos(listaMotos, tamanioListaMotos, listadoDeColores, tamanioListadoColores, listadoDeTipos, tamanioListaTipos);
        printf("Ingrese id de la moto para dar la baja");
        scanf("%d", &idBaja);
        indiceBaja = buscarMotoXId(listaMotos, tamanioListaMotos, idBaja);
        for(int i= 0; i < tamanioListaMotos; i++)
        {
            listaMotos[indiceBaja].isEmpty = 1;
            todoOk = 1;
            break;
        }
    }
    return todoOk;
}

int buscarMotoXId(eMoto listaMotos[], int tamanioListaMoto, int idABuscar)
{
    int indice;

    if(listaMotos != NULL && tamanioListaMoto > 0)
    {
        for(int i= 0; i < tamanioListaMoto; i ++)
        {
            if(listaMotos[i].id == idABuscar )
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

void harcodearColor(eColor listadoDeColores[], int tamanioListadoColores)
{
    int identificador = 10000;
    if(listadoDeColores != NULL)
    {
       for(int i= 0; i < tamanioListadoColores; i++)
       {
           strcpy(listadoDeColores[i].nombreColor,colorDataware[i]);

           listadoDeColores[i].id = identificador;
           identificador ++;
           listadoDeColores[i].isEmpty = 0;

       }
    }
}

void mostrarMotos(eMoto listaMotos[], int tamanioListaMotos, eColor listadoDeColores[], int tamanioListadoColores, eTipoMoto listadoTipos[], int tamanioListadoTipos)
{

    int flag = 1;

    printf("------------- MOTOS INGRESADOS ------------------\n");
    printf("Id moto         Marca       Color      Cilindrada  Tipo de Moto \n");
    for(int i=0; i< tamanioListaMotos; i++)
    {
        if(!listaMotos[i].isEmpty)
        {
           mostrarMoto(listaMotos[i], listadoDeColores, tamanioListadoColores, listadoTipos, tamanioListadoTipos);
           flag = 0;
        }

    }
    if(flag)
        {
            printf("No hay motos ingresadas\n");
        }


}

void mostrarMoto(eMoto unaMoto, eColor listadoDeColores[], int tamanioListadoColores, eTipoMoto listadoTipos[], int tamanioListadoTipos)
{
    char descripcion[20];
    char descripTipo[20];

    cargarNombreColor(listadoDeColores, tamanioListadoColores, unaMoto.idColor, descripcion );
    cargarNombreTipo(listadoTipos, tamanioListadoTipos, unaMoto.idTipo, descripTipo);

    printf(" %d      %10s      %d       %s  %s   %d  ", unaMoto.id , unaMoto.marca, unaMoto.cilindrada,
                                    descripcion, descripTipo, unaMoto.idTipo);

    printf("\n");
}

void cargarNombreColor(eColor listadoDeColores[], int tamanioListadoColores, int identificador, char descripcion[])
{
        if(listadoDeColores != NULL && tamanioListadoColores > 0 )
    {
        for(int i= 0; i < tamanioListadoColores; i++)
        {
            if(listadoDeColores[i].id + 1 == identificador )
            {
                strcpy(descripcion, listadoDeColores[i].nombreColor);
                break;
            }
        }
    }


}

void cargarNombreTipo(eTipoMoto listadoDeTipos[], int tamanioListadoTipos, int identificador, char descripcion[])
{
        if(listadoDeTipos != NULL && tamanioListadoTipos > 0 )
    {
        for(int i= 0; i < tamanioListadoTipos; i++)
        {
            if(listadoDeTipos[i].id + 1 == identificador )
            {
                strcpy(descripcion, listadoDeTipos[i].descripcion);
                break;
            }
        }
    }


}

void mostrarColores(eColor listadoDeColores[], int tamanioListadoColores)
{
    for(int i= 0; i < tamanioListadoColores; i++)
    {
        printf(" %d      %10s   ",listadoDeColores[i].id , listadoDeColores[i].nombreColor  );

         printf("\n");
    }

}

void harcodearTipo(eTipoMoto listadoDeTipos[], int tamanioListadoTipos)
{
    int identificador = 1;
    if(listadoDeTipos != NULL)
    {
       for(int i= 0; i < tamanioListadoTipos; i++)
       {
           strcpy(listadoDeTipos[i].descripcion,tipoDataware[i]);

           listadoDeTipos[i].id = identificador;
           identificador ++;
           listadoDeTipos[i].isEmpty = 0;

       }
    }
}

void mostrarTipos(eTipoMoto listadoDeTipos[], int tamanioListadoTipos)
{
    for(int i= 0; i < tamanioListadoTipos; i++)
    {
        printf(" %d      %10s   ",listadoDeTipos[i].id , listadoDeTipos[i].descripcion  );

         printf("\n");
    }

}

int validarCilindrada(int cilindrada)
{
    int todoOk = 0;
    if(cilindrada == 50 || cilindrada == 125 || cilindrada == 500 || cilindrada == 600 ||cilindrada ==  750 )
    {
        todoOk = 1;
    }
    return todoOk;
}

int modificarMoto(eMoto listadeMotos[], int tamanioListaMoto, eColor listadoDeColores[], int tamanioListadoColor, eTipoMoto listadoTipos[], int tamanioListadoTipos)
{
 int todoOk = -1;
 int indice;
 int id;
 int opcion;
 int auxiliarInt = 0;
 int devolucion;

    if(listadeMotos != NULL && tamanioListaMoto > 0)
    {
        mostrarMotos(listadeMotos, tamanioListaMoto, listadoDeColores, tamanioListadoColor, listadoTipos, tamanioListadoTipos);
        printf("Ingrese id de la moto a modificar\n");
        scanf("%d", &id);
        indice = buscarMotoXId(listadeMotos, tamanioListaMoto, id);
        if(indice != -1)
        {
               // encontre el que quiero modificar
                printf("Si desea modificar color ingrese 1\n");
                printf("Si desea modificar cilindrada ingrese 2\n");

                scanf("%d", &opcion);

                switch(opcion)
                {
                case 1:
                    printf("Ingrese el id del color 1.Gris,2.Negro, 3.Blanco, 4.Azul, 5.Rojo \n");
                    scanf("%d", &auxiliarInt);
                    while(auxiliarInt < 0 || auxiliarInt > 5)
                      {
                     printf("Error, reIngrese el id del color 1.Gris,2.Negro, 3.Blanco, 4.Azul, 5.Rojo \n");
                      scanf("%d", &auxiliarInt);
                      }
                    listadeMotos[indice].idColor = auxiliarInt;
                    todoOk = 0;
                    break;
                case 2:
                    printf("Ingrese cilindrada: ");
                    scanf("%d", &auxiliarInt);
                    devolucion = validarCilindrada(auxiliarInt);
                       while(devolucion == 0)
                     {
                   printf("Error, reIngrese la cilindrada de la moto 50, 125, 500, 600, 750\n");
                  scanf("%d", &auxiliarInt);
                 devolucion = validarCilindrada(auxiliarInt);
                       }
                    listadeMotos[indice].cilindrada = auxiliarInt;

                    todoOk = 0;
                    break;
                    default:
                    printf("opcion no valida");
                    system("pause");
                    break;
                }

        }
     }

    return todoOk;
}

void mostrarServicios(eServicio listadoDeServicios[], int tamanioListadoServicios)
{
    for(int i= 0; i < tamanioListadoServicios; i++)
    {
         printf(" Identificador       Servicio           Precio    \n");
        printf(" %d      %10s  %.2f  ",listadoDeServicios[i].id , listadoDeServicios[i].descripcion, listadoDeServicios[i].precio  );

         printf("\n");
    }

}

void harcodearServicios(eServicio listadoDeServicios[], int tamanioListadoServicios)
{
    int identificador = 20000;
    if(listadoDeServicios != NULL)
    {
       for(int i= 0; i < tamanioListadoServicios; i++)
       {
           strcpy(listadoDeServicios[i].descripcion, serviciosDataware[i]);
           listadoDeServicios[i].precio = preciosDataware[i];
           listadoDeServicios[i].id = identificador;
           identificador ++;
           listadoDeServicios[i].isEmpty = 0;

       }
    }
}

int ordenarMotos(eMoto listadeMotos[], int tamanioListaMotos)
{
    int todoOk = 0;

    eMoto auxiliarMoto;

    for(int i= 0; i < tamanioListaMotos -1; i++)
    {
        for(int j= i+1; j < tamanioListaMotos; j++)
        {
            if(listadeMotos[i].idTipo > listadeMotos[j].idTipo || (listadeMotos[i].idTipo == listadeMotos[j].idTipo &&  listadeMotos[i].id > listadeMotos[j].id  ))
            {
                //hacer swap
                auxiliarMoto = listadeMotos[i];
                listadeMotos[i] = listadeMotos[j];
                listadeMotos[j] = auxiliarMoto;
                 todoOk = 1;
            }

        }  // segundo for

    }  // primer for
    return todoOk;
}

void mostrarTrabajos(eTrabajo listadoDeTrabajos[], int tamanioListadoTrabajos)
{
    for(int i= 0; i < tamanioListadoTrabajos; i++)
    {
        printf("Listado de trabajos ------------------------\n");
        printf("Id      Fecha    Id de Moto   Id de servicio   Nombre       \n");
        printf(" %d  %d/%d/%d   %d  %d  %10s   ",listadoDeTrabajos[i].id , listadoDeTrabajos[i].fecha.dia, listadoDeTrabajos[i].fecha.mes,
                                  listadoDeTrabajos[i].fecha.anio, listadoDeTrabajos[i].idMoto, listadoDeTrabajos[i].idServicio,
                                  listadoDeTrabajos[i].nombre   );

         printf("\n");
    }

}

int altaTrabajo(eTrabajo listaTrabajos[], int tamanioListaTrabajos, int* nextIdTrabajos)
{
    int todoOk = 0;
    eTrabajo auxiliar;
    int respuestaLibre;


    if(listaTrabajos != NULL && tamanioListaTrabajos > 0 && nextIdTrabajos > 0)
    {
        respuestaLibre = buscarTrabajoLibre(listaTrabajos, tamanioListaTrabajos);
        if(respuestaLibre == -1)
        {
           // no hay lugar
           printf("No tiene posiciones disponibles en el array\n");
        }
        printf("Ingrese id de la moto\n");
        scanf("%d", &auxiliar.idMoto);

        printf("Ingrese el id del servicio\n");
        scanf("%d", &auxiliar.idServicio);

        printf("Ingrese fecha dd/mm/aaaa \n");
        scanf("%d/%d/%d", &auxiliar.fecha.dia, &auxiliar.fecha.mes, &auxiliar.fecha.anio);

        auxiliar.isEmpty = 0;
        auxiliar.id = *nextIdTrabajos;
        (*nextIdTrabajos) ++;
        listaTrabajos[respuestaLibre] = auxiliar;
       todoOk = 1;
    }
    return todoOk;
}

int buscarTrabajoLibre(eTrabajo listaTrabajos[], int tamanioListaTrabajos)
{
    int libre = -1;

    if(listaTrabajos != NULL && tamanioListaTrabajos > 0)
    {
        for(int i= 0; i < tamanioListaTrabajos; i ++)
        {
            if(listaTrabajos[i].isEmpty == 1)
            {
                libre = i;
                break;
            }
        }
    }
    return libre;
}

int validarFecha( int dia, int mes, int anio)
{
    int todoOk = 0;
    if(anio > 2000 && anio < 2030 && mes > 0 && mes < 13)
    {
        switch(mes)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if(dia > 0 && dia < 32)
            {
                todoOk= 1;
            }
        break;
        case 2:
            if(dia > 0 && dia < 30)
            {
                todoOk= 1;
            }
        break;
        case 4:
        case 6:
        case 9:
        case 11:
            if(dia > 0 && dia < 31)
            {
                todoOk= 1;
            }
        break;
        }

    }

    return todoOk;
}

void inicializarTrabajos(eTrabajo listaTrabajos[], int tamanioListaTrabajos){

    if(listaTrabajos != NULL && tamanioListaTrabajos > 0)
    {
        for(int i = 0; i < tamanioListaTrabajos; i++)
        {
        listaTrabajos[i].isEmpty = 1;
        }

    }
}
