#pragma once
#include "Personagem.h"

class Guerreiro : public Personagem {
public:
    explicit Guerreiro(const std::string& nome);

    std::string getTipo() const override;
    void mostrarMenuGolpes() const override;
    void executarGolpe(Personagem& alvo, int opcao) override;
};
