/*Universidade de Brasilia
Instituto de Ciencias Exatas
Departamento de Ciencia da Computacao
Estrutura de Dados – 1/2017
Aluno(a): Filipe Goncalves Botelho
Matricula: 16/0120276
Turma: B
Descricao: Jogo da Batalha Naval. O qual consiste em acertar partes de embarcações
do adversário por coordenadas do eixo cartesiano. Aquele que tiver mais pontos ao
final do jogo, ganha. */
#include <stdio.h>
#include <string.h>
#include <time.h>

char campo[2][10][10];
char gabarito[2][10][10];

Gabarito(void){
    int i, j, x, y, w, z, tem;
    memset(gabarito[0], '~', 100);
    memset(gabarito[1], '~', 100);

    srand((unsigned)time(NULL));

    tem = 0;
    i = 0;
    while (i < 6){
        x =  rand() % 10;
        y =  rand() % 5;
        w =  rand() % 10;
        z =  rand() % 5;
        j = 0;
        while (j < 5 && tem == 0){
            if (gabarito[0][x][y+j] == 'X' && gabarito[1][w][z+j] == 'X')
                tem = 1;
            j++;
        }
        if (tem == 0){
            j = 0;
            while (j < 5){
                gabarito[0][x][y+j] = 'X';
                gabarito[1][w][z+j] = 'X';
                j++;
            }
        }
        else{
            i--;
        }
        i++;
    }
}

Prejogo(char nome[][20]){
    int i;
    printf("\t\t\t\t\t\t\t\tINSTRUCOES DO JOGO\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t- O jogo consiste numa matriz 10x10\n\n");
    printf("\t\t\t\t\t\t\t- Exemplo de tiro: Ex.: 9 2\n\n");
    printf("\t\t\t\t\t\t\t- X - Embarcacao atingida!\n\n");
    printf("\t\t\t\t\t\t\t- * - Embarcacao nao atingida!\n\n");
    printf("\t\t\t\t\t\t\t- 5 pontos por cada 'X' de embarcacao\n\n");
    printf("\t\t\t\t\t\t\t- Ganha quem fizer mais pontos\n\n");
    printf("\t\t\t\t\t\t\t- Digite um numero maior que 10 ou menor que 0 para SAIR do jogo\n\n\n\n");
    for (i = 0; i < 50; i++){
        printf("*  ");
    }
    printf("\n\n");
    printf("Nome Player 1:");
    scanf(" %[^\n]s", nome[0]);
    printf("Nome Player 2:");
    scanf(" %[^\n]s", nome[1]);
    printf("\n\nPressione ENTER para continuar");
    getchar();
    getchar();

    system("cls");
}

Layout(int pontuacao[],char nome[][20]){
    int i, j;

    printf("\t\t\t\t\t\t\t\t*BATALHA NAVAL*\n\n\n");
    printf("    ");
    for (j = 0; j < 10; j++){
            printf("%i   ", j);
    }
    printf("\t\t\t\t\t\t");
    printf("    ");
    for (j = 0; j < 10; j++){
            printf("%i   ", j);
    }
    printf("\n");
    for (i = 0; i < 10; i++){
        printf("%i   ", i);
        for (j = 0; j < 10; j++){
            printf("%c   ", campo[0][i][j]);
        }
        printf("\t\t\t\t\t\t");
        printf("%i   ", i);
        for (j = 0; j < 10; j++){
            printf("%c   ", campo[1][i][j]);
        }
        printf("\n");
    }
    printf("\n\n%s: %i pontos\t\t\t\t\t\t\t\t\t\t", nome[1], pontuacao[1]);
    printf("%s: %i pontos\n", nome[0], pontuacao[0]);
}

Jogo(char nome[][20],int vez, int tiro[]){
    if(vez%2 == 0){
        printf("\n\n\n\n%s, sua vez!\n", nome[0]);
        printf("Tiro: ");
        scanf("%i %i", &tiro[0], &tiro[1]);
    }
    else{
        printf("\n\n\n\n%s, sua vez!\n", nome[1]);
        printf("Tiro: ");
        scanf("%i %i", &tiro[0], &tiro[1]);
    }

}

Verificar(int i,int tiro[], int pontuacao[]){
    int l, j;
    i = i%2;
    l = tiro[0];
    j = tiro[1];
    if (i == 0){
        if (gabarito[i][l][j] == 'X' && campo[i][l][j] == '~'){
            printf("Acertou!");
            pontuacao[i] += 5;
            campo[i][l][j] = 'X';
        }
        else if(gabarito[i][l][j] == '~' && campo[i][l][j] == '~'){
            printf("Errou!");
            campo[i][l][j] = '*';
        }
        else{
            printf("Perdeu a vez. Tiro repitido!");
        }
    }
    else{
        if (gabarito[i][l][j] == 'X' && campo[i][l][j] == '~'){
            printf("Acertou!");
            pontuacao[i] += 5;
            campo[i][l][j] = 'X';
        }
        else if(gabarito[i][l][j] == '~' && campo[i][l][j] == '~'){
            printf("Errou!");
            campo[i][l][j] = '*';
        }
        else{
            printf("Perdeu a vez. Tiro repitido!");
        }
    }

}

int main(void){
    int continuar, i, tiro[2], pontuacao[2];
    char nome[2][20];
    memset(campo[0], '~', 100);
    memset(campo[1], '~', 100);
    Gabarito();
    Prejogo(nome);
    continuar = 0;
    i = 0;
    pontuacao[0] = 0;
    pontuacao[1] = 0;
    while(continuar == 0){
        Layout(pontuacao, nome);
        Jogo(nome, i, tiro);
        if (tiro[0] >= 10 || tiro[0] < 0 || tiro[1] >= 10 || tiro[1] < 0){
            continuar = 1;
        }
        else{
            Verificar(i, tiro, pontuacao);
            getchar();
            getchar();
        }

        system("cls");

        i++;
    }
    if(pontuacao[0] > pontuacao[1]){
        printf("%s, voce e o novo campeao de Batalha Naval\n", nome[0]);
    }
    else if(pontuacao[0] < pontuacao[1]){
        printf("%s, voce e o novo campeao de Batalha Naval\n", nome[1]);
    }
    else{
        printf("O jogo deu empate!");
    }
    return 0;
}
