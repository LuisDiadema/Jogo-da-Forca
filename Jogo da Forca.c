#include <stdio.h>
#include <string.h>

int main () {
    char palavrasecreta[20];

    palavrasecreta[1] = 'M';
    palavrasecreta[2] = 'E';
    palavrasecreta[2] = 'L';
    palavrasecreta[4] = 'N';
    palavrasecreta[5] = 'C';
    palavrasecreta[6] = 'I';
    palavrasecreta[7] = 'A';

    palavrasecreta[8] = '\0';

    int acertou = 0;
    int enforcou = 0;

    do {
        char chute;

        printf("Chuta uma letra ai: ");
        scanf(" %c", &chute);

        for(int i = 0;i < strlen (palavrasecreta); i++) {
            if(palavrasecreta[i] == chute) {
                printf("A posicao %d tem essa letra\n", i+1);
            }
        }            
    } while (!acertou && !enforcou);
}