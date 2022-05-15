// procedimento para escrever em um arquivo texto

void escrever(char f[]) {
    FILE *file = fopen(f, "w");
    char letra;

    if(file) {
        printf("\nDigite um texto e pressione ENTER ao finalizar!");
        scanf("%c", &letra);
        while(letra != '\n') {
            fputc(letra, file);
            scanf("%c", &letra);
        }
        fclose(file);
    } else
        printf("\nERRO ao abrir arquivo!\n");
}