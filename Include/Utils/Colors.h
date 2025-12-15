#pragma once

#include "Core/Material.h"
#include "Core/Vetor3.h"

// Classe utilitária contendo várias cores e materiais padrão para testes
class Colors {
public:
    // Tons básicos
    static const Material vermelho;
    static const Material verde;
    static const Material azul;
    static const Material amarelo;
    static const Material ciano;
    static const Material magenta;
    static const Material branco;
    static const Material preto;
    static const Material cinza;

    // Tons mais estilizados
    static const Material roxo;
    static const Material laranja;
    static const Material rosa;

    // Materiais "realistas"
    static const Material metal;
    static const Material plastico;
    static const Material borracha;
    static const Material ouro;
    static const Material prata;
    static const Material aluminio;
    static const Material cobre;
    static const Material bronze;
    static const Material ferro;
};