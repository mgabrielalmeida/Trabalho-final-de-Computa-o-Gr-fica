#include "Objetos/Disco.h"

#include "Core/Vetor3.h"
#include "Core/Material.h"
#include "Core/Raio.h"

#include "Objetos/Acertavel.h"
#include "Objetos/Plano.h"

Disco::Disco() {}
Disco::Disco(const Ponto3& centro, const Vetor3& normal, float raio, Material* material)
    : Plano(centro, normal, material), raio(raio) {}

// Intersect do Disco
HitRecords Disco::intersect(const Raio& ray) const{
    HitRecords hitPlano = Plano::intersect(ray);
    if(hitPlano.t < 1e-6) return hitPlano;

    Ponto3 Pi = hitPlano.ponto;

    float dist2 = (Pi - ponto_ref).comprimento_ao_quadrado();

    if(dist2 > raio * raio) return HitRecords();
    else return hitPlano;
}