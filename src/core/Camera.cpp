#include "Camera.h"

#include "Vetor3.h"
#include "Raio.h"

Camera::Camera() {}
Camera::Camera(Ponto3 pos, Ponto3 o, Ponto3 dim, int nL, int nC)
: posicao(pos), olhando_para(o), dimensoes_janela(dim), nLinhas(nL), nColunas(nC) {

    Dx = dimensoes_janela.x/nColunas;
    Dy = dimensoes_janela.y/nLinhas;
}

Raio Camera::raioParaPonto(int x, int y){
    float u = -dimensoes_janela.x/2 + Dx/2 + x * Dx/2;
    float v = dimensoes_janela.y/2 - Dy/2 - y * Dy/2;

    Ponto3 coords = olhando_para + Vetor3(u, v, 0);

    return Raio(posicao, coords - posicao);
}