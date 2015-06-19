/**************************************************
*
* Davi Ferreira Santo
* Trabalho 2
* Professor: Diego Rubert
*
*/



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

  char x;
  scanf(" %s %s %s %d%*c", (*p1).nome, (*p1).raca, (*p1).classe, &(*p1).NVL);
  scanf("%c%*c", &x);
  scanf(" %s %s %s %d%*c", (*p2).nome, (*p2).raca, (*p2).classe, &(*p2).NVL);

  /*o bloco a seguir rola os dados para gerar os atributos de força, destreza e constituição*/
  (*p1).FOR = roll_hab();
  (*p1).DES = roll_hab();
  (*p1).CON = roll_hab();

  (*p2).FOR = roll_hab();
  (*p2).DES = roll_hab();
  (*p2).CON = roll_hab();
}



void gera_personagens_com_modificadores(personagem *p1, personagem *p2){
  /*o bloco a seguir gera os modificadores relacionados a raça*/
  if((*p1).raca[0] == 'E'){
    (*p1).DES += 2;
    (*p1).CON -= 2;
  }
  if((*p1).raca[0] == 'A'){
    (*p1).CON += 2;
  }
  if((*p1).raca[0] == 'H'){
    (*p1).FOR -= 2;
    (*p1).DES += 2;
  }
  if((*p1).raca[0] == 'M'){
    (*p1).FOR += 2;
  }

  if((*p2).raca[0] == 'E'){
    (*p2).DES += 2;
    (*p2).CON -= 2;
  }
  if((*p2).raca[0] == 'A'){
    (*p2).CON += 2;
  }
  if((*p2).raca[0] == 'H'){
    (*p2).FOR -= 2;
    (*p2).DES += 2;
  }
  if((*p2).raca[0] == 'M'){
    (*p2).FOR += 2;
  }
  /*termina aqui o bloco que gera os modificadores relacionados a raça*/

  /*o bloco a seguir gera os modificadores relacionados a classe*/
  if((*p1).classe[0] == 'G'){
    (*p1).AT = (*p1).NVL + (*p1).FOR;
    (*p1).DANO.vezes = 1;
    (*p1).DANO.faces = 10;
    (*p1).DANO.mod = (*p1).FOR;
    (*p1).CA = (*p1).NVL+(*p1).DES+10;
    (*p1).PV = (*p1).NVL*10 + (*p1).CON;
  }
  if((*p1).classe[0] == 'B'){
    (*p1).AT = (*p1).NVL + (*p1).FOR;
    (*p1).DANO.vezes = 1;
    (*p1).DANO.faces = 12;
    (*p1).DANO.mod = (*p1).FOR;
    (*p1).CA = (*p1).NVL+(*p1).DES+10;
    (*p1).PV = (*p1).NVL*12 + (*p1).CON;
  }
  if((*p1).classe[0] == 'R'){
    (*p1).AT = (*p1).NVL + (*p1).DES;
    (*p1).DANO.vezes = 1;
    (*p1).DANO.faces = 8;
    (*p1).DANO.mod = (*p1).DES;
    (*p1).CA = (*p1).NVL + (*p1).DES+10;
    (*p1).PV = (*p1).NVL*8 + (*p1).CON;
  }
  if((*p1).classe[0] == 'L'){
    (*p1).AT = (*p1).NVL + (*p1).DES;
    (*p1).DANO.vezes = 2;
    (*p1).DANO.faces = 6;
    (*p1).DANO.mod = (*p1).DES;
    (*p1).CA = (*p1).NVL+(*p1).DES+10;
    (*p1).PV = (*p1).NVL*6 + (*p1).CON;
  }

  if((*p2).classe[0] == 'G'){
    (*p2).AT = (*p2).NVL + (*p2).FOR;
    (*p2).DANO.vezes = 1;
    (*p2).DANO.faces = 10;
    (*p2).DANO.mod = (*p2).FOR;
    (*p2).CA = (*p2).NVL+(*p2).DES+10;
    (*p2).PV = (*p2).NVL*10 + (*p2).CON;
  }
  if((*p2).classe[0] == 'B'){
    (*p2).AT = (*p2).NVL + (*p2).FOR;
    (*p2).DANO.vezes = 1;
    (*p2).DANO.faces = 12;
    (*p2).DANO.mod = (*p2).FOR;
    (*p2).CA = (*p2).NVL+(*p2).DES+10;
    (*p2).PV = (*p2).NVL*12 + (*p2).CON;
  }
  if((*p2).classe[0] == 'R'){
    (*p2).AT = (*p2).NVL + (*p2).DES;
    (*p2).DANO.vezes = 1;
    (*p2).DANO.faces = 8;
    (*p2).DANO.mod = (*p2).DES;
    (*p2).CA = (*p2).NVL+(*p2).DES+10;
    (*p2).PV = (*p2).NVL*8 + (*p2).CON;
  }
  if((*p2).classe[0] == 'L'){
    (*p2).AT = (*p2).NVL + (*p2).DES;
    (*p2).DANO.vezes = 2;
    (*p2).DANO.faces = 6;
    (*p2).DANO.mod = (*p2).DES;
    (*p2).CA = (*p2).NVL+(*p2).DES+10;
    (*p2).PV = (*p2).NVL*6 + (*p2).CON;
  }
  /*Termina aqui o bloco que gera os modificadores relacionados a classe*/
}

void duelo(personagem p1, personagem p2){
  int cont = 0, ataque, dano;

  while(p1.PV >= 0 && p2.PV >= 0){
    // ataque do p1
    ataque = rollXdY(1, 20)+p1.AT;
    if(ataque >= p2.CA){
      dano = rollXdY(p1.DANO.vezes, p1.DANO.faces)+p1.DANO.mod;
      p2.PV -= dano;

    }else{
      dano = 0;
    }
    printf("P1 AT: %d, DANO: %d, P2 PV: %d\n", ataque, dano, p2.PV);

    if(p2.PV >= 0){
      // ataque do p2
      ataque = rollXdY(1, 20)+p2.AT;
      if(ataque >= p1.CA){
        dano = rollXdY(p2.DANO.vezes, p2.DANO.faces)+p2.DANO.mod;
        p1.PV -= dano;

      }
      printf("P2 AT: %d, DANO: %d, P1 PV: %d\n", ataque, dano, p1.PV);
    }
    cont++;
    
  }
  if(p1.PV <= 0){
    printf("Vencedor em %d turnos: %s\n", cont, p2.nome);
    printf("\n");

  }
  if(p2.PV <= 0){
    printf("Vencedor em %d turnos: %s\n", cont, p1.nome);
    printf("\n");

  }
}



void escreve_personagem(personagem p){
    
  printf("Nome: %s\n", p.nome                                     );  
  //o switch a seguir imprime a raça completa do p
  switch(p.raca[0]){
    case 'E':
      printf("Raca: Elfo\n"                                       );
    break;
    case 'A':
      printf("Raca: Anão\n"                                       );
    break;
    case 'H':
      printf("Raca: Halfling\n"                                   );
    break;
    case 'M':
      printf("Raca: Meio-Orc\n"                                   );
    break;
  }

  //o switch a seguir imprime a classe completa do p
  switch(p.classe[0]){
    case 'G':
      printf("Classe: Guerreiro\n"                                );
    break;
    case 'B':
      printf("Classe: Barbaro\n"                                  );
    break;
    case 'R':
      printf("Classe: Ranger\n"                                   );
    break;
    case 'L':
      printf("Classe: Ladino\n"                                   );
    break;
  }  
  printf("Nivel: %d\n", p.NVL                                     );
  printf("FOR: %d\n", p.FOR                                       );
  printf("DES: %d\n", p.DES                                       );
  printf("CON: %d\n", p.CON                                       );
  printf("AT: %d\n", p.AT                                         );
  printf("DANO: %dd%d+%d\n", p.DANO.vezes, p.DANO.faces, p.DANO.mod);
  printf("CA: %d\n", p.CA                                         );
  printf("PV: %d\n", p.PV                                         );
  printf("\n");

}



int main(void){

  srand(time(NULL));
  int k;
  scanf("%d", &k);
  while(k>0){
    personagem p1, p2;
    le_e_gera_personagens_sem_modificadores(&p1, &p2);
    gera_personagens_com_modificadores(&p1, &p2);
    escreve_personagem(p1);
    escreve_personagem(p2);
    duelo(p1, p2);
    k--;
  }
  return 0;
}
