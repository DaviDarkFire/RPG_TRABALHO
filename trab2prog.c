#include <stdio.h>
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



void ler_personagens(void){
  int nivel1, nivel2;
  char nome1[MAX+1], nome2[MAX+1], classe1[3], raca1[3], classe2[3], raca2[3], x;

  scanf(" %s %s %s %d%*c", nome1, raca1, classe1, &nivel1);
  scanf("%c%*c", &x);
  scanf(" %s %s %s %d%*c", nome2, raca2, classe2, &nivel2);

  printf("%s %s %s %d\n", nome1, raca1, classe1, nivel1);
  printf("%s %s %s %d\n", nome2, raca2, classe2, nivel2);



  }







int main(void){
  int k;
  scanf("%d", &k);
  while(k>0){
    ler_personagens();













    k--;
  }
  return 0;
}
