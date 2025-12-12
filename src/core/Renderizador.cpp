#include "Core/Renderizador.h"

#include "Core/Raio.h"
#include "Core/Camera.h"
#include "Core/Material.h"
#include "Core/Raio.h"
#include "Core/Vetor3.h"
#include "Core/HitRecords.h"

#include "Objetos/ListaDeAcertaveis.h"
#include "Objetos/Esfera.h"
#include "Objetos/Cilindro.h"
#include "Objetos/Cone.h"

#include "Luzes/Luz.h"

#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <iostream>

Renderizador::Renderizador() {}
Renderizador::Renderizador(const Camera& camera, const ListaDeAcertaveis& acertaveis, const std::vector<Luz*>& luzes, const Cor3& i_a, const Cor3& bgColor)
    : camera(camera), listaDeObjetos(acertaveis), listaDeLuzes(luzes), i_ambiente(i_a), cor_background(bgColor) {}

void Renderizador::renderizar(){
    Raio ray;
    HitRecords hit, hitSombra;
    Ponto3 Pi;

    Cor3 cor_ambiente, cor_especular, cor_difusa, cor_final;
    Vetor3 N, L, R, V;
    Raio ray_sombra;
    float distL;
    
    std::ofstream arquivo_ppm;
    arquivo_ppm.open(caminhoArquivoPPM);

    arquivo_ppm << "P3\n";
    arquivo_ppm << camera.nColunas << " " << camera.nLinhas << "\n";
    arquivo_ppm << "255\n";

    for(int i = 0; i < camera.nLinhas; ++i){
        for(int j = 0; j < camera.nColunas; ++j){
            cor_ambiente = Vetor3(), cor_difusa = Vetor3(), cor_especular = Vetor3();

            ray = camera.raioParaPonto(j, i);

            hit = listaDeObjetos.intersect(ray);
            
            // Se não houve intersecção 
            if(hit.t < 1e-4){
                arquivo_ppm << cor_background.x << " " << cor_background.y << " " << cor_background.z << "\n";
                continue;
            }

            Pi = ray.pontoEmT(hit.t);
            N = hit.normal.normalizar();
            V = (camera.posicao - Pi).normalizar();

            // Cálculo da componente ambiente
            cor_ambiente = prod_hadamard(i_ambiente, hit.material.ka);

            for(auto luz : listaDeLuzes){
                L = luz->posicao - Pi;
                distL = L.comprimento();
                L = L.normalizar();

                ray_sombra = Raio(Pi+(0.001*L), L);
                hitSombra = listaDeObjetos.intersect(ray_sombra);

                if(hitSombra.t < 1e-4 || hitSombra.t > distL){
                    R = 2 * prod_escalar(N, L) * N - L;

                    // Cálculo da componente difusa
                    cor_difusa += prod_hadamard(hit.material.kd, luz->intensidade) * std::max(0.0f, prod_escalar(N,L));

                    // Cálculo da componente especular
                    cor_especular += hit.material.ks * luz->intensidade * pow(std::max(0.0f, prod_escalar(R, V)), hit.material.shininess);
                }
            }
            
            cor_final = cor_ambiente + cor_difusa + cor_especular;
            cor_final = Cor3(
                std::max(0.0f, std::min(255.0f, cor_final.x)),
                std::max(0.0f, std::min(255.0f, cor_final.y)),
                std::max(0.0f, std::min(255.0f, cor_final.z))
            );
            
            arquivo_ppm << cor_final.x * 255<< " " << cor_final.y * 255 << " " << cor_final.z * 255 << "\n";
        }
    }
    std::cout << "Arquivo ppm criado na pasta: " << caminhoArquivoPPM << " !\n";
}