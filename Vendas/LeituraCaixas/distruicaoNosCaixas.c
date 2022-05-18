#include <stdio.h>
#include <stdlib.h>

#define CAIXAS 3

// Nesse arquivo farei a distribuicao das vendas
// nos caixas disponiveis, de acordo com os tempos fornecidos na entrada

// -------------------------------------------------------------------------

// Considerando tres caixas(pode ser qualquer numero de caixas)
// inicialmente temos essa distribuiçao de tempo:
// caixas   1   2   3 ... n
// tempos   0   0   0 ... 0
// tempo igual a 0 significa que todos os caixas estao disponiveis no inicio


// Na funcao a seguir, considerando a seguinte distribuiçao de tempos:
// caixas   1   2   3
// tempos   20  5   10
// a funcao deve retornar o valor 1
// que é o indice do caixa 2 que tem o menor tempo entre todos (tempo 5)
int buscaMenorTempoRetornaIndice(int vetorTempos[], int caixas){
  int indice = 0;
  int menorTempo = vetorTempos[0];
  for(int i = 1; i < caixas; i++){
    if(vetorTempos[i] < menorTempo){
      indice = i;
      menorTempo = vetorTempos[i];
    }
  }
  return indice;
}

// Dado o vetor contendo os tempos, o valor de tempo e a quantidade de caixas, 
// é percorrido todo o vetor para subtrair o valor de tempo de cada um deles, exemplo:
// caixas   1   2   3
// tempos   20  5   10

// passando o valor 2 para subtraiTempos, assim como o vetor de caixas e tempos, temos:
// caixas   1   2   3
// tempos   18  3   8
int subtraiTempos(int vetorTempos[], int tempo, int qntdCaixas){
  for(int i = 0; i < qntdCaixas; i++){
    vetorTempos[i] = vetorTempos[i] - tempo;
  }
  return *vetorTempos;
}

// Um caixa é considerado disponivel se seu valor de tempo atual é menor ou igual a 0,
// e é considerado nao disponivel se nenhum valor de tempo for menor ou igual a 0
// caixas   1   2   3
// tempos   4   3   1
// neste exemplo, nao temos caixa disponivel
int caixaDisponivel(int vetorTemposCaixa[], int numeroCaixas){
  // 1 = true
  // 0 = false
  for(int i = 0; i < numeroCaixas; i++){
    if(vetorTemposCaixa[i] <= 0 ) return 1;
  }
  return 0;
}

// Dado o vetor de tempos, o indice do caixa e o valor de tempo
// esse valor é atualizado
// caixas   1   2   3
// tempos   4   3   -2
// considerando o indice 2 (valor do tempo é -2, entao esta disponivel)
// e um tempo igual a 10, o vetor de tempos é atualizado
// caixas   1   2   3
// tempos   4   3   10
int atualizaVetorTempos(int vetorTempos[], int indiceCaixaDisponivel, int novoTempo){
  vetorTempos[indiceCaixaDisponivel] = novoTempo;
  return *vetorTempos;
}

// Dado o numero de caixas, todos os tempos sao setados para 0,
// indicando que no inicio todos os caixas estao disponiveis
// caixas   1   2   3
// tempos   0   0   0
int inicializaCaixas(int vetorTempos[], int qtdeCaixas){
  for (int i = 0; i < qtdeCaixas; i++){
    vetorTempos[i] = 0;
  }
  return *vetorTempos;
}

// retorna o indice
int indiceTempoAtual(int indice) {
  return indice;
}

void distribuiVendasNosCaixas(int temposDeEntrada[], int tamanhoEntrada, int caixas) {
  int auxiliarTempos[caixas];
  int registrosCaixas[10][caixas];
  // cada caixa pode ter ate 10 vendas, deve armazenar indice da venda

  // popula matriz com todos os valores sendo -1
  for (int i = 0; i < 10; i++){
    for(int j = 0; j < caixas; j++){
      registrosCaixas[i][j] = -1;
    }
  }

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
      printf("\n");

      for(int i = 0; i < 10; i++){
        if(registrosCaixas[i][menorCaixaDisponivel] == -1) {
          registrosCaixas[i][menorCaixaDisponivel] = contador;
          break;
        }
      }

      contador++;
      prox = temposDeEntrada[contador];

    }
    else {
      printf("sem caixa disponivel\n");
      subtraiTempos(auxiliarTempos, prox, caixas);
    }
  }

  printf("\n");
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