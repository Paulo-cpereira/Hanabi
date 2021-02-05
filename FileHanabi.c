#include <stdio.h>
#include <stdlib.h>
#include "Globais.h"
#include "lab.h"

//--------------------------------------------------------------
//function that save the game in hard disk
int saveGame(char *fileName)
{
	FILE *fp;
	
	fp=fopen(fileName,"w");
	
	if(fp==NULL)
	  return false;
	 
	fprintf(fp,"HANABI FILE GAME\n");		//signature that indicates an HANABI file game
	fprintf(fp,"%s\n",name);
	fprintf(fp,"%d\n",playing);
	for(i=0;i<50;i++)
		fprintf(fp,"%d ",deck[i]);
	fprintf(fp,"\n");
	fprintf(fp,"%d\n",inTopCard);
	for(i=0;i<5;i++)
	    fprintf(fp,"%d ",player[i]);	    
    fprintf(fp,"\n");
    for(i=0;i<5;i++)
	    fprintf(fp,"%d ",bot[i]);	    
    fprintf(fp,"\n");
    for(i=0;i<5;i++)
	    fprintf(fp,"%d ",table[i]);	    
    fprintf(fp,"\n");
    for(i=0;i<5;i++)
	    fprintf(fp,"%d ",botInfo[0][i]);	    
    fprintf(fp,"\n");
    for(i=0;i<5;i++)
	    fprintf(fp,"%d ",botInfo[1][i]);	    
    fprintf(fp,"\n");
    for(i=0;i<5;i++)
	    fprintf(fp,"%d ",playerInfo[0][i]);	    
    fprintf(fp,"\n");
    for(i=0;i<5;i++)
	    fprintf(fp,"%d ",playerInfo[1][i]);	    
    fprintf(fp,"\n");
    fprintf(fp,"%d\n%d\n",life,clues);
    for(i=0;i<5;i++)
	    {for(k=0;k<5;k++)
	        fprintf(fp,"%d ",discard[i][k]);	    
         fprintf(fp,"\n");   
	    }
	fprintf(fp,"%s",status);
	
	fclose(fp);

	return true;		  	
}

//--------------------------------------------------------------
//function that read from file the game HANABI saved
int loadGame(char *fileName)
{
	FILE *fp;
	char aux[20];
	
	fp=fopen(fileName,"r");
	
	if(fp==NULL)
	  return false;
	  
	fgets(aux,20,fp);
	if(strcmp(aux,"HANABI FILE GAME\n")!=0)		//cheks if has a HANABI file signature
	  return false;
	  
	fgets(name,16,fp);
	fscanf(fp,"%d\n",&playing);
	for(i=0;i<50;i++)
		fscanf(fp,"%d ",&deck[i]);
	fscanf(fp,"%d\n",&inTopCard);
	for(i=0;i<5;i++)
	    fscanf(fp,"%d ",&player[i]);	    
    for(i=0;i<5;i++)
	    fscanf(fp,"%d ",&bot[i]);	    
    for(i=0;i<5;i++)
	    fscanf(fp,"%d ",&table[i]);
	for(i=0;i<5;i++)
	    fscanf(fp,"%d ",&botInfo[0][i]);	    
    for(i=0;i<5;i++)
	    fscanf(fp,"%d ",&botInfo[1][i]);	    
    for(i=0;i<5;i++)
	    fscanf(fp,"%d ",&playerInfo[0][i]);	    
    for(i=0;i<5;i++)
	    fscanf(fp,"%d ",&playerInfo[1][i]);	    
    fscanf(fp,"%d\n%d\n",&life,&clues);
    for(i=0;i<5;i++)
	    {for(k=0;k<5;k++)
	        fscanf(fp,"%d ",&discard[i][k]);	      
	    }    
	fgets(status,30,fp);
		
	fclose(fp);	
	
	return true;
	
}



