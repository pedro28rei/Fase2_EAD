#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header_Files/menu.h"
#include "Header_Files/meio.h"
#include "Header_Files/gestor.h"
#include "Header_Files/cliente.h"
#include "Header_Files/grafo.h"


int main() {

	
	Meio* meio = NULL;
	Cliente* cliente = NULL;
	Gestor* gestor = NULL;

		meio = lerDadosMeios();
		cliente = lerDadosClientes();
		gestor = lerDadosGestores();


	Grafo mapa = NULL;

		mapa = lerVertices(mapa);   

		mapa = lerArestas(mapa); 

		mapa = lerMeiosGrafo(mapa);

		mapa = lerClientesGrafo(mapa);

	int codigo, idade, telemovel, nif, bateria, geo, aux;
	float saldo, autonomia, custo, volume, peso, raio;
	char nome[60], morada[60], tipo[60], geocodigo[150], verticeO[150], verticeD[150];

	
	int escolha1, escolha2, escolha3;


	do {
	system("cls");
	escolha1 = menuPerfil();


		switch (escolha1)
		{
		case 1:
			do {
			system("cls");
			escolha2 = menuGestor();

								switch (escolha2)
								{
								case 1:
									system("cls");

									listarClientes(cliente);

									printf("\n\n\tPressione qualquer tecla para regressar ao menu...");
									getch();
									break;
								case 2:
									system("cls");

									listarGestores(gestor);

									printf("\n\n\tPressione qualquer tecla para regressar ao menu...");
									getch();
									break;
								case 3:
									system("cls");

									listarMeios(meio);

									printf("\n\n\tPressione qualquer tecla para regressar ao menu...");
									getch();
									break;
								case 4:
									system("cls");

									printf("\t\t| Codigo: ");
									scanf("%d", &codigo);
									printf("\t\t| Nome: ");
									scanf("%s", nome);
									printf("\t\t| Idade: ");
									scanf("%d", &idade);
									printf("\t\t| Telemovel: ");
									scanf("%d", &telemovel);
									printf("\t\t| Morada: ");
									scanf("%s", morada);
									printf("\t\t| NIF: ");
									scanf("%d", &nif);
									printf("\t\t| Saldo: ");
									scanf("%f", &saldo);
									printf("\t\t| Geocodigo: ");
									scanf("%s", geocodigo);
									printf("\n\t\tCliente introduzido com sucesso!\n\n");

									cliente = inserirCliente(cliente, codigo, nome, idade, telemovel, morada, nif, saldo, geocodigo);

									printf("\n\t\tPressione qualquer tecla para regressar ao menu...");
									getch();
									break;
								case 5:
									system("cls");

									printf("\t\t| Codigo: ");
									scanf("%d", &codigo);
									printf("\t\t| Nome: ");
									scanf("%s", nome);
									printf("\t\t| Idade: ");
									scanf("%d", &idade);
									printf("\t\t| Telemovel: ");
									scanf("%d", &telemovel);
									printf("\t\t| Morada: ");
									scanf("%s", morada);
									printf("\n\t\tGestor introduzido com sucesso!\n\n");

									gestor = inserirGestor(gestor, codigo, nome, idade, telemovel, morada);

									printf("\n\t\tPressione qualquer tecla para regressar ao menu...");
									getch();
									break;
								case 6:
									system("cls");

									printf("\t\t| Codigo: ");

									scanf("%d", &codigo);

									printf("\t\t| Tipo: ");
									scanf("%s", tipo);
									printf("\t\t| Bateria: ");
									scanf("%d", &bateria);
									printf("\t\t| Autonomia: ");
									scanf("%f", &autonomia);
									printf("\t\t| Custo: ");
									scanf("%f", &custo);
									printf("\t\t| Geocodigo:");
									scanf("%s", geocodigo);
									printf("\t\t| Volume: ");
									scanf("%f", &volume);
									printf("\t\t| Peso: ");
									scanf("%f", &peso);
									printf("\n\t\tMeio introduzido com sucesso!\n\n");

									meio = inserirMeio(meio, codigo, tipo, bateria, autonomia, custo, 0, geocodigo, volume, peso); 

									printf("\n\t\tPressione qualquer tecla para regressar ao menu...");
									getch();
									break;
								case 7:
									system("cls");

									printf("\t\tInsira o codigo do cliente a remover: ");
									scanf("%d", &codigo);
									cliente = removerCliente(cliente, codigo);
									printf("\n\t\tCliente removido com sucesso!\n\n");

									printf("\n\t\tPressione qualquer tecla para regressar ao menu...");
									getch();
									break;
								case 8:
									system("cls");

									printf("\t\tInsira o codigo do gestor a remover: ");
									scanf("%d", &codigo);
									gestor = removerGestor(gestor, codigo);
									printf("\n\t\tGestor removido com sucesso!\n\n");

									printf("\n\t\tPressione qualquer tecla para regressar ao menu...");
									getch();
									break;
								case 9:
									system("cls");

									printf("\t\tInsira o codigo do meio a remover: ");
									scanf("%d", &codigo);
									meio = removerMeio(meio, codigo);
									printf("\n\t\tMeio removido com sucesso!\n\n");

									printf("\n\t\tPressione qualquer tecla para regressar ao menu...");
									getch();
									break;
								case 10:
									system("cls");

									alterarCliente(cliente);
									
									printf("\n\t\tPressione qualquer tecla para regressar ao menu...");
									getch();
									break;
								case 11:
									system("cls");

									alterarGestor(gestor);
							
									printf("\n\t\tPressione qualquer tecla para regressar ao menu...");
									getch();
									break;
								case 12:
									system("cls");

									alterarMeio(meio);
									
									printf("\n\t\tPressione qualquer tecla para regressar ao menu...");
									getch();
									break;
								case 13:
													do {
														 system("cls");
														 escolha3 = menuGrafo();
														
																	switch (escolha3)
																	{
																case 1:
																	system("cls");
																	
																	printf("\t\tInsira o Geocodigo que pretende adicionar: ");
																	scanf("%s", geocodigo);
																	aux = criarVertice(&mapa, geocodigo);

																		if(aux == 1) printf("\n\t\tInserido com sucesso!");
																		else printf("\n\t\tErro ao inserir! Geocodigo ja existe ou invalido!");
																	
																	printf("\n\n\tPressione qualquer tecla para regressar ao menu...");
																	getch();
																	break;
																case 2:
																	system("cls");
																	
																	printf("\t\tInsira o Geocodigo da origem: ");
																	scanf("%s", verticeO); 
																	
																	printf("\t\tInsira o Geocodigo do destino: ");
																	scanf("%s", verticeD);

																	printf("\t\tInsira a distancia entre eles(metros): ");
																	scanf("%f", &peso);

																	aux = criarAresta(mapa, verticeO, verticeD, peso);

																		if(aux == 1) printf("\n\t\tInserido com sucesso!");
																		else printf("\n\t\tErro ao inserir! Geocodigos inexistentes ou caminho ja existente!");

																	printf("\n\n\tPressione qualquer tecla para regressar ao menu...");
																	getch();
																	break;
																case 3:
																	system("cls");
																	
																	printf("\t\tInsira o Geocodigo onde pretende adicionar: ");
																	scanf("%s", geocodigo);

																	printf("\t\tInsira o codigo do meio: ");
																	scanf("%d", &codigo);
																	printf("\t\tInsira o tipo do meio: ");
																	scanf("%s", tipo);
																	printf("\t\tInsira o custo do meio: ");
																	scanf("%f", &custo);
																	printf("\t\tInsira a bateria do meio: ");
																	scanf("%d", &bateria);
																	printf("\t\tInsira o volume do meio: ");
																	scanf("%f", &volume);

																	aux = inserirMeioGrafo(mapa, geocodigo, codigo, tipo, custo, bateria, volume);
																	
																		if(aux == 1) printf("\n\t\tInserido com sucesso!");
																		else printf("\n\t\tErro ao inserir! Geocodigo inexistente ou meio ja existe!");

																	printf("\n\n\tPressione qualquer tecla para regressar ao menu...");
																	getch();
																	break;
																case 4:
																	system("cls");
																	
																	
																	printf("\t\tInsira o Geocodigo onde pretende adicionar: ");
																	scanf("%s", geocodigo);

																	printf("\t\tInsira o codigo do cliente: ");
																	scanf("%d", &codigo);

																	aux = inserirClienteGrafo(mapa, geocodigo, codigo);
																	
																		if(aux == 1) printf("\n\t\tInserido com sucesso!");
																		else printf("\n\t\tErro ao inserir! Geocodigo inexistente ou cliente ja existe!");

																	printf("\n\n\tPressione qualquer tecla para regressar ao menu...");
																	getch();
																	break;
																case 5:
																	system("cls");
																	
																	printf("\t\tInsira o Geocodigo que pretende remover: ");
																	scanf("%s", geocodigo);

																	eliminarVertice(&mapa, geocodigo);
																	printf("\n\t\tRemovido com sucesso!");

																	printf("\n\n\tPressione qualquer tecla para regressar ao menu...");
																	getch();
																	break;
																case 6:
																	system("cls");
																	
																	printf("\t\tInsira o Geocodigo da origem: ");
																	scanf("%s", verticeO); 
																	
																	printf("\t\tInsira o Geocodigo do destino: ");
																	scanf("%s", verticeD);

																	eliminarAresta(mapa, verticeO, verticeD); 
																	printf("\n\t\tRemovido com sucesso!");


																	printf("\n\n\tPressione qualquer tecla para regressar ao menu...");
																	getch();
																	break;
																case 7:
																	system("cls");
																	
																	printf("\t\tInsira o Geocodigo onde pretende remover: ");
																	scanf("%s", geocodigo);

																	printf("\t\tInsira o codigo do meio: ");
																	scanf("%d", &codigo);

																	removerMeioDoVertice(mapa, geocodigo, codigo);
																	printf("\n\t\tRemovido com sucesso!");

																	printf("\n\n\tPressione qualquer tecla para regressar ao menu...");
																	getch();
																	break;
																case 8:
																	system("cls");
																	
																	printf("\t\tInsira o Geocodigo onde pretende remover: ");
																	scanf("%s", geocodigo);

																	
																	printf("\t\tInsira o codigo do cliente: ");
																	scanf("%d", &codigo);

																	removerClienteDoVertice(mapa, geocodigo, codigo);
																	printf("\n\t\tRemovido com sucesso!");

																	printf("\n\n\tPressione qualquer tecla para regressar ao menu...");
																	getch();
																	break;
																case 9:
																	system("cls");
																	
																	listarVertices(mapa); 

																	printf("\n\n\tPressione qualquer tecla para regressar ao menu...");
																	getch();
																	break;
																case 10:
																	system("cls");

																	printf("\t\tInsira o Geocodigo : ");
																	scanf("%s", geocodigo);
																	printf("\n");

																	system("cls");
																	printf("|Geocodigo %s:\n\n", geocodigo);

																	listarAdjacentes(mapa, geocodigo);
																
																	printf("\n\n\tPressione qualquer tecla para regressar ao menu...");
																	getch();
																	break;
																case 11:
																	system("cls");
																	
																	printf("\t\tInsira o Geocodigo : ");
																	scanf("%s", geocodigo);
																	
																	system("cls");

																	listarMeiosPorGeocodigo(mapa, geocodigo);

																	printf("\n\n\tPressione qualquer tecla para regressar ao menu...");
																	getch();
																	break;
																case 12:
																	system("cls");

																	printf("\t\tInsira o Geocodigo : ");
																	scanf("%s", geocodigo);
																	system("cls");

																	listarClientesPorGeocodigo(mapa, geocodigo);

																	printf("\n\n\tPressione qualquer tecla para regressar ao menu...");
																	getch();
																	break;
																case 13:
																	system("cls");
																	
																	caixeiroViajante(mapa);

																	printf("\n\n\tPressione qualquer tecla para regressar ao menu...");
																	getch();
																	break;
																case 14:
																	system("cls");
																	
																	guardaVertices(mapa);
																	guardaArestas(mapa);
																	guardaClientesGrafo(mapa);
																	guardaMeiosGrafo(mapa);
																	guardarMeios(meio); 
																	guardarClientes(cliente); 
																	guardarGestores(gestor); 
																	guardarBinario(mapa);

																	exit(0);
																	break;
																default:
																	system("cls");
																	printf("\n\t\tEscolha inexistente!\n");
																	printf("\t\tPressione qualquer tecla para regressar ao menu...");
																	getch();
																	break;
																}
									} while (escolha3 != 14);
									 break;
									
								case 14:
									system("cls");

									guardarMeios(meio); 
									guardarClientes(cliente); 
									guardarGestores(gestor); 
									guardarBinario(mapa);

									exit(0);
									break;
								default:
									system("cls");
									printf("\n\t\tEscolha inexistente!\n");
									printf("\t\tPressione qualquer tecla para regressar ao menu...");
									getch();
									break;
								}
			} while (escolha1 != 14);
			break;
		case 2:
			do {
			system("cls");
			escolha2 = menuCliente();

								switch (escolha2)
								{
								case 1:
									system("cls");

									printf("\t|Insira o seu codigo:");
									scanf("%d", &codigo);

									verificarCliente(cliente, codigo);

									printf("\n\t\tPressione qualquer tecla para regressar ao menu...");
									getch();
								break;
								case 2:
									system("cls");

									printf("\t|Insira o seu codigo:");
									scanf("%d", &codigo);

									verificarSaldo(cliente, codigo);

									printf("\n\t\tPressione qualquer tecla para regressar ao menu...");
									getch();
									break;
								case 3:
									system("cls");


									printf("\t|Insira o seu codigo:");
									scanf("%d", &codigo);

									adicionarSaldo(cliente, codigo); 


									printf("\n\t\tPressione qualquer tecla para regressar ao menu...");
									getch();
									break;
								case 4:
									system("cls");
									
									printf("\t|Insira o seu codigo:");
									scanf("%d", &codigo);

									aluguerMeio(meio, codigo); 

									printf("\n\n\n\tPressione qualquer tecla para regressar ao menu...");
									getch();
									break;
								case 5:
									system("cls");

									listarMeios(meio); 

									printf("\n\n\tPressione qualquer tecla para regressar ao menu...");
									getch();
									break;
								case 6:
									system("cls");

									printf("\n\t| Insira o geocodigo da localizacao: ");
									scanf("%s", geocodigo);

									localizarMeios(meio, geocodigo);


									printf("\n\n\t\tPressione qualquer tecla para regressar ao menu...");
									getch();
									break;
								case 7:
									system("cls");

									printf("\n\t| Insira o seu codigo: ");
									scanf("%d", &codigo); 
									printf("\n\t| Insira o tipo do meio que pretende: ");
									scanf("%s", tipo);
									printf("\n\t| Insira a distancia maxima a que se pode econtrar o meio (metros): ");
									scanf("%f", &raio); 

									MeiosNumRaio(mapa, codigo, tipo, raio); 

									printf("\n\n\t\tPressione qualquer tecla para regressar ao menu...");
									getch();
									break;
								case 8:
									system("cls");

									guardarMeios(meio); 
									guardarClientes(cliente); 
									guardarGestores(gestor); 
									guardarBinario(mapa);

									exit(0);
								default:
									system("cls");
									printf("\n\t\tEscolha inexistente!\n");
									printf("\t\tPressione qualquer tecla para regressar ao menu...");
									getch();
								break;
								}
			} while (escolha1 != 8);
			break;
		case 3:
			system("cls");
			exit(0);
			break;
		default:
			system("cls");
			printf("\n\t\tEscolha inexistente!\n");
			printf("\t\tPressione qualquer tecla para regressar ao menu...");
			getch();
			break;
		}

	} while (escolha1 != 3);

return 0;


}