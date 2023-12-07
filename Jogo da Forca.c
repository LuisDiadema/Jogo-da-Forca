#include <stdio.h>
#include <string.h>
#include "forca.h"
#include <stdlib.h>
#include <time.h>

char palavrasecreta[TAMANHO_PALAVRA];
char chutes[26];
int chutesdados = 0;

int letraexistente(char letra) {

	for(int j = 0; j < strlen(palavrasecreta); j++)	{
		if(letra == palavrasecreta) {
			return 1;
		}
	}
	return 0;
}

int chuteserrados() {
	int erros = 0;

	for(int i = 0; i < chutesdados; i++) {
		if(!letraexistente(chutes[i])) {
		}
	}
	return erros;
}

int enforcou() {
	return chuteserrados() >= 5;
}

int ganhou() {
	for(int i = 0; i < strlen(palavrasecreta); i++) {
		if(!jachutou(palavrasecreta[i])) {
			return 0;
		}
	}
	return 1;
}

void abertura() {
	printf("   _   _   _     _   _   _   _   _          \n");
 	printf("  / \\ / \\ / \\   / \\ / \\ / \\ / \\ / \\ \n");
 	printf(" ( B | E | M ) ( V | I | N | D | O )        \n");
 	printf("  \\_/ \\_/ \\_/   \\_/ \\_/ \\_/ \\_/ \\_/ \n");
 	printf("      J O G O - D A - F O R C A           \n\n");
}

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

void desenhaforca() {

	printf("  _______         \n");
	printf(" |/      |        \n");
	printf(" |      (_)       \n");
	printf(" |      \\|/      \n");
	printf(" |       |        \n");
	printf(" |      / \\      \n");
	printf(" |                \n");
	printf("_|___             \n");
	printf("\n\n                ");


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

void palavraescolhe() {
	FILE* f;

	f = fopen("palavras.txt", "r+");
	if(f == 0) {
	printf("Banco de dados de palavra nao disponivel\n\n");
	exit(1);
	}

	int qtddepalavras;
	fscanf(f, "%d", &qtddepalavras);

	srand(time(0));
	int randomico = rand() % qtddepalavras;

	for(int i = 0; i <= randomico; i++){
		fscanf(f, "%s", palavrasecreta);
	}
	fclose(f);
}

void adicionarpalavra() {
	char quer;

	printf("Quer adicionar uma nova palavra no jofgo (S/N) ?");
	scanf(" %c", &quer);
	
	if(quer == 'S') {
		char novapalavra[TAMANHO_PALAVRA];
		
		printf("Digita a nova palavra em letras MAIUSCULAS: ");
		scanf("%s", novapalavra);

		FILE* f;

		f = fopen("palavras.txt", "a");
		if(f == 0) {
			printf("Banco de dados de palavras nao disponivel");
			exit(1);
		}
		int qtd;
		fscanf(f, "%d", &qtd);
		qtd++;
		fseek(f, 0, SEEK_SET);
		fprintf(f, "%d", qtd);

		fseek(f, 0, SEEK_END);
		fprintf(f, "\n%s", novapalavra);

		fclose(f);
	}
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