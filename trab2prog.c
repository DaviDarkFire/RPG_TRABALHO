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
    int vezes;
    int faces;
    int mod;

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


int rollXdY(int x, int y){
  int valor = 0;
  for(int i = 0;i < x; i++){
    valor += rand()%y+1;

  }
  return valor;
}



//função que rola os os dados para destreza, força e constituição
int roll_hab(void){
  int results[4], aux_troca, soma_maiores = 0;
  //gera os 4 números como se fossem as 4 jogadas do dado
  for(int i = 0; i <= 3; i++){
    results[i] = rand()%6+1;
  }
  //verifica qual é o menor número entre os que foram gerados e coloca eles na ultima posição do vetor
  for(int i = 0; i <= 3; i++){
    if(results[3] >= results[i]){
      aux_troca = results[3];
      results[3] = results[i];
      results[i] = aux_troca;
    }
  }
  //soma as 3 primeiras posições do vetor que são os 3 maiores valores gerados
  for(int i = 0; i < 3; i++){
    soma_maiores = results[i]+soma_maiores;
  }
  return soma_maiores;
}



/* A função a baixo le o nome, a raça, a classe e o nivel dos 2 adversários e gera personagens simples
   sem modificadores*/
void le_e_gera_personagens_sem_modificadores(personagem *p1, personagem *p2){


  scanf(" %s %s %s %d%*c", *(p1).nome, *(p1).raca, *(p1).classe, &*(p1).NVL);
  scanf("%c%*c", &x);
  scanf(" %s %s %s %d%*c", *(p2).nome, *(p2).raca, *(p2).classe, &*(p2).NVL);

  /*o bloco a seguir rola os dados para gerar os atributos de força, destreza e constituição*/
  *(p1).FOR = roll_hab();
  *(p2).FOR = roll_hab();
  *(p1).DES = roll_hab();
  *(p2).DES = roll_hab();
  *(p1).CON = roll_hab();
  *(p2).CON = roll_hab();
}



void gera_personagens_com_modificadores(personagem *p1, personagem *p2){
  /*o bloco a seguir gera os modificadores relacionados a raça*/
  if(*(p1).raca[0] == 'E'){
    *(p1).DES += 2;
    *(p1).CON -= 2;
  }
  if(*(p1).raca[0] == 'A'){
    *(p1).CON += 2;
  }
  if(*(p1).raca[0] == 'H'){
    *(p1).FOR -= 2;
    *(p1).DES += 2;
  }
  if(*(p1).raca[0] == 'O'){
    *(p1).FOR += 2;
  }

  if(*(p2).raca[0] == 'E'){
    *(p1).DES += 2;
    *(p1).CON -= 2;
  }
  if(*(p2).raca[0] == 'A'){
    *(p1).CON += 2;
  }
  if(*(p2).raca[0] == 'H'){
    *(p1).FOR -= 2;
    *(p1).DES += 2;
  }
  if(*(p2).raca[0] == 'O'){
    *(p1).FOR += 2;
  }
  /*termina aqui o bloco que gera os modificadores relacionados a raça*/

  /*o bloco a seguir gera os modificadores relacionados a classe*/
  if(*(p1).classe[0] == 'G'){
    *(p1).AT = *(p1).NVL + *(p1).FOR;
    *(p1).DANO.vezes = 1;
    *(p1).DANO.faces = 10;
    *(p1).DANO.mod = *(p1).FOR;
    *(p1).CA = *(p1).NVL+*(p1).DES+10;
    *(p1).PV = *(p1).NVL*10 + *(p1).CON;
  }
  if(*(p1).classe[0] == 'B'){
    *(p1).AT = *(p1).NVL + *(p1).FOR;
    *(p1).DANO.vezes = 1;
    *(p1).DANO.faces = 12;
    *(p1).DANO.mod = *(p1).FOR;
    *(p1).CA = *(p1).NVL+*(p1).DES+10;
    *(p1).PV = *(p1).NVL*12 + *(p1).CON;
  }
  if(*(p1).classe[0] == 'R'){
    *(p1).AT = *(p1).NVL + *(p1).DES;
    *(p1).DANO.vezes = 1;
    *(p1).DANO.faces = 8;
    *(p1).DANO.mod = *(p1).DES;
    *(p1).CA = *(p1).NVL + *(p1).DES+10;
    *(p1).PV = *(p1).NVL*8 + *(p1).CON;
  }
  if(*(p1).classe[0] == 'L'){
    *(p1).AT = *(p1).NVL + *(p1).DES;
    *(p1).DANO.vezes = 2;
    *(p1).DANO.faces = 6;
    *(p1).DANO.mod = *(p1).DES;
    *(p1).CA = *(p1).NVL+*(p1).DES+10;
    *(p1).PV = *(p1).NVL*6 + *(p1).CON;
  }

  if(*(p2).classe[0] == 'G'){
    *(p2).AT = *(p2).NVL + *(p2).FOR;
    *(p2).DANO.vezes = 1;
    *(p2).DANO.faces = 10;
    *(p2).DANO.mod = *(p2).FOR;
    *(p2).CA = *(p2).NVL+*(p2).DES+10;
    *(p2).PV = *(p2).NVL*10 + *(p2).CON;
  }
  if(*(p2).classe[0] == 'B'){
    *(p2).AT = *(p2).NVL + *(p2).FOR;
    *(p2).DANO.vezes = 1;
    *(p2).DANO.faces = 12;
    *(p2).DANO.mod = *(p2).FOR;
    *(p2).CA = *(p2).NVL+*(p2).DES+10;
    *(p2).PV = *(p2).NVL*12 + *(p2).CON;
  }
  if(*(p2).classe[0] == 'R'){
    *(p2).AT = *(p2).NVL + *(p2).DES;
    *(p2).DANO.vezes = 1;
    *(p2).DANO.faces = 8;
    *(p2).DANO.mod = *(p2).DES;
    *(p2).CA = *(p2).NVL+*(p2).DES+10;
    *(p2).PV = *(p2).NVL*8 + *(p2).CON;
  }
  if(*(p2).classe[0] == 'L'){
    *(p2).AT = *(p2).NVL + *(p2).DES;
    *(p2).DANO.vezes = 2;
    *(p2).DANO.faces = 6;
    *(p2).DANO.mod = *(p2).DES;
    *(p2).CA = *(p2).NVL+*(p2).DES+10;
    *(p2).PV = *(p2).NVL*6 + *(p2).CON;
  }
  /*Termina aqui o bloco que gera os modificadores relacionados a classe*/
}



int main(void){

  srand(time(NULL));
  int k;
  scanf("%d", &k);
  while(k>0){
    roll_hab();
    k--;
  }
  return 0;
}
