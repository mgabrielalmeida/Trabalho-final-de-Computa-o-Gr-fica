#pragma once

// Struct que armazena constantes necessárias pro cálculo da luz/sombra de um determinado píxel

#include "Vetor3.h"

struct Material{
    Vetor3 ka;
    Vetor3 kd;
    Vetor3 ks;
    float shininess;

    Material() : ka(), kd(), ks(), shininess(1) {};
    Material(const Vetor3& amb, const Vetor3& dif, const Vetor3& espec, float alpha) : 
    ka(amb), kd(dif), ks(espec), shininess(alpha) {};
};