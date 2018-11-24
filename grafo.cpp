#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include"grafo.hpp"

Grafo::Grafo(std::string arquivo) {
    this->arquivo = arquivo;
}

void Grafo::criarGrafo() {
    std::ifstream entrada(arquivo);
    std::string texto;
    int inteiro;

    if (entrada.is_open()) {
        std::cout << "Recebendo dados do arquivo..." << std::endl << std::endl;

        // Recebe nome
        entrada.ignore(100, ' ');
        entrada >> texto;
        setNome(texto);
        
        // Recebe comentario
        entrada.ignore(100, '\n');
        entrada.ignore(100, '\n');
        entrada.ignore(100, ' ');
        std::getline(entrada, texto);
        setComentario(texto);

        // Recebe dimensao
        entrada.ignore(100, ' ');
        entrada >> inteiro;
        setDimensao(inteiro);

        // Recebe formato
        entrada.ignore(100, '\n');
        entrada.ignore(100, '\n');
        entrada.ignore(100, ' ');
        entrada >> texto;
        setFormato(texto);

        // Recebe pesos das arestas para cada tipo de matriz
        entrada.ignore(100, '\n');
        entrada.ignore(100, '\n');

        // Matriz superior sem diagonal principal
        if (getFormato() == "UPPER_ROW") {
            for (int i = 0; i < getDimensao(); i++) {
                for (int j = i; j < getDimensao(); j++) {
                    if (i == j)
                        inteiro = 0;
                    else
                        entrada >> inteiro;
                    Aresta aresta(i, j, inteiro);
                    arestas.push_back(aresta);
                }
            }
        }

        // Matriz inferior com diagonal principal
        else if (getFormato() == "LOWER_DIAG_ROW") {
            for (int i = 1; i <= getDimensao(); i++) {
                for (int j = 1; j <= i; j++) {
                    entrada >> inteiro;
                    Aresta aresta(i - 1, j - 1, inteiro);
                    arestas.push_back(aresta);
                }
            }
        }

        else {
            std::cout << "Formato nao identificado." << std::endl;
            exit(1);
        }

        std::cout   << "Nome: " << getNome() << std::endl
                    << "Descricao: " << getComentario() << std::endl
                    << "Formato da matriz: " << getFormato() << std::endl << std::endl;

        std::cout << "Grafo criado." << std::endl << std::endl;
        entrada.close();
    }
    else {
        std::cout << "Erro ao ler o arquivo." << std::endl;
        exit(1);
    }
}

void Grafo::kruskal() {
    std::cout << "Executando o algoritmo de Kruskal..." << std::endl << std::endl;

    std::vector<Aresta> arvore;
    
    sort(arestas.begin(), arestas.end());

    int *subset = new int[getDimensao()];
    memset(subset, -1, sizeof(int) * getDimensao());

    for (int i = 0; i < arestas.size(); i++) {
        int v1 = buscar(subset, arestas[i].getV1()), v2 = buscar(subset, arestas[i].getV2());

        if (v1 != v2) {
            arvore.push_back(arestas[i]);
            unir(subset, v1, v2);
        }
    }

    std::cout << "AGM encontrada:" << std::endl << std::endl;

    for (int i = 0; i < arvore.size(); i++) {
        std::cout   << "(" << arvore[i].getV1() + 1 << ", " << arvore[i].getV2() + 1
                    << ") = " << arvore[i].getPeso() << std::endl;
    }
}

int Grafo::buscar(int subset[], int i) {
    if (subset[i] == -1) 
		return i; 
	return Grafo::buscar(subset, subset[i]); 
}

void Grafo::unir(int subset[], int v1, int v2) {
    int v1_set = buscar(subset, v1), v2_set = buscar(subset, v2);

    if (v1_set != v2_set)
        subset[v1_set] = v2_set;
}

std::string Grafo::getFormato() {
    return formato;
}

int Grafo::getDimensao() {
    return dimensao;
}

std::string Grafo::getNome() {
    return nome;
}

std::string Grafo::getComentario() {
    return comentario;
}

void Grafo::setNome(std::string nome) {
    this->nome = nome;
}

void Grafo::setComentario(std::string comentario) {
    this->comentario = comentario;
}

void Grafo::setFormato(std::string formato) {
    this->formato = formato;
}

void Grafo::setDimensao(int dimensao) {
    this->dimensao = dimensao;
}