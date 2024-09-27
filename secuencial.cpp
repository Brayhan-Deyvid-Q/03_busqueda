#include <iostream>
using namespace std;

int secuencialDes(int [], int , int);
int secuencialOrd(int [], int , int);

int main(){
	int n, vb, opcion, po;
	
	cout<<"Ingrese la cantidad de valores a ingresar: ";
	cin>>n;
	int array[n];
	for(int i=1; i<=n; i++){
		cout<<"Ingrese el valor "<<i<<" : ";
		cin>>array[i];
		cout<<endl;
	}
	do{
		cout<<"Para buscar un valor, ¿los datos proporcionados se encuentran ordenados o desordendos?"<<endl;
		cout<<"1) Ordenados"<<endl;
		cout<<"2) Desordenados"<<endl;
		cout<<"3) Salir"<<endl;
		cout<<"Ingrese una opcion: ";
		cin>>opcion;
		cout<<endl;	
	
		switch(opcion){
			case 1:
				cout<<"Ingrese el valor que desea buscar: ";
				cin>> vb;
				po = secuencialOrd( array, n, vb);
				if(po <=0){
					cout<<"El valor no se encuentra dentro del arreglo.";
				}else{
					cout<<"El valor se encuentra en la posicion: "<<po<<" del arreglo.";
				}
				cout<<endl;
				break;
			case 2:
				cout<<"Ingrese el valor que desea buscar: ";
				cin>> vb;
				po = secuencialDes(array, n, vb);
				if(po == 0){
					cout<<"El valor no se encuentra en el arreglo.";
				}else{
					cout<<"El valor se encuentra en la posicion: "<<po<<" del arreglo.";
				}
				cout<<endl;
				break;
			case 3:
				break;
			default:
				cout<<"ERROR... ingrese un valor correcto.";
				break;
		}
	}while(opcion != 3);

	return 0;
}
int secuencialOrd(int a[], int n, int dato){
	int i=1;
	int pos;
	while(i<=n && a[i]<dato){
		i=i+1;
	}
	if(i>n || a[i]!=dato){
		pos = -i;
	}else{
		pos = i;
	}
	return pos;
}

int secuencialDes(int a[], int n, int dato){
	int pos = 0;
	int i=1;
	while(i<=n && a[i]!=dato){
		i=i+1;
	}
	if(i<=n){
		pos = i;
	}
	
	return pos;
}

