//...............................................................................................................................................
//.................................Professor que questão difícil cara eu levei três dias para construí...........................................
//.................................la eu sei que o senhor provavelmente faz ela em 30min mas para minha..........................................
//.................................pessoa foi um outro patamar alcançado.........................................................................
//...............................................................................................................................................
//Sobre o codigo:................................................................................................................................
//......Apos iniciar o codigo ele pedirar o numero de bombas que você quer colocar o meu algoritimo de alocação de bombas esta mais rapido dentro 
//da faixa de 40-60 bombas, mas permite outros numeros Lembrando o carregamento ira ser mais lento fique por sua conta e risco menos ou mais que.
//o recomendado..................................................................................................................................
//...............................................................................................................................................
//Caso demore o carregamento não é erro no codigo apenas nn consegui uma forma de otimizar melhor, mas ele vai funcionar.........................
//...............................................................................................................................................
// nas cordenadas ":" siguinifica 10 - caso coloque uma cordenada em ":" digite 10...............................................................
//...............................................................................................................................................
//Atenciosamente: EVPS...........................................................................................................................




//Bibliotecas---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include<stdio.h>
#include<stdlib.h>
//biblioteca de para adicionarmos o padrão de escrita brasileira
#include<locale.h>
// para a ultilização da função sleep e usleep no linux, caso use windows descomente a linha abaixo e comente a linha #include<unistd.h> caso venha ocorrer algum erro no gcc troque usleep(5000000); por Sleep(500);
//#include <Windows.h>
#include<unistd.h>
//não retirar biblioteca ela serve para o funcionamento preciso do sistema Gerador Congruencial Linear (GCL)
//Um gerador congruencial linear (do inglês Linear congruential generator) 
//ou ainda conhecido pela sigla LCG é um algoritmo que produz uma sequência de
//números pseudo-aleatório calculados com uma função linear em trecho. 
//           srand( (unsigned)time(0) );
//            int r = rand() % 2;
#include <time.h>
#define TAM 12
#define TAMB TAM-2
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// variaveis globais------------------------------------------------------
char campo[TAM][TAM];
char charTemp, setChar; 
int quantBombs = 0, campoBomb[TAMB][TAMB], setCordLine, setCordColumn;
int partida = 0;
char confirma;
//------------------------------------------------------------------------

//reafiramções de declarações de funções---------------------------------------------------
void imprimeTela(); //declarar que imprimeTela existe
void randBombs(); //declarar que randBombs  existe
int comfereBombs(int setCordLine, int setCordColumn); //declarar que comfereBombs existe
//-----------------------------------------------------------------------------------------

//.......LEIA O CABEÇALHO (APARTIR DA PRIMEIRA LINHA ) ANTES DE RODAR O CODIGO............
//.......LEIA O CABEÇALHO (APARTIR DA PRIMEIRA LINHA ) ANTES DE RODAR O CODIGO............
//.......LEIA O CABEÇALHO (APARTIR DA PRIMEIRA LINHA ) ANTES DE RODAR O CODIGO............
//.......LEIA O CABEÇALHO (APARTIR DA PRIMEIRA LINHA ) ANTES DE RODAR O CODIGO............
//.......LEIA O CABEÇALHO (APARTIR DA PRIMEIRA LINHA ) ANTES DE RODAR O CODIGO............

int main(void)
{
    //init variaveis

     for(int i=0; i<TAM; i++){
        for(int j=0; j<TAM; j++){
            charTemp = '.';
            campo[i][j] = charTemp;
        }
    }
    setlocale(LC_ALL,"portuguese_brasil");
    printf("Quantas bombas você quer [40-60] ");
    scanf("%d", &quantBombs);
    if(quantBombs < 40 || quantBombs > 60){
        printf("Tem certeza que quer colocar um valor diferente dos citados acima? [s/n] [por padrão N]");
        scanf(" %c", &confirma);
        if(confirma == 's' || confirma == 'S'){
            printf("Ok!!");
        }else{
            printf("Reiniciando!!");
            main();
        }
    }
    printf("caregando ....\n");
    randBombs(quantBombs);

     for(int i=0; i<TAMB; i++){
            for(int j=0; j<TAMB; j++){
                printf(" %d ",campoBomb[i][j]);
            }
            printf("\n");
        }
     usleep(5000000);
     system("clear");
     int continua = 0;

     while(!continua){
    usleep(5000000);
    system("clear");
    


    imprimeTela();
    printf("\n\nMarque uma cordenada [linha][coluna] (padrão de resposta exp: 2 3): ");
    scanf("%d %d", &setCordLine, &setCordColumn);
    continua = comfereBombs(setCordLine, setCordColumn);
    
}
    
    
    return 0;
}







int comfereBombs(int setCordLine, int setCordColumn){

    if(partida == 0){
        partida ++;
        int k = 0;
        for(int i = 0; i < TAMB; i++){
            for(int j = 0; j <  TAMB; j++){
               
                if(campoBomb[i-1][j-1] == 1){
                    k ++;
                }
                if(campoBomb[i-1][j] == 1){
                    k ++;
                }
                if(campoBomb[i-1][j+1] == 1){
                    k ++;
                }
                if(campoBomb[i][j-1] == 1){
                    k ++;
                }
                if(campoBomb[i][j+1] == 1){
                    k ++;
                }
                if(campoBomb[i+1][j-1] == 1){
                    k ++;
                }
                if(campoBomb[i+1][j] == 1){
                    k ++;
                }
                 if(campoBomb[i+1][j+1] == 1){
                    k ++;
                }
                charTemp = k+'0';
                campo[i+1][j+1] = charTemp;

                k=0;

            }
        }
    } 

    if(campoBomb[setCordLine-1][setCordColumn-1] == 0){
        charTemp = '_';
        campo[setCordLine][setCordColumn] = charTemp;
    }

    if(campoBomb[setCordLine-1][setCordColumn-1] == 1){
        system("clear");
        
        for(int i=0 ; i<TAM; i++){
            for(int j=0 ; j<TAM; j++){
                if(campoBomb[i][j] == 1){
                    printf("* ");
                }
                if(campoBomb[i][j] == 0){
                    printf("_ ");
                }
            }
            printf("\n");
        }


        printf("\n\n\n");
        printf("................................................GAME OVER....................................................\n");
        printf("................................................GAME OVER....................................................\n");
        printf("................................................GAME OVER....................................................\n");
        printf("................................................GAME OVER....................................................\n");
        printf("................................................GAME OVER....................................................\n");
        printf("................................................GAME OVER....................................................\n");
        printf("................................................GAME OVER....................................................\n\n\n\n\n\n\\");
        return 1;
    }
    
}




void imprimeTela(){
    for(int i=0; i< TAM; i++){
        for(int j= 0; j< TAM; j++){

             if(i == 0 || i == 11){
                charTemp = j+'0';
                campo[i][j] = charTemp;
            }
            if(j == 0 || j == 11){
                charTemp = i+'0';
                campo[i][j] = charTemp;
            }

            if ((i == 0 && j == 0) || (i == 0 && j == 11) || (i == 11 && j == 0) || (i == 11 && j == 11))
            {
                charTemp = '=';
                campo[i][j] = charTemp;
            }
           
        }
    }

    for(int i=0; i<TAM; i++){
            for(int j=0; j<TAM; j++){
                if(i==0 || i == TAM-1 || j==0 || j == TAM-1){
                    printf("\033[0;31m");//vermelho -> o mesmo negocio la do python
                    printf("%c ",campo[i][j]);
                    printf("\033[0m");//reseta cor
                }else{
                    printf("%c ",campo[i][j]);
                }
            }
            printf("\n");
        }

}



void randBombs(int quantBombs){
    int quant = 0;
    srand( (unsigned)time(0) );

    for(int i=0; i<TAMB; i++){
        for(int j=0; j<TAMB; j++){
            int r = rand() % 2;
            campoBomb[i][j] = r;
        }
    }

    
for(int i = 0; i < TAMB; i ++){
        for(int j = 0; j <  TAMB; j ++){
            if(campoBomb[i][j]==1){
                quant ++;
            }
        }
    }
   
    usleep(5000);

    if(quant != quantBombs){
        randBombs(quantBombs);
    } 
}










































































































































































































































































































































































//Auth create by EVPS27102002
