#include "graphic.h" 
#include "cards.h"  
#include "iostream"
using namespace std;

#define CARTASINICIO 2 			//Cartas iniciales
#define DINEROINICIO 100000 	//Dinero inicial

struct jugador{
	int cantCartas = CARTASINICIO;
	char cartas[10];
	int valores[10];
	char simbolos[10];
	int suma;
	int dinero;	
};

void blackjack();


void blackjack(){
	
	system("cls");
	
	jugador User, CPU;										//Jugadores 
	int quien;												//Define el jugador ganador
	User.dinero = DINEROINICIO;								//Dinero para el juego
	char cartas[52], simbolos[52]; 							//Arreglos con informacion del mazo y del ganador
	int dinero, apuesta;									//Dinero para apostar
	int index = 0;
	int tomar, tomarCPU; 									//Número de carta para ser jugada
	bool ganador,otro,inicio; 								//Booleanos para llevar la lógica del juego
	char interrogacion = 168, u = 163, i = 161;				//Caracteres para ortografía
	string nickname;										//Nickname
	
	
	//Inicio del juego
	printf("Ingresa tu nombre\n");
	cin >> nickname;
	system("cls");
	rellenar(cartas,simbolos);		//Ordenamos cartas
	barajear(cartas,simbolos);		//Barajeamos cartas
	
	while(true){
		inicio = true; tomar = true; tomarCPU = true;				//Reset de variables para nueva partida
		CPU.cantCartas = 2; 
		User.cantCartas = 2;
		User.suma = 0;
		CPU.suma = 0;
		ganador = false;
		
		for (int i = 0; i < 10; i++){  	//Liberamos arrays que almacenan valores de cartas 
			CPU.cartas[i] = 0;
			User.cartas[i] = 0;
			CPU.simbolos[i] = 0;
			User.simbolos[i] = 0;
			CPU.valores[i] = 0;
			User.valores[i] = 0;
		}
			
		
		printf("T%c dinero:  $%d\n",u, User.dinero); //IMPRIMIMOS DINERO			
		if (User.dinero > 5000){ //VERIFICAMOS SI TIENE PARA APOSTAR
		printf("%cCuanto deseas apostar? M%cnimo $5000\n",interrogacion,i); // Pedimos valor de apuesta	
		verificacion(5000,User.dinero,&apuesta); // Verificamos mínimo
		dinero = apuesta;	
		system("cls");
			if (index > 38){
					printf("Barajeando mazo...\n");
					rellenar(cartas,simbolos);		//Ordenamos cartas
					barajear(cartas,simbolos);		//Barajeamos cartas
					index = 0;
					system("pause");
					system("cls");
			}
		
		//Inicio de la partida
		
		while(true){												
			printf("T%c dinero:  $%d\t",u, User.dinero);
			printf("T%c apuesta: $%d\n ",u, dinero);			
					
			if(inicio){
				//ARRAYS INFORMACION CARTAS CPU (INICIAL)
				for(int i = 0; i < CARTASINICIO; i++){
					CPU.cartas[i] = cartas[index];
					CPU.valores[i] = convertir(cartas[index]);
					CPU.simbolos[i] = simbolos[index];										
					index++;													
				}
				//ARRAYS INFORMACION CARTAS USER (INICIAL)
				for(int i = 0; i < CARTASINICIO; i++){
					User.cartas[i] = cartas[index];
					User.valores[i] = convertir(cartas[index]);
					User.simbolos[i] = simbolos[index];
					index++;				
				}		
				
				inicio = false; 
			} 											//FINALIZA EL INICIO
			
			
			//SUMAS 
			User.suma = sumaArreglo(User.valores,10);
			CPU.suma = sumaArreglo(CPU.valores,10);
			
			//VERIFICACIÓN AS
			isAin(User.valores,User.suma);
			isAin(CPU.valores,CPU.suma);
			
			User.suma = sumaArreglo(User.valores,10);
			CPU.suma = sumaArreglo(CPU.valores,10);			
						
			escribir({0,1});
			printf("Cartas en baraja: %d", 52-index);
			
		
			//Impresion de cartas CPU
			printf("\n\nCPU      ");		
			
			if(!ganador){
				printf("Puntaje: ???\n");				
				for (int i = 0; i < CPU.cantCartas ;i++){  
					if (i == 0){  // Carta inicial		        		//Primera carta se muestra				
						printCard(i,'c',CPU.cartas[i],CPU.simbolos[i]);	
					}
					else{
						printCard(i,'c','?','?'); 						//Cartas volteadas 
					}					
				}
			}	
			
			//IMPRESION DE CARTAS USER
			cout << endl << nickname << "     Puntaje: " << User.suma <<  endl;
			
			for(int i = 0; i < User.cantCartas ; i++){				
				printCard(i,'u',User.cartas[i],User.simbolos[i]);								
			}
						
			
			//Condicionales de ganador
			if (User.suma == 21 || CPU.suma == 21){
				if (User.suma == 21 && CPU.suma != 21){ //Si alguien consigue 21
					ganador = true;
					quien = 1;}
				else{
					ganador = true;
					quien = 0;
				}
			}
			if (21 < User.suma || 21 < CPU.suma && !ganador){//Si alguien se pasa
				if(0 < 21 - User.suma && 21 - CPU.suma < 0 ){ 
					ganador = true;
					quien = 1;
				}
				else {
					ganador = true;
					quien = 0;
				}
			}
			if (!tomar && !tomarCPU){	
				if (0 < User.suma && 0 < CPU.suma && !ganador){ // Si nadie se pasa y no se consigue 21
					if(21 - User.suma < 21 - CPU.suma){
						ganador = true;
						quien = 1;
					}
					else {
						ganador = true;
						quien = 0;
					}					
				}	
			}
			
			//Turnos
			if (tomar && !ganador){				//Turno Usuario
				printf("Es t%c Turno: Tomar(1) Dejar(0)\n",u);						
				verificacion(0,1,&tomar);
				if (tomar){
					escribir({0,21});
					printf("Tomas carta\n");							
					User.cartas[User.cantCartas] = cartas[index];
					User.valores[User.cantCartas] = convertir(cartas[index]);
					User.simbolos[User.cantCartas]= simbolos[index];
					
					User.cantCartas++;					
					index++; 
				}
				else{
					escribir({0,21});
					printf("Te quedas\n");
				}						
			}											//Turno máquina
			else if (!ganador && tomarCPU){	
				printf("Es el turno del MAQUINA\n");			
				if (CPU.suma < 17){
					printf("CPU toma carta\n");
					CPU.cartas[CPU.cantCartas] = cartas[index];
					CPU.valores[CPU.cantCartas] = convertir(cartas[index]);
					CPU.simbolos[CPU.cantCartas]= simbolos[index];
					
					CPU.cantCartas++;
					index++;					
				}else{
					printf("CPU se queda\n");
					tomarCPU = false;	
					}									
			}
			
			
		
	
			//Romper ciclo y anunciar ganador
			if(ganador){
				 // Si hay ganador muestra las cartas de la CPU
				escribir({9,3});
				printf("Puntaje: %d    ", CPU.suma);
				for (int i = 0; i < CPU.cantCartas ; i++){
					printCard(i,'c',CPU.cartas[i],CPU.simbolos[i]);					
				}
				escribir({0,20});			
				printf("Juego finalizado\n");
			}					
			system("pause");
			if(ganador){
				if (quien == 1){
					escribir({0,21});
					printf("Has ganado                                      \nDinero: $%d + $%d\n",User.dinero,dinero);
					User.dinero += dinero;					
				}else{
					escribir({0,21});
					printf("Has perdido                                     \n");
					printf("Dinero: $%d - $%d\n",User.dinero,dinero);
					User.dinero -= dinero;
				}					
				system("pause");
				system("cls");
				break;
			}				
			system("cls");
		}
		}
		
		if (User.dinero < 5000){
			printf("Ya no tienes dinero para apostar\n");
			system("PAUSE");
			break;
		}		
		else{		
			printf("Deseas jugar nuevamente (1)Si (0)No\n");
			scanf("%d",&otro);
			if(!otro){
				break;
			}else{
				system("cls");
			}
		}
		
	}
	
	system("cls");
	printf("Gracias por jugar :)\n");
	printf("T%c dinero final: $%d\n\n",u, User.dinero);
	system("pause");	
	return;
}

