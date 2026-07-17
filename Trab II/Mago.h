#pragma once
#include "Personagem.h"

class Mago : public Personagem {
public:
    explicit Mago(const std::string& nome);

    std::string getTipo() const override;
    void mostrarMenuGolpes() const override;
    void executarGolpe(Personagem& alvo, int opcao) override;
};
