#pragma once

#include "Core/Vetor3.h"
#include "Core/Material.h"
#include "Core/Raio.h"

#include "Objetos/Acertavel.h"

class Esfera : public Acertavel{
public:
    Ponto3 centro;
    float raio;

    Esfera();
    Esfera(Ponto3 centro, float raio, const Material& material);

    virtual HitRecords intersect(const Raio& raio) const override;
};