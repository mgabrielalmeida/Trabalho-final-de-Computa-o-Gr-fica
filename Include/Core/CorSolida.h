#pragma once

#include "Core/Material.h"
#include "Core/Vetor3.h"

class CorSolida : public Material{
public:
    Cor3 ka, ks, kd;
    float shininess;

    CorSolida() : ka(Vetor3()), kd(Vetor3()), ks(Vetor3()), shininess(32) {}
    CorSolida(const Cor3& ka, const Cor3& kd, const Cor3& ks, float alpha) : ka(ka), kd(kd), ks(ks), shininess(alpha) {}
    
    virtual Cor3 get_ka(float u, float v) const override { return ka; }
    virtual Cor3 get_kd(float u, float v) const override { return kd; }
    virtual Cor3 get_ks(float u, float v) const override { return ks; }
    virtual float get_shininess() const override { return shininess; }
};