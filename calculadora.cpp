#include <iostream>
#include <cmath>
using namespace std;

double sumar (double num1, double num2) {
	return num1 + num2;
}
double restar (double num1, double num2) {
	return num1 - num2;
}

int main () {
	int opcion, num1, num2;
	bool continuar = true;
	
	while (continuar) {
		//Menu dinamico
		cout<<"*********************************\n";
		cout<<"----- CALCULADORA -----\n";
		cout<<"*********************************\n";
		cout<<"    1. Sumar\n";
		cout<<"    2. Restar\n";
		cout<<"    3. Multiplicar\n";
		cout<<"    4. Dividir\n";
		cout<<"    5. Potencia\n";
		cout<<"    6. Raiz Cuadrada\n";
		cout<<"    7. Logaritmo \n";
		cout<<"    8. Logaritmo Natural\n";
		cout<<"    9. Salir\n";
		cout<<"*********************************\n";
		cout<<"Opcion: ";
		
		try {
			cin >> opcion;
			
			//Verfica si existe un error en el ingreso (ingreso de letras)
			if (cin.fail()) { 
				//Limpia el estado del error
				cin.clear(); 
				//Descarta todos los caracteres invalidos
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
				//Muestra con un nombre diferente al error
				throw runtime_error("Opcion no valida. Debe ingresar un numero."); 
			}
			
			//Limpia el buffer
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
			
			switch (opcion) {
			case 1:
				cout<<"Escriba un numero: ";
				cin>>num1;
				cout<<"Escriba otro numero: ";
				cin>>num2;
				cout<<"El resultado de la suma entre "<<num1<<" + "<<num2<<" = "<<sumar(num1,num2)<<endl;
				break;
			case 2:
				cout<<"Escriba un numero: ";
				cin>>num1;
				cout<<"Escriba otro numero: ";
				cin>>num2;
				cout<<"El resultado de la resta entre ("<<num1<<") - ("<<num2<<") = "<<restar(num1,num2)<<endl;
				break;
			case 9:
				continuar = false;
				cout << "Saliendo del programa\n";
				break;
			default:
				cout << "Opcion no valida. Intente de nuevo.\n";
			}
		} catch (const exception& e) {
			//Manejo de errores del menu
			cerr << "\nError: " << e.what() << endl;
			cout << "Por favor, intente nuevamente.\n";
		}
	}
	
	return 0;
}
