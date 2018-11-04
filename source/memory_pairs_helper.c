#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include "SDL_helper.h"
#include "memory_pairs_touch.h"
#include <time.h>
#include "memory_pairs_helper.h"

void loadIniVars(){
	semContDuoTouch = true;
	contDuoTouch=0;
	salir=false;
	mode_main_menu=true;
	mode_game=false;
	
	int z=0;int n=0;
	for(n=0;n<32;n++){//
		if(n%2==0){
			arrayCards[n]=z;
			arrayCards[n+1]=z;
			z++;
		}
	}
	contMenuMain=0;
}

void generaArrayReverseCard(){
	for(n=0;n<32; n++){
		reverseCard[n]=1;// 
		isTouchableCard[n]=1;// 
	}
}
void randomArray(){

	int estalibre[32];
	int i,pos;
	time_t t;

	//
	srand((unsigned) time(&t));

	//
	for(i=0;i<32;i++){
		estalibre[i]=1;//1 -> libre, 0 -> ocupado
	}

	for(i=0;i<32;i++)	{
		pos=rand()%32;
		//
		while (estalibre[pos]==0)pos=rand()%32;
		arrayCardsRandom[pos]=arrayCards[i];
		estalibre[pos]=0;
	}
}
void displayCards(){
	
	n=0;
	for(y=0;y<4;y++){
		for(x=0;x<8;x++){
			SDL_DrawImageScale(cards00[arrayCardsRandom[n]].texture, 55+150*x, 95+150*y, 112,150);
			n++;
		}
	}
}
void displayReverseCards(){
	n=0;
	for(y=0;y<4;y++){
		for(x=0;x<8; x++){
			if(reverseCard[n]==1)
			{
				SDL_DrawImageScale(revcard[0].texture,55+150*x, 95+150*y, 112,150);
			}
			n++;
		}
	}
}
void setCoordTouch(){
	n=0;
	for(y=0;y<4;y++){	
		for(x=0;x<8;x++){
			coordTouch[n][0]=55+150*x;coordTouch[n][1]=100+150*y;coordTouch[n][2]=165+150*x;coordTouch[n][3]=240+150*y;// CARTA X
			n++;
		}
	}
}
void captureTouchedCard(int coordTouch[],int n){
	if ((kDown & KEY_TOUCH && inBox(Stylus, coordTouch[0], coordTouch[1], coordTouch[2], coordTouch[3]) && isTouchableCard[n]==1))//
	{
			reverseCard[n]=0;// 
			isTouchableCard[n]=0;// 
			touchedCard[contDuoTouch]=n;
			contDuoTouch++;
	} 
	
}
