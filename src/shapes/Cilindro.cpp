#include "Cilindro.h"

#include "Vetor3.h"
#include "Material.h"
#include "Raio.h"
#include "Acertavel.h"
#include <cmath>

Cilindro::Cilindro() : centro_base(0, 0, 0), eixo(0, 1, 0), raio(1), altura(2) {}
Cilindro::Cilindro(Ponto3 cb, Vetor3 e, float r, float h, const Material& M) : Acertavel(M), centro_base(cb), eixo(e.normalizar()), raio(r), altura(h) {}

HitRecords Cilindro::intersect(const Raio& ray) const {
    Ponto3 p0 = ray.origem;
    Vetor3 d = ray.dir;

    Vetor3 delta_p = p0 - centro_base;

    float d_eixo = prod_escalar(d, eixo);
    float delta_p_eixo = prod_escalar(delta_p, eixo);

    // superfície lateral
    float a = prod_escalar(d, d) - d_eixo * d_eixo;
    float b = 2 * (prod_escalar(d, delta_p) - d_eixo * delta_p_eixo);
    float c = prod_escalar(delta_p, delta_p) - delta_p_eixo * delta_p_eixo - raio * raio;

    float t_lateral = -1.0f;
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
                    if (altura_ponto >= 0 && altura_ponto <= altura) {
                        t_lateral = t_candidate;
                        break;
                    }
                }
            }
        }
    }

    // base inferior
    float t_base_inf = -1.0f;
    float denom_inf = prod_escalar(eixo, d);
    if (fabs(denom_inf) > 1e-6) {
        float t_cand = -prod_escalar(eixo, p0 - centro_base) / denom_inf;
        if (t_cand > 1e-4) {
            Ponto3 pi = ray.pontoEmT(t_cand);
            if ((pi - centro_base).comprimento() <= raio) {
                t_base_inf = t_cand;
            }
        }
    }

    // base superior
    float t_base_sup = -1.0f;
    Ponto3 centro_topo = centro_base + altura * eixo;
    float denom_sup = prod_escalar(eixo, d);
    if (fabs(denom_sup) > 1e-6) {
        float t_cand = -prod_escalar(eixo, p0 - centro_topo) / denom_sup;
        if (t_cand > 1e-4) {
            Ponto3 pi = ray.pontoEmT(t_cand);
            if ((pi - centro_topo).comprimento() <= raio) {
                t_base_sup = t_cand;
            }
        }
    }

    // escolher o t mais próximo
    float t_final = -1.0f;
    int tipo = -1;
    if (t_lateral > 1e-4 && (t_final < 0 || t_lateral < t_final)) {
        t_final = t_lateral;
        tipo = 0;
    }
    if (t_base_inf > 1e-4 && (t_final < 0 || t_base_inf < t_final)) {
        t_final = t_base_inf;
        tipo = 1;
    }
    if (t_base_sup > 1e-4 && (t_final < 0 || t_base_sup < t_final)) {
        t_final = t_base_sup;
        tipo = 2;
    }
    if (t_final < 0) return HitRecords();

    Ponto3 pi = ray.pontoEmT(t_final);
    Vetor3 normal;

    if (tipo == 0) {
        // superfície lateral
        Vetor3 v = pi - centro_base;
        float proj = prod_escalar(v, eixo);
        Ponto3 ponto_eixo = centro_base + proj * eixo;
        normal = (pi - ponto_eixo).normalizar();
    } else if (tipo == 1) {
        normal = -eixo;
    } else {
        normal = eixo;
    }

    if (prod_escalar(normal, ray.dir) > 0)
        normal = -normal;

    return HitRecords(material, t_final, normal, pi, this);
}
