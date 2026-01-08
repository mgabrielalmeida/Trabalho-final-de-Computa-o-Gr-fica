#pragma once


#include "Core/Vetor3.h"
#include "Core/Raio.h"
#include "Core/HitRecords.h"
#include "Core/Material.h"

// Classe abstrata que serve de base para todos os objetos que colocaremos na cena
class Acertavel{
public:
    Material* material;

    Acertavel() : material() {}
    Acertavel(Material* material) : material(material) {}
    
    virtual HitRecords intersect(const Raio& raio) const = 0;
};