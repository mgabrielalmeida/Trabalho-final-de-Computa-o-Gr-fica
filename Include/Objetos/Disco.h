#pragma once

#include "Core/Vetor3.h"
#include "Core/Material.h"
#include "Core/Raio.h"

#include "Objetos/Acertavel.h"
#include "Objetos/Plano.h"

// Classe derivada Disco herda de plano, é um plano limitado circularmente
class Disco : public Plano{
public:
    float raio;

    Disco();
    Disco(const Ponto3& centro, const Vetor3& normal, float raio, Material* material);

    virtual HitRecords intersect(const Raio& raio) const override;
};