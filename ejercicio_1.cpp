#include <iostream>
#include <string>

using namespace std;

struct Polinomio{
	int coef; 
	int exp; 
};

void mostrarPoli(int n, Polinomio a[]){
	cout << "Se tiene el polinomio siguiente:" << endl;
	cout<<"\nP(x)=";
	for(int i=0; i<n; i++){
		cout<<a[i].coef<<"x^"<<a[i].exp;
		if (i < n-1) {
            cout<<"+";  
        }
	}  
	cout<<endl; 
}

int busquedaSec(int n, Polinomio a[], int coe, int ex) {
    int i = 0;

    while (i < n) {
        if (a[i].coef == coe && a[i].exp == ex) {
            return i;  
        }
        i++;
    }
    return -1;  
}

int main(){
	int coef, exp; 
	int result; 
	
	Polinomio pol[4]={{2,5},{3,4},{4,3},{2,2}}; 
	
	int cantpol = 4; 
	
	mostrarPoli(cantpol, pol);	
	
	cout<<"Digite un monomio para saber si existe en el arreglo: "<<endl; 
	cout<<"Coeficiente: "; 
	cin>>coef; 
	cout<<"Exponente: "; 
	cin>>exp; 
	
	result = busquedaSec(cantpol, pol, coef, exp); 
	
	cout<<endl; 
	if (result != -1) {
        cout << "El monomio " << coef << "x^" << exp << " existe dentro del polinomio." << endl;
    } 
	else {
        cout << "El monomio " << coef << "x^" << exp << " no existe dentro del polinomio." << endl;
    }
	return 0; 
}