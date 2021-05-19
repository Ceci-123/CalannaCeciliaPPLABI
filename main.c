#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moto.h"

#define TAMOTO 20
#define TAMCOL 5
#define TAMTIPO 4
#define TAMSERV 4
#define TAMTRAB 20

int main()
{

  // variables
  char salir = 'n';
   int flagAlta = 0;
   eMoto nominaDeMotos[TAMOTO];
   eColor nominaDeColores[TAMCOL];
   eTipoMoto nominaDeTipos[TAMTIPO];
   eServicio nominaDeServicios[TAMSERV];
   eTrabajo nominaDeTrabajos[TAMTRAB];
   int nextIdMoto = 1;
    int devolucionDeAlta;
   int devolucionDeBaja;
   int devolucionDeModificar;


// inicializaciones
   inicializarMoto(nominaDeMotos, TAMOTO);
    harcodearColor(nominaDeColores, TAMCOL);
    harcodearTipo(nominaDeTipos, TAMTIPO);
    harcodearServicios(nominaDeServicios, TAMSERV);
    inicializarTrabajos(nominaDeTrabajos, TAMTRAB);
      do {

	        switch(menu())
	        {
	            case 1:
	            printf("------ALTA DE Moto-----------\n");
	            devolucionDeAlta = altaMoto(nominaDeMotos, TAMOTO, &nextIdMoto);
	            if(devolucionDeAlta == 1)
                {
                    cambiarFlagATrue(&flagAlta);
                    printf("Alta de moto exitosa\n");
                    system("pause");
                }
	            break;
	            case 2:
	            printf("---------MODIFICAR Moto-----------\n");
	            if(!flagAlta)
                {

                    printf("No pueden realizarse modificaciones hasta que no se realizen altas\n");
	                system("pause");
                }
                devolucionDeModificar = modificarMoto(nominaDeMotos, TAMOTO, nominaDeColores, TAMCOL, nominaDeTipos, TAMTIPO);
	            if(devolucionDeModificar == 1)
                {
                    printf("Modificacion realizada exitosamente\n");
                    system("pause");
                }
                else
                {
                    printf("Ocurrio un  error en la modificacion");
                }
	            break;
	            case 3:
	            printf("---------BAJA DE Moto-----------\n");
	            if(!flagAlta)
                {
                    printf("No pueden realizarse bajas hasta que no se realizen altas\n");
	                system("pause");
                }
                devolucionDeBaja = bajaMoto(nominaDeMotos, TAMOTO, nominaDeColores, TAMCOL, nominaDeTipos, TAMTIPO);
                if(devolucionDeBaja == 1)
                {
                    printf("Baja realizada exitosamente\n");
                    system("pause");
                }
                else
                {
                    printf("Ocurrio un  error en la baja");
                }
	            break;
	            case 4:
	            printf("----------LISTAR Motos----------\n");
	            if(!flagAlta)
                {
                    printf("No pueden realizarse informes hasta que no se realizen altas\n");
	                system("pause");
                }
                ordenarMotos(nominaDeMotos, TAMOTO);
                mostrarMotos(nominaDeMotos, TAMOTO, nominaDeColores, TAMCOL, nominaDeTipos, TAMTIPO);
                system("pause");

	            break;
	            case 5:
	            printf("---------LISTAR Tipos--------\n");
                mostrarTipos(nominaDeTipos, TAMTIPO);
	            system("pause");

	            break;
                case 6:
	            printf("---------Listar colores --------\n");

	            mostrarColores(nominaDeColores, TAMCOL);
                system("pause");
                case 7:
	            printf("---------Listar servicios --------\n");
                mostrarServicios(nominaDeServicios, TAMSERV);
                system("pause");
	            break;
	            case 8:
	            printf("---------Alta de trabajos --------\n");

                system("pause");
	            break;
	            case 9:
	            printf("---------Listar trabajos --------\n");
                mostrarTrabajos(nominaDeTrabajos, TAMTRAB);
                system("pause");
	            break;
	            case 10:
	            printf("seguro que quiere salir? s / n\n");
	            fflush(stdin);
	            scanf("%c", &salir);
	            break;
                default:
	            printf("Opcion no valida, reingrese opcion\n");
	            system("pause");
	            break;
            }

      }while(salir == 'n'); // fin del do while del menu

    return 0;
}
