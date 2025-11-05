#include "Vetor3.h"

#pragma once

class Raio{
public:
    Vetor3 origem;
    Vetor3 dir;

    Raio() : origem(Vetor3(0, 0, 0)), dir(Vetor3(0, 0, 0)) {}
    Raio(const Vetor3& o, const Vetor3& d) : origem(o), dir(d.normalizar()) {}

    Vetor3 pontoEmT(float t) const{
        return origem + (dir * t);
    }
};