#include "Renderizador.h"

#include "Raio.h"
#include "Camera.h"
#include "Esfera.h"
#include "HitRecords.h"
#include "ListaDeAcertaveis.h"
#include "Luz.h"
#include "Material.h"
#include "Raio.h"
#include "Vetor3.h"
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
    HitRecords hit;
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
            if(hit.t == 0){
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

                if(listaDeObjetos.intersect(ray_sombra).t == 0){
                    R = 2 * prod_escalar(N, L) * N - L;

                    // Cálculo da componente difusa
                    cor_difusa += prod_hadamard(hit.material.kd, luz->intensidade) * std::max(0.0f, prod_escalar(N,L));

                    // Cálculo da componente especular
                    cor_especular += hit.material.ks * luz->intensidade * pow(std::max(0.0f, prod_escalar(R, V)), hit.material.shininess);
                }
            }

            Cor3 cor_sum = cor_ambiente + cor_difusa + cor_especular;
            cor_final = Cor3(
                std::max(0.0f, std::min(255.0f, cor_sum.x)),
                std::max(0.0f, std::min(255.0f, cor_sum.y)),
                std::max(0.0f, std::min(255.0f, cor_sum.z))
            );

            arquivo_ppm << cor_final.x << " " << cor_final.y << " " << cor_final.z << "\n";
        }
    }
    std::cout << "Arquivo ppm criado na pasta: " << caminhoArquivoPPM << " !\n";
}