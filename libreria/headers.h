#include <iostream>
#include <fstream>
#include <ctime>
#include <math.h>
#include <string>

struct Ultima_consulta
{
	unsigned int dni;
	time_t fechaturno;
	time_t fechasolicitud;
	bool presento;
	string matriculamedica;
} ultconsul;

struct Contacto
{
	unsigned int DNI;
	string telefono;
	string celular;
	string direccion;
	string mail;
} contact;

struct Paciente
{
	unsigned int DNI;
	string Nombre;
	string Apellido;
	string Genero;
	Fecha nacimiento;
	string estado;
	unsigned int id_os;
} pac;

struct medicos
{
	unsigned int matricula;
	string nombre;
	string apellido;
	string telefono;
	string especialidad;
	bool activo;
} med;

struct obra_social
{
	unsigned int id;
	string obra_social;
} obs;

void leer_Paciente(Paciente *& aux,int *tamactual,int cantaumentar);
void leer_Contacto(Contacto*& aux2, int* tamactual2, int cantaumentar2);
void leer_consultas(Ultima_consulta*& aux3, int* tamactual3, int cantaumentar3);
void leer_medico(medicos*& aux4, int* tamactual4, int cantaumentar4);

void cargar_archivos(string Pacientes, string Contactos, string Consultas, string Medicos, string ObraSocial);
double distanciafechas(Paciente aux);
bool secretaria_pacientes(string Recuperables, int codigo, Paciente aux, string obrasocial);
ctime nuevacons();
void buscarpac(Paciente*& aux, Contacto*& aux2);