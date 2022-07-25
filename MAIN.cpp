#include "iostream" //Para system()
#include "stdio.h"//printf(), scanf()
#include "funciones.h" //Para inicio(), cartaUp(), valor carta() barajear() y rellenar()__Ordenar  

//Crear funcion para poner el cursor en la consolo dependiendo el jugador y el número de posicion de carta, para así no usar system("cls")

int main (){
	system("color 0B");//Color 
	inicio();
	system("cls");
	
	int cantCartasUser = 2, cantCartasCPU = 2;
	char charCartasUser[10], charCartasCPU[10]; 
	int intCartasUser[10],intCartasCPU[10];
	float dineroUser = 100000, dineroCPU;
	char cartas[52];
	int index = 3; //inicia en 4 porque son 4 cartas iniciales
	bool tomar = 0, dejar = 0, salir = 0;
	
	char interrogacion = 168 ;
	
	//Inicio del juego
	while(true){
	
		
		if(!tomar){
			printf("Tu dinero: %.2f\n", dineroUser);	
			printf("\n");	
			printf("\n");
			printf("CPU\n");
			cartaUp(cantCartasCPU);//cpu
			printf("USER\n");
			cartaUp(cantCartasUser);//user
		}
		
		rellenar(cartas);
		barajear(cartas);
		
		valorCarta('u',cartas[0], 1);
		valorCarta('c',cartas[1], 1);
		
		valorCarta('u',cartas[2], 2);	
		valorCarta('c',cartas[3], 2);
		
		printf("%cQue deseas hacer?", interrogacion);
		scanf("%i",&tomar);//1 o 0
		
		if(tomar){
			system("cls");				
			cantCartasUser++;
			printf("Tu dinero: %.2f\n", dineroUser);	
			printf("\n");	
			printf("\n");
			printf("CPU\n");
			cartaUp(cantCartasCPU);//cpu
			printf("USER\n");
			cartaUp(cantCartasUser);//user
			valorCarta('u',cartas[index++],cantCartasUser);
			}		
			
	}			
}
