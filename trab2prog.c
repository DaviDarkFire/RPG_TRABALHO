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
    /* represente aqui de alguma forma a raça */
    /* represente aqui de alguma forma a classe */
    int NVL;
    int FOR;
    int DES;
    int CON;
    int AT;
    dados DANO;
    int CA;
    int PV;
  } personagem;


int main(void){
  int k, nivel, nivel2;
  char nome[MAX], nome2[MAX], raca[2], raca2[2], classe[2], classe2[2], x;
  scanf("%d", &k);
  while(k>0){

    scanf("%s,%s,%s,%d", nome, raca, classe, &nivel);
    scanf("%c", &x);
    scanf("%s,%s,%s,%d", nome2, raca2, classe2, &nivel2);

    printf("%s %s %s %d\n", nome, raca, classe, nivel);
    printf("%s %s %s %d\n", nome2, raca2, classe2, nivel2);








    k--;
  }
  return 0;
}
