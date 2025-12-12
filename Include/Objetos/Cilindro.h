#pragma once

#include "Core/Vetor3.h"
#include "Core/Material.h"
#include "Core/Raio.h"

#include "Objetos/Acertavel.h"

class Cilindro : public Acertavel{
public:
    Ponto3 centro_base;
    Vetor3 eixo;
    float raio;
    float altura;
    
    Cilindro();
    Cilindro(Ponto3 centro_base, Vetor3 eixo, float raio, float altura, const Material& material);
    
    virtual HitRecords intersect(const Raio& raio) const override;
};
