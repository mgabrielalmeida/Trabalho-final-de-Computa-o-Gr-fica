#pragma once

#include "Core/Material.h"
#include "Core/HitRecords.h"
#include "Core/Raio.h"
#include "Core/Vetor3.h"

#include "Objetos/Acertavel.h"

#define pff pair<float,float>

class Triangulo : public Acertavel{
public:
    Ponto3 v0, v1, v2;
    std::pff uv0, uv1, uv2;

    Triangulo();
    Triangulo(const Ponto3& v0, const Ponto3& v1, const Ponto3& v2, const Material& material);
    Triangulo(const Ponto3& v0, const Ponto3& v1, const Ponto3& v2, const Material& material, std::pff uv0, std::pff uv1, std::pff uv2);

    virtual HitRecords intersect(const Raio& raio) const override;
};