#pragma once

#include "Vetor3.h"
#include "Material.h"
#include "Raio.h"
#include "Acertavel.h"

class Esfera : public Acertavel{
public:
    Ponto3 centro;
    float raio;

    Esfera();
    Esfera(Ponto3 c, float r, const Material& M);

    virtual HitRecords intersect(const Raio& raio) const override;
};