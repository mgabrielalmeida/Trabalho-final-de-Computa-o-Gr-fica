#pragma once

#include "Core/CorSolida.h"
#include "Core/Vetor3.h"

// Classe utilitária contendo várias cores e materiais padrão para testes
class Colors {
public:
    // Tons básicos
    static CorSolida* vermelho;
    static CorSolida* verde;
    static CorSolida* azul;
    static CorSolida* amarelo;
    static CorSolida* ciano;
    static CorSolida* magenta;
    static CorSolida* branco;
    static CorSolida* preto;
    static CorSolida* cinza;

    // Tons mais estilizados
    static CorSolida* roxo;
    static CorSolida* laranja;
    static CorSolida* rosa;

    // Materiais "realistas"
    static CorSolida* metal;
    static CorSolida* plastico;
    static CorSolida* borracha;
    static CorSolida* ouro;
    static CorSolida* prata;
    static CorSolida* aluminio;
    static CorSolida* cobre;
    static CorSolida* bronze;
    static CorSolida* ferro;
};