
#include <headers.h>
using namespace std;
//paso punteros de los structs para poder guardarlos xq no se guardan si son estaticos, los archivos ya los tenes
//completar funciones leer, con un while leyendo archivo cargar datos a los punteros de struct con mem dinamica
//hacer el resize en las funciones "leer" para tener la cantidad de registros

void archivados(Ultima_consulta*& aux, Paciente*& aux2, int* tamactual, int* tamactual2) 

{
	ofstream fp;
	int i = 0, j = 0, k = 0;


	fp.open("Archivados.csv", ios::out);
	if (!(fp.is_open()))
		return;
	fp << "DNI,Nombre,Apellido,Sexo,Estado,ObraSocial" << endl;

	while (fp) {//no se si esta bien poner esto cuando se crea un archivo
		
		double diffecha = distanciafechas(aux);

		if (diffecha>=3625.25 && aux.presento == 0) {	//funcion mas de 10 anios
			fp << aux2[j].DNI << ",";
			for (i = j; i < *tamactual2; i++) {
				for (k = 0; k < *tamactual; k++) {
					if (aux2[i].DNI == aux[k].DNI) {
						fp << aux[k].nombre << "," << aux[k].Apellido << "," << aux[k].Sexo << "," << aux.[k]Estado << "," << aux.[k]id_os << endl;
					}
					else {
						continue;
					}
				}
			}
		}j++;
	}
	fp.close();
	return;
}


//hay que cambiar el leer paciente
Paciente* leer_paciente(Paciente*& aux,int *tamactual)
{
	
	int i = 0, j = 0;

	char coma;
	string header;
	
	fp >> header >> coma >> header >> coma >> header >> coma >> header >> coma >> header >> coma >> header>>coma>>header;
	while (fp) {
		*tamactual = *tamactual + 1;
		Paciente* pac = new Paciente[*tamactual];
		while (i < *tamactual - 1 && *tamactual - 1 != 0) 
		{
			pac[i] = aux[i];
			i++;
		}
		fp >> aux[j].DNI >> coma >> aux[j].Nombre >> coma >> aux[j].Apellido >> coma >> aux[j].Sexo >> coma >> aux[j].nacimiento >> coma >> aux[j].id_os;
		j++;
	}
	
	aux = pac;
	delete[]pac;

	return aux;
}

Contacto* leer_contactos(Contacto aux2, int* tamactual2) {

	int i = 0,j=0;
	

	char coma;
	string header;
	
	fp >> header >> coma >> header >> coma >> header >> coma >> header >> coma >> header;
	while (fp) {
		*tamactual2 = *tamactual2 + 1;
		Contacto* cont = new Contacto[*tamactual2];
		while (i < *tamactual2 - 1 && *tamactual2 - 1 != 0) {
			cont[i] = aux2[i];
			i++;
		}
		fp >> aux2[j].DNI >> coma >> aux2.[j]telefono >> coma >> aux2.[j]celular >> coma >> aux2.[j]direccion >> coma >> aux2.[j]mail;
		j++;
	}
	
	aux2 = cont;
	delete[]cont;
	
	return aux2;
}
Ultima_consulta* leer_consultas(Ultima_consulta*& aux3, int* tamactual3) {
	
	int i = 0,j=0;

	char coma;
	string header;
	
	fp >> header >> coma >> header >> coma >> header >> coma >> header >> coma >> header;
	while (fp) {
		*tamactual3 = *tamactual3 + 1;
		Ultima_consulta* consul = new Ultima_consulta[*tamactual3];
		while (i < *tamactual3 - 1 && *tamactual3 - 1 != 0) {
			consul[i] = aux3[i];
			i++;
		}

		fp >> aux3.[j]DNI >> coma >> aux3.[j]fechasolicitud >> coma >> aux3.[j]fechaturno >> coma >> aux3.[j]presento >> coma >> aux3.[j]matriculamedica;
		j++;
	}
	
	aux3 = consul;
	delete[]consul;
	
	return aux3;
}
medicos* leer_medicos(medicos*& aux4, int* tamactual4) {

	int i = 0,j=0;

	char coma;
	string header;

	fp >> header >> coma >> header >> coma >> header >> coma >> header >> coma >> header>>coma>>header;
	while (fp) {
		*tamactual4 = *tamactual4 + 1;
		medicos* med = new medicos[*tamactual4];
		while (i < *tamactual - 1 && *tamactual - 1 != 0) {
			med[i] = aux4[i];
			i++;
		}
		fp >> aux4.[j]matricula >> coma >> aux4.[j]nombre >> coma >> aux4.[j]apellido >> coma >> aux4.[j]telefono >> coma >> aux4.[j]especialidad>>coma>>aux4.[j]activo;
		j++;
	}

	aux4 = med;
	delete[]med;
	
	return aux3;
}

void retornables(Paciente*& aux, int* tamactual, Ultima_consulta*& aux3, int* tamactual3, medicos*& aux4, int* tamactual4) {//checkea si esta muerto o internado




}

double distanciafechas(Ultima_consulta*&aux2)
{
	tm inicio = *aux2.fechaturno; //es la fecha de la última consulta que tuvo programada el paciente
	tm actual; //es la fecha de la última consulta que tuvo programada el paciente
	struct tm* timeinfo;
	time(&actual);
	timeinfo = localtime(&actual);
	tm hoy = asctime(timeinfo));    //es la fecha y hora actual 
	time_t x = mktime(&hoy);     //el cambiartiempo nos devuelve la cantidad de segundos a partir de la Época Unix (1 de Enero del 1970 00:00:00) hasta la fecha actual. 
	time_t y = mktime(&actual);      //además, el cambiartiempo lo usamos para no tener que sumarle 1 al mes usando la estructura tm y tampoco hace falta sumarle 1900 al año.
	double diferencia = 0;
	if (x != (time_t)(-1) && y != (time_t)(-1))
	{//ambas fechas pasadas por el mktime deben ser distintas de -1 ya que si son iguales a -1 es porque no se pudo representar la fecha/hora en el calendario.
		diferencia = difftime(y, x) / (86400); //60*60*24    //calculamos y dividimos la diferencia del tiempo que se retorna en segundos por la cantidad de segundos por día.
	}
	//funcion bisisesto y dividir para que devuelva anios
	return diferencia;
}
int consrandom(int maximo,int minimo) {
	srand(time(NULL));
	int valor = rand % (maximo-minimo)+minimo;
	return valor;
}

ctime nuevacons()  //funcion para programar consulta aleatoria
{

	int minrand, horarand, diarand, mesrand, aniorand;
	minrand = consrandom(max, min);
	horarand = consrandom(max, min); //las horas en la libreria van de 0 a 23
	diarand = cosnrandom(max, min);
	do {
		mesrand = consrandom(max, min);//agregar casos febrero
		if (mesrand == 2 && diarand == 28)
			break;//los meses en la libreria van de 0 a 11
	} while (mesrand == 1 || mesrand == 3 || mesrand == 5 || mesrand == 8 || mesrand == 10 && diarand == 31);
	aniorand = consrandom(max,min);  //sumamos 122 para que sea mayor a 2022 ya que parte del 1900, en un rango de 2 anios
	
	tm consulta = { 0, minrand, horarand, diarand, mesrand,aniorand };
	time_t consulta_reprogramada = mktime(&consulta);

	return ctime(&consulta_reprogramada); //la funcion ctiempo(ctime) nos pasa la fecha de la consulta_reprogramada.
}


void buscarpac(Paciente*& aux, Contactos*& aux2,int *tamactual,int*tamactual2) {//no salida por consola
	{
		int i = 0,j=0;
	for (i; i < *tamactual; i++) {
		for (j; j < *tamactual2; j++) {
			if (aux.[i]DNI == aux2.[j]DNI && aux.[i]estado!= "fallecido") {
				cout << aux.[i]Nombre << "," << aux.[i]Apellido << "," << aux.[i]genero << "," << aux.[i]estado << "," << aux.[i]is_os << endl;
				cout << aux2.[j]telefono << "," << aux2.[j]celular << "," << aux2.[j]mail << endl;
			}
			else {
				cout << aux.[i]Nombre << "," << aux.[i]Apellido << "," << aux.[i]genero << "," << aux.[i]estado << ", no hay contacto registrado" << endl;;
			}
		}

	}
	
}

	

