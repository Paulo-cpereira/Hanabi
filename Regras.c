#ifndef _REGRASC_		//protectes from multiple including...
#define _REGRASC_

#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <locale.h>
#include "lab.h"

//--------------------------------------------------------------
//function that write the rules of the game
void rules()
{
	system("cls");
	setlocale(LC_ALL, "");
	
	int i;
	char text[]={
	
"                    Desenrolar do Jogo\n"
"\n"
"	Depois de se escolher um primeiro jogador, cada jogador joga � vez,\n"
" poder� fazer uma das seguintes a��es:\n"
"\n"
"	1. Jogar carta para Mesa\n"
"	2. Descartar uma carta\n"
"	3. Dar pista sobre uma COR\n"
"	4. Dar pista sobre um NUMERO\n"
"\n"
"\n"
"$1.Dar uma pista:                                        \n"
"\n"
"   S� poder� usar esta a��o se existirem fichas de pista dispon�veis,\n"
" primeiro vira-se uma ficha de pista n�o usada ficando a face escura para cima, e de seguida\n"
" as �nicas pistas que se podem dar s�o relativas ou � cor ou ao n�mero das cartas desse jogador.\n"
"\n"
" As pistas permitidas s�o indicar a posi��o de:\n"
"	\n"
" -todas as cartas de uma cor \n"
" -todas as cartas de um n�mero\n"
"\n"
"   Nunca se pode indicar simultaneamente a cor e o n�mero de qualquer carta.\n"
"\n"
"   Exemplo de pistas poss�veis:\n"
"\n"
"  -�Tens um 5 aqui� (Se existirem apenas um 5)\n"
"  -�Tens um 1 aqui, aqui e ali� (Se existirem exatamente tr�s cartas 1)\n"
"  -�N�o tens cartas 2� (Se o jogador n�o tiver cartas 2)\n"
"  -�Tens uma carta azul aqui� (Se existirem apenas uma carta da cor azul)\n"
"  -�Tens uma carta amarela aqui e ali� (Se existirem exatamente 2 cartas amarelas)\n"
"  -�N�o tens cartas verdes� (Se o jogador n�o tiver cartas nenhuma carta verde)\n"
"\n"
"\n"
"$2. Descartar uma carta:                                       \n"
"	\n"
"   Esta a��o adiciona-se uma pista �s existentes virando uma das que foram usadas (com a\n"
" face escura para cima). Esta a��o n�o pode ser usada caso estejam dispon�veis todas as pistas.\n"
" O jogador anuncia que vai DESCARTAR uma carta e escolhe uma das suas cartas e coloca-a no monte de \n"
" cartas descartadas. As cartas do monte de descarte podem ser consultadas em qualquer altura\n"
" por qualquer jogador.\n"
"\n"
"\n"
"$3. Jogar (para a mesa) uma carta:                                      \n"
"	\n"
"   � ao jogar cartas para a mesa que se constr�i o fogo-de-artif�cio. O jogador anuncia que vai\n"
" JOGAR uma carta e escolhe a carta para jogar na mesa. Ocorre uma das duas situa��es seguintes:\n"
"	\n"
"  - A carta PODE ser jogada corretamente na mesa, iniciando um fogo-de-artif�cio ou\n"
" continuando um j� existente. Ou seja, a carta inicia uma cor (� uma carta 1) ou �\n"
" sequencial em rela��o � sua cor (por exemplo � um 3 verde e na mesa j� existe um 2\n"
" verde). Caso a carta jogada seja um 5, completando uma cor, ganha-se uma pista. Se as 8 pistas\n"
" j� estiverem dispon�veis esta benesse perde-se.\n"
"\n"
"  - A carta pode ou N�O PODE ser jogada corretamente na mesa. Ou seja, n�o � sequencial\n"
" no monte da sua cor. Por exemplo jogar um 1 verde, e na mesa j� existir um 1 no monte\n"
" das cartas verdes, ou jogar um 4 azul e no monte azul n�o estar um 3 azul. Neste caso os\n"
" deuses ficam furiosos e enviam um raio vindo do c�u, resultando na perda de uma vida.\n"
" Volta-se uma ficha de vida ao contr�rio exibindo agora um raio. As vidas n�o s�o recuper�veis.\n"
" Depois de jogar o jogador completa a sua m�o para 5 (ou 4) cartas retirando uma nova\n"
" carta do monte de compra (se houver cartas dispon�veis no baralho de compra), mas\n"
" sem olhar para a frente da carta!\n"
"\n"
"\n"
" $  Fim do Jogo                                                 \n"
"\n"
"   O jogo termina se:\n"
" \n"
"  - todos os montes de cor forem terminados. O espet�culo terminou e a pontua��o � de 25 pontos.\n"
"  \n"
"  - a �ltima carta do baralho de compra for removida, nesse caso todos os jogadores jogam\n"
" uma �ltima vez. A pontua��o final corresponde ao total de cartas que conseguiram jogar na mesa.\n"
"\n"
"  - a terceira ficha de vida for virada. O jogo termina e a pontua��o � de 0 pontos. Os deuses\n"
" demonstram a sua ira na forma de uma tempestade que p�e fim ao fogo-de-artif�cio.\n"
" \n"
"  Como foi a vossa presta��o a montar um fogo-de-artificio?\n"
"\n"
" 0 a 5 pontos � Oh! Credo foram todos vaiados.\n"
" 6 a 10 pontos � Muito pobre, os espectadores est�o entediados.\n"
" 11 a 15 pontos � O espet�culo foi razo�vel, mas os espectadores j� viram melhor.\n"
" 16 a 20 pontos � Bom espet�culo! O p�blico est� satisfeito.\n"
" 21 a 24 pontos � Muito bom! O p�blico est� entusiasmado!\n"
" 25 pontos � Lend�rio! O p�blico nunca esquecer� este espet�culo!\n"};
				 
				 

	for(i=0;i<strlen(text);i++)
	{
		
		
		
		Sleep(1);
		if(text[i]== '$'){
		   printf("Prima algo para continuar a ver");
		   system("pause>NULL");
      	   printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
		}
		else
			{
			printf("%c",text[i]);
			Sleep(1);
		    }
	
	 } 
					
	system("pause>NULL");	
}

#endif

