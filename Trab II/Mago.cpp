#include "Mago.h"
#include <iostream>

Mago::Mago(const std::string& nome)
    : Personagem(nome, 80, 20, 5) {}

std::string Mago::getTipo() const { return "Mago"; }

void Mago::mostrarMenuGolpes() const {
    if (nome == "Raiden") {
        std::cout << "1) Lightning Bolt (raio ignora parte da defesa)\n";
        std::cout << "2) Torpedo Eletrico (dano altissimo, consome energia)\n";
    } else if (nome == "Shang Tsung") {
        std::cout << "1) Skull Fireball (cranio flamejante ignora parte da defesa)\n";
        std::cout << "2) Soul Steal (dano altissimo, consome energia)\n";
    } else if (nome == "Quan Chi") {
        std::cout << "1) Skeletal Sorcery (feitico ossudo ignora parte da defesa)\n";
        std::cout << "2) Portal Trap (dano altissimo, consome energia)\n";
    } else {
        std::cout << "1) Bola de Fogo (ignora parte da defesa)\n";
        std::cout << "2) Explosao Arcana (dano altissimo, consome sua propria energia)\n";
    }
    std::cout << "3) Defender (reduz proximo dano recebido)\n";
    std::cout << "Escolha: ";
}

void Mago::executarGolpe(Personagem& alvo, int opcao) {
    switch (opcao) {
        case 1:
            if (nome == "Raiden") std::cout << nome << " conjura um Lightning Bolt!\n";
            else if (nome == "Shang Tsung") std::cout << nome << " lanca uma Skull Fireball!\n";
            else if (nome == "Quan Chi") std::cout << nome << " invoca Skeletal Sorcery!\n";
            else std::cout << nome << " conjura uma Bola de Fogo!\n";
            alvo.receberDano(static_cast<int>(ataque * 1.4));
            break;
        case 2:
            if (nome == "Raiden") std::cout << nome << " lanca um Torpedo Eletrico!\n";
            else if (nome == "Shang Tsung") std::cout << nome << " realiza um Soul Steal!\n";
            else if (nome == "Quan Chi") std::cout << nome << " abre um Portal Trap!\n";
            else std::cout << nome << " invoca uma Explosao Arcana!\n";
            alvo.receberDano(static_cast<int>(ataque * 2.2));
            hp -= 8;
            if (hp < 0) hp = 0;
            std::cout << "  -> " << nome << " sente o custo magico (HP: " << hp << "/" << hpMax << ")\n";
            break;
        case 3:
            std::cout << nome << " ergue uma barreira e se prepara para Defender!\n";
            defendendo = true;
            break;
        default:
            std::cout << nome << " hesita e perde o turno!\n";
            break;
    }
}
