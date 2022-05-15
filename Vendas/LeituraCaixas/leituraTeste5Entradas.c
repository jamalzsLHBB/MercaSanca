#include <stdio.h>

void main() {
  FILE *arq;
  
  // Abre o arquivo teste5Entradas.txt para leitura
  arq = fopen("teste5Entradas.txt", "rt");
  
  // Se houve erro na abertura
  if (arq == NULL) {
     printf("Problemas na abertura do arquivo\n");
     return;
  }

  int quantidade, preco, tempo, pagamento;

  // retorna a leitura para o inicio do arquivo
  rewind(arq);

  // enquanto nao for o fim do arquivo
  int quantidades[4];
  int precos[4];
  int tempos[4];
  int pagamentos[4];

  int i = 0;

  while(!feof(arq)){
    // le cada item do arquivo txt como inteiro
    fscanf(arq, "%d %d %d %d", &quantidade, &preco, &tempo, &pagamento);
    printf("%d %d %d %d\n", quantidade, preco, tempo, pagamento);
    printf("\ntempo: %d\n", tempo);
    quantidades[i] = quantidade;
    precos[i] = preco;
    tempos[i] = tempo;
    printf("\ntempos[%d]: %d\n", i, tempos[i]);
    pagamentos[i] = pagamento;
    i++;
  }

  // for (int j = 0; j < 10; j++){
  //   printf("\nindice[%d]: %d", j, pagamentos[j]);
  // }

  // for (int j = 0; j < 10; j++){
  //   printf("\nindice[%d]: %d", j, tempos[j]);
  // }
  // fecha arquivo
  fclose(arq);
}