#pragma once

#include "Core/Vetor3.h"
#include "Core/Raio.h"
#include "Core/Material.h"

class Acertavel;

// Struct auxiliar que serve pra armazenar tudo que a gente precisa retornar quando há uma intersecção de um raio com um objeto qualquer
struct HitRecords{
    Material* material;
    float t;
    Vetor3 normal;
    Vetor3 ponto;
    const Acertavel* objetoAcertado;
    float u, v;

    HitRecords() : material(), t(0), normal(), ponto(), objetoAcertado(nullptr), u(0), v(0) {}

    HitRecords(Material* material, float T, const Vetor3& normal, const Vetor3& ponto_interseccao, const Acertavel* objeto_acertado) :
    material(material), t(T), normal(normal), ponto(ponto_interseccao), objetoAcertado(objeto_acertado), u(0), v(0) {}

    HitRecords(Material* material, float T, const Vetor3& normal, const Vetor3& ponto_interseccao, const Acertavel* objeto_acertado, float u, float v) :
    material(material), t(T), normal(normal), ponto(ponto_interseccao), objetoAcertado(objeto_acertado), u(u), v(v) {}
};