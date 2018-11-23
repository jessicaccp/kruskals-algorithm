#include<iostream>
#include<fstream>
#include<string>
#include"grafo.hpp"

Grafo::Grafo(std::string arquivo) {
    this->arquivo = arquivo;
}

void Grafo::criarGrafo() {
    std::ifstream entrada(arquivo);
    std::string texto;
    int inteiro;

    if (entrada.is_open()) {
        // Recebe nome
        entrada.ignore(100, ' ');
        entrada >> texto;
        setNome(texto);
        std::cout << "Lendo nome..." << std::endl;
        
        // Recebe comentario
        entrada.ignore(100, '\n');
        entrada.ignore(100, '\n');
        entrada.ignore(100, ' ');
        std::getline(entrada, texto);
        setComentario(texto);
        std::cout << "Lendo comentario..." << std::endl;

        // Recebe dimensao
        entrada.ignore(100, ' ');
        entrada >> inteiro;
        setDimensao(inteiro);
        std::cout << "Lendo dimensao..." << std::endl;

        // Recebe formato
        entrada.ignore(100, '\n');
        entrada.ignore(100, '\n');
        entrada.ignore(100, ' ');
        entrada >> texto;
        setFormato(texto);
        std::cout << "Lendo formato..." << std::endl;

        // Recebe pesos das arestas para cada tipo de matriz
        entrada.ignore(100, '\n');
        entrada.ignore(100, '\n');
        std::cout << "Lendo pesos..." << std::endl;

        // Matriz superior sem diagonal principal
        if (getFormato() == "UPPER_ROW") {
            for (int i = 1; i <= getDimensao(); i++) {
                for (int j = i; j <= getDimensao(); j++) {
                    if (i == j)
                        inteiro = 0;
                    else
                        entrada >> inteiro;
                    Aresta aresta(i, j, inteiro);
                    arestas.push_back(aresta);
                    if (i != j) {
                        Aresta aresta2(j, i, inteiro);
                        arestas.push_back(aresta2);
                    }
                }
            }
        }

        // Matriz inferior com diagonal principal
        else if (getFormato() == "LOWER_DIAG_ROW") {
            for (int i = 1; i <= getDimensao(); i++) {
                for (int j = 1; j <= i; j++) {
                    entrada >> inteiro;
                    Aresta aresta(i, j, inteiro);
                    arestas.push_back(aresta);
                    if (i != j) {
                        Aresta aresta2(j, i, inteiro);
                        arestas.push_back(aresta2);
                    }
                }
            }
        }

        else {
            std::cout << "Formato nao identificado" << std::endl;
            exit(1);
        }

        
        std::cout << "Grafo criado!" << std::endl;
        entrada.close();
    }
    else {
        std::cout << "Erro ao ler o arquivo" << std::endl;
        exit(1);
    }
}

std::string Grafo::getFormato() {
    return formato;
}

int Grafo::getDimensao() {
    return dimensao;
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