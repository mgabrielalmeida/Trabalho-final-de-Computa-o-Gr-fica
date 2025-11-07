#include "Vetor3.h"
#include "Esfera.h"
#include "Raio.h"
#include "Material.h"
#include "HitRecords.h"
#include "Acertavel.h"
#include <fstream>

// Teste de uma esfera vermelha ainda sem luz e sombra apenas pra testar o funcionamento da classe
// Ela tem um gradiente preto estranho que varia conforme a distância do ponto de intersecção
// Isso serve apenas para testar se a função intersects retorna corretamente a distância

// Comandos para compilar e rodar:
// g++ -o src/testes/teste_esfera1.exe src/testes/teste_esfera1.cpp src/shapes/Esfera.cpp -I Include -std=c++17
// .\src\testes\teste_esfera1.exe 

int main(){
    float wJanela, hJanela, dJanela; 
    int nCol, nLin;

    Cor3 bgColor = Cor3(100, 100, 100);
    Cor3 esfColor = Cor3(255, 0, 0);

    float Dx, Dy, x, y;
    Raio ray;
    Vetor3 ray_dir;

    Esfera bolaVermelha = Esfera(Ponto3(0, 0, -3), 1, Material());

    std::ofstream arquivo_ppm;
    arquivo_ppm.open("src/testes/imagens_geradas/teste_esfera1.ppm");

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

            float t = bolaVermelha.intersect(ray).t;
            if(t){
                arquivo_ppm << esfColor.x - 80*t << " " << esfColor.y << " " << esfColor.z << "\n";
            }
            else{
                arquivo_ppm << bgColor.x << " " << bgColor.y << " " << bgColor.z << "\n";
            }
        }
    }

    std::cout << "Teste_esfera1, imagem criada!\n";
    arquivo_ppm.close();
}