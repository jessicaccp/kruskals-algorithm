#ifndef GRAFO_HPP
#define GRAFO_HPP

#include<string>
#include<vector>
#include"aresta.hpp"

class Grafo {
    private:
        std::string nome, comentario, formato, arquivo;
        int dimensao;
        std::vector<Aresta> arestas;

    public:
        Grafo(std::string arquivo);

        void criarGrafo();
        void kruskal();
        int buscar(int subset[], int i);
        void unir(int subset[], int v1, int v2);

        std::string getFormato();
        int getDimensao();
        std::string getNome();
        std::string getComentario();

        void setNome(std::string nome);
        void setComentario(std::string comentario);
        void setFormato(std::string formato);
        void setDimensao(int dimensao);
};

#endif