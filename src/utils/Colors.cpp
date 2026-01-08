#include "Utils/Colors.h"


// Cores básicas
CorSolida* Colors::vermelho = new CorSolida(
    Vetor3(0.2, 0.0, 0.0),   // Ambiente
    Vetor3(0.8, 0.0, 0.0),   // Difusa
    Vetor3(0.5, 0.5, 0.5),   // Especular
    32
);

CorSolida* Colors::verde = new CorSolida(
    Vetor3(0.0, 0.2, 0.0),
    Vetor3(0.0, 0.8, 0.0),
    Vetor3(0.5, 0.5, 0.5),
    32
);

CorSolida* Colors::azul = new CorSolida(
    Vetor3(0.0, 0.0, 0.2),
    Vetor3(0.0, 0.0, 0.8),
    Vetor3(0.5, 0.5, 0.5),
    32
);

CorSolida* Colors::amarelo = new CorSolida(
    Vetor3(0.2, 0.2, 0.0),
    Vetor3(0.8, 0.8, 0.0),
    Vetor3(0.5, 0.5, 0.5),
    32
);

CorSolida* Colors::ciano = new CorSolida(
    Vetor3(0.0, 0.2, 0.2),
    Vetor3(0.0, 0.8, 0.8),
    Vetor3(0.5, 0.5, 0.5),
    32
);

CorSolida* Colors::magenta = new CorSolida(
    Vetor3(0.2, 0.0, 0.2),
    Vetor3(0.8, 0.0, 0.8),
    Vetor3(0.5, 0.5, 0.5),
    32
);

CorSolida* Colors::branco = new CorSolida(
    Vetor3(0.2, 0.2, 0.2),
    Vetor3(0.9, 0.9, 0.9),
    Vetor3(0.7, 0.7, 0.7),
    64
);

CorSolida* Colors::preto = new CorSolida(
    Vetor3(0.02, 0.02, 0.02),
    Vetor3(0.05, 0.05, 0.05),
    Vetor3(0.2, 0.2, 0.2),
    8
);

CorSolida* Colors::cinza = new CorSolida(
    Vetor3(0.2, 0.2, 0.2),
    Vetor3(0.5, 0.5, 0.5),
    Vetor3(0.4, 0.4, 0.4),
    32
);

CorSolida* Colors::roxo = new CorSolida(
    Vetor3(0.2, 0.0, 0.2),
    Vetor3(0.6, 0.0, 0.6),
    Vetor3(0.6, 0.6, 0.6),
    48
);

CorSolida* Colors::laranja = new CorSolida(
    Vetor3(0.25, 0.1, 0.0),
    Vetor3(0.9, 0.4, 0.0),
    Vetor3(0.5, 0.5, 0.5),
    32
);

CorSolida* Colors::rosa = new CorSolida(
    Vetor3(0.25, 0.1, 0.15),
    Vetor3(0.9, 0.4, 0.6),
    Vetor3(0.6, 0.6, 0.6),
    32
);

// Materiais diferentes
CorSolida* Colors::metal = new CorSolida(
    Vetor3(0.25, 0.25, 0.25),
    Vetor3(0.4, 0.4, 0.4),
    Vetor3(0.9, 0.9, 0.9),
    128
);

CorSolida* Colors::plastico = new CorSolida(
    Vetor3(0.2, 0.2, 0.2),
    Vetor3(0.6, 0.6, 0.6),
    Vetor3(0.8, 0.8, 0.8),
    64
);

CorSolida* Colors::borracha = new CorSolida(
    Vetor3(0.05, 0.05, 0.05),
    Vetor3(0.1, 0.1, 0.1),
    Vetor3(0.05, 0.05, 0.05),
    4
);

CorSolida* Colors::ouro = new CorSolida(
    Vetor3(0.25, 0.20, 0.07),   // Ambiente
    Vetor3(0.35, 0.30, 0.10),   // Difusa (baixa)
    Vetor3(0.90, 0.78, 0.34),   // Especular (dourado)
    128
);

CorSolida* Colors::prata = new CorSolida(
    Vetor3(0.25, 0.25, 0.25),
    Vetor3(0.30, 0.30, 0.30),
    Vetor3(0.95, 0.95, 0.95),
    128
);

CorSolida* Colors::cobre = new CorSolida(
    Vetor3(0.25, 0.15, 0.10),
    Vetor3(0.35, 0.20, 0.15),
    Vetor3(0.95, 0.64, 0.54),
    128
);

CorSolida* Colors::bronze = new CorSolida(
    Vetor3(0.21, 0.13, 0.05),
    Vetor3(0.30, 0.20, 0.10),
    Vetor3(0.80, 0.50, 0.20),
    96
);

CorSolida* Colors::aluminio = new CorSolida(
    Vetor3(0.20, 0.20, 0.20),
    Vetor3(0.30, 0.30, 0.30),
    Vetor3(0.88, 0.88, 0.88),
    96
);

CorSolida* Colors::ferro = new CorSolida(
    Vetor3(0.15, 0.15, 0.15),
    Vetor3(0.25, 0.25, 0.25),
    Vetor3(0.70, 0.70, 0.70),
    64
);