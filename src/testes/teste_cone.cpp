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

// g++ -o src/testes/teste_cone.exe src/testes/teste_cone.cpp src/shapes/Cone.cpp src/core/ListaDeAcertaveis.cpp src/core/Camera.cpp src/core/Renderizador.cpp -I Include -std=c++17
// ./src/testes/teste_cone.exe
int main(){
    Camera camera = Camera(Ponto3(0, 2, 1), Ponto3(0, 0, -3), Vetor3(4, 4, 0), 400, 400);

    Material verde = Material(
        Vetor3(0.1, 0.2, 0.1),
        Vetor3(0.2, 0.8, 0.2),
        Vetor3(0.5, 0.5, 0.5),
        32
    );

    std::vector<Luz*> listaLuzes;
    Luz* luz = new Luz(Vetor3(0, 3, -1), Cor3(1, 1, 1));
    listaLuzes.push_back(luz);

    ListaDeAcertaveis listaObjetos;
    Cone* cone = new Cone(Ponto3(0, -1, -3), Vetor3(0, -1, 0), 0.5, 2.0, verde);
    listaObjetos.inserir(cone);

    Renderizador renderizador = Renderizador(camera, listaObjetos, listaLuzes, Vetor3(0.1, 0.1, 0.1), Vetor3(50, 50, 50));
    renderizador.caminhoArquivoPPM = "src/testes/imagens_geradas/teste_cone.ppm";

    renderizador.renderizar();
}
