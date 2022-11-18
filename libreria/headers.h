#include <iostream>
#include <fstream>
#include <ctime>
#include <math.h>
#include <string>
using namespace std;

struct Ultima_consulta
{
	unsigned int dni;
	time_t fechaturno;
	time_t fechasolicitud;
	bool presento;
	string matriculamedica;
};

struct Contacto
{
	unsigned int DNI;
	string telefono;
	string celular;
	string direccion;
	string mail;
};

struct Paciente
{
	unsigned int DNI;
	string Nombre;
	string Apellido;
	string Genero;
	time_t nacimiento;
	string estado;
	unsigned int id_os;
};

struct medicos
{
	unsigned int matricula;
	string nombre;
	string apellido;
	string telefono;
	string especialidad;
	bool activo;
};

Paciente* leer_paciente(Paciente *& aux,int *tamactual,int cantaumentar);
Contacto* leer_contactos(Contacto*& aux2, int* tamactual2, int cantaumentar2);
Ultima_consulta* leer_consultas(Ultima_consulta*& aux3, int* tamactual3, int cantaumentar3);
medicos* leer_medicos(medicos*& aux4, int* tamactual4, int cantaumentar4);
int minrandom();
int horaramdom();
int diarandom();
int mesrandom();
int aniorandom();
//void cargar_archivos(string Pacientes, string Contactos, string Consultas, string Medicos, string ObraSocial);
double distanciafechas(Paciente*& aux,Ultima_consulta*&aux2);
//bool secretaria_pacientes(string Recuperables, int codigo, Paciente aux, string obrasocial);
ctime nuevacons();
void buscarpac(Paciente*& aux, Contacto*& aux2, int*tamactual,int*tamactual2);
void archivados(Ultima_consulta*& aux, Paciente*& aux2, int* tamactual, int* tamactual2);
