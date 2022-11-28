#include <iostream>
#include <fstream>
#include <ctime>
#include <cmath>
#include <string>
using namespace std;

struct Ultima_consulta
{
	unsigned int dni;
	tm fechasolicitud;
	tm fechaturno;
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
	char Sexo;
	tm nacimiento;
	string estado;
	string id_os;
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

Paciente* leer_paciente(Paciente *& aux,int *tamactual);
Contacto* leer_contactos(Contacto*& aux2, int* tamactual2);
Ultima_consulta* leer_consultas(Ultima_consulta*& aux3, int* tamactual3);
medicos* leer_medicos(medicos*& aux4, int* tamactual4);
//void cargar_archivos(string Pacientes, string Contactos, string Consultas, string Medicos, string ObraSocial);
double distanciafechas(Ultima_consulta*&aux2);
//bool secretaria_pacientes(string Recuperables, int codigo, Paciente aux, string obrasocial);
void buscarpac(Paciente*& aux, Contacto*& aux2, int*tamactual,int*tamactual2);
void archivados(Ultima_consulta*& aux, Paciente*& aux2, int* tamactual, int* tamactual2);

int consrandom(int maximo, int minimo);
tm nuevacons();
bool bisiestos(int anio);
