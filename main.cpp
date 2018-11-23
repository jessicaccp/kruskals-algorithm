#include<iostream>
#include"grafo.hpp"
#include"aresta.hpp"

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "Para executar o programa, execute ./programa nome-do-arquivo.tsp" << std::endl;
        exit(1);
    }

    Grafo grafo(argv[1]);
    grafo.criarGrafo();
    grafo.kruskal();

    return 0;
}