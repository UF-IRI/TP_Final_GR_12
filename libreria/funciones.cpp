using namespace std;
//paso punteros de los structs para poder guardarlos xq no se guardan si son estaticos, los archivos ya los tenes
//completar funciones leer, con un while leyendo archivo cargar datos a los punteros de struct con mem dinamica
//hacer el resize en las funciones "leer" para tener la cantidad de registros

void archivados(Ultima_consulta*& aux, Paciente*& aux2, int* tamactual, int* tamactual2) {
	ofstream fp;
	int i = 0, j = 0, k = 0;
	fp.open("Archivados.csv", ios::out);
	if (!(fp.is_open()))
		return;
	fp << "DNI,Nombre,Apellido,Sexo,Estado,ObraSocial" << endl;
	while (fp) {//no se si esta bien poner esto cuando se crea un archivo
		if (&& aux.[j]presento == 0) {	//funcion mas de 10 anios
			fp << aux2.[j]DNI << ",";
			for (i = j; i < *tamactual2; i++) {
				for (k = 0; k < *tamactual; k++) {
					if (aux2.[i]DNI == aux.[k]DNI) {
						fp << aux.[k]Nombre << "," << aux.[k]Apellido << "," << aux.[k]Sexo << "," << aux.[k]Estado << "," << aux.[k]id_os << endl;
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
	Paciente aux;
	Contacto aux2;
	Ultima_consulta aux3;
	string encabezados;
	char coma = ‘, ’;
	unsigned int dniaux;

	fstream fp, fp2, fp3;
	fp.open("Paciente", ios::in);
	fp2.open("Contacto", ios::in);
	fp3.open("Ultima_Consulta", ios::in);
	if (!(fp.is_open() && fp2.is_open() && fp3.is_open()))
	{
		return nullptr;  //retorna el puntero nulo
	}
	fp >> encabezados >> coma >> encabezados >> coma >> encabezados >> coma >> encabezados >> coma >> encabezados >> coma >> encabezados; // DNI, Nombre, Apellido, genero, nacimiento, id_os

	fp2 >> encabezados >> coma >> encabezados >> coma >> encabezados >> coma >> encabezados >> coma >> encabezados; // id, telefono, celular, direccion, mail

	fp3 >> encabezados >> coma >> encabezados >> coma >> encabezados >> coma >> encabezados; //dni, fecha, asistencia, id_medico

	while (fp)
	{
		fp >> aux.DNI >> coma >> aux.Nombre >> coma >> aux.Apellido >> coma >> aux.genero >> coma >> aux.nacimiento >> coma >> aux.id_os;
		while (fp2)
		{
			fp2 >> aux2.id >> coma >> aux2.telefono >> coma >> aux2.celular >> coma >> aux2.direccion >> coma >> aux2.mail;
			while (fp3)
			{
				fp3 >> aux3.dni >> coma >> aux3.fecha >> coma >> aux3.asistencia >> coma >> aux3.id_medico;
				if (aux.dni == aux2.id && aux2.id == aux3.dni)
				{

					break;
				}
			}
			fp3.seekg(fp3.beg);
			// Volvemos a salter el encabezado de fp3, porque posicionamos el cursor de lectura al inicio del archivo.
			fp3 >> encabezados >> coma >> encabezados >> coma >> encabezados >> coma >> encabezados;
		}
		fp2.seekg(fp2.beg);
		fp2 >> encabezados >> coma >> encabezados >> coma >> encabezados >> coma >> encabezados >> coma >> encabezados;

		fp.close();
		fp2.close();
		fp3.close();
	}

	return;
}
Contacto* leer_contactos(Contactos*& aux2, int* tamactual2) {
	ifstream fp;
	int i = 0,j=0;
	

	char coma;
	string header;
	fp.open("Contactos.csv", ios::in);
	if (!(fp.is_open()))
		return nullptr;
	fp >> header >> coma >> header >> coma >> header >> coma >> header >> coma >> header;
	while (fp) {
		*tamactual2 = *tamactual2 + 1;
		Contacto* cont = new cont[*tamactual2];
		while (i < *tamactual - 1 && *tamactual - 1 != 0) {
			cont[i] = aux2[i];
			i++;
		}
		fp >> aux2.[j]DNI >> coma >> aux2.[j]telefono >> coma >> aux2.[j]celular >> coma >> aux2.[j]direccion >> coma >> aux2.[j]mail;
		j++;
	}
	delete[]aux2;
	aux2 = cont;
	delete[]cont;
	fp.close();
	return aux2;
}
Ultima_consulta* leer_consultas(Ultima_consulta*& aux3, int* tamactual3) {
	ifstream fp;
	int i = 0,j=0;

	char coma;
	string header;
	fp.open("Consultas.csv", ios::in);
	if (!(fp.is_open()))
		return nullptr;
	fp >> header >> coma >> header >> coma >> header >> coma >> header >> coma >> header;
	while (fp) {
		*tamactual3 = *tamactual3 + 1;
		Ultima_consulta* consul = new consul[*tamactual3];
		while (i < *tamactual3 - 1 && *tamactual3 - 1 != 0) {
			consul[i] = aux3[i];
			i++;
		}

		fp >> aux3.[j]DNI >> coma >> aux3.[j]fechasolicitud >> coma >> aux3.[j]fechaturno >> coma >> aux3.[j]presento >> coma >> aux3.[j]matriculamedica;
		j++;
	}
	delete[]aux3;
	aux3 = consul;
	delete[]consul;
	fp.close();
	return aux3;
}
medicos* leer_medicos(medicos*& aux4, int* tamactual4) {
	ifstream fp;
	int i = 0,j=0;

	char coma;
	string header;
	fp.open("Consultas.csv", ios::in);
	if (!(fp.is_open()))
		return nullptr;
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
	delete[]aux4;
	aux4 = med;
	delete[]med;
	fp.close();
	return aux3;
}

void retornables(Paciente*& aux, int* tamactual, Ultima_consulta*& aux3, int* tamactual3, medicos*& aux4, int* tamactual4) {//checkea si esta muerto o internado
	ofstream fp;
	fp.open("Recuperables.csv", ios::out);
	if (!(fp.is_open()))
		return;



}

double distanciafechas(Paciente*& aux,Ultima_consulta*&aux2)
{
	tm inicio = aux;    //es la fecha de la última consulta que tuvo programada el paciente
	tm actual;   //es la fecha y hora actual 
	time_t x = mktime(&inicio);     //el cambiartiempo nos devuelve la cantidad de segundos a partir de la Época Unix (1 de Enero del 1970 00:00:00) hasta la fecha actual. 
	time_t y = mktime(&actual);      //además, el cambiartiempo lo usamos para no tener que sumarle 1 al mes usando la estructura tm y tampoco hace falta sumarle 1900 al año.
	double diferencia = 0;
	if (x != (time_t)(-1) && y != (time_t)(-1))
	{//ambas fechas pasadas por el mktime deben ser distintas de -1 ya que si son iguales a -1 es porque no se pudo representar la fecha/hora en el calendario.
		diferencia = difftime(y, x) / (60 * 60 * 24);     //calculamos y dividimos la diferencia del tiempo que se retorna en segundos por la cantidad de segundos por día.
	}
	return diferencia;
}
int minrandom() {
	srand(time(NULL));
	int valor = rand % 60;
	return valor;
}
int horaramdom() {
	int valor;
	srand(time(NULL));
	valor = rand() % 24;
	return valor;
}
int diarandom() {
	srand(time(NULL));
	int valor;
	valor = rand() % 31;
	return valor;
}
int mesrandom() {
	int valor;
	srand(time(NULL));
	valor = rand() % 12;
	return valor;
}
int aniorandom() {
	srand(time(NULL));
	int valor;
	valor = (rand() % 3) + 122;
	return valor;
}
ctime nuevacons()  //funcion para programar consulta aleatoria
{

	int minrand, horarand, diarand, mesrand, aniorand;
	minrand = minrandom();
	horarand = horarandom(); //las horas en la libreria van de 0 a 23
	diarand = diarandom();
	do {
		mesrand = mesrandom();//agregar casos febrero
		if (mesrand == 2 && diarand == 28)
			break;//los meses en la libreria van de 0 a 11
	} while (mesrand == 1 || mesrand == 3 || mesrand == 5 || mesrand == 8 || mesrand == 10 && diarand == 31);
	aniorand = aniorandom();  //sumamos 122 para que sea mayor a 2022 ya que parte del 1900, en un rango de 2 anios
	
	tm consulta = { 0, minrand, horarand, diarand, mesrand,aniorand };
	time_t consulta_reprogramada = mktime(&consulta);

	return ctime(&consulta_reprogramada); //la funcion ctiempo(ctime) nos pasa la fecha de la consulta_reprogramada.
}

void cargar_archivos(Paciente *& aux,Contacto *& aux2,Ultima_consulta *& aux3)//no se que hace esto
{//aca se tienen que cargar los archivados
	string encabezado;
	fstream fp2;
	fp2.open("archivo", ios::out);
	fstream fp2;
	if (!(fp2.is_open()))
	{
		return nullptr;  //retornaria el puntero nulo
	}
	leer_archivo(encabezado);
	escribir(archivo, aux2);//cargamos los datos en el archivo
	fp2.close();
	return;
}

void buscarpac(Paciente*& aux, Contactos*& aux2,int *tamactual,int*tamactual2) {//fijarse si esta bien
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

	

