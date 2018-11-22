#include<iostream>
#include<fstream>
#include<string>
#include"grafo.hpp"

Grafo::Grafo(std::string arquivo) {
    this->arquivo = arquivo;
}

void Grafo::criarGrafo() {
    std::ifstream entrada(arquivo);
    std::string auxiliar;

    if (entrada.is_open()) {
        // Recebe nome
        entrada.ignore(6, ' ');
        std::getline(entrada, auxiliar);
        setNome(auxiliar);
    }
    else {
        std::cout << "Erro ao ler o arquivo" << std::endl;
        exit(0);
    }
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

void Grafo::setArestas(std::vector<Aresta> arestas) {
    this->arestas = arestas;
}