#pragma once

#include "Vetor3.h"
#include "Acertavel.h"
#include "Material.h"
#include "HitRecords.h"
#include <vector>

class ListaDeAcertaveis{
public:
    std::vector<Acertavel*> lista;
    float t; // O "t" a ser retornado

    ListaDeAcertaveis();
    ListaDeAcertaveis(const std::vector<Acertavel*>& l);

    void inserir( Acertavel* obj);

    HitRecords intersect(Raio ray);
};