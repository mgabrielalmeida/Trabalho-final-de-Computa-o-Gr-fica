#include "Vetor3.h"
#include "Esfera.h"
#include "Raio.h"
#include "Material.h"
#include "HitRecords.h"
#include "Acertavel.h"
#include "ListaDeAcertaveis.h"
#include "Camera.h"
#include <fstream>

// g++ -o src/testes/teste_camera.exe src/testes/teste_camera.cpp src/shapes/Esfera.cpp src/core/ListaDeAcertaveis.cpp src/core/Camera.cpp -I Include -std=c++17
// .\src\testes\teste_camera.exe

int main(){
    float wJanela, hJanela, dJanela; 
    int nCol, nLin;

    Cor3 bgColor = Cor3(100, 100, 100);
    Cor3 cor1 = Cor3(255, 0, 255);
    Cor3 cor2 = Cor3(255, 255, 0);

    Esfera* bola1 = new Esfera(Ponto3(0, 0, -1), 0.5, Material());
    Esfera* bola2 = new Esfera(Ponto3(1.2, 0.2, -2), 0.7, Material());

    ListaDeAcertaveis l = ListaDeAcertaveis();
    l.inserir(bola2);
    l.inserir(bola1);

    float Dx, Dy, x, y;
    Raio ray;
    Vetor3 ray_dir;

    std::ofstream arquivo_ppm;
    arquivo_ppm.open("src/testes/imagens_geradas/teste_camera.ppm");

    wJanela = 2;
    hJanela = 2;
    dJanela = 1;
    nCol = 400;
    nLin = 400;

    Vetor3 dimJanela = Vetor3(wJanela, hJanela, -dJanela);
    Camera camera = Camera(Ponto3(0, 0, 0), Ponto3(0, 0, -1), dimJanela, nLin, nCol);

    arquivo_ppm << "P3\n";
    arquivo_ppm << nCol << " " << nLin << "\n";
    arquivo_ppm << "255\n";

    for(int i = 0; i<nLin; ++i){
        for(int j = 0; j<nCol; ++j){
            
            Raio ray = camera.raioParaPonto(i, j);

            HitRecords retorno = l.intersect(ray);
            if(retorno.t){
                if(retorno.objetoAcertado == bola2){
                    arquivo_ppm << cor1.x - 65*retorno.t << " " << cor1.y << " " << cor1.z - 65*retorno.t << "\n";
                }
                else{
                    arquivo_ppm << cor2.x - 65*retorno.t << " " << cor2.y  - 65*retorno.t << " " << cor2.z << "\n";
                }
            }
            else{
                arquivo_ppm << bgColor.x << " " << bgColor.y << " " << bgColor.z << "\n";
            }
        }
    }

    std::cout << "Teste_camera, imagem criada!\n";
    arquivo_ppm.close();
}