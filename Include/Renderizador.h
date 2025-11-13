#pragma once

#include "Raio.h"
#include "Camera.h"
#include "Esfera.h"
#include "HitRecords.h"
#include "ListaDeAcertaveis.h"
#include "Luz.h"
#include "Material.h"
#include "Raio.h"
#include "Vetor3.h"
#include <string>
#include <vector>

class Renderizador{
public:
    Camera camera;

    ListaDeAcertaveis listaDeObjetos;
    std::vector<Luz*> listaDeLuzes;
    Cor3 i_ambiente; // a intensidade da luz ambiente
    Cor3 cor_background;
    std::string caminhoArquivoPPM;

    Renderizador();
    Renderizador(const Camera& camera, const ListaDeAcertaveis& acertaveis, const std::vector<Luz*>& luzes, const Cor3& i_a, const Cor3& bgColor);

    void renderizar();
};