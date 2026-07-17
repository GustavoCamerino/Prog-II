#pragma once
#include "Personagem.h"

class Ninja : public Personagem {
public:
    explicit Ninja(const std::string& nome);

    std::string getTipo() const override;
    void mostrarMenuGolpes() const override;
    void executarGolpe(Personagem& alvo, int opcao) override;
};
