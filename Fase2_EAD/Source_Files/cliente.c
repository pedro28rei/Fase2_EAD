#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Header_Files/menu.h"
#include "../Header_Files/meio.h"
#include "../Header_Files/gestor.h"
#include "../Header_Files/cliente.h"
#include "../Header_Files/grafo.h"


//Função que permite ler os dados no ficheiro "DadosClientes"
Cliente* lerDadosClientes() {

	FILE* fp;

	int codigo, idade, telemovel, nif;
	float saldo;
	char nome[60], morada[60], geocodigo[150];

	Cliente* aux = NULL;


	fp = fopen("Text_Files/DadosClientes.txt", "r"); 

	if (fp != NULL) {

		while (!feof(fp)) {

			fscanf(fp, "%d;%[^;];%d;%d;%[^;];%d;%f;%s", &codigo, nome, &idade, &telemovel, &morada, &nif, &saldo, geocodigo);
			aux = inserirCliente(aux, codigo, nome, idade, telemovel, morada, nif, saldo, geocodigo);
		}

		fclose(fp);
	}
	else printf("\t\tErro ao abrir o ficheiro DadosClientes!\n");

	return(aux);
}

//Função que permite listar todos os clientes
void listarClientes(Cliente* cliente)
{
	printf("\n|Cliente:\n\n");
	while (cliente != NULL)
	{
		printf("\t|Codigo: %d  |Nome: %s  |Idade: %d  |Telemovel: %d  |Morada: %s  |Nif: %d  |Saldo: %.2f  |Geocodigo: %s  \n", cliente->codigo, cliente->nome, cliente->idade, cliente->telemovel, cliente->morada, cliente->nif, cliente->saldo, cliente->geocodigo);
		cliente = cliente->seguinte;
	}
}

//Função para inserir um cliente
Cliente* inserirCliente(Cliente* cliente, int codigo, char nome[], int idade, int telemovel, char morada[], int nif, float saldo, char geocodigo[]) {
	{
		if (!existeCliente(cliente, codigo))
		{
			Cliente* novo = malloc(sizeof(Cliente));
			if (novo != NULL)
			{
				novo->codigo = codigo;
				strcpy(novo->nome, nome);
				novo->idade = idade;
				novo->telemovel = telemovel;
				strcpy(novo->morada, morada);
				novo->nif = nif;
				novo->saldo = saldo;
				strcpy(novo->geocodigo, geocodigo);
				novo->seguinte = cliente;
				return(novo);
			}
		}
		else return(cliente);
	}
}

//Função para verificar se existe um cliente
int existeCliente(Cliente* cliente, int codigo)
{
	while (cliente != NULL)
	{
		if (cliente->codigo == codigo) return(1);
		cliente = cliente->seguinte;
	}
	return(0);
}

//Função que permite remover um cliente
Cliente* removerCliente(Cliente* cliente, int cod) {
	Cliente* anterior = cliente, * atual = cliente, * aux;

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
		if (atual == NULL) return(cliente);
		else
		{
			anterior->seguinte = atual->seguinte;
			free(atual);
			return(cliente);
		}
	}
}

//Função que permite alterar os dados de um cliente existente
void alterarCliente(Cliente* cliente) {

	int encontrado = 0;
	int codigo1, codigo2, op, idade, telemovel, nif;
	float saldo;
	char nome[60], morada[60], geocodigo[150];

	printf("\tInsira o codigo do cliente: ");
	scanf("%d", &codigo1);

	while (cliente != NULL) {

		if (cliente->codigo == codigo1) {

			printf("\n\n\t|Escolha o que pretende alterar:");
			printf("\n\n\t\t1.Codigo\n");
			printf("\t\t2.Nome\n");
			printf("\t\t3.Idade\n");
			printf("\t\t4.Telemovel\n");
			printf("\t\t5.Morada\n");
			printf("\t\t6.NIF\n");
			printf("\t\t7.Saldo\n");
			printf("\t\t8.Geocodigo\n\n");
			printf("\t| Escolha:");
			scanf("%d", &op);

			switch (op) {
			case 1:
				printf("\n\n\t|Insira o novo codigo: ");
				scanf("%d", &codigo2);
				cliente->codigo = codigo2;
				break;
			case 2:
				printf("\n\n\tInsira o novo nome: ");
				scanf("%s", nome);
				strcpy(cliente->nome, nome);
				break;
			case 3:
				printf("\n\n\tInsira a nova idade: ");
				scanf("%d", &idade);
				cliente->idade = idade;
				break;
			case 4:
				printf("\n\n\tInsira o novo telemovel: ");
				scanf("%d", &telemovel);
				cliente->telemovel = telemovel;
				break;
			case 5:
				printf("\n\n\tInsira a nova morada: ");
				scanf("%s", morada);
				strcpy(cliente->morada, morada);
				break;

			case 6:
				printf("\n\n\tInsira o novo nif: ");
				scanf("%d", &nif);
				cliente->nif = nif;
				break;

			case 7:
				printf("\n\n\tInsira o novo saldo: ");
				scanf("%f", &saldo);
				cliente->saldo = saldo;
				break;
			case 8:
				printf("\n\n\tInsira o novo geocodigo: ");
				scanf("%s", geocodigo);
				strcpy(cliente->geocodigo, geocodigo); 
				break;
			default:
				printf("\n\n\t\tEscolha inexistente!");
			}

			printf("\n\n\t\tAlteracao efetuada com sucesso!\n\n");
			encontrado = 1;
			break;
		}

		cliente = cliente->seguinte;
	}

	if (!encontrado) {
		printf("\n\t\tCodigo inexistente!");
		return;
	}
}

//Função que permite ao cliente ver os seus dados pessoais
int verificarCliente(Cliente* cliente, int codigo) {

	int encontrado = 0;

	while (cliente != NULL) {

		if (cliente->codigo == codigo) {
			printf("\n\t\t|Codigo: %d  |Nome: %s  |Idade: %d  |Telemovel: %d  |Morada: %s  |Nif: %d  \n", cliente->codigo, cliente->nome, cliente->idade, cliente->telemovel, cliente->morada, cliente->nif);
			encontrado = 1;
			break;
		}
		cliente = cliente->seguinte;
	}

	if (!encontrado) {
		printf("\n\t Codigo inexistente!");
	}

	return encontrado;
}

//Função que permite ao cliente ver o seu saldo
int verificarSaldo(Cliente* cliente, int codigo) {

	int encontrado = 0;

	while (cliente != NULL) {

		if (cliente->codigo == codigo) {
			printf("\n\t\t|Saldo: %.2f $\n", cliente->saldo);
			encontrado = 1;
			break;
		}
		cliente = cliente->seguinte;
	}

	if (!encontrado) {
		printf("\n\t Codigo inexistente!");
	}

	return encontrado;
}

//Função que permite ao cliente adicionar saldo
Cliente* adicionarSaldo(Cliente* cliente, int codigo) {

	int encontrado = 0;

	while (cliente != NULL) {

		if (cliente->codigo == codigo) {

			float montante;

			printf("\n\t\t|Saldo: %.2f $\n", cliente->saldo);
			printf("\n\t|Insira o montante que pretende adicionar: ");
			scanf("%f", &montante);


			cliente->saldo = cliente->saldo + montante;

			printf("\n\t\t|Montante adicionado com sucesso!");
			printf("\n\t\t|Saldo: %.2f $\n", cliente->saldo);

			encontrado = 1;
			break;
		}
		cliente = cliente->seguinte;
	}

	if (!encontrado) {
		printf("\n\t\tCodigo inexistente!");
	}

	return cliente;
}



//Função que guarda os dados dos clientes no ficheiro "DadosClientes"
void guardarClientes(Cliente* cliente) {

	FILE* fp;
	fp = fopen("Text_Files/DadosClientes.txt", "w");

	if (fp != NULL) {


		while (cliente != NULL)
		{
			fprintf(fp, "%d;%s;%d;%d;%s;%d;%.2f;%s\n", cliente->codigo, cliente->nome, cliente->idade, cliente->telemovel, cliente->morada, cliente->nif, cliente->saldo, cliente->geocodigo);
			cliente = cliente->seguinte;
		}
		fclose(fp);
	}
	else printf("\tErro ao guardar dados!");
}