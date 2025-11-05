#pragma once

#include "Vetor3.h"
#include "Material.h"
#include "Raio.h"
#include "Acertavel.h"
#include "Esfera.h"
#include <cmath>
// teste

class Esfera : public Acertavel{
public:
    Ponto3 centro;
    float raio;

    Esfera::Esfera() : centro (0, 0, 0), raio(1) {}
    Esfera::Esfera(Ponto3 c, float r, const Material& M) :  Acertavel(M), centro(c), raio(r) {}

    virtual HitRecords intersect(const Raio& ray) const override{
        Ponto3 p0 = ray.origem;
        Vetor3 d = ray.dir;

        Vetor3 L = p0 - centro;

        float a = 1;
        float b = 2 * (prod_escalar(L, d));
        float c = prod_escalar(L, L) - (raio * raio);

        float delta = (b*b) - (4 * a * c);

       if (delta < 0) return HitRecords(); // sem interseção

        float sqrt_delta = std::sqrt(delta);
        float t1 = (-b - sqrt_delta) / (2.0f * a);
        float t2 = (-b + sqrt_delta) / (2.0f * a);

        float t = -1.0f;
        if (t1 > 0) t = t1;
        else if (t2 > 0) t = t2;
        else return HitRecords(); // interseções atrás da origem

        Ponto3 pi = ray.pontoEmT(t);
        Vetor3 normal = (pi - centro).normalizar();

        return HitRecords(material, t, normal, pi, this);
    }
};
