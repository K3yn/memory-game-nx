#ifndef memory_pairs_helper_H
#define memory_pairs_helper_H

u32 kDown;
u32 kHeld;
u32 kUp;

int reverseCard[32];
int arrayCards[32];// 
int arrayCardsRandom[32];//
int n,x,y;
bool semContDuoTouch;
int contDuoTouch;// 
int isTouchableCard[32];// 
int coordTouch[32][4];
int x,y,n;
int reverseCard[32];
int touchedCard[2];
int arrayCardsRandom[32];
int contMenuMain;
bool salir;
bool mode_main_menu;
bool mode_game;

void loadIniVars();
void generaArrayReverseCard();
void randomArray();// 
void displayCards(); // 
void displayReverseCards();//
void setCoordTouch();
void captureTouchedCard(int coordTouch[],int n);// 
#endif
