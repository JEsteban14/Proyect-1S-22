#include "iostream"
#include "windows.h"
#include "stdio.h"
#include "stdlib.h"

//Cuadrar 10 en printCard '0'
void inicio();
void printCard(int pos, char user, char valor);
void escribir(COORD pos, char mensaje[]);

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

void printCard(int pos, char user, char valor, int forma){
	char v = 186 ,cul = 201 ,h = 205 ,cur = 187 ,cdl = 200 ,cdr = 188;
	char c = 3 ,p= 6 ,t= 5, d = 4, simbolo;
	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD posicion;	
	int y,x;
	
	switch (forma){
		case '0':
			simbolo = c;
			break;
		case '1':
			simbolo = p;
			break;
		case '2':
			simbolo = t;
			break;
		case '3':
			simbolo = d;
			break;
	}
	
	
	if (user == 'u'){
			y = 13; //Depende de la posición de cartas de del jugador
		}
		else if (user == 'c'){
			y = 4; // Depende de la posicion de cartas de la cpu
		}		
		//Coordenada x
		if (pos == 1){
			x = 0;
		}
		else{
			x = (10*(pos-1));
		}
	posicion = {x,y};
			
	SetConsoleCursorPosition(hConsole, posicion);
	printf("%c%c%c%c%c%c%c%c%c ",cul,h,h,h,h,h,h,h,cur);
	posicion = {x,y+1};		
	SetConsoleCursorPosition(hConsole, posicion);
	printf("%c%c      %c ",v,simbolo,v);
	posicion = {x,y+2};		
	SetConsoleCursorPosition(hConsole, posicion);
	printf("%c       %c ",v,v);
	posicion = {x,y+3};		
	SetConsoleCursorPosition(hConsole, posicion);
	printf("%c   %c   %c ",v,valor,v);
	posicion = {x,y+4};		
	SetConsoleCursorPosition(hConsole, posicion);
	printf("%c       %c ",v,v);
	posicion = {x,y+5};		
	SetConsoleCursorPosition(hConsole, posicion);
	printf("%c      %c%c ",v,simbolo,v);
	posicion = {x,y+6};		
	SetConsoleCursorPosition(hConsole, posicion);
	printf("%c%c%c%c%c%c%c%c%c \n",cdl,h,h,h,h,h,h,h,cdr);
	posicion = {0,20}; //Posición final
}

void escribir(COORD pos, char mensaje[]){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, pos);
	printf("%c", mensaje);
}
