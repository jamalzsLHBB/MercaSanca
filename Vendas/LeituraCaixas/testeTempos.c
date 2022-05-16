#include <stdio.h>
#include <stdlib.h>

// nesse arquivo farei a distribuicao das vendas
// nos caixas disponiveis, de acordo com o tempo fornecido na entrada

int buscaMenorTempoRetornaIndice(int vetorTempos[], int caixas){
  int indice = 0;
  int menorTempo = vetorTempos[0];
  for(int i = 1; i < caixas; i++){
    // printf("\nvalor atual menor tempo: %d\n", menorTempo);
    if(vetorTempos[i] < menorTempo){
      // printf("\n entrando no if\n");
      indice = i;
      menorTempo = vetorTempos[i];
    }
  }
  return indice;
}

int subtraiTempos(int vetorTempos[], int tempo, int qntdCaixas){
  for(int i = 0; i < qntdCaixas; i++){
    vetorTempos[i] = vetorTempos[i] - tempo;
  }
  return *vetorTempos;
}

int caixaDisponivel(int vetorTemposCaixa[], int numeroCaixas){
  // 1 = true
  // 0 = false
  for(int i = 0; i < numeroCaixas; i++){
    if(vetorTemposCaixa[i] <= 0 ) return 1;
  }
  return 0;
}

int atualizaVetorTempos(int vetorTempos[], int indiceCaixaDisponivel, int novoTempo){
  vetorTempos[indiceCaixaDisponivel] = novoTempo;
  return *vetorTempos;
}

int inicializaCaixas(int vetorTempos[], int qtdeCaixas){
  for (int i = 0; i < qtdeCaixas; i++){
    vetorTempos[i] = 0;
  }

  return *vetorTempos;
}

int indiceTempoAtual(int indice) {
  return indice;
}

void distribuiVendasNosCaixas(int temposDeEntrada[], int tamanhoEntrada, int caixas) {
  int auxiliarTempos[caixas];
  int registrosCaixas[10][caixas]; // cada caixa pode ter ate 10 vendas, deve armazenar indice da venda 

  inicializaCaixas(auxiliarTempos, caixas);

  int contador = 0;

  int prox = temposDeEntrada[0];

  while(contador <  tamanhoEntrada){

    printf("\nvalor do proximo: %d\n", prox);
    
    if (caixaDisponivel(auxiliarTempos, caixas)){
      int menorCaixaDisponivel = buscaMenorTempoRetornaIndice(auxiliarTempos, caixas);
      printf("caixa disponivel no indice: %d\n", menorCaixaDisponivel);
      // preciso guardar a informacao de que o indice 0 dos tempos de entrada foi para o caixa 0
      // posso guardar isso numa matriz

      atualizaVetorTempos(auxiliarTempos, menorCaixaDisponivel, prox);

      printf("valores atuais de tempo\n");
      for(int i = 0; i < caixas; i++){
        printf("%d ", auxiliarTempos[i]);
      }

      registrosCaixas[contador][menorCaixaDisponivel] = contador;
      contador++;
      prox = temposDeEntrada[contador];

    }
    else {
      printf("sem caixa disponivel\n");
      subtraiTempos(auxiliarTempos, prox, caixas);
    }
  }

  for(int i = 0; i < tamanhoEntrada; i++){
    for(int j = 0; j < caixas; j++){
      printf("%d ", registrosCaixas[i][j]);
    }
    printf("\n");
  }

}

void main() {
  int caixas = 3, tamanhoEntrada = 6;
  int temposRegistrados[] = {10, 10, 10, 4, 4, 4};
  // int tamanho = 6;
  // int tamanhoVetor = sizeof(tempos)/sizeof(tempos[0]);

  // int auxiliarTempos[caixas];

  // inicializaCaixas(auxiliarTempos, caixas);


  // printf("tamanho vetor: %d\n", tamanhoVetor);

  // subtraiTempos(tempos, 2, tamanhoVetor);

  // int disponivel = caixaDisponivel(tempos, caixas);

  // printf("\ncaixa disponivel? %d", disponivel);

  // for(int i = 0; i < caixas; i++){
  //   printf("\nindice %d: %d", i, auxiliarTempos[i]);
  // }
  distribuiVendasNosCaixas(temposRegistrados, tamanhoEntrada, caixas);
  
}