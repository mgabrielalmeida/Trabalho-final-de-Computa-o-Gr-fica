#pragma once

#include "Core/Vetor3.h"
#include "Core/Material.h"
#include "Core/HitRecords.h"

#include "Objetos/Acertavel.h"

#include <vector>

// Lista com todos os objetos da cena que possui um método para encontrar a intersecção mais próxima
class ListaDeAcertaveis{
public:
    std::vector<Acertavel*> lista;

    ListaDeAcertaveis();
    ListaDeAcertaveis(const std::vector<Acertavel*>& l);

    void inserir(Acertavel* obj);

    HitRecords intersect(Raio ray);
};