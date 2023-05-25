#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Struct para guardar a informação sobre um gestor
typedef struct gestor {
    int codigo;
    char nome[60];
    int idade;
    int telemovel;
    char morada[60];
    struct gestor* seguinte;
} Gestor;


//Função que permite ler a informação do ficheiro de texto "DadosGestores"
Gestor* lerDadosGestores();

//Função que permite listar todos os gestores
void listarGestores(Gestor* gestor);

//Função que permite inserir um gestor
Gestor* inserirGestor(Gestor* inicioG, int codigo, char nome[], int idade, float telemovel, char morada[]);

//Função para verificar se existe um gestor
int existeGestor(Gestor* inicioG, int codigo);

//Função que permite remover um gestor
Gestor* removerGestor(Gestor* gestor, int cod);

//Função que permite alterar os dados de um gestor existente
void alterarGestor(Gestor* gestor);

//Função que guarda os dados dos gestores no ficheiro "DadosGestores"
void guardarGestores(Gestor* gestor);
