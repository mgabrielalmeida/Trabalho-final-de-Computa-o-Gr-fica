#pragma once

#include "Core/Vetor3.h"
#include "Core/Raio.h"

class Camera{
public:
    Ponto3 posicao;
    Ponto3 olhando_para;
    Vetor3 dimensoes_janela;
    int nLinhas;
    int nColunas;

    float Dx, Dy;

    Vetor3 eixoX, eixoY, eixoZ;

    Camera();
    Camera(Ponto3 posicao, Ponto3 olhando_para, Vetor3 dimensoes_janela, int nL, int nC);

    Raio raioParaPonto(int x, int y);
};