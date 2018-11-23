#include"aresta.hpp"

Aresta::Aresta(int v1, int v2, int peso) {
    this->v1 = v1;
    this->v2 = v2;
    this->peso = peso;
}

int Aresta::getV1() {
    return v1;
}

int Aresta::getV2() {
    return v2;
}

int Aresta::getPeso() {
    return peso;
}

bool Aresta::operator < (const Aresta& aresta2) const {
	return (peso < aresta2.peso);
}