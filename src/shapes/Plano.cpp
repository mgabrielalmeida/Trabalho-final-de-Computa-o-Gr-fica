#include "Objetos/Plano.h"

#include "Core/Vetor3.h"
#include "Core/HitRecords.h"
#include "Core/Raio.h"
#include "Core/Material.h"

#include "Objetos/Acertavel.h"

Plano::Plano() {}
Plano::Plano(const Ponto3& p, const Vetor3& n, Material* m) 
    : Acertavel(m), ponto_ref(p), normal(n.normalizar()) {}

    
// Intersect do Plano
HitRecords Plano::intersect(const Raio& ray) const {
    // 1. Calcular o denominador (Direcao . Normal)
    float denom = prod_escalar(ray.dir, normal);

    // 2. Verificar se o raio não é paralelo ao plano
    // Usamos um valor pequeno (epsilon) para evitar divisão por zero
    if (fabs(denom) > 1e-6) {
        
        // 3. Calcular o termo de cima: (Q - Origem) . N
        Vetor3 origem_para_plano = ponto_ref - ray.origem;
        float t = prod_escalar(origem_para_plano, normal) / denom;

        // 4. Verificar se o t é válido (está na frente da câmera)
        if (t > 1e-4) {
            Ponto3 p = ray.pontoEmT(t);
            
            // A normal do plano é constante, mas precisamos garantir
            // que ela aponte contra o raio (para a luz funcionar dos dois lados)
            Vetor3 normal_corrigida = normal;
            if (denom > 0) {
                normal_corrigida = -normal;
            }

            return HitRecords(material, t, normal_corrigida, p, this);
        }
    }

    // Se for paralelo ou estiver atrás da câmera
    return HitRecords();
}

