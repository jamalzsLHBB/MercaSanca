#include <stdio.h>
#include <stdlib.h>

int buscaMenorTempoRetornaIndice(int vetorTempos[], int caixas){
  int indice = 0;
  int menorTempo = vetorTempos[0];
  for(int i = 0; i < caixas; i++){
    if(vetorTempos[i] < menorTempo){
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
    if(vetorTemposCaixa[i] <=0 ) return 1;
  }
  return 0;
}

int atualizaVetorTempos(int vetorTempos[], int indiceCaixaDisponivel, int novoTempo){
  vetorTempos[indiceCaixaDisponivel] = novoTempo;
  return *vetorTempos;
}

void main() {
  int caixas = 3, tamanho;
  tamanho = 6;
  int tempos[] = {10, 10, 10, 4, 4, 4};
  // int tamanho = 6;
  int tamanhoVetor = sizeof(tempos)/sizeof(tempos[0]);

  printf("tamanho vetor: %d\n", tamanhoVetor);
  // tamanho do vetor

  subtraiTempos(tempos, 2, tamanhoVetor);

  int disponivel = caixaDisponivel(tempos, caixas);
  // teste

  printf("\ncaixa disponivel? %d", disponivel);

  for(int i = 0; i < 6; i++){
    printf("\nindice %d: %d", i, tempos[i]);
  }
}