#include "Cone.h"

#include "Vetor3.h"
#include "Material.h"
#include "Raio.h"
#include "Acertavel.h"
#include <cmath>

Cone::Cone() : centro_base(0, 0, 0), eixo(0, 1, 0), raio(1), altura(2) {}

Cone::Cone(Ponto3 cb, Vetor3 e, float r, float h, const Material& M) : Acertavel(M), centro_base(cb), eixo(e.normalizar()), raio(r), altura(h) {}

HitRecords Cone::intersect(const Raio& ray) const {
    Ponto3 p0 = ray.origem;
    Vetor3 d = ray.dir;
    Vetor3 delta_p = p0 - centro_base;
    float k = raio / altura;
    float k2 = k * k;

    float d_eixo = prod_escalar(d, eixo);
    float delta_p_eixo = prod_escalar(delta_p, eixo);

    // eq do cone
    float a = prod_escalar(d, d) - (1 + k2) * d_eixo * d_eixo;
    float b = 2 * (prod_escalar(d, delta_p) - (1 + k2) * d_eixo * delta_p_eixo);
    float c = prod_escalar(delta_p, delta_p) - (1 + k2) * delta_p_eixo * delta_p_eixo;

    float t_cone = -1.0f;
    if (fabs(a) > 1e-6) {
        float delta = b * b - 4 * a * c;
        if (delta >= 0) {
            float sqrt_delta = sqrt(delta);
            float t1 = (-b - sqrt_delta) / (2 * a);
            float t2 = (-b + sqrt_delta) / (2 * a);
            for (float t_candidate : {t1, t2}) {
                if (t_candidate > 1e-4) {
                    Ponto3 pi = ray.pontoEmT(t_candidate);
                    float altura_ponto = prod_escalar(pi - centro_base, eixo);
                    // Ignora interseções muito próximas ao vértice ou à base (limite maior)
                    if (altura_ponto > 5e-2 && altura_ponto < altura - 5e-2) {
                        t_cone = t_candidate;
                        break;
                    }
                }
            }
        }
    }

    // base do cone 
    float t_base = -1.0f;
    float denom = prod_escalar(eixo, d);
    if (fabs(denom) > 1e-6) {
        Ponto3 centro_base_topo = centro_base + altura * eixo;
        float t_cand = prod_escalar(eixo, centro_base_topo - p0) / denom;
        if (t_cand > 1e-4) {
            Ponto3 pi = ray.pontoEmT(t_cand);
            if ((pi - centro_base_topo).comprimento() <= raio) {
                t_base = t_cand;
            }
        }
    }

    // escolher o t mais próximo
    float t_final = -1.0f;
    int tipo = -1;
    
    if (t_base > 1e-4 && (t_final < 0 || t_base < t_final)) {
        t_final = t_base;
        tipo = 1;
    } else if (t_cone > 1e-4 && (t_final < 0 || t_cone < t_final)) {
        t_final = t_cone;
        tipo = 0;
    }
    if (t_final < 0) return HitRecords();

    Ponto3 pi = ray.pontoEmT(t_final);
    Vetor3 normal;
    if (tipo == 0) {
        // lateral do cone
        Vetor3 v = pi - centro_base;
        float proj = prod_escalar(v, eixo);
        Vetor3 radial = v - proj * eixo;
        
        if (radial.comprimento() < 1e-4) {
            normal = -eixo;
        } else {
            normal = (radial - k * proj * eixo).normalizar();
        }
    } else {
        // base do cone
        normal = eixo;
    }

    if (prod_escalar(normal, ray.dir) > 0)
        normal = -normal;

    return HitRecords(material, t_final, normal, pi, this);
}