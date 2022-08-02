#include "time.h" //Librerias para número aleatorio
#include "stdlib.h"
#include "iostream"
#include "stdio.h"

using namespace std;

void barajear(char baraja[],char simbolos[]); 			//Barajear las cartas

void rellenar(char baraja52[], char simbolos[]); 		//Ordenas las cartas

int convertir(char x);									//Convierte los char de las cartas en int para operar suma

int verificacion(int rango0, int rango1, int *choose);	//Para verificar elecciones del usuario

int sumaArreglo(int array[], int n);					//Suma el los valores de un arreglo

void isAin(int suma,char array[]); 								//Revisar

void barajear(char baraja[],char simbolos[]){
	int x;
	char save1, save2;
	srand(time(NULL)); 									// Aplicamos semillas para generar números aleatorios
	for(int i = 0; i < 52; i++){
			
			x = rand()%52;						
		
			save1 = baraja[i];				
			baraja[i] = baraja[x];			
			baraja[x] = save1;
			
			save2 = simbolos[i];
			simbolos[i] = simbolos[x];
			simbolos[x] = save2;
		}
	}
	
void rellenar(char baraja52[], char simbolos[]){                                //Valor por defecto de tamaños de char 52
	char CARTAS[] = {'A','2','3','4','5','6','7','8','9','0','J','K','Q'};		//Valores de las cartas
	char SIMBOLOS[]= {'0','1','2','3'};											// Cada número corresponde a un simbolo 
	
	
	for(int i = 0; i < 52 ; i++){												//Ordena el array con valores de CARTAS[]
		if (i <= 12){
			baraja52[i] = CARTAS[i];
		}
		else if (i > 12 && i <= 25){
			baraja52[i] = CARTAS[i-13];
		}
		else if (i > 25 && i <= 38){
			baraja52[i] = CARTAS[i-26];
		}
		else if (i > 38){
			baraja52[i] = CARTAS[i-39];
		}	
	}
	
	for(int i = 0; i < 52; i++){												//Ordena el array con valores de SIMBOLOS[]
		if(i < 13){
			simbolos[i] = SIMBOLOS[0];
		}
		else if(i < 26){
			simbolos[i] = SIMBOLOS[1];
		}
		else if(i < 39){
			simbolos[i] = SIMBOLOS[2];
		}
		else if(i < 52){
			simbolos[i] = SIMBOLOS[3];
		}
	}
}

int convertir(char x){					
	switch(x){
		case 'A': return 11; break; 		//El as toma dos valores, en este caso toma siempre 11 
		case '1': return 1; break;			//Mdiante la funcion isAin() se verifica y se reemplaza dependiendo suma
		case '2': return 2; break;
		case '3': return 3; break;
		case '4': return 4; break;
		case '5': return 5; break;
		case '6': return 6; break;
		case '7': return 7; break;
		case '8': return 8; break;
		case '9': return 9; break;
		case '0': return 10; break;
		case 'J': return 10; break;
		case 'K': return 10; break;
		case 'Q': return 10; break;		
	}
}

int verificacion(int rango0, int rango1, int *choose){
	std::cin >> *choose;
	while ( !std::cin||*choose > rango1 || *choose < rango0){  			//Ciclo para verficar rangos
		std::cout << "valor invalido, digita nuevamente" << endl;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cin >> *choose;
	}
	return *choose;														//Ciclo para verficar rangos
}
int sumaArreglo(int array[], int n){
	int suma = 0;
	for(int i = 0; i < n; i++){
		suma += array[i];
	}
	return suma;
	
}

void isAin(int array[], int suma){
	if(suma > 21){
	for(int i = 0; i < 10; i++){		
			if(array[i] == 11){
				array[i] = 1;
				break;
			}
		}
	}
}
