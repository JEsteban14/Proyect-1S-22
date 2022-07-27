#include "time.h"
#include "stdlib.h"

void barajear(char baraja[],char simbolos[]);
void rellenar(char baraja52[]);

void barajear(char baraja[],char simbolos[]){
	
	for(int i = 0; i < 52; i++){
			srand(time(NULL));
			int x = rand()%52;						//Esta cagado mirar aaa en //shit
		
			char save1 = baraja[i];		
			baraja[i] = baraja[x];			
			baraja[x] = save1;
			
			//char save2 = simbolos[i];
			//simbolos[i] = simbolos[x];
			//simbolos[x] = save2;
		}
	}
	
void rellenar(char baraja52[]){
	char CARTAS[] = {'A','2','3','4','5','6','7','8','9','0','J','K','Q'};
	int SIMBOLOS[52]= {0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,3,3,3};
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
