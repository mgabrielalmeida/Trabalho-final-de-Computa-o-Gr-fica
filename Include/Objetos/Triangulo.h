#pragma once

#include "Core/Material.h"
#include "Core/HitRecords.h"
#include "Core/Raio.h"
#include "Core/Vetor3.h"

#include "Objetos/Acertavel.h"

class Triangulo : public Acertavel{
public:
    Ponto3 v0, v1, v2;

    Triangulo();
    Triangulo(const Ponto3& v0, const Ponto3& v1, const Ponto3& v2, const Material& material);

    virtual HitRecords intersect(const Raio& raio) const override;
};