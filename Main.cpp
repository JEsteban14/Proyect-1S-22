#include "game.h"

int main(){
 	inicio();
 	bool salir = false; 		
 	int opc; 	
 	while(!salir){
 		system("color 03");				// Color principal de consola
 		menu();							//Impresi�n de men�
 		verificacion(0,5,&opc);
			switch(opc){
				case 1:					
					blackjack();	 	//Juego					
					break;
				case 2:
					instrucciones();	//Instructivo
					break;
				case 3:
					info();				//C�digo del proyecto
					break;
				case 4:
					outScore();			//Impresi�n de puntajes
					system("pause");
					break;
				case 5:
					inicio();			//Portada
					break;
				case 0:
					salir = true;
					break;
			}
		}
 	despedida();						//Mensaje de despedida
	return 0;			
}
