#ifndef ARESTA_HPP
#define ARESTA_HPP

class Aresta {
    private:
        int v1, v2, peso;

    public:
        Aresta(int v1, int v2, int peso);

        int getV1();
        int getV2();
        int getPeso();
};

#endif