#include "Objetos/Esfera.h"

#include "Core/Vetor3.h"
#include "Core/Material.h"
#include "Core/Raio.h"

#include "Objetos/Acertavel.h"

#include <cmath>

// Construtores
Esfera::Esfera() : centro (0, 0, 0), raio(1) {}
Esfera::Esfera(Ponto3 centro, float raio, const Material& material) 
    : Acertavel(material), centro(centro), raio(raio) {}

// Intersect da Esfera
HitRecords Esfera::intersect(const Raio& ray) const{
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

