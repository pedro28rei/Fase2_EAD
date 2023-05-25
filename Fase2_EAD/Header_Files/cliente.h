#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Struct para guardar a informação sobre um cliente
typedef struct cliente {
    int codigo;
    char geocodigo[150];
    char nome[60];
    int idade;
    int telemovel;
    char morada[60];
    int nif;
    float saldo;
    struct cliente* seguinte;
} Cliente; 


//Função que permite listar todos os clientes
void listarClientes(Cliente* cliente);

//Função que permite ler os dados no ficheiro "DadosClientes"
Cliente* lerDadosClientes();

//Função que permite inserir um cliente
Cliente* inserirCliente(Cliente* inicioC, int codigo, char nome[], int idade, int telemovel, char morada[], int nif, float saldo, char geocodigo[]);

// Função para verificar se existe um cliente
int existeCliente(Cliente* inicioC, int codigo);

//Função que permite remover um cliente
Cliente* removerCliente(Cliente* cliente, int cod);

//Função que permite alterar os dados de um cliente existente
void alterarCliente(Cliente* cliente);

//Função que permite ao cliente ver os seus dados pessoais
int verificarCliente(Cliente* cliente, int codigo);

//Função que permite ao cliente ver o seu saldo
int verificarSaldo(Cliente* cliente, int codigo);

//Função que permite ao cliente adicionar saldo
Cliente* adicionarSaldo(Cliente* cliente, int codigo);

//Função que guarda os dados dos clientes no ficheiro "DadosClientes"
void guardarClientes(Cliente* cliente);