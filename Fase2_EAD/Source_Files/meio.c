#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Header_Files/menu.h"
#include "../Header_Files/meio.h"
#include "../Header_Files/gestor.h"
#include "../Header_Files/cliente.h"
#include "../Header_Files/grafo.h"


//Função que permite listar todos os meios
void listarMeios(Meio* meio)
{
	printf("\n|Meios:\n\n");
	while (meio != NULL)
	{
		printf("\t|Codigo: %d  |Tipo: %s  |Bateria: %d  |Autonomia: %.1f km  |Custo: %.2f $  |Alugado: %d  |Geocodigo: %s \n", meio->codigo, meio->tipo, meio->bateria, meio->autonomia, meio->custo, meio->alugado, meio->geocodigo);
		meio = meio->seguinte;
	}
}

//Função que permite ler os dados no ficheiro "DadosMeios"
Meio* lerDadosMeios() {

	FILE* fp;

	int codigo, bateria, alugado;
	float autonomia, custo, volume, peso;
	char tipo[50], geocodigo[150];

	Meio* aux = NULL;


	fp = fopen("Text_Files/DadosMeios.txt", "r");

	if (fp != NULL) {

		while (!feof(fp)) {

			fscanf(fp, "%d;%[^;];%d;%f;%f;%d;%[^;];%f;%f", &codigo, tipo, &bateria, &autonomia, &custo, &alugado, geocodigo, &volume, &peso);
			aux = inserirMeio(aux, codigo, tipo, bateria, autonomia, custo, alugado, geocodigo, volume, peso);
		}

		fclose(fp);
	}
	else printf("\t\tErro ao abrir o ficheiro DadosMeios!\n");

	return(aux);
}

//Função para inserir um meio
Meio* inserirMeio(Meio* meio, int codigo, char tipo[], int bateria, float autonomia, float custo, int alugado, char geocodigo[], float volume, float peso)
{

	if (!existeMeio(meio, codigo))
	{
		Meio* novo = malloc(sizeof(Meio));
		if (novo != NULL)
		{
			novo->codigo = codigo;
			strcpy(novo->tipo, tipo);
			novo->bateria = bateria;
			novo->autonomia = autonomia;
			novo->custo = custo;
			novo->alugado = alugado;
			strcpy(novo->geocodigo, geocodigo);
			novo->volume = volume;
			novo->peso = peso;
			novo->seguinte = meio;
			return(novo);
		}
	}
	else return(meio);

}

//Função para verificar se existe um meio
int existeMeio(Meio* meio, int codigo)
{
	while (meio != NULL)
	{
		if (meio->codigo == codigo) return(1);
		meio = meio->seguinte;
	}
	return(0);
}

////Função que permite remover um meio
Meio* removerMeio(Meio* meio, int cod) {
	Meio* anterior = meio, * atual = meio, * aux;

	if (atual == NULL) return(NULL);
	else if (atual->codigo == cod) 
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
		if (atual == NULL) return(meio);
		else
		{
			anterior->seguinte = atual->seguinte;
			free(atual);
			return(meio);
		}
	}
}

//Função que permite alterar os dados de um meio existente
void alterarMeio(Meio* meio) {

	int encontrado = 0;
	int codigo1, codigo2, op, bateria, alugado;
	float autonomia, custo, volume, peso;
	char tipo[50], geocodigo[150];

	printf("\tInsira o codigo do meio: ");
	scanf("%d", &codigo1);

	while (meio != NULL) {

		if (meio->codigo == codigo1) {

			printf("\n\n\t|Escolha o que pretende alterar:");
			printf("\n\n\t\t1.Codigo\n");
			printf("\t\t2.Tipo\n");
			printf("\t\t3.Bateria\n");
			printf("\t\t4.Autonomia\n");
			printf("\t\t5.Custo\n");
			printf("\t\t6.Alugado\n");
			printf("\t\t7.Geocodigo\n");
			printf("\t\t8.Volume\n");
			printf("\t\t9.Peso\n\n");
			printf("\t| Escolha:");
			scanf("%d", &op);

			switch (op) {
			case 1:
				printf("\n\n\t|Insira o novo codigo: ");
				scanf("%d", &codigo2);
				meio->codigo = codigo2;
				break;
			case 2:
				printf("\n\n\tInsira o novo tipo: ");
				scanf("%s", tipo);
				strcpy(meio->tipo, tipo);
				break;
			case 3:
				printf("\n\n\tInsira a nova bateria: ");
				scanf("%d", &bateria);
				meio->bateria = bateria;
				break;
			case 4:
				printf("\n\n\tInsira a nova autonomia: ");
				scanf("%f", &autonomia);
				meio->autonomia = autonomia;
				break;
			case 5:
				printf("\n\n\tInsira o novo custo: ");
				scanf("%f", &custo);
				meio->custo = custo;
				break;
			case 6:
				printf("\n\n\tInsira o novo alugado(1/0): ");
				scanf("%d", &alugado);
				meio->alugado = alugado;
				break;
			case 7:
				printf("\n\n\tInsira o novo geocodigo: ");
				scanf("%s", geocodigo);
				strcpy(meio->geocodigo, geocodigo);
				break;
			case 8:
				printf("\n\n\tInsira o novo volume: ");
				scanf("%f", &volume);
				meio->volume = volume;
				break;	
			case 9:
				printf("\n\n\tInsira o novo peso: ");
				scanf("%f", &peso);
				meio->peso = peso;
				break;
			default:
				printf("\n\n\t\tEscolha inexistente!");
			}

			printf("\n\n\t\tAlteracao efetuada com sucesso!\n\n");
			encontrado = 1;
			break;
		}

		meio = meio->seguinte;
	}

	if (!encontrado) {
		printf("\n\t\tCodigo inexistente!");
		return;
	}
}

//Função que permite alugar um meio
Meio* aluguerMeio(Meio* meio, int codigoC) { 
    listarMeios(meio);

    int codigo, encontrado;
    encontrado = 0;

    printf("\n\n| Os meios disponiveis apresentam em |Alugado: 0 ");
    printf("\n\n\n\t|Insira o codigo do meio que quer alugar:");
    scanf("%d", &codigo);

    while (meio != NULL) {
        if (meio->codigo == codigo) {
            if (meio->alugado != 1) {  
                meio->alugado = 1;

		
                printf("\n\n| Alugou %s com sucesso!\n", meio->tipo);
                printf("| Foi levantado do seu saldo %.2f $\n", meio->custo);
                encontrado = 1;
            } else {
                printf("\n\n| Insucesso! O meio escolhido encontra-se atualmente alugado por outro cliente!\n");
				encontrado = 1;
            }
        }

        meio = meio->seguinte;
    }

    if (!encontrado) {
        printf("\n\n\tCodigo inexistente!\n");
    }
}

//Função que permite lista todos os meios disponiveis em determinada localização
void localizarMeios(Meio* meio, char geocodigo[]) {

	int encontrado = 0;

	while (meio != NULL) {

		if (strcmp(meio->geocodigo, geocodigo) == 0) {
			printf("\n\t\t|Codigo: %d  |Tipo: %s  |Bateria: %d  |Autonomia: %.1f km  |Custo: %.2f $ |Alugado: %d |Geocodigo: %s ", meio->codigo, meio->tipo, meio->bateria, meio->autonomia, meio->custo, meio->alugado, meio->geocodigo);
			encontrado = 1;
		}
		meio = meio->seguinte;
	}

	if (!encontrado) {
		printf("\n\n\t\tNenhum meio encontrado nesta localizacao!\n", geocodigo);
	}
}

//Função que guarda os dados dos meios no ficheiro "DadosMeios"
void guardarMeios(Meio* meio) {

	FILE* fp;
	fp = fopen("Text_Files/DadosMeios.txt", "w");

	if (fp != NULL) {


		while (meio != NULL)
		{
			fprintf(fp, "%d;%s;%d;%.1f;%.2f;%d;%s;%.2f;%.2f\n", meio->codigo, meio->tipo, meio->bateria, meio->autonomia, meio->custo, meio->alugado, meio->geocodigo, meio->volume, meio->peso);
			meio = meio->seguinte;
		}
		fclose(fp);
	}
	else printf("\tErro ao guardar dados!");
}
