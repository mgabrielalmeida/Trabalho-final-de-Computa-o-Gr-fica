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
#include "Objetos/Plano.h"
#include "Objetos/Disco.h"
#include "Objetos/Triangulo.h"
#include "Objetos/Malha.h"

#include "Luzes/Luz.h"

#include "Utils/Colors.h"

#include <vector>

// g++ -o src/testes/teste_renderizador.exe src/testes/teste_renderizador.cpp src/shapes/Esfera.cpp src/core/ListaDeAcertaveis.cpp src/utils/Colors.cpp src/core/Camera.cpp src/shapes/Cilindro.cpp src/shapes/Plano.cpp src/shapes/Cone.cpp src/shapes/Disco.cpp src/shapes/Triangulo.cpp src/shapes/Malha.cpp src/core/Renderizador.cpp -I Include -std=c++17; .\src\testes\teste_renderizador.exe; code src/testes/imagens_geradas/teste_renderizador.ppm
int main(){
    Camera camera = Camera(Ponto3(0, 3, 1.5), Ponto3(0, 0, -1), Vetor3(0, 1, 0), 140.0, 1.77, 400, 0);

    std::vector<Luz*> listaLuzes;
    Luz* luz = new Luz(Vetor3(4, 6, 2), Cor3(1, 1, 1));
    listaLuzes.push_back(luz);

    ListaDeAcertaveis listaObjetos;
    
    Plano* planoVerde = new Plano(Ponto3(0, 0, 0), Vetor3(0, 1, 0), Colors::verde);
    Cilindro* cilindroRoxo = new Cilindro(Ponto3(0, 0, -1), Vetor3(0, 1, 0), 0.5, 1, Colors::roxo, false, true);
    Cone* coneVermelho = new Cone(Ponto3(-0.5, 0, -0.2), Vetor3(0, 1, 0), 0.2, 1, Colors::vermelho);
    Esfera* esferaAzul = new Esfera(Vetor3(0.5, 0, -0.2), 0.2, Colors::azul);
    Disco* agua = new Disco(Ponto3(0, 0.4, -1), Vetor3(0, 1, 0), 0.5, Colors::ciano);
    listaObjetos.inserir(coneVermelho);
    listaObjetos.inserir(cilindroRoxo);
    listaObjetos.inserir(esferaAzul);
    listaObjetos.inserir(planoVerde);
    listaObjetos.inserir(agua);

    Malha malha;
    // Face 1 (V0 -> V1 -> Topo)
    malha.inserirTriangulo(
        Ponto3(1.700, 0.0, -0.800),   // Vértice 0 (0 graus)
        Ponto3(1.355, 0.0, -0.324),   // Vértice 1 (72 graus)
        Ponto3(1.200, 1.0, -0.800)    // Ápice
    );

    // Face 2 (V1 -> V2 -> Topo)
    malha.inserirTriangulo(
        Ponto3(1.355, 0.0, -0.324),   // Vértice 1
        Ponto3(0.796, 0.0, -0.506),   // Vértice 2 (144 graus)
        Ponto3(1.200, 1.0, -0.800)    // Ápice
    );

    // Face 3 (V2 -> V3 -> Topo)
    malha.inserirTriangulo(
        Ponto3(0.796, 0.0, -0.506),   // Vértice 2
        Ponto3(0.796, 0.0, -1.094),   // Vértice 3 (216 graus)
        Ponto3(1.200, 1.0, -0.800)    // Ápice
    );

    // Face 4 (V3 -> V4 -> Topo)
    malha.inserirTriangulo(
        Ponto3(0.796, 0.0, -1.094),   // Vértice 3
        Ponto3(1.355, 0.0, -1.276),   // Vértice 4 (288 graus)
        Ponto3(1.200, 1.0, -0.800)    // Ápice
    );

    // Face 5 (V4 -> V0 -> Topo)
    malha.inserirTriangulo(
        Ponto3(1.355, 0.0, -1.276),   // Vértice 4
        Ponto3(1.700, 0.0, -0.800),   // Vértice 0
        Ponto3(1.200, 1.0, -0.800)    // Ápice
    );
    malha.material = Colors::laranja;
    malha.enviarParaCena(listaObjetos);

    Renderizador renderizador = Renderizador(camera, listaObjetos, listaLuzes, Vetor3(0.2, 0.2, 0.2), Vetor3(50, 50, 50));
    renderizador.caminhoArquivoPPM = "src/testes/imagens_geradas/teste_renderizador.ppm";

    renderizador.renderizar();
}