#pragma once
#include <string>

class Personagem {
protected:
    std::string nome;
    int hpMax;
    int hp;
    int ataque;
    int defesa;
    bool defendendo;

public:
    Personagem(const std::string& nome, int hp, int ataque, int defesa);
    virtual ~Personagem() = default;

    std::string getNome() const;
    int getHP() const;
    int getHPMax() const;
    int getAtaque() const;
    int getDefesa() const;
    bool estaVivo() const;

    void setHP(int valor);
    void setAtaque(int valor);
    void setDefesa(int valor);

    virtual std::string getTipo() const = 0;
    virtual void mostrarMenuGolpes() const = 0;
    virtual void executarGolpe(Personagem& alvo, int opcao) = 0;
    virtual void receberDano(int dano);

    void exibirStatus() const;
};
