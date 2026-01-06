#include "Core/Camera.h"

#include "Core/Vetor3.h"
#include "Core/Raio.h"

#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Camera::Camera() {}
Camera::Camera(Ponto3 posicao, Ponto3 olhando_para, float vfov, float aspect_ratio, int numero_linhas)
: posicao(posicao), olhando_para(olhando_para), vfov(vfov), aspect_ratio(aspect_ratio), nLinhas(numero_linhas) {

    nColunas = int(nLinhas * aspect_ratio);

    float d = (posicao - olhando_para).comprimento();
    float theta = vfov * M_PI / 180.0; // ângulo do vfov em radianos
    alturaImagem = std::tan(theta/2);
    larguraImagem = alturaImagem * aspect_ratio;

    Dx = larguraImagem/nColunas;
    Dy = alturaImagem/nLinhas;

    eixoZ = (posicao - olhando_para).normalizar(); 

    Vetor3 v_up_mundo = Vetor3(0, 1, 0);

    if (std::abs(eixoZ.y) > 0.999){
        // nesse caso, estamos olhando para cima (ou para baixo) quase perfeitamente
        Vetor3 v_up_temporario = Vetor3(0, 0, 1);
        
        // Se estivermos olhando reto para (0,0,1), o v_up_temp também falha,
        // então usamos (1,0,0) nesse caso extremo.
        if (std::abs(eixoZ.z) > 0.999) {
             v_up_temporario = Vetor3(1, 0, 0);
        }

        eixoX = prod_vetorial(v_up_temporario, eixoZ).normalizar();
        eixoY = prod_vetorial(eixoZ, eixoX).normalizar();
    } 
    else{
        // caso normal
        eixoX = prod_vetorial(v_up_mundo, eixoZ).normalizar();
        eixoY = prod_vetorial(eixoZ, eixoX).normalizar();
    }
}

Raio Camera::raioParaPonto(int x, int y){
    float u = -larguraImagem/2 + Dx/2 + x * Dx;
    float v = alturaImagem/2 - Dy/2 - y * Dy;

    Ponto3 coords = olhando_para + u * eixoX + v * eixoY;

    return Raio(posicao, coords - posicao);
}