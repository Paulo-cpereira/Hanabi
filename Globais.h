#ifndef _GLOBAISH_		//protectes from multiple including...
#define _GLOBAISH_

#include <stdio.h>
#include <stdlib.h>
#include "lab.h"

    char name[16];						//player user name
    int playing=0;						//who is playing: 0-Bot 1-Player
	int k,i,deck[50];					//deck to hold the game cards
	int inTopCard=49;					//top card indicator of deck
	int player[5];						//hold the player cards(cards are numbers from 0-49)
	int bot[5];							//hold the bot cards(cards are numbers from 0-49)
	int table[5]={-1,-1,-1,-1,-1};		//hold the last played card for each color(-1=NULL, 0-BLUE, 1-GREEN, ...)
	int botInfo[2][5]={0,0,0,0,0,		//hold if bot has number clue of bot hand 
					   0,0,0,0,0};		//hold if bot has color clue of bot hand (ex: botInfo[1][4]=1 - has color clue for card 4: right most card)
					   
	int playerInfo[2][5]={0,0,0,0,0,	//same as botInfo but for player
					      0,0,0,0,0};				   
	int lastRound=0;					//flag that indicates when last round is being playing
	int life=3;							//hold life
	int clues=8;						//hold clue
	int indCard;						//hold the index of card (value from 0-49)
	int color;							//auxiliar to hold temporary color card
	int position;						//indicates position of card choosen in hand or table(from 1-5)
	
	int discard[5][5]={0,0,0,0,0,		//keep the cards that are discarded, first dimention color, second dimention number
					   0,0,0,0,0,		//ex: discard[3][2]=1, means that there is ONE, number THREE([2]) YELLOW([3]) card discarded  
					   0,0,0,0,0,
					   0,0,0,0,0,
					   0,0,0,0,0};
	
	//array that holds the NUMBER of each 50 HANABI cards				   
	const int cardNumber[]={1,1,1,2,2,3,3,4,4,5,1,1,1,2,2,3,3,4,4,5,1,1,1,2,2,3,3,4,4,5,1,1,1,2,2,3,3,4,4,5,1,1,1,2,2,3,3,4,4,5};
    
    //array that holds the COLOR of each 50 HANABI cards
	const int cardColor[]={AZUL,AZUL,AZUL,AZUL,AZUL,AZUL,AZUL,AZUL,AZUL,AZUL,
				VERDE,VERDE,VERDE,VERDE,VERDE,VERDE,VERDE,VERDE,VERDE,VERDE,
                VERMELHO,VERMELHO,VERMELHO,VERMELHO,VERMELHO,VERMELHO,VERMELHO,VERMELHO,VERMELHO,VERMELHO,
				AMARELO,AMARELO,AMARELO,AMARELO,AMARELO,AMARELO,AMARELO,AMARELO,AMARELO,AMARELO,
				BRANCO,BRANCO,BRANCO,BRANCO,BRANCO,BRANCO,BRANCO,BRANCO,BRANCO,BRANCO};  
				
	const char colorName[][10]={"AZUL","VERDE","VERMELHO","AMARELO","BRANCO"};  //color names in portuguese
   
	char status[30]="Bot:";			//status mensage for bot action			   
					  					   
#endif					   
