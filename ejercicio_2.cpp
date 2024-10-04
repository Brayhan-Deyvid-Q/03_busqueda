#include <iostream>
#include <string>

using namespace std;

struct Fecha {
    int dia;
    int mes;
    int anio;
};

struct Personal {
    string dni;
    string nombres;
};

int compararFechas(Fecha f1, Fecha f2) {
    if (f1.anio < f2.anio){
    	return -1;
	} 
    else if (f1.anio > f2.anio){
    	return 1;
	} 
    else if (f1.mes < f2.mes){
    	return -1;
	} 
    else if (f1.mes > f2.mes){
    	return 1;
	}
    else if (f1.dia < f2.dia){
    	return -1;
	} 
    else if (f1.dia > f2.dia){
    	return 1;
	}
    return 0;  
}

void ordenarPorFecha(Personal per[], Fecha fe[], int n) {
    for (int i = 1; i < n; i++) {
        Personal actualPersonal = per[i];
        Fecha actualFecha = fe[i];
        int j = i - 1;

        while (j >= 0 && compararFechas(fe[j], actualFecha) > 0) {
            fe[j + 1] = fe[j];
            per[j + 1] = per[j];
            j--;
        }

        fe[j + 1] = actualFecha;
        per[j + 1] = actualPersonal;
    }
}

int busquedaBinaria(Fecha fe[], int n, Fecha clave) {
    int izquierda = 0;
    int derecha = n - 1;

    while (izquierda <= derecha) {
        int medio = (izquierda + derecha) / 2;
        int resultadoComparacion = compararFechas(fe[medio], clave);

        if (resultadoComparacion == 0)
            return medio; 
        else if (resultadoComparacion < 0)
            izquierda = medio + 1;
        else
            derecha = medio - 1;
    }

    return -1; 
}

void mostrarPersonal(int n, Personal per[], Fecha fe[]) {
    for (int i = 0; i < n; i++) {
        cout << "DNI: " << per[i].dni << ", Nombre: " << per[i].nombres
             << ", Fecha de nacimiento: " << fe[i].dia << "/" << fe[i].mes << "/" << fe[i].anio << endl;
    }
}

int main() {
    int n;
    cout << "Digite la cantidad de personas a ingresar: ";
    cin >> n;

    Personal per[n];
    Fecha fe[n];
    cout<<"Ingrese los datos personales del personal."<<endl<<endl;

    for (int i = 0; i < n; i++) {
        cout << "\nDatos del personal " << i + 1 << endl;
        cout << "DNI: ";
        cin >> per[i].dni;
        cout << "Nombre: ";
        cin.ignore();
        getline(cin, per[i].nombres);
        cout << "Dia de nacimiento: ";
        cin >> fe[i].dia;
        cout << "Mes de nacimiento: ";
        cin >> fe[i].mes;
        cout << "Anho de nacimiento: ";
        cin >> fe[i].anio;
    }

    ordenarPorFecha(per, fe, n);

    cout << "\nLista de personal ordenada por fecha de nacimiento:\n";
    mostrarPersonal(n, per, fe);

    Fecha clave;
    cout << "\nIngrese la fecha de nacimiento a buscar:\n";
    cout << "Dia: ";
    cin >> clave.dia;
    cout << "Mes: ";
    cin >> clave.mes;
    cout << "Anio: ";
    cin >> clave.anio;

    int resultado = busquedaBinaria(fe, n, clave);

    if (resultado != -1) {
        cout << "\nEl personal con la fecha de nacimiento ingresada es:\n";
        cout << "DNI: " << per[resultado].dni << ", Nombre: " << per[resultado].nombres << endl;
    } else {
        cout << "\nNo se encontro a ninguna persona con esa fecha de nacimiento.\n";
    }

    return 0;
}