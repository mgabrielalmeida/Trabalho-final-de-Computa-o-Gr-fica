#pragma once

#include "Core/Material.h"
#include <iostream>
#include <algorithm> 

#include "../External/stb_image.h" 

class TexturaImagem : public Material {
public:
    unsigned char* dados; 
    int largura, altura;
    int canais; 

    Cor3 ks_fixo; 
    float shininess_fixo;

    TexturaImagem(const char* caminho_arquivo, Cor3 ks = Cor3(0.1, 0.1, 0.1), float sh = 32.0f) : ks_fixo(ks), shininess_fixo(sh){
        dados = stbi_load(caminho_arquivo, &largura, &altura, &canais, 3);

        if(!dados){
            std::cerr << "ERRO: Falha ao carregar textura '" << caminho_arquivo << "'" << std::endl;
            largura = altura = 1;
            dados = new unsigned char[3]{255, 0, 255}; 
        }
    }

    virtual ~TexturaImagem(){ if (dados) stbi_image_free(dados); }

    virtual Cor3 get_kd(float u, float v) const override{
        if (!dados) return Cor3(1, 0, 1); // Erro (Rosa)

        u = std::min(std::max(u, 0.0f), 1.0f);
        v = 1.0f -  std::min(std::max(v, 0.0f), 1.0f); 

        int i = static_cast<int>(u * largura);
        int j = static_cast<int>(v * altura);

        if (i >= largura) i = largura - 1;
        if (j >= altura) j = altura - 1;

        int indice_pixel = (j * largura + i) * 3;

        float r = dados[indice_pixel + 0] / 255.0f; 
        float g = dados[indice_pixel + 1] / 255.0f;
        float b = dados[indice_pixel + 2] / 255.0f;

        return Cor3(r, g, b);
    }

    virtual Cor3 get_ka(float u, float v) const override{ return get_kd(u, v); }

    virtual Cor3 get_ks(float u, float v) const override{ return ks_fixo; }

    virtual float get_shininess() const override{ return shininess_fixo; }
};