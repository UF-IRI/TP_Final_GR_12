using namespace std;

void leer_archivo(string Pacientes, string Contactos, string Consultas, string Medicos, string ObraSocial)
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

double distanciafechas(Paciente aux)
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

ctime nuevacons()  //funcion para programar consulta aleatoria
{
	srand(time(NULL)); //TENDRIAMO QUE HACER EL RANDOM EN UNA FUNCION DISTINTA.
	int minrand, horarand, diarand, mesrand, aniorand;
	minrand = rand() % 59;
	horarand = rand() % 23; //las horas en la libreria van de 0 a 23
	diarand = rand() % 31;
	mesrand = rand() % 11;//los meses en la libreria van de 0 a 11
	aniorand = (rand() % 3) + 122;  //sumamos 122 para que sea mayor a 2022 ya que parte del 1900, en un rango de 2 anios

	tm consulta = { 0, minrand, horarand, diarand, mesrand,aniorand };
	time_t consulta_reprogramada = mktime(&consulta);

	return ctime(&consulta_reprogramada); //la funcion ctiempo(ctime) nos pasa la fecha de la consulta_reprogramada.
}

void cargar_archivos(string Pacientes, string Contactos, string Consultas, string Medicos, string ObraSocial)
{
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