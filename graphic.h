#include "iostream"
#include "windows.h"
#include "stdio.h"
#include "stdlib.h"

void inicio(); 											//Impresion de pantalla de inicio

void menu();

void info();

void printCard(int pos, char user, char valor);			// Impresion de cartas

void escribir(int x, int y); 								//Colocar cursor en consola

void instrucciones();									//Instructivo

void despedida();										//Despedida


void inicio(){	
	system("cls");
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

void menu(){ 
	system("cls");
	printf("MEN%c\n\n(1)Jugar \n(2)Instrucciones \n(3)Informaci%cn proyecto\n(4)Highscores\n(5)Volver\n(0)Salir\n",233,162);
}

void info(){
	system("cls");
	printf("Abriendo Proyecto en navegador...\n");
	system("pause");
	system("start msedge https://github.com/JEsteban14/Proyect-1S-22");
}

void printCard(int pos, char user, char valor, int forma){
	char v = 186 ,cul = 201 ,h = 205 ,cur = 187 ,cdl = 200 ,cdr = 188;
	char c = 3 ,p= 6 ,t= 5, d = 4, inc = '?', simbolo;
	
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
			default:
			simbolo = inc;
	}
	
	
	if (user == 'u'){
			y = 13; //Depende de la posición de cartas de del jugador
		}
		else if (user == 'c'){
			y = 4; // Depende de la posicion de cartas de la cpu
		}		
		//Coordenada x
		if (pos == 0){
			x = 0;
		}
		else{
			x = (10*pos);
		}
		
	posicion.X = x;
	posicion.Y = y;	
	//posicion = {x,y};
	
			
	SetConsoleCursorPosition(hConsole, posicion);
	printf("%c%c%c%c%c%c%c%c%c ",cul,h,h,h,h,h,h,h,cur);
	//posicion = {x,y+1};
	posicion.X = x;
	posicion.Y = y + 1;		
	SetConsoleCursorPosition(hConsole, posicion);
	printf("%c%c      %c ",v,simbolo,v);
	//posicion = {x,y+2};
	posicion.X = x;
	posicion.Y = y + 2;		
	SetConsoleCursorPosition(hConsole, posicion);
	printf("%c       %c ",v,v);
	//posicion = {x,y+3};
	posicion.X = x;
	posicion.Y = y + 3;
	if (valor == '0'){
		SetConsoleCursorPosition(hConsole, posicion);
		printf("%c   10  %c ",v,v);
	}else{		
		SetConsoleCursorPosition(hConsole, posicion);
		printf("%c   %c   %c ",v,valor,v);
	}	
	//posicion = {x,y+4};
	posicion.X = x;
	posicion.Y = y + 4;		
	SetConsoleCursorPosition(hConsole, posicion);
	printf("%c       %c ",v,v);
	//posicion = {x,y+5};
	posicion.X = x;
	posicion.Y = y + 5;		
	SetConsoleCursorPosition(hConsole, posicion);
	printf("%c      %c%c ",v,simbolo,v);
	//posicion = {x,y+6};
	posicion.X = x;
	posicion.Y = y + 6;		
	SetConsoleCursorPosition(hConsole, posicion);
	printf("%c%c%c%c%c%c%c%c%c \n",cdl,h,h,h,h,h,h,h,cdr);
	//posicion = {0,20}; //Posición final
	//SetConsoleCursorPosition(hConsole, posicion);
}

void escribir(int x, int y){
	COORD pos;
	pos.X = x;
	pos.Y = y;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, pos);
	
}

void instrucciones(){
	char a = 160, u = 163, n = 164, o = 162;
	system("cls"); 
	printf("Objetivo del juego.\n\n");
	printf("Este juego consiste en enfrentarse de forma individual a la banca comparando su  mano con la propia \n");
	printf("de cada jugador, intentando conseguir 21 puntos o el numero m%cs  cercano posible sin  pasarse. Para \n",a);
	printf("conseguir  dicha puntuaci%cn  se suman los valores de dos cartas que se   reparten de inicio a  cada \n",o);
	printf("jugador, con los de  aquellas  nuevas cartas  que, opcionalmente, se podr%cn  a%cadir en  el turno de \n",a,n);
	printf("juego. Si las dos cartas iniciales suman 21, se denomina Blackjack, y es la mejor jugada. Cuando un \n");
	printf("jugador no  suma 21 con sus  dos cartas podr%c pedir cartas para conseguir dicho n%cmero uno cercano, \n",a,u);
	printf("pero si el jugador se pasa de esos 21 puntos pierde, indistintamente de lo que haga la banca.\n");
	printf("En caso de empate el jugador pierde.\n\n");	
	printf("\n");	
	system("PAUSE");
}

void despedida(){
	system("cls");
	printf("Gracias por jugar, que tenga un buen d%ca\n",161);
	system("PAUSE");	
	}

