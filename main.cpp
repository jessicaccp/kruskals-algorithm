#include<iostream>
#include"grafo.hpp"
#include"aresta.hpp"

int main(int argc, char** argv) {
    if (argc < 2)
        std::cout << "Para executar o programa, execute ./programa nome-do-arquivo.tsp" << std::endl;
    else {
        Grafo grafo(argv[1]);
        grafo.criarGrafo();
    }

    return 0;
}