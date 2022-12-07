#include <iostream>
#include <fstream>
#include <ctime>
#include <cmath>
#include <string>
using namespace std;

struct Ultima_consulta
{
	int dni;
	tm fechasolicitud;  //usamos las estrucutras en tm ya que es el tipo d eestructura que usa la libreria ctime.
	tm fechaturno = {0,0,0};
	bool presento;
	string matriculamedica;
};

struct Contacto
{
	int DNI;
	string telefono;
	string celular;
	string direccion;
	string mail;
};

struct Paciente
{
	int DNI;
	string Nombre;
	string Apellido;
	char Sexo;
	tm nacimiento;
	string estado;
	string id_os;
};

struct medicos
{
	string matricula;
	string nombre;
	string apellido;
	string telefono;
	string especialidad;
	bool activo;
};

struct Pos_recp //posibles recuperables,creamos la struct para trabajar mas facilmente con el archivo:Posibles recupeables
{
	int DNI;
	string nombre;
	string apellido;
	string telefono;
	string celular;
	string matr_medico;
	string nombre_med;
	string apellido_med;
	string telefono_med;
	string esp_med;
	bool activo;

};

//LECTURA
bool Leer_Pacientes(Paciente*& aux, ifstream& pac, int* tam1);
bool Leer_Contactos(Contacto*& aux, ifstream& contact, int* tam2);
bool Leer_Consultas(Ultima_consulta*& aux, ifstream& consul, int* tam3);
bool Leer_Medicos(medicos*& aux, ifstream& med, int* tam4);

//RESIZE

void resize_paciente(Paciente auxpac, Paciente*& aux, int* tamactual);
void resize_contactos(Contacto auxcont, Contacto*& aux2, int* tamactual2);
void resize_consultas(Ultima_consulta auccons, Ultima_consulta*& aux3, int* tamactual3);
void resize_medicos(medicos auxmed, medicos*& aux4, int* tamactual4);

//DIVISION POR GRUPOS

bool division_grupos(Paciente*& aux, int* tam1, Ultima_consulta*& aux2, int* tam2, Contacto*& aux3, int* tam3, medicos*& aux4, int* tam4,fstream &fp,fstream &fp2);
int buscarpac(Paciente*& aux, int* tam, unsigned int dni);

void cargararchivados(Paciente aux, fstream& fp);
string buscarmed(medicos*& aux4, int* tamactual4, Ultima_consulta*& aux2, int* tam2, Paciente aux, Paciente*& aux3, int* tam);

void cargar_posibles_recup(Pos_recp aux, fstream& fp);

//SECRETARIA

bool secretaria_de_pacientes(Pos_recp*& aux5, fstream& recups, int* tam5);
void resize_pos_recp(Pos_recp auxrecup, Pos_recp*& aux5, int* tam5);
void contactar_pac(Pos_recp pac, fstream& arch, Paciente*& aux, int* tam1, tm& nueva_consulta, string& nueva_obra_social);
int buscarpac2(Paciente*& aux, int* tam1, unsigned int dni);

//FUNCIONES AUXULIARES

bool distanciafechas(Ultima_consulta*& aux2, int pospaciente, Paciente*& aux, int* tam2);
tm ultcons(Ultima_consulta*& aux2, int pospaciente, Paciente*& aux, int* tam2);
bool bisiestos(int anio);
int consrandom(int maximo, int minimo);
tm nuevacons();
bool mayorahoy(tm nueva_consulta);
string random_obra_social(string obra_social, Paciente*& aux, int* tam2);
