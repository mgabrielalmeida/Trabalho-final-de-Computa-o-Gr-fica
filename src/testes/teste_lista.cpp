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
#include <fstream>

// g++ -o src/testes/teste_lista.exe src/testes/teste_lista.cpp src/shapes/Esfera.cpp src/core/ListaDeAcertaveis.cpp -I Include -std=c++17
// .\src\testes\teste_lista.exe
int main(){
    float wJanela, hJanela, dJanela; 
    int nCol, nLin;

    Cor3 bgColor = Cor3(100, 100, 100);
    Cor3 vermelho = Cor3(255, 0, 0);
    Cor3 azul = Cor3(0, 0, 255);

    Esfera* bolaVermelha = new Esfera(Ponto3(0, 0, -3), 1, Material());
    Esfera* bolaAzul = new Esfera(Ponto3(0, 1, -2.5), 1, Material());

    ListaDeAcertaveis l = ListaDeAcertaveis();
    l.inserir(bolaAzul);
    l.inserir(bolaVermelha);

    float Dx, Dy, x, y;
    Raio ray;
    Vetor3 ray_dir;

    std::ofstream arquivo_ppm;
    arquivo_ppm.open("src/testes/imagens_geradas/teste_lista.ppm");

    wJanela = 2;
    hJanela = 2;
    dJanela = 1;
    nCol = 400;
    nLin = 400;

    arquivo_ppm << "P3\n";
    arquivo_ppm << nCol << " " << nLin << "\n";
    arquivo_ppm << "255\n";

    for(int i = 0; i<nLin; ++i){
        for(int j = 0; j<nCol; ++j){
            Dx = wJanela/nCol;
            Dy = hJanela/nLin;

            x = - wJanela/2 + Dx/2  + j*Dx;
            y = hJanela/2  -  Dy/2  -  i*Dy;

            ray_dir = Vetor3(x, y, -dJanela) - Vetor3(0, 0, 0);
            ray = Raio(Ponto3(0, 0, 0), ray_dir);

            HitRecords retorno = l.intersect(ray);
            if(retorno.t){
                if(retorno.objetoAcertado == bolaAzul){
                    arquivo_ppm << azul.x << " " << azul.y << " " << azul.z - 40*retorno.t << "\n";
                }
                else{
                    arquivo_ppm << vermelho.x - 40*retorno.t << " " << vermelho.y << " " << vermelho.z << "\n";
                }
            }
            else{
                arquivo_ppm << bgColor.x << " " << bgColor.y << " " << bgColor.z << "\n";
            }
        }
    }

    std::cout << "Teste_lista, imagem criada!\n";
    arquivo_ppm.close();
}