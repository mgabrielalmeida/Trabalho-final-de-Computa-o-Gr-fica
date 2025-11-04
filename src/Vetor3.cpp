#pragma once

#include "Vetor3.h"
#include <cmath> 
#include <iostream>

class Vetor3 {
public:
    float x, y, z;

    Vetor3() : x(0), y(0), z(0) {} // Construtor padrão

    Vetor3(float x_val, float y_val, float z_val) : x(x_val), y(y_val), z(z_val) {} // Construtor com valores

    // MÉTODOS
    // Retorna o comprimento (magnitude) do vetor
    float comprimento() const{
        return std::sqrt(comprimento_ao_quadrado());
    }

    // Retorna o comprimento ao quadrado (mais rápido, evita sqrt)
    float comprimento_ao_quadrado() const{
        return x*x + y*y + z*z;
    }

    // Retorna uma versão normalizada (comprimento 1) do vetor
    Vetor3 normalizar() const{
        float compr = comprimento();
        if (compr == 0) return Vetor3(0, 0, 0); 
        return Vetor3(x / compr, y / compr, z / compr);
    }
};

