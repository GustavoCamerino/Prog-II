#include "Ninja.h"
#include <iostream>
#include <random>

Ninja::Ninja(const std::string& nome)
    : Personagem(nome, 90, 16, 6) {}

std::string Ninja::getTipo() const { return "Ninja"; }

void Ninja::mostrarMenuGolpes() const {
    if (nome == "Scorpion") {
        std::cout << "1) Spear (\"Get Over Here!\")\n";
        std::cout << "2) Hellfire Uppercut (chance de critico)\n";
    } else if (nome == "Sub-Zero") {
        std::cout << "1) Ice Ball (congela e golpeia)\n";
        std::cout << "2) Slide (rasteira cortante, chance de critico)\n";
    } else if (nome == "Liu Kang") {
        std::cout << "1) Flying Kick (chute voador duplo)\n";
        std::cout << "2) Bicycle Kick (chance de critico)\n";
    } else {
        std::cout << "1) Chute Duplo (dois golpes rapidos)\n";
        std::cout << "2) Golpe Fatal (chance de critico)\n";
    }
    std::cout << "3) Defender (reduz proximo dano recebido)\n";
    std::cout << "Escolha: ";
}

void Ninja::executarGolpe(Personagem& alvo, int opcao) {
    static std::mt19937 rng(std::random_device{}());

    switch (opcao) {
        case 1: {
            if (nome == "Scorpion") std::cout << nome << " arremessa a lanca gritando \"GET OVER HERE!\"\n";
            else if (nome == "Sub-Zero") std::cout << nome << " lanca uma Ice Ball congelante!\n";
            else if (nome == "Liu Kang") std::cout << nome << " ataca com Flying Kick!\n";
            else std::cout << nome << " ataca com Chute Duplo!\n";
            int danoParcial = static_cast<int>(ataque * 0.6);
            for (int i = 0; i < 2 && alvo.estaVivo(); ++i) {
                alvo.receberDano(danoParcial);
            }
            break;
        }
        case 2: {
            if (nome == "Scorpion") std::cout << nome << " tenta um Hellfire Uppercut!\n";
            else if (nome == "Sub-Zero") std::cout << nome << " tenta um Slide cortante!\n";
            else if (nome == "Liu Kang") std::cout << nome << " tenta um Bicycle Kick!\n";
            else std::cout << nome << " tenta um Golpe Fatal!\n";
            std::uniform_int_distribution<int> dist(1, 100);
            bool critico = dist(rng) <= 40;
            int dano = static_cast<int>(ataque * (critico ? 2.2 : 1.3));
            if (critico) std::cout << "  CRITICO!\n";
            alvo.receberDano(dano);
            break;
        }
        case 3:
            std::cout << nome << " desaparece nas sombras e se prepara para Defender!\n";
            defendendo = true;
            break;
        default:
            std::cout << nome << " hesita e perde o turno!\n";
            break;
    }
}
