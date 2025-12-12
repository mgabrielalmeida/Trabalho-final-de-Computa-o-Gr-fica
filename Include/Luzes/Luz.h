#pragma once

#include "Core/Vetor3.h"

// Classe base para os outros tipos de luzes que teremos no futuro mas também serve como uma luz pontual
class Luz{
public:
    Ponto3 posicao;
    Cor3 intensidade;

    Luz() {}
    Luz(Ponto3 p, Cor3 i) : posicao(p), intensidade(i) {}

    using LuzPontual = Luz;
};