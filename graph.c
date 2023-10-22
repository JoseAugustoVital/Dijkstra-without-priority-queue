/*                   Questao 5: Relat�rio da implementa��o                 */

/* Implementado por: Glauber Cintra - 14set1998                            */

/* Este programa implementa o algoritmo de Dijkstra para o problema do     */
/* caminho de custo m�nimo em grafos dirigidos com custos positivos nas    */
/* arestas.                                                                */

/* O grafo � representado usando-se a vari�vel "vertices" que indica       */
/* o n�mero de v�rtices do grafo e uma matriz de incid�ncia onde o         */
/* elemento na linha i e coluna j desta matriz cont�m o custo do arco      */
/* que sai de i e incide em j, ou -1 sem n�o existe arco de i para j.      */

/* O programa possui um menu principal com 3 op��es. Selecionando a        */
/* primeira op��o, � requerido do usu�rio digitar as informa��es relativas */
/* a um novo grafo, come�ando por especificar o n�mero de v�rtices e       */
/* depois digitando, em qualquer ordem, os arcos do grafo, especificando   */
/* os v�rtices adjacentes ao arco e seu custo.                             */

/* Atrav�s da segunda op��o o usu�rio informa quais os v�rtices origem     */
/* e destino. A fun��o dijkstra � ent�o chamada com os par�metros          */
/* "vertices", "origem", "destino" e a matriz de incid�ncia "custos".      */
/* A fun��o calcula um caminho dirigido de custo m�nimo entre "origem" e   */
/* "destino", e devolve este caminho (na ordem reversa) e seu custo,       */
/* se ele existir, ou a mensagem "No digrafo dado n�o existe caminho       */
/* entre os v�rtices origem e destino !!", caso contr�rio.                 */

/* A terceira op��o do menu principal serve para sair do programa.         */

/* Na fun��o dijkstra "ant[i]" guarda o antecessor do v�rtice i no         */
/* caminho de custo m�nimo entre "origem" e "destino". O valor "dist[i]"   */
/* indica o custo do menor caminho da "origem" ao v�rtice i. O vetor      */
/* "z" indica o conjunto de v�rtices para os quais j� se conhece um        */
/* caminho de custo m�nimo partindo da "origem".                           */

/* Determinamos o v�rtice que deve entrar em z olhando sequencialmente     */
/* o vetor "dist", o que leva tempo O(V). Atualizamos os custos            */
/* dos vizinhos do novo v�rtice de z tamb�m em tempo O(V). Nossa           */
/* implementa��o portanto requer tempo O(V^2).                             */

/* Executamos diversos testes e em todos eles verificamos que o            */
/* programa encontrou a solu��o correta.                                   */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXVERTICES 100

void dijkstra(int vertices,int origem,int destino,int *custos)
{ int i,v,    /* vari�veis auxiliares */
      ant[MAXVERTICES],   /* vetor dos antecessores */
      z[MAXVERTICES];     /* v�rtices para os quais se conhece o caminho m�nimo */
  double min, /* vari�vel auxiliar */
       dist[MAXVERTICES]; /* vetor com os custos dos caminhos */

/* OBS: O usu�rio enxerga os v�rtices como rotulados de 1 a "v�rtices",  */
/* mas o programa armazena as informa��es usando os elementos 0 dos */
/* dos vetores. Dessa formar � preciso subtrair 1 de "origem" e "destino" */
/* ao mape�-los nos vetores. */

  /* Inicializa��o */

  for (i=0;i<vertices;i++) {
    if (custos[(origem-1)*vertices+i]!=-1) {
      ant[i]=origem-1; 
      dist[i]=custos[(origem-1)*vertices+i];
    }
    else {
      ant[i]=-1;
      dist[i]=HUGE_VAL;
    }
    z[i]=0;
  }
  z[origem-1]=1;
  dist[origem-1]=0;

  /* La�o principal */

  do {

    /* Encontrando o v�rtice que deve entrar em z */

    min=HUGE_VAL;
    for (i=0;i<vertices;i++)
      if (!z[i])
        if (dist[i]>=0 && dist[i]<min) {min=dist[i];v=i;}

    /* Calculando as dist�ncias dos novos vizinhos de z */

    if (min!=HUGE_VAL && v!=destino-1) {
      z[v]=1;
      for (i=0;i<vertices;i++)
        if (!z[i]) {
          if (custos[v*vertices+i]!=-1 && dist[v]+custos[v*vertices+i]<dist[i])
            { dist[i]=dist[v]+custos[v*vertices+i];ant[i]=v; }
        }
    }
  } while (v!=destino-1 && min!=HUGE_VAL);

  /* Imprimindo o resultado  */

  if (min==HUGE_VAL)
    printf("\nNo digrafo dado n�o existe caminho entre os v�rtices %d e %d !!\n",origem,destino);
  else {
    printf("\nO caminho de custo m�nimo entre os v�rtices %d e %d  � (na ordem reversa):\n",
           origem,destino);
    i=destino;
    printf("%d",i);
    i=ant[i-1];
    while (i!=-1) {
      printf("<-%d",i+1);
      i=ant[i];
    }
    printf("\nO custo deste caminho �: %d\n",(int) dist[destino-1]);
  }
  
} /* dijsktra */


main(int argc, char **argv) {

char opcao,lixo[50];   /* vari�veis auxiliares */
int i,custo,           /* vari�veis auxiliares */
    vertices=0,        /* n�mero de v�rtices do grafo */
    origem,            /* v�rtice origem */
    destino,           /* v�rtice destino */
    *custos=NULL;      /* matriz de incid�ncia */

do {

  /* Menu principal */

  printf("\n      Solucionador para o problema do caminho de custo m�nimo em digrafos\n");
  printf("(Algoritmo proposto por Dijkstra e implementado por Glauber Cintra em 11set1998)\n\n");
  printf("Escolha sua op��o:\n");
  printf("     1. Digitar um digrafo\n");
  printf("     2. Resolver uma inst�ncia\n");
  printf("     3. Sair do programa\n\n");
  printf("Op��o: ");
  gets(&opcao);

  /* Digitar novo grafo */

  if (opcao==49) {
    do {
      printf("\nN�mero de v�rtices (entre 2 e %d): ",MAXVERTICES);
      scanf("%d",&vertices);
    } while (vertices<2 || vertices>MAXVERTICES);

    if (!custos)
      free(custos);
    custos=(int *) malloc(sizeof(int)*vertices*vertices);
    for (i=0;i<=vertices*vertices;i++) custos[i]=-1;
    printf("Digite agora as arestas\n");
    do {

      do {
        printf("Origem da aresta (entre 1 e %d ou 0 para sair): ",vertices);
        scanf("%d",&origem);
      } while (origem<0 || origem>vertices);

      if (origem) {

        do {
          printf("Destino da aresta (entre 1 e %d, menos %d): ",vertices,origem);
          scanf("%d",&destino);
        } while (destino<1 || destino>vertices || destino==origem);

        do {
          printf("Custo (positivo) da aresta do v�rtice %d para o v�rtice %d: ",origem,destino);
          scanf("%d",&custo);
	} while (custo<0);
      custos[(origem-1)*vertices+destino-1]=custo;
      }

    } while (origem);
    gets(lixo);
  }

  /* Achar caminho m�nimo entre 2 v�rtices */

  if (opcao==50 && vertices>0) {
    printf("\nDigite os v�rtices origem e destino do caminho\n");
    do {
      printf("V�rtice origem (entre 1 e %d): ",vertices);
      scanf("%d",&origem);
    } while (origem<1 || origem>vertices);
  
    do {
      printf("V�rtice destino (entre 1 e %d, menos %d): ",vertices,origem);
      scanf("%d",&destino);
    } while (destino<1 || destino>vertices || destino==origem);

    dijkstra(vertices,origem,destino,custos);
    gets(lixo);
  }

} while (opcao!=51);

printf("\nAt� a pr�xima...\n\n");

} /* Fim do programa */
