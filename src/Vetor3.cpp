#include <bits/stdc++.h>
#include "Vetor3.h"

Vetor3::Vetor3(float x_val, float y_val, float z_val) {
    x = x_val;
    y = y_val;
    z = z_val;
}

Vetor3 Vetor3::soma(const Vetor3& other){
    return Vetor3(x + other.x, y + other.y, z + other.z);
}

Vetor3 Vetor3::subtracao(const Vetor3& other){
    return Vetor3(x - other.x, y - other.y, z - other.z);
}

Vetor3 Vetor3::multPorEscalar(float escalar){
    return Vetor3(x*escalar, y*escalar, z*escalar);
}

Vetor3 Vetor3::divPorEscalar(float escalar){
    return Vetor3(x/escalar, y/escalar, z/escalar);
}