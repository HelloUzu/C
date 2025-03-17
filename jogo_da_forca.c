#include <stdio.h>
#include <string.h>
#include <locale.h>

void jogoForca(int numTentativas);
void limparTela(void);
void menuAdivinha(void);
void menuPalavra(void);
int dicaFunc(void);

int main(void) {
    setlocale(LC_ALL, "");

    limparTela();

    int dica;
    char palavra[99 + 1];
    char palavra_underscore[99 + 1];
    char caractere;
    int tentativas = 0;

    menuPalavra();

    printf("\t| 1 - Animal\n");
    printf("\t| 2 - Produto\n");
    printf("\t| 3 - Elemento\n");
    printf("\t| 4 - Número\n");
    printf("\t| 5 - Outros\n");

    printf("\n\t[+] - Dica: ");
    dica = dicaFunc();

    limparTela();
    menuPalavra();
    printf("\n[+] - Digite a palavra: ");
    scanf("%s", palavra);
    limparTela();

    menuAdivinha();
    jogoForca(0);

    for (int i = 0; i < strlen(palavra); i++) {
        palavra_underscore[i] = '_';
    }
    palavra_underscore[strlen(palavra)] = '\0';

    while (1) {
        printf("\t[ Dica: %s ]\n", (dica == 1) ? "Animal" :
                                  (dica == 2) ? "Produto" :
                                  (dica == 3) ? "Elemento" :
                                  (dica == 4) ? "Número" : "Outros");
        printf("\t[ Palavra: %s ]\n", palavra_underscore);
        getchar();
        printf("\t[ Digite um caractere: ] ");
        scanf("%c", &caractere);

        int acertou = 0;
        for (int i = 0; i < strlen(palavra); i++) {
            if (palavra[i] == caractere) {
                palavra_underscore[i] = caractere;
                acertou = 1;
            }
        }

        if (!acertou) {
            tentativas++;
        }

        jogoForca(tentativas);

        if (strcmp(palavra, palavra_underscore) == 0) {
            printf("\n\t[+] Você ganhou! A palavra era: %s\n", palavra);
            break;
        }

        if (tentativas >= 6) {
            printf("\n\t[-] Você perdeu! A palavra era: %s\n", palavra);
            break;
        }
    }

    return 0;
}

/*
    - Função jogoForca
    - Em cada caso, aumenta uma parte do corpo.
*/
void jogoForca(int numTentativas) {
    switch(numTentativas) {
        case 0:
            limparTela();
            printf("\n\t  +--------------------+\n");
            printf("\t  |                    |\n");
            printf("\t  |                    |\n");
            printf("\t  |                    |\n");
            printf("\t  |                    |\n");
            printf("\t  |                    |\n");
            printf("\t  |                    |\n");
            printf("\t  +--------------------+\n");
            break;

        case 1:
            limparTela();
            printf("\n\t  +--------------------+\n");
            printf("\t  |        O           |\n");
            printf("\t  |                    |\n");
            printf("\t  |                    |\n");
            printf("\t  |                    |\n");
            printf("\t  |                    |\n");
            printf("\t  |                    |\n");
            printf("\t  +--------------------+\n");
            break;

        case 2:
            limparTela();
            printf("\n\t  +--------------------+\n");
            printf("\t  |        O           |\n");
            printf("\t  |        |           |\n");
            printf("\t  |                    |\n");
            printf("\t  |                    |\n");
            printf("\t  |                    |\n");
            printf("\t  |                    |\n");
            printf("\t  +--------------------+\n");
            break;

        case 3:
            limparTela();
            printf("\n\t  +--------------------+\n");
            printf("\t  |        O           |\n");
            printf("\t  |       /|           |\n");
            printf("\t  |                    |\n");
            printf("\t  |                    |\n");
            printf("\t  |                    |\n");
            printf("\t  |                    |\n");
            printf("\t  +--------------------+\n");
            break;

        case 4:
            limparTela();
            printf("\n\t  +--------------------+\n");
            printf("\t  |        O           |\n");
            printf("\t  |       /|\\         |\n");
            printf("\t  |                    |\n");
            printf("\t  |                    |\n");
            printf("\t  |                    |\n");
            printf("\t  |                    |\n");
            printf("\t  +--------------------+\n");
            break;

        case 5:
            limparTela();
            printf("\n\t  +--------------------+\n");
            printf("\t  |        O           |\n");
            printf("\t  |       /|\\         |\n");
            printf("\t  |       /            |\n");
            printf("\t  |                    |\n");
            printf("\t  |                    |\n");
            printf("\t  |                    |\n");
            printf("\t  +--------------------+\n");
            break;

        case 6:
            limparTela();
            printf("\n\t  +--------------------+\n");
            printf("\t  |        O           |\n");
            printf("\t  |       /|\\         |\n");
            printf("\t  |       / \\         |\n");
            printf("\t  |                    |\n");
            printf("\t  |                    |\n");
            printf("\t  |                    |\n");
            printf("\t  +--------------------+\n");
            break;
    }
}

void limparTela(void) {
    for (int i = 0; i <= 15; i++) {
        printf("\n");
    }
}

void menuPalavra(void) {
    printf("  ————————————————————————————\n");
    printf("         Jogo da Forca        \n");
    printf("         Menu de Dicas        \n");
    printf("          Jogador #0          \n");
    printf("  ————————————————————————————\n\n");
}

void menuAdivinha(void) {
    printf("  ————————————————————————————\n");
    printf("         Jogo da Forca        \n");
    printf("       Menu de Adivinhar      \n");
    printf("          Jogador #1          \n");
    printf("  ————————————————————————————\n\n");
}

int dicaFunc(void) {
    int numDica;
    while(1) {
        if(scanf("%d", &numDica) == 1 && numDica >= 1 && numDica <= 5) {
            break;
        } else {
            printf("\n\t[-] Opção não encontrada. Tente novamente.");
            while (getchar() != '\n');
        }
    }
    return numDica;
}
