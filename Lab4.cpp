#include <iostream>
#include <cstring>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

void menu();
double* ejercicio1(double*);
void ejercicio2();

int main(int argc, char*agrv[]){
	menu();
	return 0;
}

void menu(){
	int opc;
	while(opc < 3){
		cout <<  "1.-Ejercicio 1" << endl;
		cout <<  "2.-Ejercicio 2" << endl;
		cout << "3.-Salir" << endl;
		cout <<  "Opcion: ";
		cin >> opc;
		if(opc == 1){
			double* polinomio = new double[3];
			int size = 3;
			cout << "Polinomio";
			cout << "X^2 = ";
			cin >> polinomio[0];
			cout << "X = ";
			cin >> polinomio[1];
			cout << "Constante = ";
			cin >> polinomio[2];
			for (int i = 0; i < 2; i++){
				ejercicio1(polinomio)[i] *= -1;
			}
			cout << "X^2 " << polinomio[0] << " + X " << polinomio[1] << " + " << polinomio[2] << endl;
			cout << "(X + " << ejercicio1(polinomio)[0] << ")(X + " << ejercicio1(polinomio)[1] << ")" << endl;
			delete [] polinomio;
		} else if (opc == 2){
			ejercicio2();
		}
	}
}

double* ejercicio1(double* polinomio){
	if(polinomio[0] == 0){
		return polinomio;
	} else {
		double* resultado = new double[2];
		int raizCuadrada = (pow(polinomio[1],2) - (4 * polinomio[0] * polinomio[2]));
		if(raizCuadrada < 0){
			return polinomio;
		} else {
			resultado[0] = ((-1 * polinomio[1] + sqrt(raizCuadrada))/ (2 * polinomio[0]));
			resultado[1] = ((-1 * polinomio[1] - sqrt(raizCuadrada))/ (2 * polinomio[0]));
			return resultado;
		}
	}
}

void ejercicio2(){
	char* verboOriginal = new char[35];
	cout << "Verbo original: ";
	cin >> verboOriginal;
	int size = strlen(verboOriginal);
	char* verboModificado = new char[size-2];
	if (verboOriginal[size-1] != 'r'){
		cout << "No es verbo" << endl;
	} else if (verboOriginal[size-2] == 'a'){
		strncpy(verboModificado, verboOriginal, size-2);
		cout << "Pasado: " <<verboModificado << "é" << endl;
		cout << "Presente: " << verboModificado << "o" <<endl;
		cout << "Futuro: " << verboModificado << "aré" << endl;
	} else if (verboOriginal[size-2] == 'e'){
		strncpy(verboModificado, verboOriginal, size-2);
		cout << "Pasado: " <<verboModificado << "í" << endl;
		cout << "Presente: " << verboModificado << "o" <<endl;
		cout << "Futuro: " << verboModificado << "eré" << endl;
	} else if (verboOriginal[size-2] == 'i'){
		strncpy(verboModificado, verboOriginal, size-2);
		cout << "Pasado: " <<verboModificado << "í" << endl;
		cout << "Presente: " << verboModificado << "o" <<endl;
		cout << "Futuro: " << verboModificado << "iré" << endl;
	}
	delete[] verboModificado;
	delete[] verboOriginal;
}
