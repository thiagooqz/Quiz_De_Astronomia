#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

			/* AstroQuiz */
			
			
// Criando tr�s tipos de Struct

typedef struct{
  char per[200];
  char opc[200];
  char res[5];
}arqlido;

typedef struct{
  char r[1];
  char nome[50];
  int pontua;
}escreveu;

typedef struct{
  char nome[50];
  int pontua;
}organiza;



int main(){
	setlocale(LC_ALL, "Portuguese"); // Ativando Locale para que os acentos sejam impresos corretament. 

  int val, i=0, j=0, z=0;
  int  v, aux, w=1, ponto=0;;
  int c=0, certo=0, errado=0, cont_jogadores=0;
  char mudar;
  
  arqlido wil[115];  // Criando vetores onde as os dados de struct ser�o guardados.
  escreveu a;	
  organiza tudo[10];
  
			FILE *pont = fopen("Arquivo_perguntas.txt", "r"); // Criando ponteiros e abrindo arquivos no modo de leitura.
			FILE *p_opcao = fopen("Opcoes_das_questoes.txt", "r");
			FILE *p_res = fopen("Respostas.txt", "r");
			FILE *melhoresjogadores = fopen("Melhores_jogadores.txt", "r");
			
			if(pont == NULL){    // Verificando se os arquivos foram abertos corretamente.
				printf("Erro na abertura do arquivo de perguntas!\n");
			}
			if(p_opcao == NULL){
				printf("Erro na abertura do arquivo Opcoes das questoes!\n");
			}
			if(p_res == NULL){
				printf("Erro na abertura do arquivo Respostas!\n");
			}
			
			// Lendo tudo o que est� escrito no arquivo dos melhores jogadores e guardando em cada posi��o do vetor tudo 
			//do struct do organiza.
			if(melhoresjogadores != NULL){ 
				while(fscanf(melhoresjogadores, "%[^\n]s", tudo[i].nome)!=EOF){
					  fscanf(melhoresjogadores, "\n");
            		  fscanf(melhoresjogadores, "%d", &tudo[i].pontua);
            		  fscanf(melhoresjogadores, "\n");
            	i=i+1;	  
				}
	 	
 			 }
 			 j=i;
 			 fclose(melhoresjogadores); // Fechando o arquivo dos melhores jogadores.
 			 
 		 // Lendo tudo o que est� escrito nos arquivos e guardando em cada posi��o do vetor wil do struct d tipo arquilido.
	  i = 0;
      if(pont != NULL){
				while(fscanf(pont, "%[^\n]s", wil[i].per)!=EOF){
            fscanf(p_opcao, "%[^\n]s", wil[i].opc);
            fscanf(p_opcao, "\n");
            fscanf(p_res, "%[^\n]s", wil[i].res);
            fscanf(p_res, "\n");
            fscanf(pont, "\n");
            i++;  
            
        }   // fechando os arquivos.
        fclose(pont);
        fclose(p_opcao); 
		fclose(p_res); 
			}
      
	
do{
printf("\n");
printf("**************************************************************\n");
printf("     MENU PRINCIPAL DO JOGO TRIVIA SHOW \n");
printf("1\tJOGAR \n");
printf("2\tMELHORES JOGADORES \n");
printf("3\tSAIR \n\n");
printf("**************************************************************\n\n");
printf("Qual das opc�es do menu � que vo�� deseja realizar? \n");
scanf("%d", &val);


  switch(val){
    
	     case 1:{
		
		 
        printf("\n");
	    fflush(stdin);
	    
	    errado=0;
		certo=0;		
		c=0;
		w=1;
		
        while(c < 10){
      	printf("\n");

        srand(time(NULL));	// Escolhendo um n�mero aleat�rio.			
		v = rand() % 111;
		printf("O n�mero escolhido aleatoriamente � %d. \n\n", v);
		
          i = v;
          printf("%d %s \n\n", w, wil[i].per);  // imprimindo pergunta e as op��es das perguntas.
          printf("%s \n", wil[i].opc);
          fflush(stdin);
          printf("\nQual � o item correto? R: ");
          scanf("%c", &mudar);

		printf("Vo�� digitou a letra %c. \n", mudar);
		
			if(mudar>='A' && mudar<='Z'){    // verificando se a letra digitada � mai�scula, se for ela ser� mudada para menuscula.
              mudar = mudar - 'A' + 'a';  // pal[i] = pal[i]+32;
              a.r[0]= mudar;
        	}else
        
        a.r[0] = mudar;

        	if(a.r[0] == wil[i].res[0]){ // Verificando se a resposta do usu�rio est� correta.
        		printf("\n\nResposta correta! \n\n");
        		certo+=1;
        	}else
			
			if(a.r[0] != wil[i].res[0]){
           		printf("\nResposta errada! \n\n");
           		printf("A resposta correta � o item %s. \n\n", wil[i].res);
            	errado+=1;
        	}
        c++;
        w++;
        printf("===============================================================\n\n");
      }
       
	   	printf("Total de perguntas respondidas: %d\n", c);
	   	
      		if(certo == 0){
     
      			printf("\nVoc� errou todas as quest�es!\n");
	  		}else
	  		
      		if(certo >= 1){
      			printf("\nVo�� respondeu %d quest�es certas!\n", certo);
      			printf("Vo�� respondeu %d  quest�es erradas!\n", errado);
      			printf("===============================================================\n\n");
	  		}
	
	  
	  		if(certo >= 1){
	  			ponto=0;
	  			ponto = certo*10;
				printf("Parab�ns vo�� tem %d pontos.\n", ponto);
				cont_jogadores = cont_jogadores+1;
			}
			
		
			if(certo >= 1){
			
				i=0;
				i= j;
					
					if(cont_jogadores>1){
					i= j+1;	
					}
					
					fflush(stdin);
					printf("Digite o seu nome: ");
					scanf("%[^\n]s", tudo[i].nome);
					tudo[i].pontua = ponto;
		
			}
			
        break;
			
    	}
		    case 2:{
		    
		z = j+cont_jogadores;
	
		printf("===============================================================\n\n");
	
		if(z<=0){
			printf("N�o existe melhor jogador por enquanto.\n");
		}else
		
		if(z==1){
			printf("O melhor Jogador � o: \n\n");
			printf("Posi��o\t\t\t  Nome\t\t\t  Pontua��o\n\n");
		}else
		
		if(z>1){
			printf("Os melhores Jogadores s�o: \n\n");
			printf("Posi��o\t\t\t  Nome\t\t\t  Pontua��o\n\n");
		}
	
			for(int i=0;i<z;i++){  // Organizando os nomes dos jogadores em ordem decrescente de acordo com as suas pontua��es.
				for(int j = 0; j<z; j++){
					if(tudo[i].pontua > tudo[j].pontua){
						organiza aux = tudo[i];
						tudo[i] = tudo[j];
						tudo[j] = aux;
							
					}
				}
			}
			
		w=1;
		for(int i=0; i<z; i++){  // Imprimindo os nomes dos jogadores que est�o guardados no vetor tudo do struct organiza.
			printf(" %d\t\t\t%s\t\t\t%d\n", w, tudo[i].nome, tudo[i].pontua);
        	w++;
				if(i==4){
					break;
				}
		}

			printf("\n\n");	
				break;
		
		}
		
		case 3:{
			
			printf("===============================================================\n");
			
			z=j+cont_jogadores;
			
			// Organizando os nomes dos jogadores em ordem decrescente de acordo com as suas pontua��es.
				for(int i=0;i<z;i++){   
					for(int j = 0; j<z; j++){
						if(tudo[i].pontua > tudo[j].pontua){
							organiza aux = tudo[i];
							tudo[i] = tudo[j];
							tudo[j] = aux;
						}
					}
				}
		
			printf("\nFechando o Jogo ... \n");
			
	    	// Abrindo o arquivo dos melhores Jogadores no modo "w" substituindo tudo o que estava no arquivo.
			melhoresjogadores = fopen("Melhores_jogadores.txt", "w"); 
			
				if(melhoresjogadores != NULL){
					for(int i=0; i<z; i++){
						// Escrevendo no aquivo dos melhores Jogadores tudo o que est� no struct tudo do tipo organiza. 
						fprintf(melhoresjogadores, "%s\n%d\n", tudo[i].nome, tudo[i].pontua); 
						if(i==4){
							break;
						}
					}
				}
				
			fclose(melhoresjogadores);
				
			printf("Fim do jogo! \n\n");
			
		break;
		}
		
    	default:
		printf("===============================================================\n\n");
	    printf("Essa op��o n�o existe no Menu! \n\n");
		printf("===============================================================\n\n");
		fflush(stdin);	
  }	
			
	 
}while(val != 3);


getch();
return (0);
}
