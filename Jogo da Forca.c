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

	int numeros[3];

	int* ponteiros = numeros;
	numeros[0] = 10;
	numeros[1] = 20;
	numeros[2] = 30;

	for(int i = 0; 1 < 3; i++){
	printf("%d ", numeros[0]);

	printf("%d ", *(ponteiros + 1));
	}
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

			jachutou(palavrasecreta[i], chutes, tentativas);

			if(achou) {
				printf("%c ", palavrasecreta[i]);
			} else {
				printf("_ ");
			}
		}
		printf("\n");

		chuta(chutes, &tentativas);
		printf("Voce ja chuteu %d vezes vai certar ou nao ??\n\n", tentativas);
	} while (!acertou && !enforcou);
}