#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<conio.c>

//variaveis globais
//FILE *file;
//int indice = 0;
struct funcionario{
    int id;
    //char usuario[100];
    char senha[100];
    char nome[100];
    char email[100];
}func;

void login_improvisado(){
    system("cls");
    char email[100], senha[100];
    int val1, val2;
    printf("\nL O G I N\n\n");
    printf("Email: ");
    scanf("%s", &email);
    printf("Senha: ");
    scanf("%s", &senha);
    //printf("\n%s %s\n", email, senha);
    val1 = strcmp(email, "admin");
    val2 = strcmp(senha, "admin");
    fflush(stdin);
    do{
        if(val1 == 0 && val2 == 0){
            printf("\n\nUsuario logado");
            getchar();
            break;
        }
        else{
            //system("cls");
            printf("\n\nUsuario nao encontrado ou login invalido!");
            getchar();
            login_improvisado();
        }
    }while(email!=NULL && senha!=NULL);
}

void login(){
    int id, size, size_cmp;
    char email_cmp[100], senha_cmp[100];
    char email[100], senha[100], nome[100];
    FILE *file = fopen("teste.txt", "r");
    if(file==NULL){
        printf("\\nNao ha dados cadastrados!!");
    }

    printf("\nL O G I N\n\n");
    printf("Email: ");
    scanf("%s", &email_cmp);
    printf("Senha: ");
    scanf("%s", &senha_cmp);
    fflush(stdin);
    //i=0;
    printf("\n\n%s %s\n\n", email_cmp, senha_cmp);
    while(fscanf(file, "%d%s%s%s",&id, nome,email, senha)!=-1){
       if(strcmp(email_cmp,email)==1 && strcmp(senha_cmp, senha)==1){
            printf("\n\nUsuario nao cadastrado ou dados invalidos!\n");
        /*if(strcmp(email,email_cmp)==0 && strcmp(senha, senha_cmp)==0){
            printf("\nUsuario logado com sucesso!\n");
            return;*/
        }else{
            printf("\nID: %d\nNome: %s\nEmail: %s\nSenha: %s\n", id, nome, email, senha);

            return;
        }
    }
}


void cadastro(){
    //system("cls");
    char conf;
    FILE *file = fopen("teste.txt", "a+");
    if(file==NULL){
        printf("\nErro ao abrir o arquivo!");
    }
    printf("\nC A D R A S T O\n");
    printf("ID: ");
    scanf("%d", &func.id);
    fprintf(file, "%d\n", func.id);
    //fputs(func.id, file);
    fflush(stdin);
    printf("Nome: ");
    scanf("%s",&func.nome);
    fprintf(file, "%s\n", func.nome);
    printf("Email: ");
    scanf("%s", &func.email);
    fprintf(file, "%s\n", func.email);
    printf("Senha: ");
    scanf("%s",&func.senha);
    fprintf(file, "%s\n", func.senha);
    printf("\n\nConfirma os dados para gravacao ? (S/N): ");

    do{
            scanf("%c", &conf);
   	}while( conf != 's' && conf != 'S'&& conf != 'n' && conf != 'N' );
    fflush(stdin);
    if( conf == 's' || conf == 'S' ){
		    system("cls");
			fflush(file);//descarrega o buffer no disco
			printf("\n\nDados salvos com sucesso!");
            fclose(file);
			getchar();
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
    int op;
    login();
    /*do{
        start();
        printf("\n\nOpcao: ");
        scanf("%d", &op);
        fflush(stdin);
        switch(op){
            case 1:
                system("cls");
                //login();
                login();
                //printf("\nEm desenvolvimento");
                getchar();
                break;
            case 2:
                system("cls");
                cadastro();
                break;
            case 3:
                system("cls");
                printf("Obrigado pelo uso!");
                getchar();
                exit(0);
        }
    }while(op!=0);*/

    return 0;
}
