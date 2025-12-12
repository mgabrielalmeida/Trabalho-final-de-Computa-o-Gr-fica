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

#include "Luzes/Luz.h"
#include <vector>

// g++ -o src/testes/teste_renderizador.exe src/testes/teste_renderizador.cpp src/shapes/Esfera.cpp src/core/ListaDeAcertaveis.cpp src/core/Camera.cpp src/shapes/Cilindro.cpp src/shapes/Plano.cpp src/shapes/Cone.cpp src/core/Renderizador.cpp -I Include -std=c++17
// .\src\testes\teste_renderizador.exe
int main(){
    Camera camera = Camera(Ponto3(0, 5, 3), Vetor3(0, 0, -1), Vetor3(2, 2, 0), 400, 400);

    Material vermelho = Material(
        Vetor3(1, 0, 0),
        Vetor3(0.8, 0, 0),
        Vetor3(0.5, 0.5, 0.5),
        32
    );
    Material verde = Material(
        Vetor3(0, 0.4, 0),
        Vetor3(0, 0.8, 0),
        Vetor3(0.5, 0.5, 0.5),
        32
    );
    Material bg = Material(
        Vetor3(0.05, 0.05, 0.05),
        Vetor3(0.7, 0.7, 0.7),
        Vetor3(),
        1
    );

    std::vector<Luz*> listaLuzes;
    Luz* luz = new Luz(Vetor3(3, 3, -1), Cor3(1, 1, 1));
    listaLuzes.push_back(luz);

    ListaDeAcertaveis listaObjetos;

    Plano* planoVerde = new Plano(Ponto3(0, 0, 0), Vetor3(0, 1, 0), verde);
    Cilindro* cilindroVermelho = new Cilindro(Ponto3(0, 0, -1), Vetor3(0, 1, 0), 0.5, 1, vermelho);
    Cone* coneVermelho = new Cone(Ponto3(-0.5, 0, -0.2), Vetor3(0, 1, 0), 0.2, 1, vermelho);
    Esfera* esferaVerde = new Esfera(Vetor3(0.5, 0, -0.2), 0.2, vermelho);
    listaObjetos.inserir(coneVermelho);
    listaObjetos.inserir(cilindroVermelho);
    listaObjetos.inserir(esferaVerde);
    listaObjetos.inserir(planoVerde);

    /*
    Esfera* esferaVermelha = new Esfera(Vetor3(0, -5, 0), 0.5, vermelho);
    listaObjetos.inserir(esferaVermelha);
    */

    Renderizador renderizador = Renderizador(camera, listaObjetos, listaLuzes, Vetor3(0.1, 0.1, 0.1), Vetor3(50, 50, 50));
    renderizador.caminhoArquivoPPM = "src/testes/imagens_geradas/teste_renderizador.ppm";

    renderizador.renderizar();
}