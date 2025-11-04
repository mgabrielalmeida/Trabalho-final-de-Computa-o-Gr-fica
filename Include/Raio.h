#include "Vetor3.h"

#pragma once

class Raio{
public:
    Vetor3 origem;
    Vetor3 dir;

    Raio();
    Raio(const Vetor3& o, const Vetor3& d); 

    Vetor3 pontoEmT(float t);
};