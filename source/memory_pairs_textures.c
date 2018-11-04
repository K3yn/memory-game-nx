#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "SDL_Helper.h"
#include "memory_pairs_textures.h"

void load_textures(void){
	
	
	// user icon

	surface = IMG_Load("romfs:/resources/icon_frame.png");
	iconframe.texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	
	// Numeros de colores
	surface = IMG_Load("romfs:/resources/NUMBERS_SET.png");
	numerosColoresTxt.texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);	
	
	// revcard
	surface = IMG_Load("romfs:/resources/revcard/revcard00.png");
	revcard[0].texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);	

	// cartas   ON 

	surface = IMG_Load("romfs:/resources/cards00/card00.png");
	cards00[0].texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	
	surface = IMG_Load("romfs:/resources/cards00/card01.png");
	cards00[1].texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	surface = IMG_Load("romfs:/resources/cards00/card02.png");
	cards00[2].texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	
	surface = IMG_Load("romfs:/resources/cards00/card03.png");
	cards00[3].texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	
	surface = IMG_Load("romfs:/resources/cards00/card04.png");
	cards00[4].texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	
	surface = IMG_Load("romfs:/resources/cards00/card05.png");
	cards00[5].texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	surface = IMG_Load("romfs:/resources/cards00/card06.png");
	cards00[6].texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	
	surface = IMG_Load("romfs:/resources/cards00/card07.png");
	cards00[7].texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	surface = IMG_Load("romfs:/resources/cards00/card08.png");
	cards00[8].texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	surface = IMG_Load("romfs:/resources/cards00/card09.png");
	cards00[9].texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	
	surface = IMG_Load("romfs:/resources/cards00/card10.png");
	cards00[10].texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	surface = IMG_Load("romfs:/resources/cards00/card11.png");
	cards00[11].texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	surface = IMG_Load("romfs:/resources/cards00/card12.png");
	cards00[12].texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	
	surface = IMG_Load("romfs:/resources/cards00/card13.png");
	cards00[13].texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	
	surface = IMG_Load("romfs:/resources/cards00/card14.png");
	cards00[14].texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	
	surface = IMG_Load("romfs:/resources/cards00/card15.png");
	cards00[15].texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);	
}
