#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int main(void)
{
  int *v; 
  int i, numeros;
  
  printf("Informe a quantidade de números:\n");
  scanf("%d", &numeros);
  while(numeros<6||numeros>15){
    printf("Essa opção não é válida!\nDigite uma quantidade válida de números!\n");
    printf("Informe a quantidade de números:\n");
    scanf("%d", &numeros);
  }
    v = (int *) malloc(numeros * sizeof(int));
  
  //Armazenando os números em um vetor dinâmico
  printf("\nAgora escreva os %d numeros;\n", numeros);
  int n, val=1, x=0;
  for (i = 0; i < numeros;)
  {
    val=1;
    printf("\nNúmero %d: ", i+1);
    scanf("%d", &n);
    int check=0;
    while(val){
      if(n>0&&n<61){
        for(int j=0; j<=i; j++){
          if(n==v[j]){
            check+=1;
          }
        }
      if(check==0){
        v[i]=n;
        i+=1;
        val=0;
        }
      }
      val=0;
    }
  }

  //Gerar números sorteados
  srand(time(NULL));
  int s, c=0;
  int vs[6]={0, 0, 0, 0, 0, 0};
  i=0;
  while(i<6){
    s=rand() % 61;
    for(int j=0; j<=i; j++){
      if(s==vs[j]){
        c+=1;
      }
    }
    if(c==0){
      vs[i]=s;
      i+=1;
    }
    c=0;
  }

  // Contagem de acertos
  int acertos=0;
  for(i=0; i<6; i++){
    for(int j=0; j<numeros; j++){
      if(vs[i]==v[j]){
        acertos+=1;
      }     
    }
  }

  // ------ Imprimindo os valores ----------
  printf("\n*** Valores escolhidos ***\n\n");
  for (i = 0;i < numeros; i++)
  {
    printf("%.2d\n",v[i]);
  }
  free(v);
  printf("\n*** Valores sorteados ***\n\n");
  for (i = 0;i < 6; i++)
  {
  printf("%.2d\n",vs[i]);
  }
  if(acertos==6){
    printf("\nParabéns, voce acertou a SENA!!!");
  }
  if(acertos==5){
    printf("\nParabéns, voce acertou a QUINA!!!");
  }
  if(acertos==4){
    printf("\nParabéns, voce acertou a QUADRA!!!");
  }
  if(acertos<4){
    printf("\nQue pena, você teve %d acertos e não ganhou nenhum prêmio!!!", acertos);
  }
  return 0;
}