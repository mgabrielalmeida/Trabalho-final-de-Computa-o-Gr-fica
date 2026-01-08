#include "Objetos/Triangulo.h"

#include "Core/Material.h"
#include "Core/HitRecords.h"
#include "Core/Raio.h"
#include "Core/Vetor3.h"

#include "Objetos/Acertavel.h"

#define pff pair<float,float>

Triangulo::Triangulo() {}
Triangulo::Triangulo(const Ponto3& v0, const Ponto3& v1, const Ponto3& v2, const Material& material) 
    : v0(v0), v1(v1), v2(v2), Acertavel(material) {}
Triangulo::Triangulo(const Ponto3& v0, const Ponto3& v1, const Ponto3& v2, const Material& material, std::pff uv0, std::pff uv1, std::pff uv2)
 : v0(v0), v1(v1), v2(v2), uv0(uv0), uv1(uv1), uv2(uv2) {}

// Intersect do Triângulo
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

    float u_bary = u;
    float v_bary = v;
    float w_bary = 1.0 - u_bary - v_bary;

    float u_tex = (w_bary * uv0.first) + (u_bary * uv1.first) + (v_bary * uv2.first);
    float v_tex = (w_bary * uv0.second) + (u_bary * uv1.second) + (v_bary * uv2.second);

    HitRecords hit;

    Vetor3 normal_geometrica = prod_vetorial(aresta1, aresta2).normalizar();

    if(prod_escalar(raio.dir, normal_geometrica) > 0.0) hit.normal = -normal_geometrica;
    else hit.normal = normal_geometrica;
    
    hit.t = t;
    hit.ponto = raio.pontoEmT(t);
    hit.material = material;
    hit.objetoAcertado = this;
    hit.u = u_tex;
    hit.v = v_tex;

    return hit;
}