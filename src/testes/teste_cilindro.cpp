#include "Renderizador.h"
#include "Raio.h"
#include "Camera.h"
#include "Cilindro.h"
#include "HitRecords.h"
#include "ListaDeAcertaveis.h"
#include "Luz.h"
#include "Material.h"
#include "Raio.h"
#include "Vetor3.h"
#include <vector>

// g++ -o src/testes/teste_cilindro.exe src/testes/teste_cilindro.cpp src/shapes/Cilindro.cpp src/core/ListaDeAcertaveis.cpp src/core/Camera.cpp src/core/Renderizador.cpp -I Include -std=c++17
// ./src/testes/teste_cilindro.exe
int main(){
    Camera camera = Camera(Ponto3(0, 4, 2), Ponto3(0, 0, -3), Vetor3(4, 4, 0), 400, 400);

    Material azul = Material(
        Vetor3(0.1, 0.1, 0.3),
        Vetor3(0.3, 0.3, 0.8),
        Vetor3(0.5, 0.5, 0.5),
        32
    );

    std::vector<Luz*> listaLuzes;
    Luz* luz = new Luz(Vetor3(3, 2, -3), Cor3(1, 1, 1));
    listaLuzes.push_back(luz);

    ListaDeAcertaveis listaObjetos;
    Cilindro* cilindro = new Cilindro(Ponto3(0, -1, -3), Vetor3(0, 1, 0), 0.5, 2.0, azul);
    listaObjetos.inserir(cilindro);

    Renderizador renderizador = Renderizador(camera, listaObjetos, listaLuzes, Vetor3(0.1, 0.1, 0.1), Vetor3(50, 50, 50));
    renderizador.caminhoArquivoPPM = "src/testes/imagens_geradas/teste_cilindro.ppm";

    renderizador.renderizar();
}