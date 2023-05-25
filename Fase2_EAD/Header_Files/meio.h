#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Struct para guardar informação sobre os meios
typedef struct meio {
    int codigo;
    char tipo[50];
    int bateria;
    float autonomia;
    float custo;
    int alugado;
    char geocodigo[150];
    float peso;
    float volume;
    struct meio* seguinte;
} Meio;


//Função que permite ler os dados no ficheiro "DadosMeios"
Meio* lerDadosMeios();

//Função que permite listar todos os meios
void listarMeios(Meio* meio);

//Função que permite inserir um meio
Meio* inserirMeio(Meio* inicioM, int codigo, char tipo[], int bateria, float autonomia, float custo, int alugado, char geocodigo[], float volume, float peso);

//Função para verificar se existe um meio
int existeMeio(Meio* inicioM, int codigo);

//Função que permite remover um meio
Meio* removerMeio(Meio* meio, int cod);

//Função que permite alterar os dados de um meio existente
void alterarMeio(Meio* meio);

//Função que permite alugar um meio
Meio* aluguerMeio(Meio* meio, int codigoC);   

//Função que permite lista todos os meios disponiveis em determinada localização
void localizarMeios(Meio* meio, char geocodigo[]);

//Função que guarda os dados dos meios no ficheiro "DadosMeios"
void guardarMeios(Meio* meio);
