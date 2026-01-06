#pragma once

#include "Core/Vetor3.h"
#include "Core/Raio.h"

class Camera{
public:
    Ponto3 posicao;
    Ponto3 olhando_para;

    float vfov; // ângulo de visão em graus
    float aspect_ratio; // razão entre largura e altura

    float alturaImagem; // as dimensões da imagem são calculadas baseado no vfov e no aspect_ratio
    float larguraImagem; 

    int nLinhas; // essa é dada no construtor
    int nColunas; // essa é calculada baseado no aspect_ratio, pra evitar quebrar a imagem
    // diz respeito ao número de píxels na imagem

    Ponto3 centro, primeiro_pixel; // coordenadas de alguns píxeis potencialmente importantes

    float Dx, Dy; // tamanho de cada píxel

    Vetor3 vup;
    Vetor3 eixoX, eixoY, eixoZ; // eixos ortonormais da câmera

    Camera();
    Camera(const Ponto3& posicao, const Ponto3& olhando_para, const Vetor3& vup, float vfov, float aspect_ratio, int numero_linhas);

    Raio raioParaPonto(int x, int y);
};