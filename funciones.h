#ifndef _LIBRERIA
#define _LIBRERIA

#include "iostream"
#include "windows.h"
#include "stdio.h"
#include "time.h"
#include "stdlib.h"

void barajear(char baraja[]){

	for(int i = 0; i < 52; i++){
			srand(time(NULL));
			int x = rand()%52;
			int save = baraja[i];
			baraja[i] = baraja[x];
			baraja[x] = save;
		}
	}
	
void rellenar(char baraja52[]){
	char CARTAS[] = {'A','2','3','4','5','6','7','8','9','0','J','K','Q'};
	for(int i = 0; i < 52 ; i++){
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
}

void inicio(){	
	char a = 244 ;//simbolos	
	printf("\n");
	printf(" %c%c%c%c%c%c  %c       %c%c%c%c%c%c  %c%c%c%c%c%c  %c   %c  %c%c%c%c%c%c  %c%c%c%c%c%c  %c%c%c%c%c%c  %c   %c\n",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
	printf(" %c    %c  %c       %c    %c  %c       %c  %c      %c    %c    %c  %c       %c  %c\n",a,a,a);
	printf(" %c    %c  %c       %c    %c  %c       %c %c       %c    %c    %c  %c       %c %c\n",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
	printf(" %c%c%c%c%c%c  %c       %c%c%c%c%c%c  %c       %c%c        %c    %c%c%c%c%c%c  %c       %c%c\n",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
	printf(" %c    %c  %c       %c    %c  %c       %c %c    %c  %c    %c    %c  %c       %c %c\n",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
	printf(" %c    %c  %c       %c    %c  %c       %c  %c   %c  %c    %c    %c  %c       %c  %c\n",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
	printf(" %c%c%c%c%c%c  %c%c%c%c%c%c  %c    %c  %c%c%c%c%c%c  %c   %c   %c%c     %c    %c  %c%c%c%c%c%c  %c   %c\n",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
	printf("\n");
	printf("\n");
	printf("ELABORADO POR:\n\n");
	printf("JUAN ESTEBAN MEDINA CARDENAS\n");
	printf("20221020015\n\n");
	printf("YOHAN STEVEN JIMENEZ HILARION ""\n");
	printf("20221020016\n\n");
	printf("\n");
	printf("\n");
	system("PAUSE");
		
}


void cartaUp(int quantity){
	
	char v = 186 ,cul = 201 ,h = 205 ,cur = 187 ,cdl = 200 ,cdr = 188;
	
	for(int i = 0; i < quantity; i++){
		printf("%c%c%c%c%c%c%c%c%c",cul,h,h,h,h,h,h,h,cur);
		printf (" ");
	}
	printf ("\n");
	for(int i = 0; i < quantity; i++){
		printf("%c       %c",v,v);
		printf (" ");
	}
	printf ("\n");
	for(int i = 0; i < quantity; i++){
		printf("%c       %c",v,v);
		printf (" ");
	}
	printf ("\n");
	for(int i = 0; i < quantity; i++){
		printf("%c       %c",v,v);
		printf (" ");
	}
	printf ("\n");
	for(int i = 0; i < quantity; i++){
		printf("%c       %c",v,v);
		printf (" ");
	}
	printf ("\n");
	for(int i = 0; i < quantity; i++){
		printf("%c       %c",v,v);
		printf (" ");
	}
	printf ("\n");
	for(int i = 0; i < quantity; i++){
		printf("%c%c%c%c%c%c%c%c%c",cdl,h,h,h,h,h,h,h,cdr);
		printf (" ");
	}
	printf ("\n");
	printf ("\n");
}

// char player = u, c
// char valor 0 = 10
// int nCarta = La posicion de la carta de izquierda a derecha
void valorCarta(char player, char valor, int nCarta){
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD posicion;
		int y,x;
		
		//Coordenada y
		if (player == 'u'){
			y = 16; //Depende de la posición de cartas de del jugador
		}
		else if (player == 'c'){
			y = 7; // Depende de la posicion de cartas de la cpu
		}
		
		//Coordenada x
		if (nCarta == 1){
			x = 4;
		}
		else{
			x = 4+(10*(nCarta-1));
		}
		
		posicion = {x,y};
		
		SetConsoleCursorPosition(hConsole, posicion);
		if(valor == 'A'){
			WriteConsole(hConsole, "A", 1, NULL, NULL);
		}
		if(valor == '2'){
			WriteConsole(hConsole, "2", 1, NULL, NULL);
		}
		if(valor == '3'){
			WriteConsole(hConsole, "3", 1, NULL, NULL);
		}
		if(valor == '4'){
			WriteConsole(hConsole, "4", 1, NULL, NULL);
		}
		if(valor == '5'){
			WriteConsole(hConsole, "5", 1, NULL, NULL);
		}
		if(valor == '6'){
			WriteConsole(hConsole, "6", 1, NULL, NULL);
		}
		if(valor == '7'){
			WriteConsole(hConsole, "7", 1, NULL, NULL);
		}
		if(valor == '8'){
			WriteConsole(hConsole, "8", 1, NULL, NULL);
		}
		if(valor == '9'){
			WriteConsole(hConsole, "9", 1, NULL, NULL);
		}
		if(valor == '0'){
			WriteConsole(hConsole, "10", 2, NULL, NULL);
		}
		if(valor == 'J'){
			WriteConsole(hConsole, "J", 1, NULL, NULL);
		}
		if(valor == 'Q'){
			WriteConsole(hConsole, "Q", 1, NULL, NULL);
		}
		if(valor == 'K'){
			WriteConsole(hConsole, "K", 1, NULL, NULL);
		}
		if(valor == '?'){
			WriteConsole(hConsole, "?", 1, NULL, NULL);
		}
		posicion = {0,20}; //Posición final
		SetConsoleCursorPosition(hConsole, posicion);	
}

#include "funciones.h"
#endif
