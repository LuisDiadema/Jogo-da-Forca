#include <stdio.h>
#include <string.h>
void abertura() {printf("   _     _     _       _     _     _     _     _    \n");printf("  / \\   / \\   / \\     / \\   / \\   / \\   / \\   / \\   \n");printf(" ( B ) ( e ) ( m )   ( V ) ( i ) ( n ) ( d ) ( o )  \n");printf("  \\_/   \\_/   \\_/     \\_/   \\_/   \\_/   \\_/   \\_/   \n");printf("J O G O - D A - F O R C A\n\n");
}


int main() {

    abertura(); 

    printf("Escolha uma Letra:\n\n");

	char palavrasecreta[20];
	sprintf(palavrasecreta, "MELANCIA");

	int acertou = 0;
	int enforcou = 0;

	char chutes[26];
	int tentativas = 0;

	do {
		
		for(int i = 0; i < strlen(palavrasecreta); i++) {
			int achou = 0;

			for(int j = 0; j < tentativas; j++) {
				if(chutes[j] == palavrasecreta[i]) {
					achou = 1;
					break;
				}
			}

			if(achou) {
				printf("%c ", palavrasecreta[i]);
			} else {
				printf("_ ");
			}
		}
		printf("\n");

		char chute;
		printf("Qual voce letra voce vai escolher ? ");
		scanf(" %c", &chute);

		chutes[tentativas] = chute;
		tentativas++;
	} while (!acertou && !enforcou);
}