#include <iostream>
using namespace std; 

int binario (int [], int , int);

int main(){
	int n, R, dato;
 
	cout <<"Digite la cantidad de elementos del arreglo: "<< endl; 
	cin>>n; 
	
	int a[n]; 
	cout << "Ingrese los elementos de su areglo"<<endl;
	for(int i=0; i<n; i++){
	   cout<<"Elemento "<< 1+i << " : ";
	   cin>>a[i]; 
	}
	
	cout<<"\nEscriba el elemento a buscar en el arreglo: ";
	cin>>dato; 
	
	R = binario(a, n, dato); 
	
	if(R >= 0){
		cout<<"El elemento existe en el arreglo y se encuentra en el indice :" << R<<endl; 
	}
	else{
		cout<<"No se encuentra en el arreglo. "<<endl;
		cout<<"El elemento se deberia ubicar en: "<<-R<<endl; 
	}
	
	return 0; 
}

int binario (int a[], int n, int dato){
	int izq = 0; 
	int der = n;
	int cen = 0;
	int m;
	int pos = -1;
	while (izq<=der && cen == 0){
		m = (izq + der)/2;
		if (a[m] = dato){
			cen = 1;
		}else if (a[m]<dato){
			izq = m+1;
		}else{
			der = m-1;
		}
	}
	if(cen = 1){
		pos = m;
	}else{
		pos = -izq;
	}
	return pos;
}