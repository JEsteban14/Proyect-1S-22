#include "graficos.h"
#include "cartas.h"  

int main (){
	system("color 0D");//Color 
	inicio();
	system("cls");
	
	int cantCartasUser = 2, cantCartasCPU = 2;
	char charCartasUser[10], charCartasCPU[10]; 
	int intCartasUser[10],intCartasCPU[10];
	float dineroUser = 100000, dineroCPU;
	char cartas[52];
	int index = 2; //inicia en 4 porque son 4 cartas iniciales
	bool tomar = 0, dejar = 0, salir = 0;
	
	char interrogacion = 168 ;
	
	//Inicio del juego
	while(true){
		
		rellenar(cartas);
		barajear(cartas);
		
		printf("Tu dinero: %.2f\n", dineroUser);	
		printf("\n");	
		printf("\n");
		printf("CPU\n");
		printCard(1,'c',cartas[0],1);
		printf("\nUSER\n");
		printCard(1,'u',cartas[1],2);
		printCard(2,'c',cartas[2],0);
		printCard(2,'u',cartas[3],1);
		
		
			
		do{
			printf("%cQue deseas hacer?", interrogacion);
			scanf("%i",&tomar);//1 o 0
			
			if(tomar){				
				cantCartasUser++;
				index++;
				printCard(cantCartasUser, 'u', cartas[index],1);
			}
			
		}while(tomar);			
	}
}
