#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Header_Files/menu.h"
#include "../Header_Files/meio.h"
#include "../Header_Files/gestor.h"
#include "../Header_Files/cliente.h"
#include "../Header_Files/grafo.h"


//Função que permite ler a informação do ficheiro de texto "DadosGestores"
Gestor* lerDadosGestores() {

	FILE* fp;

	int codigo, idade, telemovel;
	char nome[60], morada[60];

	Gestor* aux = NULL;


	fp = fopen("Text_Files/DadosGestores.txt", "r");

	if (fp != NULL) {

		while (!feof(fp)) {

			fscanf(fp, "%d;%[^;];%d;%[^;];%d", &codigo, nome, &idade, morada, &telemovel);
			aux = inserirGestor(aux, codigo, nome, idade, telemovel, morada);
		}

		fclose(fp);
	}
	else printf("\t\tErro ao abrir o ficheiro DadosGestores!\n");

	return(aux);
}

//Função que permite listar todos os gestores
void listarGestores(Gestor* gestor)
{
	printf("\n|Gestor:\n\n");
	while (gestor != NULL)
	{
		printf("\t|Codigo: %d  |Nome: %s  |Idade: %d  |Telemovel: %d  |Morada: %s\n", gestor->codigo, gestor->nome, gestor->idade, gestor->telemovel, gestor->morada);
		gestor = gestor->seguinte;
	}
}

//Função que permite inserir um gestor
Gestor* inserirGestor(Gestor* gestor, int codigo, char nome[], int idade, float telemovel, char morada[]) {
	{
		if (!existeGestor(gestor, codigo))
		{
			Gestor* novo = malloc(sizeof(Gestor));
			if (novo != NULL)
			{
				novo->codigo = codigo;
				strcpy(novo->nome, nome);
				novo->idade = idade;
				novo->telemovel = telemovel;
				strcpy(novo->morada, morada);
				novo->seguinte = gestor;
				return(novo);
			}
		}
		else return(gestor);
	}
}

//Função para verificar se existe um gestor
int existeGestor(Gestor* gestor, int codigo)
{
	while (gestor != NULL)
	{
		if (gestor->codigo == codigo) return(1);
		gestor = gestor->seguinte;
	}
	return(0);
}

//Função que permite remover um gestor
Gestor* removerGestor(Gestor* gestor, int cod) {
	Gestor* anterior = gestor, * atual = gestor, * aux;

	if (atual == NULL) return(NULL);
	else if (atual->codigo == cod) // remoção do 1º registo
	{
		aux = atual->seguinte;
		free(atual);
		return(aux);
	}
	else
	{
		while ((atual != NULL) && (atual->codigo != cod))
		{
			anterior = atual;
			atual = atual->seguinte;
		}
		if (atual == NULL) return(gestor);
		else
		{
			anterior->seguinte = atual->seguinte;
			free(atual);
			return(gestor);
		}
	}
}

//Função que permite alterar os dados de um gestor existente
void alterarGestor(Gestor* gestor) {

	int encontrado = 0;
	int codigo1, codigo2, op, idade, telemovel;
	char nome[60], morada[60];

	printf("\tInsira o codigo do gestor: ");
	scanf("%d", &codigo1);

	while (gestor != NULL) {

		if (gestor->codigo == codigo1) {

			printf("\n\n\t\t1.Codigo\n");
			printf("\t\t2.Nome\n");
			printf("\t\t3.Idade\n");
			printf("\t\t4.Telemovel\n");
			printf("\t\t5.Morada\n\n");
			printf("\t| Escolha:");
			scanf("%d", &op);

			switch (op) {
			case 1:
				printf("\n\n\t|Insira o novo codigo: ");
				scanf("%d", &codigo2);
				gestor->codigo = codigo2;
				break;
			case 2:
				printf("\n\n\tInsira o novo nome: ");
				scanf("%s", nome);
				strcpy(gestor->nome, nome);
				break;
			case 3:
				printf("\n\n\tInsira a nova idade: ");
				scanf("%d", &idade);
				gestor->idade = idade;
				break;
			case 4:
				printf("\n\n\tInsira o novo telemovel: ");
				scanf("%d", &telemovel);
				gestor->telemovel = telemovel;
				break;
			case 5:
				printf("\n\n\tInsira a nova morada: ");
				scanf("%s", morada);
				strcpy(gestor->morada, morada);
				break;
			default:
				printf("\n\n\t\tEscolha inexistente!");
			}

			printf("\n\n\t\tAlteracao efetuada com sucesso!\n\n");
			encontrado = 1;
			break;
		}

		gestor = gestor->seguinte;
	}

	if (!encontrado) {
		printf("\n\t\tCodigo inexistente!");
		return;
	}
}

//Função que guarda os dados dos gestores no ficheiro DadosGestores
void guardarGestores(Gestor* gestor) {

	FILE* fp;
	fp = fopen("Text_Files/DadosGestores.txt", "w");

	if (fp != NULL) {


		while (gestor != NULL)
		{
			fprintf(fp, "%d;%s;%d;%s;%d\n", gestor->codigo, gestor->nome, gestor->idade, gestor->morada, gestor->telemovel);
			gestor = gestor->seguinte;
		}
		fclose(fp);
	}
	else printf("\tErro ao guardar dados!");
}
