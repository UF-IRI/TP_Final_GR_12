#include "headers.h"
using namespace std;
//paso punteros de los structs para poder guardarlos xq no se guardan si son estaticos, los archivos ya los tenes
//completar funciones leer, con un while leyendo archivo cargar datos a los punteros de struct con mem dinamica
//hacer el resize en las funciones "leer" para tener la cantidad de registros


bool Leer_Pacientes(Paciente*& aux, ifstream& pac, int* tam1)
{
	if (aux == nullptr||tam1==nullptr)
		return false;

	Paciente auxpac;
	char coma = ' , ';
	string header;
	getline(pac, header);

	while (pac)
	{
		pac>> auxpac.DNI >> coma;
		getline(pac, auxpac.Nombre, coma);
		getline(pac, auxpac.Apellido, coma);
		pac>> auxpac.Sexo >> coma;
		pac>> auxpac.nacimiento.tm_mday >> coma;
		pac>> auxpac.nacimiento.tm_mon >> coma;
		pac>> auxpac.nacimiento.tm_year >> coma;
		getline(pac, auxpac.estado, coma);
		getline(pac, auxpac.id_os, coma);

	}

	resize_paciente(auxpac, aux, tam1);

	return true;
}

bool Leer_Contactos(Contacto*& aux, ifstream& contact, int* tam2)
{
	if (aux == nullptr||tam2==nullptr)
		return false;
	char coma = ' , ';
	string header;
	Contacto auxcont;

	getline(contact, header);


	while (contact)
	{
		contact >> auxcont.DNI >> coma;
		getline(contact, auxcont.telefono, coma);
		getline(contact, auxcont.celular, coma);
		getline(contact, auxcont.direccion, coma);
		getline(contact, auxcont.mail, coma);
	}
	resize_contactos(auxcont, aux, tam2);

	return true;
}

bool Leer_Consultas(Ultima_consulta*& aux, ifstream& consul, int* tam3)
{
	if (aux == nullptr||tam3==nullptr)
		return false;

	char coma = ' , ';
	string header;
	Ultima_consulta auxconsul;
	getline(consul, header);

	while (consul)
	{
		consul >> auxconsul.dni >> coma;
		consul >> auxconsul.fechasolicitud.tm_mday >> coma;
		consul >> auxconsul.fechasolicitud.tm_mon >> coma;
		consul >> auxconsul.fechasolicitud.tm_year >> coma;
		consul >> auxconsul.fechaturno.tm_mday >> coma;
		consul >> auxconsul.fechaturno.tm_mon >> coma;
		consul >> auxconsul.fechaturno.tm_year >> coma;
		consul >> auxconsul.presento >> coma;
		getline(consul, auxconsul.matriculamedica, coma);
	
	}
	resize_consultas(auxconsul, aux, tam3);
	return true;
}

bool Leer_Medicos(medicos*& aux, ifstream& med, int* tam4)
{
	if (aux == nullptr || tam4 == nullptr)
		return false;

	char coma = ' , ';
	string header;
	medicos auxmed;
	getline(med, header);
	
	while (med)
	{
		med >> auxmed.matricula >> coma;
		getline(med, auxmed.nombre, coma);
		getline(med, auxmed.apellido, coma);
		getline(med, auxmed.telefono, coma);
		getline(med, auxmed.especialidad, coma);
		med >> auxmed.activo >> coma;
	}

	resize_medicos(auxmed, aux, tam4);
	return true;
}
//arrancan los resize 
void resize_paciente(Paciente auxpac,Paciente*& aux,int *tamactual)
{
	
	*tamactual = *tamactual + 1;
	int i = 0;
	Paciente* pac = new Paciente[*tamactual];

	while (i < *tamactual - 1 && *tamactual - 1 != 0) 
	{
		pac[i] = aux[i];
		i++;
	}	
	pac[*tamactual - 1] = auxpac;
	delete[]aux;
	aux = pac;

	return;
}

void resize_contactos(Contacto auxcont,Contacto *&aux2, int* tamactual2) 
{
	*tamactual2 = *tamactual2 + 1;
	int i = 0;
	Contacto* cont = new Contacto[*tamactual2];

	while (i < *tamactual2 - 1 && *tamactual2 - 1 != 0) 
	{
		cont[i] = aux2[i];
		i++;
	}
	cont[*tamactual2 - 1] = auxcont;
	delete[]aux2;
	aux2 = cont;

	return;
}

void resize_consultas(Ultima_consulta auccons,Ultima_consulta*& aux3, int* tamactual3) 
{
	*tamactual3 = *tamactual3 + 1;
	int i = 0;
	Ultima_consulta* consul = new Ultima_consulta[*tamactual3];

	while (i < *tamactual3 - 1 && *tamactual3 - 1 != 0) 
	{
		consul[i] = aux3[i];
		i++;
	}
	consul[*tamactual3 - 1] = auccons;
	delete[]aux3;
	aux3 = consul;
	
	return;
}

void resize_medicos(medicos auxmed,medicos*& aux4, int* tamactual4) 
{
	*tamactual4 = *tamactual4 + 1;
	int i = 0;
	medicos* med = new medicos[*tamactual4];

	while (i < *tamactual4 - 1 && *tamactual4 - 1 != 0) 
	{
		med[i] = aux4[i];
		i++;
	}
	med[*tamactual4 - 1] = auxmed;
	delete[]aux4;
	aux4 = med;

	return;
}





void archivados(Ultima_consulta*& aux, Paciente*& aux2, int* tamactual, int* tamactual2)
{
	ofstream fp;
	int i = 0, j = 0, k = 0;

	fp.open("Archivados.csv", ios::out);
	if (!(fp.is_open()))
		return;
	fp << "DNI,Nombre,Apellido,Sexo,Estado,ObraSocial" << endl;

	while (fp)
	{//no se si esta bien poner esto cuando se crea un archivo

		double diffecha = distanciafechas(aux);

		if (diffecha >= 3652.5 && aux.presento == false)
		{	//funcion mas de 10 anios
			fp << aux2[j].DNI << ",";
			for (i = j; i < *tamactual2; i++)
			{
				for (k = 0; k < *tamactual; k++)
				{
					if (aux2[i].DNI == aux[k].dni)
					{
						fp << aux2[k].DNI << aux2[k].Nombre << "," << aux2[k].Apellido << "," << aux2[k].Sexo << "," << aux2[k].estado << "," << aux2[k].id_os << endl;
					}
					else
					{
						continue;
					}
				}
			}
		}j++;
	}
	fp.close();
	return;
}

//funciones leer

void retornables(Paciente*& aux, int* tamactual, Ultima_consulta*& aux3, int* tamactual3, medicos*& aux4, int* tamactual4) 
{//checkea si esta muerto o internado




}

double distanciafechas(Ultima_consulta *&aux2) //cuando la llamemos en el main hay que meterla dentro de un for
{
	int i = 0;
	tm inicio = aux2[i].fechaturno; //es la fecha de la última consulta que tuvo programada el paciente
	time_t timer;   
	time(&timer);   //usamos el timer para tener la fecha y hora actual 
	//el mktime nos devuelve la cantidad de segundos a partir de la Época Unix (1 de Enero del 1970 00:00:00) hasta la fecha actual. 
	time_t y = mktime(&inicio);      //además, el mktime lo usamos para no tener que sumarle 1 al mes usando la estructura tm y tampoco hace falta sumarle 1900 al año.
	double diferencia = 0;
	if (y != (time_t)(-1))
	{//ambas fechas pasadas por el mktime deben ser distintas de -1 ya que si son iguales a -1 es porque no se pudo representar la fecha/hora en el calendario.
		diferencia = difftime(timer, y) / (86400); //60*60*24    //calculamos y dividimos la diferencia del tiempo que se retorna en segundos por la cantidad de segundos por día.
	}
	return diferencia;
}

void buscarpac(Paciente*& aux, Contacto*& aux2, int*tamactual, int*tamactual2) //no salida por consola
{
	int i = 0,j=0;
	for (i; i < *tamactual; i++) 
	{
		for (j; j < *tamactual2; j++) 
		{
			if (aux[i].DNI == aux2[j].DNI && aux[i].estado!= "fallecido")  
			{
			
			}
			
		}

	}
	
}

int consrandom(int maximo, int minimo)
{
	srand(time(NULL));
	int valor = rand() % (maximo - minimo) + minimo;
	return valor;
}

tm nuevacons()  //funcion para programar una nueva consulta aleatoria
{
	int minrand, horarand, diarand, mesrand, aniorand;
	minrand = consrandom(59, 0);
	horarand = consrandom(20, 6); //las horas en la libreria van de 0 a 23
	mesrand = consrandom(11, 0);  //los meses en la libreria van de 0 a 11
	aniorand = consrandom(126, 123);  //sumamos 122 para que sea mayor a 2022 ya que parte del 1900, en un rango de 3 anios

	int anio = 0;
	bool anio_bisiesto = bisiestos(anio);

	if (anio_bisiesto == true && mesrand == 1)
		diarand = consrandom(29, 1); //los dias del mes van de 0 a 31.
	else
		diarand = consrandom(28, 1);

	if (mesrand == 0 || mesrand == 2 || mesrand == 4 || mesrand == 6 || mesrand == 7 || mesrand == 9 || mesrand == 11)
		diarand = consrandom(31, 1);
	else if (mesrand != 1)
		diarand = consrandom(30, 1);

	tm consulta = { 0, minrand, horarand, diarand, mesrand, aniorand };

	return consulta; //Nos pasa la fecha de la consulta reprogramada.
}

bool bisiestos(int anio)
{
	Ultima_consulta UltConsul;
	if ((UltConsul.fechaturno.tm_year % 4) == 0 && (UltConsul.fechaturno.tm_year % 100) != 0)
		return true;
	else
		return false;
}