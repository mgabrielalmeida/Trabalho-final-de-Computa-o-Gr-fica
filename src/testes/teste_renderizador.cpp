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

#include "Luzes/Luz.h"

#include "Utils/Colors.h"

#include <vector>

// g++ -o src/testes/teste_renderizador.exe src/testes/teste_renderizador.cpp src/shapes/Esfera.cpp src/core/ListaDeAcertaveis.cpp src/utils/Colors.cpp src/core/Camera.cpp src/shapes/Cilindro.cpp src/shapes/Plano.cpp src/shapes/Cone.cpp src/shapes/Disco.cpp src/core/Renderizador.cpp -I Include -std=c++17; .\src\testes\teste_renderizador.exe; code src/testes/imagens_geradas/teste_renderizador.ppm
int main(){
    Camera camera = Camera(Ponto3(0, 5, 1.5), Vetor3(0, 0, -1), 130, 1.77, 400);

    std::vector<Luz*> listaLuzes;
    Luz* luz = new Luz(Vetor3(4, 6, 2), Cor3(1, 1, 1));
    listaLuzes.push_back(luz);

    ListaDeAcertaveis listaObjetos;

    // Esfera* ouro = new Esfera(Ponto3(1, 0, -1), 0.3, Colors::ouro);
    // Esfera* prata = new Esfera(Ponto3(0, 0, -1), 0.3, Colors::prata);
    // Esfera* bronze = new Esfera(Ponto3(-1, 0, -1), 0.3, Colors::bronze);
    // Esfera* borracha = new Esfera(Ponto3(1, 0, 0), 0.3, Colors::borracha);
    // Esfera* plastico = new Esfera(Ponto3(0, 0, 0), 0.3, Colors::plastico);
    // Esfera* aluminio = new Esfera(Ponto3(-1, 0, 0), 0.3, Colors::aluminio);
    // Plano* ferro = new Plano(Ponto3(0, -2, 0), Vetor3(0, 1, 0), Colors::ferro);

    // listaObjetos.inserir(ouro);
    // listaObjetos.inserir(ferro);
    // listaObjetos.inserir(aluminio);
    // listaObjetos.inserir(plastico);
    // listaObjetos.inserir(borracha);
    // listaObjetos.inserir(bronze);
    // listaObjetos.inserir(prata);
    
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

    Renderizador renderizador = Renderizador(camera, listaObjetos, listaLuzes, Vetor3(0.2, 0.2, 0.2), Vetor3(50, 50, 50));
    renderizador.caminhoArquivoPPM = "src/testes/imagens_geradas/teste_renderizador.ppm";

    renderizador.renderizar();
}