#pragma once

#include "Core/Raio.h"
#include "Core/Camera.h"
#include "Core/Raio.h"
#include "Core/HitRecords.h"
#include "Core/Vetor3.h"
#include "Core/Material.h"

#include "Objetos/Esfera.h"
#include "Objetos/Cilindro.h"
#include "Objetos/ListaDeAcertaveis.h"

#include "Luzes/Luz.h"

#include <string>
#include <vector>

// Classe que contém toda a lógica de pintar o canvas, bem como todos os elementos da cena
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

    // Método para pintar o canvas e renderizar a imagem em um arquivo ppm no caminho especificado
    void renderizar();
};