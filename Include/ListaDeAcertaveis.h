#pragma once

#include "Vetor3.h"
#include "Acertavel.h"
#include "Material.h"
#include "HitRecords.h"
#include <vector>

class ListaDeAcertaveis{
public:
    std::vector<Acertavel*> lista;

    ListaDeAcertaveis();
    ListaDeAcertaveis(const std::vector<Acertavel*>& l);

    void inserir(Acertavel* obj);

    HitRecords intersect(Raio ray);
};