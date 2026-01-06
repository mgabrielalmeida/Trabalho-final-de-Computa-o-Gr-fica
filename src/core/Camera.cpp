#include "Core/Camera.h"

#include "Core/Vetor3.h"
#include "Core/Raio.h"

#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Camera::Camera() {}
Camera::Camera(const Ponto3& posicao, const Ponto3& olhando_para, const Vetor3& vup, float vfov, float aspect_ratio, int numero_linhas)
: posicao(posicao), olhando_para(olhando_para), vup(vup), vfov(vfov), aspect_ratio(aspect_ratio), nLinhas(numero_linhas) {

    // Definição dos parâmetros relativos à imagem final
    nColunas = int(nLinhas * aspect_ratio);

    float d = (posicao - olhando_para).comprimento();
    float theta = vfov * M_PI / 180.0; // ângulo do vfov em radianos
    alturaImagem = std::tan(theta/2);
    larguraImagem = alturaImagem * aspect_ratio;

    Dx = larguraImagem/nColunas;
    Dy = alturaImagem/nLinhas;

    // Cálculo dos vetores ortonormais com verificação de segurança para vup sugerido inadequado
    eixoZ = (posicao - olhando_para).normalizar(); 

    if(std::abs(prod_escalar(vup, eixoZ)) > 0.999f){        
        Vetor3 vup_alternativo = Vetor3(1, 0, 0);
        if (std::abs(prod_escalar(eixoZ, vup_alternativo)) > 0.999f){
            vup_alternativo = Vetor3(0, 0, 1);
        }
        eixoX = prod_vetorial(vup_alternativo, eixoZ).normalizar();
    }
    else eixoX = prod_vetorial(vup, eixoZ).normalizar();

    eixoY = prod_vetorial(eixoZ, eixoX);
    
}

Raio Camera::raioParaPonto(int x, int y){
    float u = -larguraImagem/2 + Dx/2 + x * Dx;
    float v = alturaImagem/2 - Dy/2 - y * Dy;

    Ponto3 coords = olhando_para + u * eixoX + v * eixoY;

    return Raio(posicao, coords - posicao);
}