#include "time.h" 			//Librerias para número aleatorio
#include "stdlib.h"
#include "iostream"
#include "stdio.h"
#include "iomanip"
#include "fstream"
#include "sstream"

using namespace std;

void barajear(char baraja[],char simbolos[]); 			//Barajear las cartas

void rellenar(char baraja52[], char simbolos[]); 		//Ordenas las cartas

int convertir(char x);									//Convierte los char de las cartas en int para operar suma

int verificacion(int rango0, int rango1, int *choose);	//Para verificar elecciones del usuario

int sumaArreglo(int array[], int n);					//Suma el los valores de un arreglo

void isAin(int suma,char array[]); 						//Verifica la suma dependiendo el valor del AS (1 o 11)			

string intoString(int a);								//Funcion para la escritura en archivo de puntajes

void inScore(string name, int score);					//Escribe nuevo puntaje en archivo de puntajes.txt

void outScore();										//Imprime puntajes de mayor a menor, guardados en archivo de puntajes.txt


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

string intoString(int a){
	stringstream s;
	s << a;
	string x;
	s >> x;
	return x; 
}

void inScore(string name, int score){
	ofstream archivo;
	archivo.open("scores.txt",ios::app);  //APPEND __ ADJUNTAR
	string final = name + " " + intoString(score);	 
	archivo << endl <<  final;
	archivo.close();
}

void outScore(){
	
	struct data{
	string nick;
	string score;
	int puntaje;
	};
	
	
	//LECTURA DE DATOS EN ARCHIVO
	FILE *file;
	file = fopen("scores.txt","r");
	
	if (!file){
		file = fopen("scores.txt", "w");
		system("cls");
		printf("No hay puntajes. Empieza a jugar para almacenar\n");
	}else{
		
		char c;
		int lines = 0;
		
		//VER CUANTOS JUGADORES HAY (CADA INFO DE JUGADOR ESTÁ POR LINEA) POR ESO SE SUMA SI HAY \_n	

		do{		
			c = fgetc(file);
			
			if( c == EOF){
				break;
			}if(c == '\n'){
				lines++;
			}
			
		}while(true);
		
		//	
		rewind(file);
		data persona[lines];
		
		do{ //skip la primera linea
			c = fgetc(file);
			if(c == '\n'){				
				break;
			}
		}while(true);
		
		//PASAMOS DATOS A VARIABLES
		for (int i = 0; i < lines; i++){	
			do{//NOMBRE
				c = fgetc(file);			
				if( c == EOF || c == ' '){
					break;
				}		
				persona[i].nick += c;		
			}while(true);		
			do{//PUNTAJE
				c = fgetc(file);			
				if( c == EOF || c == '\n'){
					break;
				}		
				persona[i].score += c;
			}while(true);
		}
		
		fclose(file);
	
		
		//PASAMOS CHAR A INT
		
		for (int i = 0; i < lines; i++){
			sscanf(persona[i].score.c_str(), "%d",&persona[i].puntaje);	
		}
		
		//ORGANIZAR HIGHSCORES
		string save;
		for(int j = 1; j < lines; j++){
			for (int i = 0; i < lines; i++){
				if(persona[i].puntaje < persona[j].puntaje){
					save = persona[i].nick;
					persona[i].nick = persona[j].nick;
					persona[j].nick = save;
					save = persona[i].score;
					persona[i].score = persona[j].score;
					persona[j].score = save;
					int a = persona[i].puntaje;				
					persona[i].puntaje = persona[j].puntaje;
					persona[j].puntaje = a;
				}
			}
		}
		system("cls");
		//IMPRIME RESULTADOS
		cout << setw(20) << left <<"   \tNOMBRE" << setw(12) << "PUNTAJE " <<  endl;	
		for(int i = 0; i < lines; i++){		
			cout << setw(3) <<right << i+1 << ".\t";
			cout << setw(14) <<left << persona[i].nick << right <<"$";
			cout << setw(10) << right <<  persona[i].puntaje  << endl;	
		}
	}	
	
}
