#include <stdio.h>
#include <stdlib.h>
#include "lab.h"
#include "Globais.h"



//--------------------------------------------------------------
// Sub-program to shuffle all cards
void shuffleDeck(int vec[],int num)
{
	int ntrocas=rand()%200+190;
	int i,ind1,ind2;
	int aux;		
	for(i=0;i<ntrocas;i++)
	{
		ind1=rand()%num;
		ind2=rand()%num;
		
		aux=vec[ind1];
		vec[ind1]=vec[ind2];
		vec[ind2]=aux;  				
	}
}

//--------------------------------------------------------------
// Takes from one card number from deck and gives to hand[](player or BOT)
// updating topCard indice
void giveCards(int deck[],int hand[],int *topCard,int num)
{
	int i;
	for(i=0;i<num;i++)
	{
	hand[i]=deck[*topCard];
	(*topCard)--;	
	}	
}

//--------------------------------------------------------------
// Show Bot Cards
void showHandBot(int hand[],int num,int x,int y)
{
	int i;
	for(i=0;i<num;i++)	
		if(hand[i]!=-1)
		   drawCardAt(i*9+x,y,cardNumber[hand[i]],cardColor[hand[i]]);		
}

//--------------------------------------------------------------
// Show table Cards
void showTableCards(int table[],int num,int x,int y)
{
	int i;
	
	for(i=0;i<num;i++)
	{
		if(table[i]!=-1)
		   drawCardAt(i*9+x,y,cardNumber[table[i]],cardColor[table[i]]);
		
	}	
}

//--------------------------------------------------------------
// Draw Cards Rectangles
void drawCards(int x,int y,int num)
{
	int i;
	
	for(i=0;i<num;i++)
	{
		showRectAt(i*9+x,y,8,6);
	}	
}

//--------------------------------------------------------------
// Show how many lives we have left
void showLives(int x,int y,int lives)
{
	int i;
	printfAt(x,y,"VIDAS:");
	setColor(VERMELHO,VERMELHO);
	for(i=0;i<lives;i++)
		showRectAt(i*3+x+7,y,0,0);	
	resetColor();
}

//--------------------------------------------------------------
// Show how many clues we have left
void showClues(int x,int y,int clues)
{
	int i;
	printfAt(x,y,"DICAS:");
	setColor(AZUL,AZUL);
	for(i=0;i<clues;i++)
		showRectAt(i*3+x+7,y,0,0);	
	resetColor();
}

//--------------------------------------------------------------
// Discard Table, shows cards that are thrown away
// updating in real time the table 
void showDiscard(int discard[5][5],int x,int y)
{
 int i,j;	
 showRectAt(x,y,30,11);  
 printfAt(x+9,y," - Discard - ");
 printfAt(x+6,y+1,"1    2    3    4    5");
 	
 setColor(AZUL,AZUL);						//draw discard zone
 showRectAt(x+1,y+2,0,0);
 setColor(VERDE,VERDE);						//draw discard zone
 showRectAt(x+1,y+4,0,0);
 setColor(VERMELHO,VERMELHO);						//draw discard zone
 showRectAt(x+1,y+6,0,0);
 setColor(AMARELO,AMARELO);
 showRectAt(x+1,y+8,0,0);
 setColor(BRANCO,BRANCO);
 showRectAt(x+1,y+10,0,0);
	
 resetColor();
 for(i=0;i<5;i++)
 	{
 	for(j=0;j<5;j++)
 		{
		 gotoxy(x+6+j*5,y+2+i*2);
 		 printf("%d",discard[i][j]);
 		}
	}		
}


//--------------------------------------------------------------
// Get top card from deck
// returs (aux) card number with indice "*indice" 
int getNextCard(int deck[],int *indice)
{
 int aux=-1;
 if(*indice>-1)
    aux=deck[*indice];
 (*indice)--;
 return aux;
	
}     

//--------------------------------------------------------------    
// Sub-program to write an array with dimension "num"   
void mostraVetor(int vec[], int num)
{ 
	int i;
	
	for(i=0;i<num;i++)
	{
		printf("  %d  ",vec[i]);
	}
		
}

//--------------------------------------------------------------
// Sub-program that takes the card from Player or Bot Hand and 
// Discard them, giving one more clue and a new card from deck
// to the respective player 
void discardAct(int hand[],int dicas[][5],int position)
{	
	 for (i=position-1;i>0;i--) // Shifts Cards and Clues one position to the right (Not every Card, only those that need)
		         {
		          //Shift cards
		          hand[i]=hand[i-1];
				  // Shift clues place
				  dicas[0][i]=dicas[0][i-1];
				  dicas[1][i]=dicas[1][i-1];	
				 }
				 
 hand[0]= getNextCard(deck,&inTopCard);	// place a new card on first hand position (hand[0])
 dicas[0][0]=0;
 dicas[1][0]=0;
		
	color = indCard / 10;	  
	discard[color][cardNumber[indCard]-1]++;		// Update discard table
	clues++;	
}


//--------------------------------------------------------------
// Sub-program to play one card to the table from player or BOT hand
// to the table, receiving the card position in hand[] and giving
// a new card to the respective hand[], shifting clues needed 
void tablePlay(int hand[], int dicas[][5],int position)
{
		  
 for (i=position-1;i>0;i--) // Shifts Cards and Clues one position to the right (Not every Card, only those that need)
		         {
		          // Shift cards
		          hand[i]=hand[i-1];
	      		  // Shift clues
				  dicas[0][i]=dicas[0][i-1];
				  dicas[1][i]=dicas[1][i-1];	
				 }
				 
 hand[0]= getNextCard(deck,&inTopCard);		// place a new card on first hand position (hand[0])
 dicas[0][0]=0;
 dicas[1][0]=0;
 	
 // Calculate Card Color
 color = indCard / 10; 
				 
 if(cardNumber[table[color]]==-1)							 // If table is empty on that color position 
	{
	 if(cardNumber[indCard]==1)			 	
		 table[color]=indCard; 											// Gives to the table indice of carta
	 else
	  {
		 discard[color][cardNumber[indCard]-1]++;						// Discard Card with color "color" and Number "cardNumber"
		 life--;
	  }
	}
 else														 // Else 
	 if(cardNumber[table[color]]+1==cardNumber[indCard])	 			// Check if Player (or BOT) have the next card (with same color) from the table 
		 table[color]=indCard;
				 	
	 else																// Otherwise (not being possibel to play the card), throws the card to discard area
	  {																	// Losing one life
		 discard[color][cardNumber[indCard]-1]++;	
		 life--;
	  }
	
}

//--------------------------------------------------------------
// Sub-program that receives PLayer or BOT hand and the clues given to eachother
// with the diferent colors possibel 'Red' 'Yellow' 'Green' 'White' 'Blue'
void colorClue(int hand[],int cluesGiven[][5],int color)
{
	int i;
		
	for(i=0;i<5;i++)
	{
		if(cardColor[hand[i]]==color)
			cluesGiven[1][i]=1;		
	}	
}

//--------------------------------------------------------------
// Sub-program that receives PLayer or BOT hand and the clues given to eachother
// with the diferent colors possibel 'Red' 'Yellow' 'Green' 'White' 'Blue'
void numberClues(int hand[],int cluesGiven[][5],int number)
{
	int i;	
		
	for(i=0;i<5;i++)
	{
		if(cardNumber[hand[i]]==number)
			cluesGiven[0][i]=1;		
	}	
}

//--------------------------------------------------------------
// Start a New Game Inicializing all variables needed to play from beggining
// with new name, deck, and diferent hands (all cards without clues) and update Discard table
// clearing all numbers, setting lifes to max (3) and clues to max (8)
void newGame()
{
  srand(time(NULL));
		
	printfAt(40,13,"Escreva o seu Nickname: ");
	gets(name);				
	// Creat deck , each position array position will have one Card number from game ('1' '2' '3' '4' '5')
	// for example,  '0' its Number 1 Blue Card, '49' its Number 5 white card
	
	for(k=0;k<50;k++) 
	    deck[k]=k;					
	shuffleDeck(deck,50);					//shuffle all deck
		
    inTopCard=49;
    giveCards(deck,bot,&inTopCard,5);		//giveCards to Bot and player
	giveCards(deck,player,&inTopCard,5);	

	playing=rand()%2;
	
	for(i=0;i<5;i++) 					// Initialize clues 
		{table[i]=-1;
		 botInfo[0][i]=0;
		 botInfo[1][i]=0;
		 playerInfo[0][i]=0;
		 playerInfo[1][i]=0;
	    for(k=0;k<5;k++)
	    	discard[i][k]=0;
		}	
	clues=8;
	life=3;	
	lastRound=0;	
	strcpy(status,"Bot:");
}

//--------------------------------------------------------------
// Show BOT clues Numbers and Colors given from Player
void showBotInfo()
{
	 for (i=0;i<5;i++)
	{	  
	  if (botInfo[0][i]==1)
	 	{
	 	 gotoxy(7+i*9,8);
	     printf("%d",cardNumber[bot[i]]);	 			
	    } 
	  if (botInfo[1][i]==1)
	 	{
		 setColor(cardColor[bot[i]],cardColor[bot[i]]);
	     showRectAt(9+i*9,8,0,0);
	     resetColor();	
	    } 
	}		
}

//--------------------------------------------------------------
// Show PLayer CLues, Number and Colors
void showPlayerInfo(int hand[])
{
	 for (i=0;i<5;i++)
	{	
	  if(playerInfo[0][i]==1 && playerInfo[1][i]==1)//draw i card		
	  	{
			drawCardAt(i*9+4,21,cardNumber[hand[i]],cardColor[hand[i]]);
	    }		  
	  else
	    {

	      if (playerInfo[0][i]==1)//draw number of i card
	 	   	drawCardAt(i*9+4,21,cardNumber[hand[i]],8);			
	      if (playerInfo[1][i]==1)//draw color of i card 
		    drawCardAt(i*9+4,21,0,cardColor[hand[i]]);
	    }
	}		
}

//--------------------------------------------------------------
// Sub-program to calculate table score adding card Numbers
// returns Adding result
int tableScore()
{
	int soma=0;	
	for(i=0;i<5;i++)
	  if(table[i]!=-1)
		soma=soma+cardNumber[table[i]];	
	return soma;
}

//--------------------------------------------------------------
// sub-program to show ending game result from '0' (min) to '25' (max)
void showResult()
{
	int total=tableScore();
	
	if(total<=5)
	  printf("Oh! Credo foram todos vaiados");
	if(total>=6 && total<=10)
      printf("Muito pobre, os espectadores estão entediados");
    if(total>=11 && total<=15)
	  printf("O espetáculo foi razoável, mas os espectadores já viram melhor");
	if(total>=16 && total<=20)
	  printf("Bom espetáculo! O público está satisfeito");
	if(total>=20 && total<=24)
	  printf("Muito bom! O público está entusiasmado!");
	if(total==25)
	  printf("Lendário! O público nunca esquecerá este espetáculo!");		
}


//--------------------------------------------------------------
//--------------------------------------------------------------
// Main Code Block of the Game
//--------------------------------------------------------------
//--------------------------------------------------------------
void playGame()
{	
	int op=0;
		
	
do{
	system("cls");
	showRectAt(0,0,118,29);
	showVerticalWordAt(3,3,"BOT",3);		//namesOfHands
	showHandBot(bot,5,4,1);

	//Bot clues Area
    showBotInfo();
	
	showVerticalWordAt(2,12,"MESA",4);		
	showRectAt(4,9,50,10);					//Table
	showTableCards(table,5,5,11);
	
	gotoxy(20,28);
	printf("%s",name);
	drawCards(4,21,5);
	//showHandBot(player,5,4,21);  // For testing purpose (show player Cards)
	showPlayerInfo(player);
	
	
	showLives(83,2,life);
	
	showClues(83,4,clues);
		
	showDiscard(discard,75,8);
	
	// Cards left in deck
	showRectAt(57,11,8,6);
	gotoxy(60,14);
	printf("%d",inTopCard+1);
	
	
	// Option menu
	showRectAt(60,21,45,7);
    printfAt(62,21," MENSAGENS: ");
    
    
    
    if(life==0)
    	{
    	 printfAt(62,22,"SEM VIDAS: FIM DE JOGO!!");
    	 gotoxy(62,24);
	 	 printf("Pontuacao= %d",tableScore());	
    	 gotoxy(62,25);
    	 showResult();		 
		 getch();
		 return;			
	
		}
	if(tableScore()==25)
	   {
    	 printfAt(62,22,"VITORIA!!");
    	 gotoxy(62,24);
	 	 printf("Pontuacao= %d",tableScore());
		 gotoxy(62,25);
		 showResult(); 	
    	 getch();
		 return;			
		}
		
	if(lastRound==2)
		{
    	 printfAt(62,22,"SEM CARTAS:FIM DE JOGO!!");
    	 gotoxy(62,24);
	 	 printf("Pontuacao= %d",tableScore());
		 gotoxy(62,25);
		 showResult(); 	
    	 getch();
		 return;			
		}
	
	if(inTopCard<0) // Check if there are no Cards left at deck, and starts last round
		lastRound++;	
	
	
	printfAt(62,27,status);	// Shows Previous Bot Action
		
    //BOT turn 
    if(playing==0)
    {
		setColor(7,7);
		showRectAt(50,4,0,0);
		resetColor();
		botAction();
		playing++;
		saveGame("GameHanabi.txt");
	}
    
    //PLAYER turn
    else{

 do{
 	setColor(7,7);
	showRectAt(50,25,0,0);
	resetColor();
	
    do 
	{
	 printfAt(62,25,"                                      ");
     printfAt(62,22,"1- Jogar Carta  2- Descartar");
	 printfAt(62,23,"3- Pista COR    4- Pista Numero ");
	 printfAt(62,24,"5- Guardar Jogo 6- Sair ");
     op=getche();	
	}while (op<'1' || op>'6'); 
	 if(op=='6'|| op=='5')
	 	break;
	 printfAt(62,25,"position da carta (0 para cancelar): ");
     position=getche();	
  }while (position<'1' || position>'5' );

  position=position-'0';  // change '1' (string) to 1 (int)
  switch(op)
	{
		case '1':
				 indCard=player[position-1];
				 tablePlay(player,playerInfo,position);
				 playing--;
				 break;				  
		case '2':
					if(clues==8)
                 	{
	                	printfAt(62,25,"Numero de dicas no maximo permitido   ");
	                	sleep(2);
	                }
	                else
				 	{	
					 indCard=player[position-1];
			  	     discardAct(player,playerInfo,position);  
					 playing--;  	
				    }
				 break;
		case '3':
				if(clues>0)
				{
				 clues--;
				 colorClue(bot,botInfo,cardColor[bot[position-1]]);
				 playing--;
			    }
			    else
			    {
				 printfAt(62,25,"Sem dicas disponiveis                 ");
			     getch();
			    }
			    
				break;
		case '4':
			    if(clues>0)
				{
				 clues--;
				 numberClues(bot,botInfo,cardNumber[bot[position-1]]);
			     playing--;   
				}
			    else
			    {
				 printfAt(62,25,"Sem dicas disponiveis                  ");
			     getch();
			    }
				break;
				
	    case '5':
	    	     if(saveGame("GameHanabi.txt")==true)
				 	printfAt(62,25,"Jogo guardado com sucesso!             ");
				  else
				    printfAt(62,25,"Erro na gravacao do jogo...            ");	
	    	     getche();
	    	     break;
	    case '6':
				 do
				 {
				 	printfAt(62,25,"Corfirmar saida: 1-Sim 2-Nao  ");
				 	gotoxy(93,25);
				 	k=getche();			 		
				 }while(k!='1' && k!='2');
				 if(k=='2')
				 	op='0';
				 break;
				 		  
	}// end of switch	

if(op!='6')		
 saveGame("GameHanabi.txt");

}//end of player turn
}while (op!='6');	

}
	
	

	

						
	
	
	
	
	
	
	
	

