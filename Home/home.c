#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<conio.c>

//variaveis globais
FILE *file;
//int indice = 0;
struct funcionario{
    int id;
    //char usuario[100];
    char senha[100];
    char nome[100];
    char email[100];
}func[10];

void login(int *ind){
    char email[100], senha[100];
    file = fopen("teste.txt", "r");
    if(file==NULL){
        printf("\\nNao ha dados cadastrados!!");
    }

    printf("\nL O G I N\n\n");
    printf("Email: ");
    scanf("%s", &email);
    printf("Senha: ");
    scanf("%s", &senha);
    fflush(stdin);
    while(!feof(file)){
        if(email == func[*ind].email && senha == func[*ind].senha){
            printf("\n\nUsuario logado!");
            return;
        }else{
            printf("\n\nUsuario nao cadastrado ou dados invalidos!");
            return;
        }
    }


}


void cadastro(int *ind){
    char conf;
    func[*ind].id = *ind;
    file = fopen("teste.txt", "w");
    if(file==NULL){
        printf("\nErro ao abrir o arquivo!");
    }
    printf("\nC A D R A S T O\n");
    printf("ID: %d\n", *ind);
    fprintf(file, "%d", func[*ind].id);
    //scanf("%d", &func[*ind].id);
    //fputs(func.id, file);
    fflush(stdin);
    printf("Nome: ");
    scanf("%s",&func[*ind].nome);
    fprintf(file, "%s\n", func[*ind].nome);
    printf("Email: ");
    scanf("%s", &func[*ind].email);
    fprintf(file, "%s\n", func[*ind].email);
    printf("Senha: ");
    scanf("%s",&func[*ind].senha);
    fprintf(file, "%s\n", func[*ind].senha);

    printf("\n\nConfirma os dados para gravacao ? (S/N): ");
    do{
            scanf("%c", &conf);
   	}while( conf != 's' && conf != 'S'&& conf != 'n' && conf != 'N' );

    if( conf == 's' || conf == 'S' ){
		    system("cls");
			fflush(file);//descarrega o buffer no disco
			printf("\n\nDados salvos com sucesso!");
			getche();
	 	}
		system("cls");
		return;

}

void start(){
    system("cls");
    printf("\nMERCADO");
    printf("\n1 - Entrar");
    printf("\n2 - Cadastrar");
    printf("\n3 - Sair");
}


int main(){
    int op, indice=1;
    do{
        start();
        printf("\n\nOpcao: ");
        scanf("%d", &op);
        fflush(stdin);
        switch(op){
            case 1:
                system("cls");
                login(&indice);
                //printf("\nEm desenvolvimento");
                getchar();
                break;
            case 2:
                system("cls");
                cadastro(&indice);
                fclose(file);
                break;
            case 3:
                system("cls");
                printf("Obrigado pelo uso!");
                getchar();
                exit(0);
        }
    }while(op!=0);

    return 0;
}
