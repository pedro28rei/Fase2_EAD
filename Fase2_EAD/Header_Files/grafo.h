#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Struct para representar o grafo (os vértices vão ser o geocódgio da zona)
typedef struct registo1{
    char vertice[150];
    struct registo2 *Adjacentes; 
    struct registo3 *Meios;
    struct registo4 *Clientes; 
    struct registo1 *seguinte;
} *Grafo; 

//Struct para os vertice adjacentes e a distância a que se encontram
typedef struct registo2
{
    char vertice[150];
    float distancia; 
    struct registo2 *seguinte;
} *Adjacente; 

//Struct para representar os meios no grafo 
typedef struct registo3{
    int codigo;
    char tipo[60];
    float custo; 
    int bateria; 
    float volume;
    struct registo3 *seguinte;
} * MeioG;

//Struct para representar os clientes no grafo 
typedef struct registo4{
    int codigo;
    struct registo4 *seguinte;
} * ClienteG;  


//Função responsável por criar os vértices do grafo (que vão ser os geocódigos)
int criarVertice(Grafo *mapa, char geocodigo[]);

//Função que verifica se o vértice já existe ou não, devolve 1 se o vertice existe no grafo ou 0 caso contrário
int existeVertice(Grafo mapa, char vertice[]);

//Função responsável por criar as arestas do grafo (distância entre os geocódigos)
int criarAresta(Grafo mapa, char vOrigem[], char vDestino[], float distancia);  

//Função responsável por ler os vértices que se econtram no ficheiro de texto "Vertice.txt" e adiciona-los ao grafo
Grafo lerVertices(Grafo mapa);  

//Função responsável por ler as arestas que se econtram no ficheiro de texto "Arestas.txt" e adiciona-las ao grafo
Grafo lerArestas(Grafo mapa);  

//Função responsável por listar os vertices do grafo
void listarVertices(Grafo mapa);

//Função responsável por listar os vertices adjacentes de um vértice
void listarAdjacentes(Grafo mapa, char vertice[]);

// Função responsável por guardar os dados sobre os vértices no ficheiro de texto "Vertices.txt"
void guardaVertices(Grafo mapa);

// Função responsável por guardar os dados sobre os vértices no ficheiro de texto "Arestas.txt"
void guardaArestas(Grafo mapa);

// Função que permite eliminar um vértice do grafo(gecódigo)
void eliminarVertice(Grafo *mapa, char geocodigo[]);

// Função que permite eliminar uma aresta do grafo
void eliminarAresta(Grafo mapa, char vOrigem[], char vDestino[]);

// Função para inserir um meio num determinado geocodigo(Vertice do Grafo)
int inserirMeioGrafo(Grafo mapa, char geocodigo[], int codigoMeio, char tipo[], float custo, int bateria, float volume);

// Função que lista os meios num determinado geocodigo(Vertice do Grafo)
void listarMeiosPorGeocodigo(Grafo mapa, char geocodigo[]);

// Função que permite remover um meio de um determinado geocodigo(Vertice do mapa)
void removerMeioDoVertice(Grafo mapa, char geocodigo[], int codigoMeio);

// Função para inserir um cliente num determinado geocodigo(Vertice do Grafo)
int inserirClienteGrafo(Grafo mapa, char geocodigo[], int codigoCliente);

// Função que lista os codigo dos clientes num determinado geocodigo(Vertice do Grafo)
void listarClientesPorGeocodigo(Grafo mapa, char geocodigo[]);

// Função que permite remover um cliente de um determinado geocodigo(Vertice do mapa)
void removerClienteDoVertice(Grafo mapa, char geocodigo[], int codigoCliente); 

// Função responsável por ler os codigos dos meios que se encontram num geocodigo, no ficheiro de texto "GrafoMeios.txt"
Grafo lerMeiosGrafo(Grafo mapa);
 
// Função responsável por ler os codigos dos clientes que se encontram num geocodigo, no ficheiro de texto "GrafoClientes.txt"
Grafo lerClientesGrafo(Grafo mapa); 

// Função responsável por guardar a informação dos meios que se econtram presentes num geocodigo(vertice do grafo) no ficheiro de texto "GrafoMeios"
void guardaMeiosGrafo(Grafo mapa);

// Função responsável por guardar a informação dos clientes que se econtram presentes num geocodigo(vertice do grafo) no ficheiro de texto "GrafoClientes"
void guardaClientesGrafo(Grafo mapa);

// Função que verifica se o meio já existe, devolve 1 se existe no grafo ou 0 caso contrário
int existeMeioGrafo(Grafo mapa, int codigo);

// Função que verifica se o cliente já existe, devolve 1 se existe no grafo ou 0 caso contrário *
int existeClienteGrafo(Grafo mapa, int codigo);

// Função que ao utilizador inserir o seu codigo, e o tipo de meio, lista os meios existentes nesse geocodigo e nos adjancentes e a distancia a que se encontram
int MeiosNumRaio(Grafo mapa, int codigo, char tipo[], float raio);

// Função que calcula o trajeto mais curto para um camião fazer a recolha de todos os meios com carga de bateria < 50%, o ponto de partida e chegada é o mesmo
int caixeiroViajante(Grafo mapa); 

// Função responsável por guardar os dados sobre os vértices no ficheiro de texto "Binario.txt" em binario
void guardarBinario(Grafo mapa);