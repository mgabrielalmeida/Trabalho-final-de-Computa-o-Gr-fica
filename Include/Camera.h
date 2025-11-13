#pragma once

#include "Vetor3.h"
#include "Raio.h"

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
    Camera(Ponto3 pos, Ponto3 o, Vetor3 dim, int nL, int nC);

    Raio raioParaPonto(int x, int y);
};