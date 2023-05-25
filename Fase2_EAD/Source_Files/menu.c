#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Header_Files/menu.h"
#include "../Header_Files/meio.h"
#include "../Header_Files/gestor.h"
#include "../Header_Files/cliente.h"
#include "../Header_Files/grafo.h"


//Funções para o menu do programa

int menuPerfil() {

    int escolha1;

    printf("\t\t _____________________________________\n");
    printf("\t\t|       Selecione o seu perfil:       |\n");
    printf("\t\t|_____________________________________|\n");
    printf("\t\t|                                     |\n");
    printf("\t\t|            1. Gestor                |\n");
    printf("\t\t|            2. Cliente               |\n");
    printf("\t\t|            3. Sair                  |\n");
    printf("\t\t|_____________________________________|\n");
    printf("\n\t\t| Insira a sua escolha: ");
    scanf("%d", &escolha1);

    return(escolha1);
}

int menuGestor() {

    int escolha2;

    printf("\t\t ________________________________________________\n");
    printf("\t\t|                     Menu:                      |\n");
    printf("\t\t|________________________________________________|\n");
    printf("\t\t| Escolha:                                       |\n");
    printf("\t\t|            1. Listar Clientes                  |\n");
    printf("\t\t|            2. Listar Gestores                  |\n");
    printf("\t\t|            3. Listar Meios                     |\n");
    printf("\t\t|            4. Inserir Cliente                  |\n");
    printf("\t\t|            5. Inserir Gestor                   |\n");
    printf("\t\t|            6. Inserir Meio                     |\n");
    printf("\t\t|            7. Remover Cliente                  |\n");
    printf("\t\t|            8. Remover Gestor                   |\n");
    printf("\t\t|            9. Remover Meio                     |\n");
    printf("\t\t|           10. Alterar Cliente                  |\n");
    printf("\t\t|           11. Alterar Gestor                   |\n");
    printf("\t\t|           12. Alterar Meio                     |\n");
    printf("\t\t|           13. Grafo dos Geocodigos             |\n");
    printf("\t\t|           14. Sair                             |\n");
    printf("\t\t|________________________________________________|\n");
    printf("\n\t\t| Insira a sua escolha: ");
    scanf("%d", &escolha2);


    return(escolha2);
}

int menuCliente() {

    int escolha2;

    printf("\t\t __________________________________________________________________________\n");
    printf("\t\t|                                Menu:                                     |\n");
    printf("\t\t|__________________________________________________________________________|\n");
    printf("\t\t| Escolha:                                                                 |\n");
    printf("\t\t|            1. Verificar dados pessoais                                   |\n");
    printf("\t\t|            2. Verificar saldo                                            |\n");
    printf("\t\t|            3. Adicionar  saldo                                           |\n");
    printf("\t\t|            4. Registo do aluguer de um determinado meio                  |\n");
    printf("\t\t|            5. Listagem dos meios por ordem decrescente de autonomia      |\n");
    printf("\t\t|            6. Listagem dos meios existentes num determinado local        |\n");
    printf("\t\t|            7. Listagem dos meios existentes num determinado raio         |\n");
    printf("\t\t|            8. Sair!                                                      |\n");
    printf("\t\t|__________________________________________________________________________|\n");
    printf("\n\t\t| Insira a sua escolha: ");
    scanf("%d", &escolha2);


    return(escolha2);
}

int menuGrafo() {

        int escolha3;

    printf("\t\t __________________________________________________________\n");
    printf("\t\t|                           Menu:                          |\n");
    printf("\t\t|__________________________________________________________|\n");
    printf("\t\t| Escolha:                                                 |\n");
    printf("\t\t|           1. Inserir Geocodigo(Vertice no Grafo)         |\n");
    printf("\t\t|           2. Inserir Ligacao(Aresta no Grafo)            |\n");
    printf("\t\t|           3. Inserir Meio num Geocodigo                  |\n");
    printf("\t\t|           4. Inserir Cliente num Geocodigo               |\n");
    printf("\t\t|           5. Remover Geocodigo(Vertice no Grafo)         |\n");
    printf("\t\t|           6. Remover Ligacao(Aresta no Grafo)            |\n");
    printf("\t\t|           7. Remover Meio num Geocodigo                  |\n");
    printf("\t\t|           8. Remover Cliente num Geocodigo               |\n");
    printf("\t\t|           9. Listar Geocodigos(Vertices do Grafo)        |\n");
    printf("\t\t|          10. Listar Ligacoes(Arestas do Grafo)           |\n");
    printf("\t\t|          11. Listar Meios num Geocodigo                  |\n");
    printf("\t\t|          12. Listar Clientes num Geocodigo               |\n");
    printf("\t\t|          13. Solucao do Caixeiro Viajante                |\n");
    printf("\t\t|          14. Sair!                                       |\n");
    printf("\t\t|__________________________________________________________|\n");
    printf("\n\t\t| Insira a sua escolha: ");
    scanf("%d", &escolha3);


    return(escolha3);
}