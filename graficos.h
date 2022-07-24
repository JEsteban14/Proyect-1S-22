#ifndef _LIBRERIA
#define _LIBRERIA

#include "iostream"
#include "windows.h"

void inicio(){	
	char a = 244 ;	
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
}


// char player = u, c
// char valor 0 = 10
// int nCarta = La posicion de la carta de izquierda a derecha
void valorCarta(char player, char valor, int nCarta){
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD pos;
		int y,x;
		if (player == 'u'){
			y = 3; //Depende de la posición de cartas de del jugador
		}
		else if (player == 'c'){
			y = 10; // Depende de la posicion de cartas de la cpu
		}	
		
		if (nCarta == 1){
			x = 4;
		}
		else{
			x = 4+(10*(nCarta-1));
		}
		
		pos = {x,y};
		SetConsoleCursorPosition(hConsole, pos);
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
		pos = {0,20}; //Posición final
		SetConsoleCursorPosition(hConsole, pos);	
}

#include "graficos.h"
#endif
