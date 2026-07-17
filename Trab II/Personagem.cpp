#include "Personagem.h"
#include <iostream>

Personagem::Personagem(const std::string& nome, int hp, int ataque, int defesa)
    : nome(nome), hpMax(hp), hp(hp), ataque(ataque), defesa(defesa), defendendo(false) {}

std::string Personagem::getNome() const { return nome; }
int Personagem::getHP() const { return hp; }
int Personagem::getHPMax() const { return hpMax; }
int Personagem::getAtaque() const { return ataque; }
int Personagem::getDefesa() const { return defesa; }
bool Personagem::estaVivo() const { return hp > 0; }

void Personagem::setHP(int valor) {
    hp = valor;
    if (hp < 0) hp = 0;
    if (hp > hpMax) hp = hpMax;
}

void Personagem::setAtaque(int valor) { ataque = valor; }
void Personagem::setDefesa(int valor) { defesa = valor; }

void Personagem::receberDano(int dano) {
    int danoFinal = dano - defesa;
    if (danoFinal < 1) danoFinal = 1;

    if (defendendo) {
        danoFinal /= 2;
        if (danoFinal < 1) danoFinal = 1;
        defendendo = false;
    }

    hp -= danoFinal;
    if (hp < 0) hp = 0;

    std::cout << "  -> " << nome << " sofreu " << danoFinal
              << " de dano! (HP: " << hp << "/" << hpMax << ")\n";
}

void Personagem::exibirStatus() const {
    std::cout << nome << " [" << getTipo() << "] HP: " << hp << "/" << hpMax
              << "  ATK: " << ataque << "  DEF: " << defesa << "\n";
}
