#pragma once

#include "Core/Vetor3.h"
#include "Core/Raio.h"
#include "Core/Material.h"

class Acertavel;

// Struct auxiliar que serve pra armazenar tudo que a gente precisa retornar quando há uma intersecção de um raio com um objeto qualquer
struct HitRecords{
    Material material;
    float t;
    Vetor3 normal;
    Vetor3 ponto;
    const Acertavel* objetoAcertado;

    HitRecords() : material(), t(0), normal(), ponto(), objetoAcertado(nullptr) {}

    HitRecords(const Material& mat, float T, const Vetor3& N, const Vetor3& Pi, const Acertavel* obj) :
    material(mat), t(T), normal(N), ponto(Pi), objetoAcertado(obj) {}
};