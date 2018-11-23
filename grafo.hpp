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

        std::string getFormato();
        int getDimensao();

        void setNome(std::string nome);
        void setComentario(std::string comentario);
        void setFormato(std::string formato);
        void setDimensao(int dimensao);
};

#endif