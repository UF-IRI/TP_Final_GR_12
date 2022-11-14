#include <iostream>
#include <fstream>
#include <ctime>
#include <math.h>
#include <string>

struct Ultima_consulta
{
	unsigned int dni;
	time_t fecha;
	bool asistencia;
	string id_medico;
} ultconsul;

struct Contacto
{
	unsigned int id;
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
	unsigned int id_os;
} pac;

struct medicos
{
	unsigned int id;
	string nombre;
	string apellido;
	string especialidad;
} med;

struct obra_social
{
	unsigned int id;
	string cobertura;
} obs;

void leer_archivo(string Pacientes, string Contactos, string Consultas, string Medicos, string ObraSocial);
void cargar_archivos(string Pacientes, string Contactos, string Consultas, string Medicos, string ObraSocial);
double distanciafechas(Paciente aux);
bool secretaria_pacientes(string Recuperables, int codigo, Paciente aux, string obrasocial);
ctime nuevacons();