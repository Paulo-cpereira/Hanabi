#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Globais.h"

//--------------------------------------------------------------
//returns number of cards of value "number"
int playerHasNumber(int number)
{
	int i,c=0;
	
	for(i=0;i<5;i++)
		if(cardNumber[player[i]]==number)
		     c++;

	return c;
}

//--------------------------------------------------------------
//checks if bot has number 1 for first bot play
//if exists return that position, if not return -1
int botHasNumber1()
{
	int i;
	
	for(i=0;i<5;i++)
	{
		if(botInfo[0][i]==1)
			if(cardNumber[bot[i]]==1)
				return i+1;			
	}
	return -1;
}

//--------------------------------------------------------------
//check if bot has card whith number and color given
//return position of card or -1 if no card found 
int botHasCard(int number,int color)
{
	int i;
	
	for(i=0;i<5;i++)
	{
		if(botInfo[0][i]==1 && botInfo[1][i]==1)
			if(cardNumber[bot[i]]==number && cardColor[bot[i]]==color)
				return i+1;
	}
	return -1;
}

//--------------------------------------------------------------
//check if player has a card to play 
//return the position of that card or -1 if no card playable
int playerHasCard(int number,int color)
{
	int i;
	
	for(i=0;i<5;i++)
	{
		if(cardNumber[player[i]]==number && cardColor[player[i]]==color)
			return i+1;		
	}	
	return -1;	
}

//--------------------------------------------------------------
//count the number of cards of "int number" that player has in the hand 
//and returns that amount
int countPlayerCardsNumber(int number)
{
	int count=0,i;
	
	for(i=0;i<5;i++)
		if(cardNumber[player[i]]==number)
			count++;					
	return count;
}


//--------------------------------------------------------------
//count the number of cards of "int color" that player has in hand
//and returns that amount 
int countPlayerCardsColor(int color)
{
	int count=0,i;
	
	for(i=0;i<5;i++)
		if(cardColor[player[i]]==color)
			count++;					
	return count;
}

//-------------------------------------------------------------- 
//returns the small number with no clues on player hand
//return 6 if all player cards has a number clue
int smallPlayerNumber()
{
	int i,menor=6;
	
	for(i=0;i<5;i++)
		if(cardNumber[player[i]]<menor && playerInfo[0][i]==0)
			menor=cardNumber[player[i]];
	
	return menor;	
}

//--------------------------------------------------------------
//checks how many cards in player hand dont have any color clue
//returns that amount  
int howManyNoCluesColor()
{
	int i,count=0;
	
	for(i=0;i<5;i++)
        if(playerInfo[1][i]==0)
			count++;	
	
	return count;
	
}
//--------------------------------------------------------------
//checks the first card without clues from bot hand 
//returns the position of that card ,-1 if it doesnt exist
int botFirstNoClueCard()
{
	int i;
	
	for(i=4;i>=0;i--)
		{
		 if(botInfo[0][i]==0 && botInfo[1][i]==0)
			return i+1;
	    }
			
	return 0;
}
//--------------------------------------------------------------
//checks the smallest number in table
//returns that number
int smallTableNumber()
{
	int i,smallest=6;
	
	for(i=0;i<5;i++)
		{
		 if(table[i]==-1)
		 	{
			 smallest=0;
			 return smallest;
		    }
		 if(cardNumber[table[i]]<smallest)
			smallest=cardNumber[table[i]];
        }
	return smallest;	
}
//--------------------------------------------------------------
//check if bot have all cards with color and number clue,return 1
//if some card doesnt have a clue return 0 
int botHasAllClues()
{
	int i;
	
	for(i=0;i<5;i++)
	{
		if(botInfo[0][i]==0 || botInfo[1][i]==0){	
			return 0;
		}
		return 1;		
	}	
}
//--------------------------------------------------------------
//count how many clues the player has
//return that amount
int countPlayerClues()
{
	int i,count=0;
	
	for(i=0;i<5;i++)
	   count=count+playerInfo[0][i]+playerInfo[1][i];
	
	return count;
}


//--------------------------------------------------------------
//--------------------------------------------------------------
//main function for bot turn
//--------------------------------------------------------------
//--------------------------------------------------------------
void botAction()
{    
	int position=0,i,number,aux;

//first play
		
//check if table is empty and bot has 1
	if(tableScore()==0)
	 {
	  position=botHasNumber1();
	  if(position!=-1)
	   {
	   	 indCard=bot[position-1];
		 tablePlay(bot,botInfo,position);
		 strcpy(status,"Bot: Jogou uma carta 1");
	  	 return;
	   }
     }

	//check if table is empty and if player has 1
	if(tableScore()==0 && playerHasNumber(1)>0)
			{		
			 numberClues(player,playerInfo,1);
			 clues--;
			 strcpy(status,"Bot: Deu dica de numero 1");	
			 return;
			}
			
//end of first play 

//check if bot can play a card to table
	for(i=0;i<5;i++)
	{
	  if(table[i]==-1)
		 number=0;
	  else
		 number=cardNumber[table[i]];
	  
	  color=cardColor[i*10];
		
	  position=botHasCard(number+1,color);
	  
	  if(position!=-1)
	  	{
	  	 indCard=bot[position-1];	
         tablePlay(bot,botInfo,position);
		 sprintf(status,"Bot: Jogou Carta %d %s",cardNumber[indCard],colorName[indCard/10]);	
		 return;	    
		}		
}
	
//check if bot can discard non playable card
//colocado aqui para melhorar a IA do bot 
if(clues<8 && countPlayerClues()>2)    //o player ja tem 3 dicas nao necessita de mais :)
{ 
 position=0;
 aux=smallTableNumber();
 
 if(aux!=0)
 {
  for(i=0;i<5;i++)
   {
   	if(botInfo[0][i]==1)
   	   if(cardNumber[bot[i]]<=aux)
		{ 
		 aux=cardNumber[bot[i]];
		 position=i+1;
	    }
   }
  if(position!=0)
  	{
  	 indCard=bot[position-1];
	 discardAct(bot,botInfo,position);  
	 sprintf(status,"Bot: Descartou Carta %d %s",cardNumber[indCard],colorName[indCard/10]);
	 return;	
	}	
 }	
}
	
//no cards playable
if(clues>0)
{
	for(i=0;i<5;i++)
	{
	  if(table[i]==-1)
		 number=0;
	  else
		 number=cardNumber[table[i]];
	  
	  color=cardColor[i*10];
		
	  position=playerHasCard(number+1,color);
	  if(position!=-1)
	    {
	      if(playerInfo[0][i]==0 && playerInfo[1][i]==0)	//if card is playable and is without clues
	      {
	    	if(countPlayerCardsNumber(number+1)==1)
	    		{
	    		 numberClues(player,playerInfo,cardNumber[player[position-1]]);
	             sprintf(status,"Bot: Tens um unico numero %d",number+1);	
                 clues--;	
	    		 return;	
				}
			else
				 if(countPlayerCardsColor(color)==1)
	    		{
	    		 colorClue(player,playerInfo,cardColor[player[position-1]]);
	             sprintf(status,"Bot: Tens uma unica carta %s",colorName[i]);	
                 clues--;	
	    		 return;			
			    }
		   }
	      else
	         if(playerInfo[0][i]==1)
			 	{
			 	 colorClue(player,playerInfo,cardColor[player[position-1]]);
	             sprintf(status,"Bot: Deu dica de cor %s",colorName[i]);	
                 clues--;
				 return;	
			 	}	
	    	 else
	    	     if(playerInfo[1][i]==1)
	    	      {
	    		    numberClues(player,playerInfo,cardNumber[player[position-1]]);
	                sprintf(status,"Bot: Deu dica de numero %d",number+1);	
                    clues--;	
	    		    return;	
				  }
	    	     else
				    if(rand()%2==1)
					  {
					   numberClues(player,playerInfo,cardNumber[player[position-1]]);
	                   sprintf(status,"Bot: Deu dica de numero %d",number+1);	
                       clues--;	
	    		       return;	
					  }		
	    	     	else
	    	     	   {
			 	        colorClue(player,playerInfo,cardColor[player[position-1]]);
	                    sprintf(status,"Bot: Deu dica de cor %s",colorName[i]);	
                        clues--;
				        return;	
				       }
		}// end if player has playable card 	
}//end of for


//going to check if bot can give a clue of the smallest number of player 
int menor=smallPlayerNumber();
if(menor!=6)
{
 numberClues(player,playerInfo,menor);
 sprintf(status,"Bot: Deu dica de numero %d",menor);	
 clues--;	
 return;			
}
//going to check if bot can give a clue of a random color 
if(howManyNoCluesColor()!=0)
{

      while(1)
	  {	
		aux=rand()%5;
		if(playerInfo[1][aux]==0)
			{
		     colorClue(player,playerInfo,cardColor[player[aux]]);
	         sprintf(status,"Bot: Deu dica de cor %s",colorName[player[aux]/10]);	
             clues--;
             return;
            }
      }
}

}//end of if(clues>0)


//no clues left bot makes a discard
//discards the first no clue card
 position=botFirstNoClueCard();
 if(position!=0)
 {
	indCard=bot[position-1];
	discardAct(bot,botInfo,position);  
	sprintf(status,"Bot: Descartou Carta %d %s",cardNumber[indCard],colorName[indCard/10]);
	return;
 }
 
 //checking if can discard any 
 position=0;
 aux=smallTableNumber();
 
 if(aux!=0)
 {
  for(i=0;i<5;i++)
   {
   	if(botInfo[0][i]==1)
   	   if(cardNumber[bot[i]]<=aux)
		{ 
		 aux=cardNumber[bot[i]];
		 position=i+1;
	    }
   }
  if(position!=0)
  	{
  	 indCard=bot[position-1];
	 discardAct(bot,botInfo,position);  
	 sprintf(status,"Bot: Descartou Carta %d %s",cardNumber[indCard],colorName[indCard/10]);
	 return;	
	}	
 }	

//checks if bot has a card without all clues and discards it randomly
if(botHasAllClues()!=1)
{
	while(1)
	{
		position=rand()%5+1;
		if(botInfo[0][position-1]==0 || botInfo[1][position-1]==0)
		   {
		   	indCard=bot[position-1];
	        discardAct(bot,botInfo,position);  
	        sprintf(status,"Bot: Descartou Carta %d %s",cardNumber[indCard],colorName[indCard/10]);
	        return;
		   }
	}
}

//bot will discard a random card
	position=rand()%5+1;
    indCard=bot[position-1];
	discardAct(bot,botInfo,position);  
	sprintf(status,"Bot: Descartou Carta %d %s",cardNumber[indCard],colorName[indCard/10]);
	return;	
		
}//end of botAction


