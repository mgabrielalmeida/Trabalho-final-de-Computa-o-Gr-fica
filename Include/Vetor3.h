#pragma once

class Vetor3{
public:
    float x, y, z;

    Vetor3(float x_val, float y_val, float z_val);

    Vetor3 soma(const Vetor3& other);
    Vetor3 subtracao(const Vetor3& other);
    Vetor3 multPorEscalar(float escalar);
    Vetor3 divPorEscalar(float escalar);
    float produtoEscalar(const Vetor3& other);
    Vetor3 produtoVetorial(const Vetor3& other);
    float norma();
    float normalizar();
    float negativo();
};