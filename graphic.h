#include "iostream"
#include "windows.h"
#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);		//Global para la impresión de graficos	

void inicio(); 											//Impresion de pantalla de inicio

void menu();

void info();

void printCard(int pos, char user, char valor);			// Impresion de cartas

void escribir(int x, int y); 							//Colocar cursor en consola

void instrucciones();									//Instructivo

void despedida();										//Despedida

void efectoEscritura(const char text[]);

void inicio(){	
	
	char a = 244 ;//simbolos
	system("cls");		
	cout << endl;
	SetConsoleTextAttribute(hConsole,3);
	printf(" %c%c%c%c%c%c  %c       %c%c%c%c%c%c  %c%c%c%c%c%c  %c   %c  %c%c%c%c%c%c  %c%c%c%c%c%c  %c%c%c%c%c%c  %c   %c\n",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
	printf(" %c    %c  %c       %c    %c  %c       %c  %c      %c    %c    %c  %c       %c  %c\n",a,a,a);
	printf(" %c    %c  %c       %c    %c  %c       %c %c       %c    %c    %c  %c       %c %c\n",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
	printf(" %c%c%c%c%c%c  %c       %c%c%c%c%c%c  %c       %c%c        %c    %c%c%c%c%c%c  %c       %c%c\n",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
	printf(" %c    %c  %c       %c    %c  %c       %c %c    %c  %c    %c    %c  %c       %c %c\n",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
	printf(" %c    %c  %c       %c    %c  %c       %c  %c   %c  %c    %c    %c  %c       %c  %c\n",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
	printf(" %c%c%c%c%c%c  %c%c%c%c%c%c  %c    %c  %c%c%c%c%c%c  %c   %c   %c%c     %c    %c  %c%c%c%c%c%c  %c   %c\n",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);

	
	char str1[] = " ELABORADO POR: ";
	char str2[] = " JUAN ESTEBAN MEDINA CARDENAS ";
	char str3[] = " 20221020015                  ";
	char str4[] = " YOHAN STEVEN JIMENEZ HILARION";
	char str5[] = " 20221020016                  ";
	char str6[] = " Pulsa una tecla para jugar...";
	
	escribir(1,10);
	for (int i = 0; i < strlen(str1); i++){
		cout << str1[i];
		Sleep(70);
	}cout << endl;
	
	Sleep(200);
	for (int i =0 ; i < strlen(str2); i++){
		SetConsoleTextAttribute(hConsole,15);
		escribir(1+i,12);
		cout << str2[i];
		SetConsoleTextAttribute(hConsole,2);
		escribir(1+i,13);
		cout << str3[i];
		SetConsoleTextAttribute(hConsole,15);
		escribir(1+i,15);
		cout << str4[i];
		SetConsoleTextAttribute(hConsole,2);
		escribir(1+i,16);
		cout << str5[i];
		Sleep(70);
	}
	cout << endl << endl;
	
	Sleep(200);
	SetConsoleTextAttribute(hConsole,3);
	for (int i = 0; i < strlen(str6); i++){
		cout << str6[i];
		Sleep(70);
	}
	
	getch();	
}

void menu(){ 
	system("cls");
	char clr[] ="                         ";
	for(int i = 0; i < 30; i++){
		escribir(0,0);
		printf("MEN%c\n\n(1)Jugar \n(2)Instrucciones \n(3)Informaci%cn proyecto\n(4)Highscores\n(5)Volver\n(0)Salir\n",233,162);
		escribir(i,0);cout << clr;
		escribir(i,2);cout << clr;
		escribir(i,3);cout << clr;
		escribir(i,4);cout << clr;
		escribir(i,5);cout << clr;
		escribir(i,6);cout << clr;
		escribir(i,7);cout << clr;
		Sleep(50);
	}cout << endl;
}

void info(){
	system("cls");
	 
	efectoEscritura("Abriendo Proyecto en navegador...\n");
	Sleep(200);
	system("start msedge https://github.com/JEsteban14/Proyect-1S-22");
}

void printCard(int pos, char user, char valor, int forma){
	char v = 186 ,cul = 201 ,h = 205 ,cur = 187 ,cdl = 200 ,cdr = 188;
	char c = 3 ,p= 6 ,t= 5, d = 4, inc = '?', simbolo;
	
	COORD posicion;	
	int y,x;
	
	switch (forma){
		case '0':
			simbolo = c;
			SetConsoleTextAttribute(hConsole,4);
			break;
		case '1':
			simbolo = p;
			SetConsoleTextAttribute(hConsole,15);
			break;
		case '2':
			simbolo = t;
			SetConsoleTextAttribute(hConsole,10);
			break;
		case '3':
			simbolo = d;
			SetConsoleTextAttribute(hConsole,9);
			break;
		default:
			SetConsoleTextAttribute(hConsole,7);	
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

	
			
	SetConsoleCursorPosition(hConsole, posicion);
	printf("%c%c%c%c%c%c%c%c%c ",cul,h,h,h,h,h,h,h,cur);

	posicion.X = x;
	posicion.Y = y + 1;		
	SetConsoleCursorPosition(hConsole, posicion);
	printf("%c%c      %c ",v,simbolo,v);

	posicion.X = x;
	posicion.Y = y + 2;		
	SetConsoleCursorPosition(hConsole, posicion);
	printf("%c       %c ",v,v);
	
	posicion.X = x;
	posicion.Y = y + 3;
	if (valor == '0'){
		SetConsoleCursorPosition(hConsole, posicion);
		printf("%c   10  %c ",v,v);
	}else{		
		SetConsoleCursorPosition(hConsole, posicion);
		printf("%c   %c   %c ",v,valor,v);
	}	

	posicion.X = x;
	posicion.Y = y + 4;		
	SetConsoleCursorPosition(hConsole, posicion);
	printf("%c       %c ",v,v);

	posicion.X = x;
	posicion.Y = y + 5;		
	SetConsoleCursorPosition(hConsole, posicion);
	printf("%c      %c%c ",v,simbolo,v);

	posicion.X = x;
	posicion.Y = y + 6;		
	SetConsoleCursorPosition(hConsole, posicion);
	printf("%c%c%c%c%c%c%c%c%c \n",cdl,h,h,h,h,h,h,h,cdr);
	SetConsoleTextAttribute(hConsole,6);
}

void escribir(int x, int y){
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hConsole, pos);
	
}

void instrucciones(){
	char a = 160, u = 163, n = 164, o = 162;
	system("cls");
	SetConsoleTextAttribute(hConsole,3);
	printf("Objetivo del juego.\n\n");
	SetConsoleTextAttribute(hConsole,7);
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
	efectoEscritura("Gracias por jugar.\n\n");

SetConsoleTextAttribute(hConsole,15);
cout << "                /|         ," << endl;  
cout << "              ,///        /|" << endl;
cout << "             // //     ,///" << endl;
cout << "            // //     // //" << endl;
cout << "           // //     || ||" << endl;
cout << "           || ||    // //" << endl;
cout << "           || ||   // //" << endl;
cout << "           || ||  // //" << endl;
cout << "           || || || ||" << endl;
cout << "           \\\\,\\|,|\\_//" << endl;
cout << "            \\\\)\\)\\\\|/" << endl;
cout << "            )-.\"\" .-(            ";
SetConsoleTextAttribute(hConsole,3);
printf("%c%c%cESO ES TODO, VIEJO!!!\n",173,173,173);
SetConsoleTextAttribute(hConsole,7);
cout << "           //^\\` `/^\\\\" << endl;
cout << "          //  |   |  \\\\" << endl;
cout << "        ,/_| 0| _ | 0|_\\," << endl;
cout << "      /`    `\"=.v.=\"`    `\\" << endl;
cout << "     /`    _.\"{_,_}\"._    `\\" << endl;
cout << "     `/`  ` \\  |||  / `  `\\`" << endl;
cout << "      `\",_  \\\\=^~^=//  _,\"`" << endl;
cout << "          \"=,\\'-=-'/,=\"	" << endl;				
cout << "    	      '---' " << endl;
SetConsoleTextAttribute(hConsole,3);
getch();
	}
	
void efectoEscritura(const char text[]){
	int n = strlen(text);
	for (int i = 0; i < n; i++){
		cout << text[i];
		Sleep(70);
	}
	
}

