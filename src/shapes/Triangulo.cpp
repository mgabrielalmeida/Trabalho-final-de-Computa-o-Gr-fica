#include "Objetos/Triangulo.h"

#include "Core/Material.h"
#include "Core/HitRecords.h"
#include "Core/Raio.h"
#include "Core/Vetor3.h"

#include "Objetos/Acertavel.h"

Triangulo::Triangulo() {}
Triangulo::Triangulo(const Ponto3& v0, const Ponto3& v1, const Ponto3& v2, const Material& material) 
    : v0(v0), v1(v1), v2(v2), Acertavel(material) {}

HitRecords Triangulo::intersect(const Raio& raio) const{
    Vetor3 aresta1 = v1 - v0;
    Vetor3 aresta2 = v2 - v0;

    Vetor3 h = prod_vetorial(raio.dir, aresta2);
    float a = prod_escalar(aresta1, h);

    if(std::abs(a) < 1e-4) return HitRecords();

    float f = 1.0 / a;
    Vetor3 s = raio.origem - v0;
    float u = f * prod_escalar(s, h);

    if(u < 0.0 || u > 1.0) return HitRecords();

    Vetor3 q = prod_vetorial(s, aresta1);
    float v = f * prod_escalar(raio.dir, q);

    if(v < 0.0 || u + v > 1.0) return HitRecords();

    float t = f * prod_escalar(aresta2, q);
    if(t < 1e-4) return HitRecords();

    HitRecords hit;

    Vetor3 normal_geometrica = prod_vetorial(aresta1, aresta2).normalizar();

    if(prod_escalar(raio.dir, normal_geometrica) > 0.0) hit.normal = -normal_geometrica;
    else hit.normal = normal_geometrica;
    
    hit.t = t;
    hit.ponto = raio.pontoEmT(t);
    hit.material = material;
    hit.objetoAcertado = this;

    return hit;
}