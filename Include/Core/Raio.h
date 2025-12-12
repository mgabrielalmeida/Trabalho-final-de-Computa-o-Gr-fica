#pragma once

#include "Core/Vetor3.h"

class Raio{
public:
    Ponto3 origem;
    Vetor3 dir;

    Raio() : origem(Vetor3(0, 0, 0)), dir(Vetor3(0, 0, 0)) {}
    Raio(const Ponto3& o, const Vetor3& d) : origem(o), dir(d.normalizar()) {}

    Vetor3 pontoEmT(float t) const{
        return origem + (dir * t);
    }
};