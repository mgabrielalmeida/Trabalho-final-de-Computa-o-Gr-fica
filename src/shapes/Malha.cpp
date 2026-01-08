#include "Objetos/Malha.h"

#include "Core/Vetor3.h"
#include "Core/HitRecords.h"

#include "Objetos/Acertavel.h"
#include "Objetos/Triangulo.h"

#include <vector>

Malha::Malha() {}
Malha::Malha(const std::vector<Ponto3>& vertices, const std::vector<int>& indices, const Material& material)
    : vertices(vertices), indices(indices), material(material) {}

void Malha::inserirTriangulo(const Ponto3& v0, const Ponto3& v1, const Ponto3& v2){
    int i = vertices.size();
    vertices.push_back(v0);
    vertices.push_back(v1);
    vertices.push_back(v2);
    
    indices.push_back(i);
    indices.push_back(i+1);
    indices.push_back(i+2);
}

void Malha::inserirTriangulo(const Triangulo& triangulo){
    int i = vertices.size();
    vertices.push_back(triangulo.v0);
    vertices.push_back(triangulo.v1);
    vertices.push_back(triangulo.v2);
    
    indices.push_back(i);
    indices.push_back(i+1);
    indices.push_back(i+2);
}

void Malha::enviarParaCena(ListaDeAcertaveis& listaDeObjetos){
    for (size_t i = 0; i < indices.size(); i += 3){
        Ponto3 v0 = vertices[indices[i]];
        Ponto3 v1 = vertices[indices[i+1]];
        Ponto3 v2 = vertices[indices[i+2]];

        listaDeObjetos.inserir(new Triangulo(v0, v1, v2, material));
    }
}