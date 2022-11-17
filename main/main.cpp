#include "iri.cpp"
#include <iostream>

int main() {

    Paciente* leer_Paciente(Paciente * &aux, int* tamactual, int cantaumentar);
    Contacto* leer_Contacto(Contacto * &aux2, int* tamactual2, int cantaumentar2);
    Ultima_consulta* leer_consultas(Ultima_consulta * &aux3, int* tamactual3, int cantaumentar3);
    medicos* leer_medico(medicos * &aux4, int* tamactual4, int cantaumentar4);
    double distanciafechas(Paciente * &aux, Ultima_consulta * &aux2);
    void buscarpac(Paciente * &aux, Contacto * &aux2);
    void archivados(Ultima_consulta * &aux, Paciente * &aux2, int* tamactual, int* tamactual2);

    return EXIT_SUCCESS;
}
