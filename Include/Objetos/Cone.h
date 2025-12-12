#pragma once

#include "Core/Vetor3.h"
#include "Core/Material.h"
#include "Core/Raio.h"

#include "Objetos/Acertavel.h"

class Cone : public Acertavel {
public:
    Ponto3 centro_base;
    Vetor3 eixo;
    float raio;
    float altura;

    Cone();
    Cone(Ponto3 centro_base, Vetor3 eixo, float raio, float altura, const Material& material);
    
    virtual HitRecords intersect(const Raio& ray) const override;
};
