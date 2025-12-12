#include "Core/Camera.h"

#include "Core/Vetor3.h"
#include "Core/Raio.h"

Camera::Camera() {}
Camera::Camera(Ponto3 posicao, Ponto3 olhando_para, Ponto3 dimensoes_janela, int numero_linhas, int numero_colunas)
: posicao(posicao), olhando_para(olhando_para), dimensoes_janela(dimensoes_janela), nLinhas(numero_linhas), nColunas(numero_colunas) {

    Dx = dimensoes_janela.x/nColunas;
    Dy = dimensoes_janela.y/nLinhas;

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
    float u = -dimensoes_janela.x/2 + Dx/2 + x * Dx;
    float v = dimensoes_janela.y/2 - Dy/2 - y * Dy;

    Ponto3 coords = olhando_para + u * eixoX + v * eixoY;

    return Raio(posicao, coords - posicao);
}