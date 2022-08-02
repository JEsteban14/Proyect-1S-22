#include "game.h"

int main(){
	system("color 0A");
 	inicio();
 	bool m = true; 		
 	int opc;
 	
 		while(m){
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
	 					printf("Acá va lo de los archivos :)");
	 					system("pause");
	 					break;
	 				case 5:
	 					inicio();
	 					break;
	 				case 0:
	 					m = false;
	 					break;
				 }
		}
 	despedida();
	return 0;			
}
