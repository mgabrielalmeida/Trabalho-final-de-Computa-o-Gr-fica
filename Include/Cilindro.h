#pragma once

#include "Vetor3.h"
#include "Material.h"
#include "Raio.h"
#include "Acertavel.h"

class Cilindro : public Acertavel{
public:
    Ponto3 centro_base;
    Vetor3 eixo;
    float raio;
    float altura;
    
    Cilindro();
    Cilindro(Ponto3 cb, Vetor3 e, float r, float h, const Material& M);
    
    virtual HitRecords intersect(const Raio& raio) const override;
};
