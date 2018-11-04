#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <switch.h>
#include <errno.h>
#include <time.h>
#include <sys/stat.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "SDL_helper.h"
#include "memory_pairs_helper.h"
#include "memory_pairs_touch.h"
#include "memory_pairs_savegame.h"
#include "memory_pairs_textures.h"
#include "memory_pairs_acc.h"
#include "memory_pairs_fonts.h"

char resultado[10];
char charContDuoTouch[20];
char charTouchCoard0[2];
char charTouchCoard1[2];
char charArrayCard0[2];
char charArrayCard1[2];
char charFin[10];


void displayGame(){
	SDL_RenderClear(renderer);
	
	SDL_DrawRect(renderer,0,0,1280,768,WHITE);
	SDL_DrawText(renderer, Roboto_60, 60, 15, GRAY, "MEMORY PAIRS");//
	if(mode_main_menu)
	{
		SDL_DrawText(renderer, Roboto_80, 500, 200, GRAY, "PLAY");//
		SDL_DrawText(renderer, Roboto_80, 500, 400, GRAY, "EXIT");//
		switch(contMenuMain){
			case 0:// PLAY 
				SDL_DrawText(renderer, Roboto_80, 500, 200, BLACK, "PLAY");//
				break;
			case 1:// EXIT   
				SDL_DrawText(renderer, Roboto_80, 500, 400, BLACK, "EXIT");//
				break;					
			default:
				break;
		}
	}
	else if(mode_game)
	{	
		//SDL_DrawText(renderer, Roboto_large, 550, 15, BLACK, resultado);//
		//SDL_DrawText(renderer, Roboto_large, 750, 15, BLACK, charFin);//
		//SDL_DrawText(renderer, Roboto, 1160, 10, BLACK, charContDuoTouch);//
		//SDL_DrawText(renderer, Roboto, 1100, 35, BLACK, charTouchCoard0);// 
		//SDL_DrawText(renderer, Roboto, 1150, 35, BLACK, charTouchCoard1);// 
		//SDL_DrawText(renderer, Roboto, 1100, 60, BLACK, charArrayCard0);//
		//SDL_DrawText(renderer, Roboto, 1150, 60, BLACK, charArrayCard1);//
		displayCards();// 
		displayReverseCards(); // 
	}

	//SDL_DrawImageScale(icon.texture, 20, 600, 96, 96);
	//SDL_DrawImageScale(iconframe.texture, 20, 600, 96, 96);
	//SDL_DrawText(renderer, Roboto_large, 130, 630, BLACK, username);

	SDL_RenderPresent(renderer);				
}

void manageControls(){
	if(mode_main_menu)
	{
		u8 newContMenuMain;
		if ((kDown & KEY_TOUCH && inBox(Stylus, 500, 210, 700, 280)))// - start game
		{
			newContMenuMain=0;
			
			if (contMenuMain == newContMenuMain)
			{
				mode_main_menu=false;
				mode_game=true;
				//selectorModo=true;
				//playSound('A');
			}
			else
			{
				contMenuMain = newContMenuMain;
				//playSound('N');
			}
		} 
		else if ((kDown & KEY_TOUCH && inBox(Stylus, 500, 410, 700, 480)))// - EXIT
		{	newContMenuMain=1;
			
			if (contMenuMain == newContMenuMain)
			{
				salir=true;
				//selectorModo=true;
				//playSound('A');
			}
			else
			{
				contMenuMain = newContMenuMain;
				//playSound('N');
			}
		} 		
	}
	else if(mode_game)
	{
		if (contDuoTouch<2)
		{
			n=0;
			for(y=0;y<4;y++){	
				for(x=0;x<8;x++){
					captureTouchedCard(coordTouch[n],n);//
					n++;
				}
			}
			itoa(touchedCard[0],charTouchCoard0,10);// 
			itoa(touchedCard[1],charTouchCoard1,10);// 
			itoa(contDuoTouch,charContDuoTouch,10);
		}
		else if(contDuoTouch==2)
		{
			
			if(arrayCardsRandom[touchedCard[0]]==arrayCardsRandom[touchedCard[1]])
			{
				strcpy(resultado,"acierto");
				
			}
			else
			{
				strcpy(resultado,"");
				SDL_Delay(1000);// 
				reverseCard[touchedCard[0]]=1;reverseCard[touchedCard[1]]=1;//
				isTouchableCard[touchedCard[0]]=1;isTouchableCard[touchedCard[1]]=1;//
				
			}
			itoa(arrayCardsRandom[touchedCard[0]],charArrayCard0,10);
			itoa(arrayCardsRandom[touchedCard[1]],charArrayCard1,10);
			semContDuoTouch=false;
			itoa(contDuoTouch,charContDuoTouch,10);
			contDuoTouch++;
		}
		else if(contDuoTouch==3)
		{
			
			for(x=0;x<32;x++){
				if(isTouchableCard[x]!=0){
					x=100;
					contDuoTouch=0;
				}
			}
			if(x==32){
				strcpy(charFin,"");
				contDuoTouch++;
			}
			
		}
		else if(contDuoTouch==4)
		{	
		
			SDL_Delay(3000);
			strcpy(charFin,"In game");
			loadIniVars();
			generaArrayReverseCard();
			randomArray();
			setCoordTouch();
			contDuoTouch=0;
		}
		if (kDown & KEY_L)// - start game
		{
			SDL_Delay(750);
			loadIniVars();
			generaArrayReverseCard();
			randomArray();
			setCoordTouch();
			contDuoTouch=0;
		}
	}	
}
	
int main(int argc, char **argv)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);
	SDL_Init(SDL_INIT_AUDIO);
	romfsInit();
	TTF_Init();
	srand (time(NULL));
	// SDL
	window = SDL_CreateWindow("Main-Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 0, 0, SDL_WINDOW_FULLSCREEN_DESKTOP);	
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
	
	load_textures(); // 
	load_fonts();// 
	loadIniVars();
	generaArrayReverseCard();
	randomArray();
	setCoordTouch();

	// Main loop
    while(appletMainLoop())
    {   
        //Scan all the inputs. This should be done once for each frame
        hidScanInput();
		hidTouchRead(&Stylus, 0);
		
		kDown = hidKeysDown(CONTROLLER_P1_AUTO);
		kUp = hidKeysUp(CONTROLLER_P1_AUTO);
		kHeld= hidKeysHeld(CONTROLLER_P1_AUTO);
        if (kDown & KEY_PLUS || salir) break; // break in order to return to hbmenu
		
		displayGame();//
	    	manageControls();
    }// 
	
	SDL_DestroyWindow(window);// 
	
	TTF_Quit();
	romfsExit();
	IMG_Quit();
	SDL_Quit();
	
    return 0;
}
