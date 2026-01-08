#pragma once

#include "Core/Vetor3.h"

// Struct que armazena constantes necessárias pro cálculo da luz/sombra de um determinado píxel
class Material{
public:
    virtual ~Material() = default;
    
    virtual Cor3 get_kd(float u, float v) const = 0;
    virtual Cor3 get_ks(float u, float v) const = 0;
    virtual Cor3 get_ka(float u, float v) const = 0;
    virtual float get_shininess() const = 0;

    // Vetor3 ka;
    // Vetor3 kd;
    // Vetor3 ks;
    // float shininess;

    // Material() : ka(), kd(), ks(), shininess(1) {};
    // Material(const Vetor3& amb, const Vetor3& dif, const Vetor3& espec, float alpha) : 
    // ka(amb), kd(dif), ks(espec), shininess(alpha) {};
};