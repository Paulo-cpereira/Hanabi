#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "lab.h"
#include "BotAI.c"
#include "Regras.c"
#include "Globais.h"
#include "FileHanabi.c"
#include "jogar.c"


//--------------------------------------------------------------
// Clear screen
// And shows intro screen
void splashScreen()
{
 system("cls");
 setlocale(LC_ALL,"");
 showRectAt(0,0,118,29);
	
 resetColor();
 setForeColor(8);
	
 printfAt(27,1,"##      ##  ########  ##      ##  ########  #########      ##    "); Sleep(100);
 printfAt(27,2,"##      ## ##      ## ###     ## ##      ## #        #     ##    "); Sleep(100);    
 printfAt(27,3,"##      ## ##      ## ## #    ## ##      ## #        #           "); Sleep(100);  
 printfAt(27,4,"########## ########## ##  #   ## ########## #########            "); Sleep(250); 
 printfAt(27,5,"########## ########## ##   #  ## ########## #########      ##    "); Sleep(100);
 printfAt(27,6,"##      ## ##      ## ##    # ## ##      ## #        #     ##    "); Sleep(100);
 printfAt(27,7,"##      ## ##      ## ##     ### ##      ## #        #     ##    "); Sleep(100);
 printfAt(27,8,"##      ## ##      ## ##      ## ##      ## #########      ##    "); Sleep(100);
	
 setForeColor(AMARELO);
 printfAt(1,25,"Trabalho realizado por:");
 printfAt(1,26,"Paulo Jorge");
 printfAt(1,27,"Pedro Mourao");
 printfAt(1,28,"Tiago Lameirao");
 resetColor();
 
}

//--------------------------------------------------------------
// Sub-program to show Option Menu
// Returns option from '1' to '4'
char menuOptions(void)
{
  char opcao;
  printfAt(48,15,"1-Jogar                           ");
  printfAt(48,16,"2-Jogar jogo Guardado");
  printfAt(48,17,"3-Como Jogar");
  printfAt(48,18,"4-Sair");
  printfAt(48,22,"Escolha uma opcao: ");
  do{		
	opcao=getch();
	}while(opcao<='0' || opcao>='5');
  return opcao;
}

//--------------------------------------------------------------
// Sub-program to ask if you wanna exit program
// Return option '1' for yes or '2' for no
char confirmExit()
{
	char opcao,a;
	
	showRectAt(46,20,20,3);
	printfAt(48,21,"Tem a certeza?");
	printfAt(48,22,"1-Sim   2-Nao     ");
	do{	
	gotoxy(45,26);	
	opcao=getch();
	}while(opcao<'1' || opcao>'2');
	
	return opcao;	
			
}

//--------------------------------------------------------------
// Main Code Block that gets player option and execute it
// 1->Play Game| 2->Load Previous Game| 3->Rules| 4->Exit Game
void main(void)
{
 system("MODE con cols=150 lines=55");
 char opcao;
 char opexit='0';
 
 setlocale(LC_ALL,"");
 system("title Hanabi");
	
 splashScreen();
 printfAt(45,15,"Press Any Key to Continue ");
 gotoxy(57,16);
 getch();
  	
 
// While Option != 4 keep game open
// '1' to Play new Game
// '2' to Load Previous Game
// '3' to read game rules
// '4' to exit Game
 do {
  splashScreen();	
  opcao=menuOptions();		
  switch(opcao)
	{
		case '1':
				system("cls");
				newGame();
				playGame();
				break;								
		case '2':
				if(loadGame("GameHanabi.txt")==false)
					{
					 printfAt(48,22,"Erro ao carregar o jogo");
					 getch();
					}
				else
				  playGame();
				break;				
		case '3':
				rules();
				break;
		case '4':
				if(confirmExit()=='2')
				   opcao='0';				//Not to exit
								
	}
	}while(opcao!='4');
	
 splashScreen();
 resetColor();
 printfAt(45,15,"Thanks for playing ");
 Sleep(1000);
 system("cls");
	
}
