#include <stdio.h>
#include <string.h>
#include "forca.h"
#include <stdlib.h>

char palavrasecreta[20];
char chutes[26];
int chutesdados = 0;

int enforcou() {
	int erros = 0;

	for(int i = 0; i < chutesdados; i++) {
		
		int existe = 1;

		for(int j = 0; j < strlen(palavrasecreta); j++) {
			if(chutes[i] == palavrasecreta[j]) {
				existe = 1;
				break;
			}
		}
		if (!existe) erros++;
	}
	return erros >= 5;
}

void abertura() {
	printf("   _   _   _     _   _   _   _   _          \n");
 	printf("  / \\ / \\ / \\   / \\ / \\ / \\ / \\ / \\ \n");
 	printf(" ( B | E | M ) ( V | I | N | D | O )        \n");
 	printf("  \\_/ \\_/ \\_/   \\_/ \\_/ \\_/ \\_/ \\_/ \n");
 	printf("      J O G O - D A - F O R C A           \n\n");
}

void palavraescolhe() {
	FILE* f;

	f = fopen("palavras.txt", "r");
	if(f == 0);{
	printf("Banco de dados de palavra nao disponivel\n\n");
	exit(1);
	}
}

int qtddepalavras;
fscanf(f, "%d", &qtddepalavras);

void chuta() {
	char chute;
	printf("\nQual e o seu chute ??\n\n");
	scanf(" %c", &chute);

	chutes[chutesdados] = chute;
	(chutesdados)++;
}

int jachutou(char letra) {
	int achou = 0;

	for(int j = 0; j < chutesdados; j++) {
		if(chutes[j] == letra) {
			achou = 1;
			break;
		}
	}

	return achou;
}

int ganhou() {
	for(int i = 0; i < strlen(palavrasecreta); i++){
		if(!jachutou(palavrasecreta[i])) {
			return 0;
		}
	}
	return 1;
}

void desenhaforca() {
	printf("Quantidade de chutes foram %d\n\n", chutesdados);

	for(int i = 0; i < strlen(palavrasecreta); i++) {

		if(jachutou(palavrasecreta[i])) {
			printf("%c ", palavrasecreta[i]);
		} else {
			printf("_ ");
		}
	}
	printf("\n");
}

void escolherpalavra() {
	sprintf(palavrasecreta, "MELANCIA");
}

int main() {
	
	abertura();
	escolherpalavra();


	do {

		desenhaforca();
		chuta();

		chutesdados++;
	} while (!ganhou() && !enforcou());
}