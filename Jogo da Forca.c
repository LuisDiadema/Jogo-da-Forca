#include <stdio.h>
#include <string.h>

void abertura() {printf("   _     _     _       _     _     _     _     _    \n");printf("  / \\   / \\   / \\     / \\   / \\   / \\   / \\   / \\   \n");printf(" ( B ) ( E ) ( M )   ( V ) ( I ) ( N ) ( D ) ( O )  \n");printf("  \\_/   \\_/   \\_/     \\_/   \\_/   \\_/   \\_/   \\_/   \n");printf("J O G O - D A - F O R C A\n\n");
}

void chuta(char chutes[], int* tentativas) {
	char chute;
	printf("Qual e o seu chute ??\n\n");
	scanf(" %c", &chute);

	chutes[*tentativas] = chute;
	(*tentativas)++;
}

void desenhaforca(char* palavrasecreta, char* chutes, int tentativas) {
	printf("Voce ja deu %d chutes\n", tentativas);

	for(int i = 0; i < strlen(palavrasecreta); i++) {
		if(jachutou(palavrasecreta[0], chutes, tentativas)) {
		prinft("%c ", palavrasecreta[i]);
		} else {
			printf("_ ");
		}
	}
}

int jachutou(char letra, char* chutes, int tentativas) {
	int achou = 0;

	for(int j = 0; j < tentativas; j++) {
		if(chutes[j] == letra) {
			achou = 1;
			break;
		}
	}

	return achou;
}
int main() {

    abertura(); 

    printf("Escolha uma letra:\n\n");

	char palavrasecreta[20];
	sprintf(palavrasecreta, "MELANCIA");

	int acertou = 0;
	int enforcou = 0;

	char chutes[26];
	int tentativas = 0;

	do {

		desenhaforca(palavrasecreta, chutes, tentativas);
		chuta(chutes, &tentativas);

	} while (!acertou && !enforcou);
}