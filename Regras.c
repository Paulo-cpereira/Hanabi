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
"	Depois de se escolher um primeiro jogador, cada jogador joga à vez,\n"
" poderá fazer uma das seguintes ações:\n"
"\n"
"	1. Jogar carta para Mesa\n"
"	2. Descartar uma carta\n"
"	3. Dar pista sobre uma COR\n"
"	4. Dar pista sobre um NUMERO\n"
"\n"
"\n"
"$1.Dar uma pista:                                        \n"
"\n"
"   Só poderá usar esta ação se existirem fichas de pista disponíveis,\n"
" primeiro vira-se uma ficha de pista não usada ficando a face escura para cima, e de seguida\n"
" as únicas pistas que se podem dar são relativas ou à cor ou ao número das cartas desse jogador.\n"
"\n"
" As pistas permitidas são indicar a posição de:\n"
"	\n"
" -todas as cartas de uma cor \n"
" -todas as cartas de um número\n"
"\n"
"   Nunca se pode indicar simultaneamente a cor e o número de qualquer carta.\n"
"\n"
"   Exemplo de pistas possíveis:\n"
"\n"
"  -“Tens um 5 aqui” (Se existirem apenas um 5)\n"
"  -“Tens um 1 aqui, aqui e ali” (Se existirem exatamente três cartas 1)\n"
"  -“Não tens cartas 2” (Se o jogador não tiver cartas 2)\n"
"  -“Tens uma carta azul aqui” (Se existirem apenas uma carta da cor azul)\n"
"  -“Tens uma carta amarela aqui e ali” (Se existirem exatamente 2 cartas amarelas)\n"
"  -“Não tens cartas verdes” (Se o jogador não tiver cartas nenhuma carta verde)\n"
"\n"
"\n"
"$2. Descartar uma carta:                                       \n"
"	\n"
"   Esta ação adiciona-se uma pista às existentes virando uma das que foram usadas (com a\n"
" face escura para cima). Esta ação não pode ser usada caso estejam disponíveis todas as pistas.\n"
" O jogador anuncia que vai DESCARTAR uma carta e escolhe uma das suas cartas e coloca-a no monte de \n"
" cartas descartadas. As cartas do monte de descarte podem ser consultadas em qualquer altura\n"
" por qualquer jogador.\n"
"\n"
"\n"
"$3. Jogar (para a mesa) uma carta:                                      \n"
"	\n"
"   É ao jogar cartas para a mesa que se constrói o fogo-de-artifício. O jogador anuncia que vai\n"
" JOGAR uma carta e escolhe a carta para jogar na mesa. Ocorre uma das duas situações seguintes:\n"
"	\n"
"  - A carta PODE ser jogada corretamente na mesa, iniciando um fogo-de-artifício ou\n"
" continuando um já existente. Ou seja, a carta inicia uma cor (é uma carta 1) ou é\n"
" sequencial em relação à sua cor (por exemplo é um 3 verde e na mesa já existe um 2\n"
" verde). Caso a carta jogada seja um 5, completando uma cor, ganha-se uma pista. Se as 8 pistas\n"
" já estiverem disponíveis esta benesse perde-se.\n"
"\n"
"  - A carta pode ou NÃO PODE ser jogada corretamente na mesa. Ou seja, não é sequencial\n"
" no monte da sua cor. Por exemplo jogar um 1 verde, e na mesa já existir um 1 no monte\n"
" das cartas verdes, ou jogar um 4 azul e no monte azul não estar um 3 azul. Neste caso os\n"
" deuses ficam furiosos e enviam um raio vindo do céu, resultando na perda de uma vida.\n"
" Volta-se uma ficha de vida ao contrário exibindo agora um raio. As vidas não são recuperáveis.\n"
" Depois de jogar o jogador completa a sua mão para 5 (ou 4) cartas retirando uma nova\n"
" carta do monte de compra (se houver cartas disponíveis no baralho de compra), mas\n"
" sem olhar para a frente da carta!\n"
"\n"
"\n"
" $  Fim do Jogo                                                 \n"
"\n"
"   O jogo termina se:\n"
" \n"
"  - todos os montes de cor forem terminados. O espetáculo terminou e a pontuação é de 25 pontos.\n"
"  \n"
"  - a última carta do baralho de compra for removida, nesse caso todos os jogadores jogam\n"
" uma última vez. A pontuação final corresponde ao total de cartas que conseguiram jogar na mesa.\n"
"\n"
"  - a terceira ficha de vida for virada. O jogo termina e a pontuação é de 0 pontos. Os deuses\n"
" demonstram a sua ira na forma de uma tempestade que põe fim ao fogo-de-artifício.\n"
" \n"
"  Como foi a vossa prestação a montar um fogo-de-artificio?\n"
"\n"
" 0 a 5 pontos – Oh! Credo foram todos vaiados.\n"
" 6 a 10 pontos – Muito pobre, os espectadores estão entediados.\n"
" 11 a 15 pontos – O espetáculo foi razoável, mas os espectadores já viram melhor.\n"
" 16 a 20 pontos – Bom espetáculo! O público está satisfeito.\n"
" 21 a 24 pontos – Muito bom! O público está entusiasmado!\n"
" 25 pontos – Lendário! O público nunca esquecerá este espetáculo!\n"};
				 
				 

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

