#include "Utils/Colors.h"


// Cores básicas
const Material Colors::vermelho = Material(
    Vetor3(0.2, 0.0, 0.0),   // Ambiente
    Vetor3(0.8, 0.0, 0.0),   // Difusa
    Vetor3(0.5, 0.5, 0.5),   // Especular
    32
);

const Material Colors::verde = Material(
    Vetor3(0.0, 0.2, 0.0),
    Vetor3(0.0, 0.8, 0.0),
    Vetor3(0.5, 0.5, 0.5),
    32
);

const Material Colors::azul = Material(
    Vetor3(0.0, 0.0, 0.2),
    Vetor3(0.0, 0.0, 0.8),
    Vetor3(0.5, 0.5, 0.5),
    32
);

const Material Colors::amarelo = Material(
    Vetor3(0.2, 0.2, 0.0),
    Vetor3(0.8, 0.8, 0.0),
    Vetor3(0.5, 0.5, 0.5),
    32
);

const Material Colors::ciano = Material(
    Vetor3(0.0, 0.2, 0.2),
    Vetor3(0.0, 0.8, 0.8),
    Vetor3(0.5, 0.5, 0.5),
    32
);

const Material Colors::magenta = Material(
    Vetor3(0.2, 0.0, 0.2),
    Vetor3(0.8, 0.0, 0.8),
    Vetor3(0.5, 0.5, 0.5),
    32
);

const Material Colors::branco = Material(
    Vetor3(0.2, 0.2, 0.2),
    Vetor3(0.9, 0.9, 0.9),
    Vetor3(0.7, 0.7, 0.7),
    64
);

const Material Colors::preto = Material(
    Vetor3(0.02, 0.02, 0.02),
    Vetor3(0.05, 0.05, 0.05),
    Vetor3(0.2, 0.2, 0.2),
    8
);

const Material Colors::cinza = Material(
    Vetor3(0.2, 0.2, 0.2),
    Vetor3(0.5, 0.5, 0.5),
    Vetor3(0.4, 0.4, 0.4),
    32
);

const Material Colors::roxo = Material(
    Vetor3(0.2, 0.0, 0.2),
    Vetor3(0.6, 0.0, 0.6),
    Vetor3(0.6, 0.6, 0.6),
    48
);

const Material Colors::laranja = Material(
    Vetor3(0.25, 0.1, 0.0),
    Vetor3(0.9, 0.4, 0.0),
    Vetor3(0.5, 0.5, 0.5),
    32
);

const Material Colors::rosa = Material(
    Vetor3(0.25, 0.1, 0.15),
    Vetor3(0.9, 0.4, 0.6),
    Vetor3(0.6, 0.6, 0.6),
    32
);

// Materiais diferentes
const Material Colors::metal = Material(
    Vetor3(0.25, 0.25, 0.25),
    Vetor3(0.4, 0.4, 0.4),
    Vetor3(0.9, 0.9, 0.9),
    128
);

const Material Colors::plastico = Material(
    Vetor3(0.2, 0.2, 0.2),
    Vetor3(0.6, 0.6, 0.6),
    Vetor3(0.8, 0.8, 0.8),
    64
);

const Material Colors::borracha = Material(
    Vetor3(0.05, 0.05, 0.05),
    Vetor3(0.1, 0.1, 0.1),
    Vetor3(0.05, 0.05, 0.05),
    4
);

const Material Colors::ouro = Material(
    Vetor3(0.25, 0.20, 0.07),   // Ambiente
    Vetor3(0.35, 0.30, 0.10),   // Difusa (baixa)
    Vetor3(0.90, 0.78, 0.34),   // Especular (dourado)
    128
);

const Material Colors::prata = Material(
    Vetor3(0.25, 0.25, 0.25),
    Vetor3(0.30, 0.30, 0.30),
    Vetor3(0.95, 0.95, 0.95),
    128
);

const Material Colors::cobre = Material(
    Vetor3(0.25, 0.15, 0.10),
    Vetor3(0.35, 0.20, 0.15),
    Vetor3(0.95, 0.64, 0.54),
    128
);

const Material Colors::bronze = Material(
    Vetor3(0.21, 0.13, 0.05),
    Vetor3(0.30, 0.20, 0.10),
    Vetor3(0.80, 0.50, 0.20),
    96
);

const Material Colors::aluminio = Material(
    Vetor3(0.20, 0.20, 0.20),
    Vetor3(0.30, 0.30, 0.30),
    Vetor3(0.88, 0.88, 0.88),
    96
);

const Material Colors::ferro = Material(
    Vetor3(0.15, 0.15, 0.15),
    Vetor3(0.25, 0.25, 0.25),
    Vetor3(0.70, 0.70, 0.70),
    64
);