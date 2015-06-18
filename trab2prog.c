
/* Rola x dados de y faces */
//int rollXdY(int x, int y);
/* Rola dados */
//int roll(dados d);
/* Rola 4d6, excluindo o pior resultado */
//int roll_hab(void);
/* Lê e devolve personagem gerado com os dados lidos */
//personagem le_e_gera_personagem(void);
/* Escreve personagem completo */
//void escreve_personagem(personagem p);
/* Realiza duelo, devolvendo o número de turnos */
//int duelo(personagem p1, personagem p2);*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10


typedef struct {
    int vezes; /* quantas rolagens */
    int faces; /* quantas faces */
    int mod;
    /* modificador (p.ex. +12) */
  } dados;
typedef struct {
    char nome[MAX+1];
    char raca[3];
    char classe[3];
    int NVL;
    int FOR;
    int DES;
    int CON;
    int AT;
    dados DANO;
    int CA;
    int PV;
  } personagem;

//função que rola os os dados para destreza, força e constituição
void roll_hab(void){

  int results[4], aux_troca, soma_maiores = 0;      
  srand(time(NULL));   
  //gera os 4 números como se fossem as 4 jogadas do dado
  for(int i = 0; i <= 3; i++){    
    results[i] = rand()%6+1;    
  }

  //verifica qual é o menor número entre os que foram gerados  
  for(int i = 0; i <= 3; i++){    
    if(results[3] >= results[i]){
      aux_troca = results[3];
      results[3] = results[i];
      results[i] = aux_troca;         
    }
    
  }
  for(int i = 0; i <= 3; i++){    

    printf("%d ", results[i]);


  }
  printf("\n");
  for(int i = 0; i < 3; i++){    
    soma_maiores = results[i]+soma_maiores;
    printf("%d\n", soma_maiores);  

  }

  








}
// A função a baixo le o nome, a raça, a classe e o nivel dos 2 adversários
void ler_personagens(void){
  int nivel1, nivel2;
  char nome1[MAX+1], nome2[MAX+1], classe1[3], raca1[3], classe2[3], raca2[3], x;

  scanf(" %s %s %s %d%*c", nome1, raca1, classe1, &nivel1);
  scanf("%c%*c", &x);
  scanf(" %s %s %s %d%*c", nome2, raca2, classe2, &nivel2);

  


}







int main(void){
  int k;
  scanf("%d", &k);
  while(k>0){
    roll_hab();













    k--;
  }
  return 0;
}
