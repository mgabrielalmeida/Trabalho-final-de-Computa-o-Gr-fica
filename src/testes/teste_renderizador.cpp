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

// g++ -o src/testes/teste_renderizador.exe src/testes/teste_renderizador.cpp src/shapes/Esfera.cpp src/core/ListaDeAcertaveis.cpp src/core/Camera.cpp src/core/Renderizador.cpp -I Include -std=c++17
// .\src\testes\teste_renderizador.exe
int main(){
    Camera camera = Camera(Ponto3(0, 0, 0), Vetor3(0, 0, -1), Vetor3(2, 2, 0), 400, 400);

    Material vermelho = Material(
        Vetor3(0.1, 0, 0),
        Vetor3(0.8, 0, 0),
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
    Luz* luz = new Luz(Vetor3(4, 5, 0), Cor3(1, 1, 1));
    listaLuzes.push_back(luz);

    ListaDeAcertaveis listaObjetos;
    Esfera* esfera = new Esfera(Vetor3(0, 0, -1), 0.5, vermelho);
    listaObjetos.inserir(esfera);

    Renderizador renderizador = Renderizador(camera, listaObjetos, listaLuzes, Vetor3(0.1, 0.1, 0.1), Vetor3(50, 50, 50));
    renderizador.caminhoArquivoPPM = "src/testes/imagens_geradas/teste_renderizador.ppm";

    renderizador.renderizar();
}