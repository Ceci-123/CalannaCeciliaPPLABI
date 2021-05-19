#ifndef MOTO_H_INCLUDED
#define MOTO_H_INCLUDED


typedef struct{
        int dia;
        int mes;
        int anio;
}eFecha;

typedef struct{
        int id;
        char marca[20];
        int idTipo;
        int idColor;
        int cilindrada;
        int isEmpty;

 }eMoto;

 typedef struct{
        int id;
        char descripcion[20];
        float precio;
       int isEmpty;

 }eServicio;

 typedef struct{
        int id;
        eFecha fecha;
        char nombre[20];
        int idMoto;
        int idServicio;
        int isEmpty;

 }eTrabajo;

typedef struct{
        int id;
        char nombreColor[20];
        int isEmpty;

 }eColor;

 typedef struct{
        int id;
        char descripcion[20];
        int isEmpty;

 }eTipoMoto;


 int menu();
void cambiarFlagATrue(int* bandera);
int buscarMotoLibre(eMoto listaMotos[], int tamanioListaMotos);
int altaMoto(eMoto listaMotos[], int tamanioListaMotos, int* nextIdMoto);
int bajaMoto(eMoto listaMotos[], int tamanioListaMotos, eColor listadoDeColores[], int tamanioListadoColores, eTipoMoto listadoDeTipos[], int tamanioListaTipos);
void mostrarMotos(eMoto listaMotos[], int tamanioListaMotos, eColor listadoDeColores[], int tamanioListadoColores, eTipoMoto listadoTipos[], int tamanioListadoTipos);
void mostrarMoto(eMoto unaMoto, eColor listadoDeColores[], int tamanioListadoColores, eTipoMoto listadoTipos[], int tamanioListadoTipos);
void cargarNombreColor(eColor listadoDeColores[], int tamanioListadoColores, int identificador, char descripcion[]);
int buscarMotoXId(eMoto listaMotos[], int tamanioListaMoto, int idABuscar);
void harcodearColor(eColor listadoDeColores[], int tamanioListadoColores);
void inicializarMoto(eMoto listaMotos[], int tamanioListaMotos);
void mostrarColores(eColor listadoDeColores[], int tamanioListadoColores);
void harcodearTipo(eTipoMoto listadoDeTipos[], int tamanioListadoTipos);
void mostrarTipos(eTipoMoto listadoDeTipos[], int tamanioListadoTipos);
int validarCilindrada(int cilindrada);
void cargarNombreTipo(eTipoMoto listadoDeTipos[], int tamanioListadoTipos, int identificador, char descripcion[]);
int modificarMoto(eMoto listadeMotos[], int tamanioListaMoto, eColor listadoDeColores[], int tamanioListadoColor, eTipoMoto listadoTipos[], int tamanioListadoTipos);
void harcodearServicios(eServicio listadoDeServicios[], int tamanioListadoServicios);
void mostrarServicios(eServicio listadoDeServicios[], int tamanioListadoServicios);
int ordenarMotos(eMoto listadeMotos[], int tamanioListaMotos);
void mostrarTrabajos(eTrabajo listadoDeTrabajos[], int tamanioListadoTrabajos);
int buscarTrabajoLibre(eTrabajo listaTrabajos[], int tamanioListaTrabajos);
int altaTrabajo(eTrabajo listaTrabajos[], int tamanioListaTrabajos, int* nextIdTrabajos);
int validarFecha( int dia, int mes, int anio);
void inicializarTrabajos(eTrabajo listaTrabajos[], int tamanioListaTrabajos);
#endif // MOTO_H_INCLUDED
