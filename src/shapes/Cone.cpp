#include "Objetos/Cone.h"

#include "Core/Vetor3.h"
#include "Core/Material.h"
#include "Core/Raio.h"

#include "Objetos/Acertavel.h"

#include <cmath>

// Construtores
Cone::Cone() : centro_base(0,0,0), eixo(0,1,0), raio(1), altura(2) {}

Cone::Cone(Ponto3 centro_base, Vetor3 eixo, float raio, float altura, const Material& material) 
    : Acertavel(material), centro_base(centro_base), eixo(eixo.normalizar()), raio(raio), altura(altura) {}

// Intersect do Cone
HitRecords Cone::intersect(const Raio& ray) const {

    Ponto3 vertice = centro_base + altura * eixo;
    Vetor3 d = ray.dir;
    Vetor3 delta_p = ray.origem - vertice;

    Vetor3 eixo_inv = -eixo; 
    
    float tan_theta = raio / altura;
    float cos_theta_sq = 1.0f / (1.0f + tan_theta * tan_theta); // cos^2(theta)

    float d_dot_axis = prod_escalar(d, eixo_inv);
    float dp_dot_axis = prod_escalar(delta_p, eixo_inv);

    float a = d_dot_axis * d_dot_axis - cos_theta_sq; 
    float b = 2 * (d_dot_axis * dp_dot_axis - prod_escalar(d, delta_p) * cos_theta_sq);
    float c = dp_dot_axis * dp_dot_axis - prod_escalar(delta_p, delta_p) * cos_theta_sq;

    float t_lateral = -1.0f;

    float delta = b * b - 4 * a * c;
    if(delta >= 0){
        float sqrt_delta = sqrt(delta);
        float t1 = (-b - sqrt_delta) / (2 * a);
        float t2 = (-b + sqrt_delta) / (2 * a);

        for(float t_cand : {t1, t2}){
            if(t_cand > 1e-4){
                Ponto3 pi = ray.pontoEmT(t_cand);

                float h = prod_escalar(pi - centro_base, eixo);
                
                if(h >= 0 && h <= altura){
                    if(t_lateral < 0 || t_cand < t_lateral){
                        t_lateral = t_cand;
                    }
                }
            }
        }
    }

    // Intersecção com a BASE (O "chão" do cone)
    float t_base = -1.0f;
    float denom = prod_escalar(eixo, d); // Normal da base é o próprio eixo
    
    // Só testamos a base se o raio estiver vindo de "baixo" ou de lado
    if(fabs(denom) > 1e-6){
        float t_cand = prod_escalar(centro_base - ray.origem, eixo) / denom; // Plano da base
        if(t_cand > 1e-4){
            Ponto3 pi = ray.pontoEmT(t_cand);
            // Verifica se está dentro do círculo do raio
            if((pi - centro_base).comprimento_ao_quadrado() <= raio * raio){
                t_base = t_cand;
            }
        }
    }

    // Escolher o mais próximo
    float t_final = -1.0f;
    int tipo = -1; // 0 = lateral, 1 = base

    if(t_lateral > 1e-4){
        t_final = t_lateral;
        tipo = 0;
    }
    if(t_base > 1e-4 && (t_final < 0 || t_base < t_final)){
        t_final = t_base;
        tipo = 1;
    }

    if(t_final < 0) return HitRecords();

    // Calcular Normal
    Ponto3 pi = ray.pontoEmT(t_final);
    Vetor3 normal;

    if(tipo == 1){
        normal = -eixo; // Normal da base aponta para baixo
    } 
    else{

        Ponto3 ponto_no_eixo = vertice; 
        Vetor3 v_topo_p = pi - vertice;

        Vetor3 radial = prod_vetorial(v_topo_p, eixo); 
        normal = prod_vetorial(radial, v_topo_p).normalizar(); 
    }

    if(prod_escalar(normal, d) > 0) normal = -normal;

    return HitRecords(material, t_final, normal, pi, this);
}
