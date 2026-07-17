#include "Guerreiro.h"
#include <iostream>

Guerreiro::Guerreiro(const std::string& nome)
    : Personagem(nome, 120, 18, 10) {}

std::string Guerreiro::getTipo() const { return "Guerreiro"; }

void Guerreiro::mostrarMenuGolpes() const {
    if (nome == "Jax") {
        std::cout << "1) Gotcha Grab (agarrao e soco)\n";
        std::cout << "2) Ground Pound (soqueira no chao, dano alto)\n";
    } else if (nome == "Kano") {
        std::cout << "1) Cannonball (investida em bola)\n";
        std::cout << "2) Heart Rip (arranca o coracao, dano alto)\n";
    } else if (nome == "Baraka") {
        std::cout << "1) Blade Charge (investida com laminas)\n";
        std::cout << "2) Chop Chop (golpe duplo de laminas, dano alto)\n";
    } else if (nome == "Goro") {
        std::cout << "1) Four-Arm Smash (soco com os quatro bracos)\n";
        std::cout << "2) Stomp (pisao esmagador, dano alto)\n";
    } else {
        std::cout << "1) Golpe de Espada (ataque padrao)\n";
        std::cout << "2) Investida Brutal (dano alto)\n";
    }
    std::cout << "3) Defender (reduz proximo dano recebido)\n";
    std::cout << "Escolha: ";
}

void Guerreiro::executarGolpe(Personagem& alvo, int opcao) {
    switch (opcao) {
        case 1:
            if (nome == "Jax") std::cout << nome << " usa Gotcha Grab!\n";
            else if (nome == "Kano") std::cout << nome << " usa Cannonball!\n";
            else if (nome == "Baraka") std::cout << nome << " usa Blade Charge!\n";
            else if (nome == "Goro") std::cout << nome << " usa Four-Arm Smash!\n";
            else std::cout << nome << " desfere um Golpe de Espada!\n";
            alvo.receberDano(ataque);
            break;
        case 2:
            if (nome == "Jax") std::cout << nome << " usa Ground Pound!\n";
            else if (nome == "Kano") std::cout << nome << " usa Heart Rip!\n";
            else if (nome == "Baraka") std::cout << nome << " usa Chop Chop!\n";
            else if (nome == "Goro") std::cout << nome << " usa Stomp!\n";
            else std::cout << nome << " usa Investida Brutal!\n";
            alvo.receberDano(static_cast<int>(ataque * 1.8));
            break;
        case 3:
            std::cout << nome << " ergue a guarda e se prepara para Defender!\n";
            defendendo = true;
            break;
        default:
            std::cout << nome << " hesita e perde o turno!\n";
            break;
    }
}
