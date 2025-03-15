#include <stdio.h>
#include <locale.h>
#include <string.h>

#define TAM_MAX 99 + 1

int main(void){

    setlocale(LC_ALL, "");

    char str[TAM_MAX];
    char inverse_str[TAM_MAX];

    printf("Type the string: ");
    fgets(str, TAM_MAX, stdin);

    if(str[strlen(str) - 1] == '\n'){
        str[strlen(str) - 1] = '\0';
    }

    for(int i = strlen(str) - 1; i >= 0; i--){
        inverse_str[i] = str[strlen(str) - i - 1];
    }

    printf("Reverse string: %s\n", inverse_str);

    return 0;

}
