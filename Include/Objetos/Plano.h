#pragma once

#include "Core/Vetor3.h"
#include "Core/Material.h"
#include "Core/Raio.h"

#include "Objetos/Acertavel.h"

class Plano : public Acertavel{
public:
    Ponto3 ponto_ref;
    Vetor3 normal;

    Plano();
    Plano(const Ponto3& ponto_referencia, const Vetor3& normal, Material* material);

    virtual HitRecords intersect(const Raio& raio) const override;
};