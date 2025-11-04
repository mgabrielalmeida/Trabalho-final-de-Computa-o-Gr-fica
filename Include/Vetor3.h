#pragma once

#include <iostream>
#include <cmath>

class Vetor3{
// comentários de explicação para cada método/operador estão no arquivo cpp
public:
    float x, y, z;

    Vetor3();
    Vetor3(float x_val, float y_val, float z_val);

    float comprimento() const;
    float comprimento_ao_quadrado() const;
    Vetor3 normalizar() const;

    // OPERADORES
    // Negação (operador unário)
    Vetor3 operator-() const { return Vetor3(-x, -y, -z); }

    // Soma e atribuição
    Vetor3& operator+=(const Vetor3& outro){
        x += outro.x;
        y += outro.y;
        z += outro.z;
        return *this;
    }

    // Subtração e atribuição
    Vetor3& operator-=(const Vetor3& outro){
        x -= outro.x;
        y -= outro.y;
        z -= outro.z;
        return *this;
    }

    // Multiplicação por escalar e atribuição
    Vetor3& operator*=(float escalar){
        x *= escalar;
        y *= escalar;
        z *= escalar;
        return *this;
    }

    // Divisão por escalar e atribuição
    Vetor3& operator/=(float escalar){
        // A divisão é apenas uma multiplicação pelo inverso
        return *this *= (1.0f / escalar);
    }

    // Podemos usar Ponto3 e Cor3 como nomes alternativos para Vetor3
    using Ponto3 = Vetor3;
    using Cor3 = Vetor3;
};

// Funções auxiliares de fora da classe que facilitam muito a manipulação de vetores

// Permite imprimir um vetor com std::cout
inline std::ostream& operator<<(std::ostream& out, const Vetor3& v){
    return out << "Vetor3(" << v.x << ", " << v.y << ", " << v.z << ")";
}

// Soma de dois vetores (v1 + v2)
inline Vetor3 operator+(const Vetor3& v1, const Vetor3& v2){
    return Vetor3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

// Subtração de dois vetores (v1 - v2)
inline Vetor3 operator-(const Vetor3& v1, const Vetor3& v2){
    return Vetor3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

// Multiplicação de dois vetores (componente a componente)
inline Vetor3 operator*(const Vetor3& v1, const Vetor3& v2){
    return Vetor3(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
}

// Multiplicação por escalar (vetor * escalar)
inline Vetor3 operator*(const Vetor3& v, float escalar){
    return Vetor3(v.x * escalar, v.y * escalar, v.z * escalar);
}

// Multiplicação por escalar (escalar * vetor)
inline Vetor3 operator*(float escalar, const Vetor3& v){
    // A ordem não importa, então reutilizamos o operador anterior
    return v * escalar; 
}

// Divisão por escalar (vetor / escalar)
inline Vetor3 operator/(const Vetor3& v, float escalar){
    return v * (1.0f / escalar);
}

// Produto Escalar (Dot Product)
inline float produto_escalar(const Vetor3& v1, const Vetor3& v2){
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

// Produto Vetorial (Cross Product)
inline Vetor3 produto_vetorial(const Vetor3& v1, const Vetor3& v2){
    return Vetor3(
        v1.y * v2.z - v1.z * v2.y,
        v1.z * v2.x - v1.x * v2.z,
        v1.x * v2.y - v1.y * v2.x
    );
}