#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Header_Files/menu.h"
#include "../Header_Files/meio.h"
#include "../Header_Files/gestor.h"
#include "../Header_Files/cliente.h"
#include "../Header_Files/grafo.h"


//Função responsável por criar os vértices do grafo (que vão ser os geocódigos)
int criarVertice(Grafo *mapa, char geocodigo[]) {
    
    if (existeVertice(*mapa, geocodigo) == 1) {
        return 0; 
    }
    
    Grafo novo = malloc(sizeof(struct registo1));
        
        if (novo!=NULL) {
            strcpy(novo->vertice, geocodigo);

            novo->Adjacentes = NULL;
            novo->Meios = NULL;
            novo->Clientes = NULL;

            novo->seguinte = *mapa;
            *mapa = novo;

        return(1);
        }
 
        else return(0);
}

// Função que verifica se o vértice já existe ou não, devolve 1 se o vertice existe no grafo ou 0 caso contrário
int existeVertice(Grafo mapa, char vertice[]) { 
    
    while (mapa!=NULL) { 
        
        if (strcmp(mapa->vertice,vertice) == 0) return(1);
        else mapa=mapa->seguinte;
    }
    return(0);
}

//Função responsável por criar as arestas do grafo (distância entre os geocódigos)
int criarAresta(Grafo mapa, char vOrigem[], char vDestino[], float distancia) {
    
    Adjacente novo;
        if (existeVertice(mapa,vOrigem) && existeVertice(mapa,vDestino)) {

            while(strcmp(mapa->vertice,vOrigem)!=0) mapa=mapa->seguinte;
             novo = malloc(sizeof(struct registo1));
        if (novo!=NULL) {
            strcpy(novo->vertice,vDestino);
	        novo->distancia = distancia;
	        novo->seguinte = mapa->Adjacentes;
	        mapa->Adjacentes=novo;
	    return(1);
	    }
        else return(0);
        }
        else return(0);
}

// Função responsável por listar os vertices adjacentes de um vértice
void listarAdjacentes(Grafo mapa, char vertice[]) {

    Adjacente aux;
         if (existeVertice(mapa,vertice)){
            
            while (strcmp(mapa->vertice,vertice)!=0) mapa=mapa->seguinte;
                aux = mapa->Adjacentes;

                while (aux!=NULL) {
                    printf("\t\t|Adjacente: %s    |Distancia: %.2f metros\n", aux->vertice, aux->distancia);
                    aux=aux->seguinte;
                }
            }
}

//Função quer permite listar todos os vértices do grafo (respetivo geocodigo)
void listarVertices(Grafo mapa) {

    while (mapa != NULL) {
        printf("\t\t|Geocodigo: %s\n", mapa->vertice);
        mapa = mapa->seguinte;
    }
}

//Função responsável por ler os vértices que se econtram no ficheiro de texto "Vertice.txt" e adiciona-los ao grafo
Grafo lerVertices(Grafo mapa) {

    FILE* fp;

	char geocodigo[150];

	fp = fopen("Text_Files/Vertices.txt", "r");

	if (fp != NULL) {

		while (!feof(fp)) {

			fscanf(fp, "%s", geocodigo); 
			criarVertice(&mapa, geocodigo);
		}

		fclose(fp);
	}
	else printf("\t\tErro ao abrir o ficheiro Vertices!\n");

	return(mapa);
}

//Função responsável por ler as arestas que se econtram no ficheiro de texto "Arestas.txt" e adiciona-los ao grafo
Grafo lerArestas(Grafo mapa) {

    FILE* fp;

	char origem[150], destino[150];
    float distancia; 

	fp = fopen("Text_Files/Arestas.txt", "r");

	if (fp != NULL) {

		while (!feof(fp)) {

			fscanf(fp, "%[^;];%[^;];%f\n", origem, destino, &distancia); 

			criarAresta(mapa, origem, destino, distancia);
		}

		fclose(fp);
	}
	else printf("\t\tErro ao abrir o ficheiro Arestas!\n");

	return(mapa);
}

// Função responsável por guardar os dados sobre os vértices no ficheiro de texto "Vertices.txt"
void guardaVertices(Grafo mapa){

    FILE* fp;

	    fp = fopen("Text_Files/Vertices.txt", "w");

	        if (fp != NULL) {

		        while (mapa != NULL)
		        {
			        fprintf(fp, "%s\n", mapa->vertice);
			        mapa = mapa->seguinte;
		        }

		fclose(fp);
        
	        }
	        else printf("\tErro ao guardar dados!");
} 

// Função responsável por guardar os dados sobre os vértices no ficheiro de texto "Arestas.txt"
void guardaArestas(Grafo mapa){

    FILE* fp;
    fp = fopen("Text_Files/Arestas.txt", "w");

    if (fp != NULL) {
        Adjacente adjacente;

        while (mapa != NULL) {
            adjacente = mapa->Adjacentes;

            while (adjacente != NULL) {
                fprintf(fp, "%s;%s;%.2f\n", mapa->vertice, adjacente->vertice, adjacente->distancia);
                adjacente = adjacente->seguinte;
            }

            mapa = mapa->seguinte;
        }

        fclose(fp);
    } else {
        printf("\tErro ao guardar o ficheiro Arestas!\n");
    }
}

// Função que permite eliminar um vértice do grafo(gecódigo)
void eliminarVertice(Grafo *mapa, char geocodigo[]) {

    if (*mapa == NULL) {
        return;
    }

    Grafo atual = *mapa;
    Grafo anterior = NULL;

    // Verifica se o vértice a ser eliminado é o primeiro do grafo
    if (strcmp(atual->vertice, geocodigo) == 0) {
        *mapa = atual->seguinte;
        free(atual);
        return;
    }

    // Percorre o grafo para encontrar o vértice a ser eliminado
    while (atual != NULL) {
        if (strcmp(atual->vertice, geocodigo) == 0) {
            anterior->seguinte = atual->seguinte;
            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->seguinte;
    }
}

// Função que permite eliminar uma aresta do grafo
void eliminarAresta(Grafo mapa, char vOrigem[], char vDestino[]) {

    while (mapa != NULL) {

        if (strcmp(mapa->vertice, vOrigem) == 0) {

            Adjacente atual = mapa->Adjacentes;
            Adjacente anterior = NULL;

                while (atual != NULL) {

                  if (strcmp(atual->vertice, vDestino) == 0) {
                        if (anterior == NULL) {
                        mapa->Adjacentes = atual->seguinte;
                        } else {
                        anterior->seguinte = atual->seguinte;
                        }

                    free(atual);
                    return;
                    }

                anterior = atual;
                atual = atual->seguinte;
            }

            return;
        }

        mapa = mapa->seguinte;
    }
}

// Função para inserir um meio num determinado geocodigo(Vertice do Grafo)
int inserirMeioGrafo(Grafo mapa, char geocodigo[], int codigoMeio, char tipo[], float custo, int bateria, float volume) {

    if (existeMeioGrafo(mapa, codigoMeio) == 1) {
    return 0;
}

    while ((mapa != NULL)&&(strcmp(mapa->vertice,geocodigo)!=0))
	    mapa = mapa->seguinte; 

            if (mapa == NULL) return(0);
            else {MeioG novo = malloc(sizeof(struct registo3));
                novo->codigo = codigoMeio;
                strcpy(novo->tipo, tipo);
                novo->custo = custo;
                novo->bateria = bateria;
                novo->volume = volume; 
                novo->seguinte = mapa->Meios;
                mapa->Meios = novo;
            return(1);	 
    }
    return 0;
}

// Função que lista os codigos dos meios num determinado geocodigo(Vertice do Grafo)
void listarMeiosPorGeocodigo(Grafo mapa, char geocodigo[]) {

    while (mapa != NULL) {

        if (strcmp(mapa->vertice, geocodigo) == 0) {
            MeioG meio = mapa->Meios;

            if (meio == NULL) {
                printf("Nenhum meio neste geocodigo %s!\n", geocodigo);
            } else {
                
                printf("|Meios em %s:\n\n", geocodigo);
                while (meio != NULL) {
                    printf("\t\t|Codigo do meio: %d  |Tipo: %s  |Custo: %.2f$  |Bateria: %d  |Volume: %.2f |\n", meio->codigo, meio->tipo, meio->custo, meio->bateria, meio->volume);
                    meio = meio->seguinte;
                }
            }
            return;
        }
        mapa = mapa->seguinte;
    }
    printf("Geocodigo %s nao encontrado !\n", geocodigo);
}

// Função que permite remover um meio de um determinado geocodigo(Vertice do mapa)
void removerMeioDoVertice(Grafo mapa, char geocodigo[], int codigoMeio) {

    while (mapa != NULL) {

        if (strcmp(mapa->vertice, geocodigo) == 0) {

            MeioG meio = mapa->Meios;
            MeioG anterior = NULL;

            while (meio != NULL) {

                if (meio->codigo == codigoMeio) {

                    if (anterior == NULL) {
                        mapa->Meios = meio->seguinte;
                    } else {
                        anterior->seguinte = meio->seguinte;
                    }

                    free(meio);

                    return;
                }

                anterior = meio;
                meio = meio->seguinte;
            }
            return;
        }
        mapa = mapa->seguinte;
    }
}

// Função para inserir um cliente num determinado geocodigo(Vertice do Grafo)
int inserirClienteGrafo(Grafo mapa, char geocodigo[], int codigoCliente) {

if (existeClienteGrafo(mapa, codigoCliente) == 1) {
    return 0; 
}
    while ((mapa != NULL)&&(strcmp(mapa->vertice,geocodigo)!=0))
	    mapa = mapa->seguinte; 

            if (mapa == NULL) return(0);
            else {ClienteG novo = malloc(sizeof(struct registo4));
                novo->codigo = codigoCliente;
                novo->seguinte = mapa->Clientes;
                mapa->Clientes = novo;
            return(1);	 
    }
}

// Função que lista os codigo dos clientes num determinado geocodigo(Vertice do Grafo)
void listarClientesPorGeocodigo(Grafo mapa, char geocodigo[]) {

    while (mapa != NULL) {

        if (strcmp(mapa->vertice, geocodigo) == 0) {
            ClienteG cliente = mapa->Clientes;

            if (cliente == NULL) {
                printf("Nenhum cliente neste geocodigo %s!\n", geocodigo);
            } else {
                
                printf("|Clientes em %s:\n\n", geocodigo);

                while (cliente != NULL) {
                    printf("\t\t|Codigo do cliente: %d\n", cliente->codigo); 
                    cliente = cliente->seguinte;
                }
            }
            return;
        }
        mapa = mapa->seguinte;
    }
    printf("Geocodigo %s não encontrado !\n", geocodigo);
}

// Função que permite remover um cliente de um determinado geocodigo(Vertice do mapa)
void removerClienteDoVertice(Grafo mapa, char geocodigo[], int codigoCliente) {

    while (mapa != NULL) {

        if (strcmp(mapa->vertice, geocodigo) == 0) {
            ClienteG cliente = mapa->Clientes;
            ClienteG anterior = NULL;

            while (cliente != NULL) {
                if (cliente->codigo == codigoCliente) {
                    if (anterior == NULL) {
                        mapa->Clientes = cliente->seguinte;
                    } else {
                        anterior->seguinte = cliente->seguinte;
                    }

                    free(cliente);
                    return;
                }

                anterior = cliente;
                cliente = cliente->seguinte;
            }
            return;
        }
        mapa = mapa->seguinte;
    }

}

// Função responsável por ler os codigos dos meios que se encontram num geocodigo, no ficheiro de texto "GrafosMeios.txt"
Grafo lerMeiosGrafo(Grafo mapa){

    FILE* fp;

	char geocodigo[150], tipo[60];
    int codigo, bateria;  
    float custo, volume;

	fp = fopen("Text_Files/GrafoMeios.txt", "r");

	if (fp != NULL) {

		while (!feof(fp)) {

			fscanf(fp, "%[^;];%d;%[^;];%f;%d;%f\n", geocodigo, &codigo, tipo, &custo, &bateria, &volume);  

			inserirMeioGrafo(mapa, geocodigo, codigo, tipo, custo, bateria, volume);
		}

		fclose(fp);
	}
	else printf("\t\tErro ao abrir o ficheiro GrafosMeios!\n");

	return(mapa);
}


// Função responsável por ler os codigos dos clientes que se encontram num geocodigo, no ficheiro de texto "GrafoClientes.txt"
Grafo lerClientesGrafo(Grafo mapa){

    FILE* fp;

	char geocodigo[150];
    int codigo;  

	fp = fopen("Text_Files/GrafoClientes.txt", "r");

	if (fp != NULL) {

		while (!feof(fp)) {

			fscanf(fp, "%[^;];%d\n", geocodigo, &codigo);  

			inserirClienteGrafo(mapa, geocodigo, codigo);
		}

		fclose(fp);
	}
	else printf("\t\tErro ao abrir o ficheiro GrafosClientes!\n");

	return(mapa);
}

// Função responsável por guardar a informação dos meios que se econtram presentes num geocodigo(vertice do grafo) no ficheiro de texto "GrafoMeios"
void guardaMeiosGrafo(Grafo mapa){

    FILE* fp;
    fp = fopen("Text_Files/GrafoMeios.txt", "w");

    if (fp != NULL) {
        MeioG meio;

        while (mapa != NULL) {
            meio = mapa->Meios;

            while (meio != NULL) {
                fprintf(fp, "%s;%d;%s;%.2f;%d;%.2f\n", mapa->vertice, meio->codigo, meio->tipo, meio->custo, meio->bateria, meio->volume);
                meio = meio->seguinte;
            }

            mapa = mapa->seguinte;
        }

        fclose(fp);
    } else {
        printf("\tErro ao guardar o ficheiro GrafoMeios!\n");
    }
}

// Função responsável por guardar a informação dos clientes que se econtram presentes num geocodigo(vertice do grafo) no ficheiro de texto "GrafoClientes"
void guardaClientesGrafo(Grafo mapa){

    FILE* fp;
    fp = fopen("Text_Files/GrafoClientes.txt", "w");

    if (fp != NULL) {
        ClienteG cliente; 

        while (mapa != NULL) {
            cliente = mapa->Clientes;

            while (cliente != NULL) {
                fprintf(fp, "%s;%d\n", mapa->vertice, cliente->codigo);
                cliente = cliente->seguinte;
            }

            mapa = mapa->seguinte;
        }

        fclose(fp);
    } else {
        printf("\tErro ao guardar o ficheiro GrafoClientes!\n");
    }
}

// Função que verifica se o meio já existe, devolve 1 se existe no grafo ou 0 caso contrário
int existeMeioGrafo(Grafo mapa, int codigo){

     while (mapa != NULL) {
        MeioG meio = mapa->Meios;
        while (meio != NULL) {
            if (meio->codigo == codigo) {
                return 1;  // Meio encontrado, retorna 1
            }
            meio = meio->seguinte;
        }
        mapa = mapa->seguinte;
    }
    return 0;  // Meio não encontrado, retorna 0
}

// Função que verifica se o cliente já existe, devolve 1 se existe no grafo ou 0 caso contrário *
int existeClienteGrafo(Grafo mapa, int codigo){

    while (mapa != NULL) {
        ClienteG cliente = mapa->Clientes;
        while (cliente != NULL) {
            if (cliente->codigo == codigo) {
                return 1;  // Cliente encontrado, retorna 1
            }
            cliente = cliente->seguinte;
        }
        mapa = mapa->seguinte;
    }
    return 0;  // Cliente não encontrado, retorna 0
}


// Função que ao utilizador inserir o seu codigo, e o tipo de meio, lista os meios existentes nesse geocodigo e nos adjancentes e a distancia a que se encontram
int MeiosNumRaio(Grafo mapa, int codigo, char tipo[], float raio) {
    Grafo vertice = mapa;

    // Localiza o vértice onde o cliente se encontra
    while (vertice != NULL) {
        ClienteG cliente = vertice->Clientes;

        while (cliente != NULL) {

            if (cliente->codigo == codigo) {
                break;
            }
            cliente = cliente->seguinte;
        }

        if (cliente != NULL) {
            break;
        }

        vertice = vertice->seguinte;
    }

    // Se percorrer todos os vértices e não encontrar aquele cliente associado a um geocódigo, apresenta a seguinte mensagem para o utilizador e retorna 0
    if (vertice == NULL) {
        printf("\n\n\n\t\tCodigo de cliente inexistente ou invalido!\n");
        return 0;
    }

    system("cls");
    printf("> Meios disponiveis(na sua localizacao): \n\n");

    // Verifica os meios no geocódigo onde o cliente está localizado
    MeioG meio = vertice->Meios;

    while (meio != NULL) {
        if (strcmp(meio->tipo, tipo) == 0) {
            printf("\t|Codigo: %d   | Tipo: %s   | Custo: %.2f $  | Bateria: %d  | Distancia: 0 metros\n", meio->codigo, meio->tipo, meio->custo, meio->bateria);
        }
        meio = meio->seguinte;
    }

    printf("\n\n> Meios disponiveis(distantes): \n\n");

    // Verifica os vértices adjacentes ao vertice onde o cliente se localiza
    Adjacente adjacente = vertice->Adjacentes;

    while (adjacente != NULL) {
        Grafo adjacenteVertice = mapa;

        // Localiza o vértice adjacente
        while (adjacenteVertice != NULL && strcmp(adjacenteVertice->vertice, adjacente->vertice) != 0) {
            adjacenteVertice = adjacenteVertice->seguinte;
        }

        if (adjacenteVertice != NULL) {

            // Verifica os meios que se econtram no vértice adjacente
            MeioG meioAdjacente = adjacenteVertice->Meios;

            while (meioAdjacente != NULL) {

                // Imprime os meios que sejam do tipo que o utilizado quer, e no raio ( distancia em metros) que ele escolheu 
                if (strcmp(meioAdjacente->tipo, tipo) == 0 && adjacente->distancia <= raio) {
                    printf("\t|Codigo: %d  | Tipo: %s  | Custo: %.2f $ | Bateria: %d | Distancia: %.2f metros\n",  meioAdjacente->codigo, meioAdjacente->tipo, meioAdjacente->custo, 
                    meioAdjacente->bateria, adjacente->distancia);
                }
                meioAdjacente = meioAdjacente->seguinte;
            }
        }

        adjacente = adjacente->seguinte;
    }
}


// Função que calcula o trajeto mais curto para um camião fazer a recolha de todos os meios com carga de bateria < 50%, o ponto de partida e chegada é o mesmo
int caixeiroViajante(Grafo mapa) {


    int maxBateria = 50 ;

    // volume máximo do camião vai ser 500
    float volumeCamiao = 0;
    
    Grafo geocodigos = mapa;

    printf("Meios para recolha pelo camiao: \n\n");

            // Percorrer os geocodigos do grafo
            while (geocodigos != NULL) {

                 MeioG meio = geocodigos->Meios;

                // Percorre os meios associados a cada geocodigo 
                while (meio != NULL){ 

                        // Verifica se o meio tem bateria inferior a 50% , e se ao o adicionar ao camiao nao excede o seu volume máximo (500)
                        if (meio->bateria <= maxBateria && (volumeCamiao + meio->volume) <= 500){ 
                            
                            printf("\t|Codigo: %d   |Volume: %.2f   |Localizacao (geocodigo): %s\n", meio->codigo, meio->volume, geocodigos->vertice);

                            // atualiza o volume ocupado pelo camiao
                            volumeCamiao = volumeCamiao + meio->volume;
                        }

                meio = meio->seguinte;
                }

            geocodigos = geocodigos->seguinte;   
            }

    printf("\n\nPercurso mais curto para recolha dos meios: ");
     
    return 0;
}

// Função responsável por guardar os dados sobre os vértices no ficheiro "Binario.bin" em binario
void guardarBinario(Grafo mapa){

  FILE* fp;

    fp = fopen("Text_Files/Binario.bin", "wb");

    if (fp != NULL) {

        while (mapa != NULL) {

            fwrite(mapa->vertice, sizeof(char), strlen(mapa->vertice), fp);
            fwrite("\n", sizeof(char), 1, fp);
            mapa = mapa->seguinte;
        }

        fclose(fp);

    } else printf("Erro ao guardar dados!");
} 