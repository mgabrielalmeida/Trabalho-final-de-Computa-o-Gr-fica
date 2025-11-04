#pragma once

// Classe abstrata que serve de base para todos os objetos que colocaremos na cena

#include "Vetor3.h"
#include "Raio.h"
#include "HitRecords.h"
#include "Material.h"

class Acertavel{
public:
    Material material;

    HitRecords intersect(Raio raio);
};