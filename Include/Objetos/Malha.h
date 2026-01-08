#pragma once

#include "Core/Vetor3.h"
#include "Core/HitRecords.h"
#include "Core/Material.h"

#include "Objetos/Acertavel.h"
#include "Objetos/ListaDeAcertaveis.h"
#include "Objetos/Triangulo.h"

#include <vector>

class Malha{
public:
    std::vector<Ponto3> vertices;
    std::vector<int> indices;
    Material* material;

    Malha();
    Malha(const std::vector<Ponto3>& vertices, const std::vector<int>& indices, Material* material);

    void inserirTriangulo(const Ponto3& v0, const Ponto3& v1, const Ponto3& v2);
    void inserirTriangulo(const Triangulo& triangulo);
    void enviarParaCena(ListaDeAcertaveis& listaDeObjetos);
};