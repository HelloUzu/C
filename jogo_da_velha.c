#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void limparTela(void);
void imprimeTabuleiro(char tabuleiro[3][3]);
int ganhador(char tabuleiro[3][3]);

int main(void){

    setlocale(LC_ALL, "");

    limparTela();

    char tabuleiroJogo[3][3] = {{'1', '2', '3'},
                                {'4', '5', '6'},
                                {'7', '8', '9'}};
    int numeroJogadas = 0;
    int posicaoJogada = 0;

    while(1){
        limparTela();
        printf("\n\t+-+-+-+-+-+-+-+-+-+\n\n");
        imprimeTabuleiro(tabuleiroJogo);
        printf("\n\t+-+-+-+-+-+-+-+-+-+\n\n");

        printf("\t- Jogador Atual: %c\n", (numeroJogadas % 2) == 0 ? 'X' : 'O');
        printf("\n\t- Posição (1-9): ");
        scanf("%d", &posicaoJogada);

        if(posicaoJogada < 1 || posicaoJogada > 9){
            printf("\n\tEscolha um número válido.");
            continue;
        }

        int linha = (posicaoJogada - 1) / 3;
        int coluna = (posicaoJogada - 1) % 3;

        if(tabuleiroJogo[linha][coluna] == 'X' || tabuleiroJogo[linha][coluna] == 'O'){
            printf("\n\tEssa posição já está ocupada.");
            continue;
        }

        tabuleiroJogo[linha][coluna] = (numeroJogadas % 2) == 0 ? 'X' : 'O';
        numeroJogadas++;

        if(ganhador(tabuleiroJogo)){
            limparTela();
            printf("\n\t+-+-+-+-+-+-+-+-+-+\n\n");
            imprimeTabuleiro(tabuleiroJogo);
            printf("\n\t+-+-+-+-+-+-+-+-+-+\n\n");
            printf("\n\t- O Jogador %c venceu!\n", (numeroJogadas % 2) == 0 ? '0' : 'X');
            exit(0);
        }

        if(numeroJogadas == 9){
            limparTela();
            printf("\n\t+-+-+-+-+-+-+-+-+-+\n\n");
            imprimeTabuleiro(tabuleiroJogo);
            printf("\n\t+-+-+-+-+-+-+-+-+-+\n\n");
            printf("\n\t- Deu velha!\n");
            exit(1);
        }

    }

    return EXIT_SUCCESS;
}

/*

- Funções:

*/

void limparTela(void){
    for(int i = 0; i <= 5; i++){
        printf("\n");
   }

}

void imprimeTabuleiro(char tabuleiro[3][3]){
    for(int i = 0; i != 3; i++){
        for(int j = 0; j != 3; j++){
            printf("\t %c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int ganhador(char tabuleiro[3][3]){

    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2]) {
            return 1;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i]) {
            return 1;
        }
    }

    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2]) {
        return 1;
    }

    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]) {
        return 1;
    }

    return 0;
}
