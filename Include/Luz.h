#pragma once

#include "Vetor3.h"

class Luz{
public:
    Ponto3 posicao;
    Cor3 intensidade;

    Luz() {}
    Luz(Ponto3 p, Cor3 i) : posicao(p), intensidade(i) {}

    using LuzPontual = Luz;
};