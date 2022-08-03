#include "game.h"

int main(){
	system("color 06");
 	inicio();
 	bool salir = false; 		
 	int opc; 	
 	while(!salir){
 		menu();
 		verificacion(0,5,&opc);
			switch(opc){
				case 1:					
					blackjack();	 					
					break;
				case 2:
					instrucciones();
					break;
				case 3:
					info();
					break;
				case 4:
					outScore();
					system("pause");
					break;
				case 5:
					inicio();
					break;
				case 0:
					salir = true;
					break;
			}
		}
 	despedida();
	return 0;			
}
