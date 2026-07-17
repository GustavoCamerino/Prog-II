#include "Personagem.h"
#include "Guerreiro.h"
#include "Ninja.h"
#include "Mago.h"
#include <iostream>
#include <vector>
#include <memory>
#include <random>
#include <limits>

int lerOpcao(int min, int max) {
    int opcao;
    while (!(std::cin >> opcao) || opcao < min || opcao > max) {
        std::cout << " Opcao invalida. Tente novamente: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return opcao;
}

std::vector<std::unique_ptr<Personagem>> criarRoster() {
    std::vector<std::unique_ptr<Personagem>> roster;
    roster.push_back(std::make_unique<Guerreiro>("Jax"));
    roster.push_back(std::make_unique<Ninja>("Scorpion"));
    roster.push_back(std::make_unique<Mago>("Raiden"));
    roster.push_back(std::make_unique<Guerreiro>("Kano"));
    roster.push_back(std::make_unique<Ninja>("Sub-Zero"));
    roster.push_back(std::make_unique<Mago>("Shang Tsung"));
    roster.push_back(std::make_unique<Guerreiro>("Baraka"));
    roster.push_back(std::make_unique<Ninja>("Liu Kang"));
    roster.push_back(std::make_unique<Mago>("Quan Chi"));
    roster.push_back(std::make_unique<Guerreiro>("Goro"));
    roster.push_back(std::make_unique<Guerreiro>("Sonya Blade"));
    roster.push_back(std::make_unique<Ninja>("Kitana"));
    roster.push_back(std::make_unique<Ninja>("Mileena"));
    roster.push_back(std::make_unique<Ninja>("Jade"));
    roster.push_back(std::make_unique<Mago>("Skarlet"));
    return roster;
}

void exibirLista(const std::vector<std::unique_ptr<Personagem>>& roster) {
    std::cout << "=== LUTADORES DISPONIVEIS ===\n";
    for (std::size_t i = 0; i < roster.size(); ++i) {
        std::cout << (i + 1) << ") " << roster[i]->getNome() << " [" << roster[i]->getTipo()
                  << "] HP:" << roster[i]->getHPMax() << " ATK:" << roster[i]->getAtaque()
                  << " DEF:" << roster[i]->getDefesa() << "\n";
    }
}

int main() {
    std::mt19937 rng(std::random_device{}());
    auto roster = criarRoster();

    exibirLista(roster);
    std::cout << "Escolha seu lutador (1-" << roster.size() << "): ";
    int escolhaJogador = lerOpcao(1, static_cast<int>(roster.size())) - 1;

    std::cout << "Deseja escolher o oponente? (1-Sim / 2-Sistema aleatorio): ";
    int modoOponente = lerOpcao(1, 2);

    int escolhaOponente;
    if (modoOponente == 1) {
        do {
            std::cout << "Escolha o oponente (1-" << roster.size() << "): ";
            escolhaOponente = lerOpcao(1, static_cast<int>(roster.size())) - 1;
            if (escolhaOponente == escolhaJogador) {
                std::cout << "Voce nao pode escolher a si mesmo!\n";
            }
        } while (escolhaOponente == escolhaJogador);
    } else {
        std::uniform_int_distribution<int> distRoster(0, static_cast<int>(roster.size()) - 1);
        do {
            escolhaOponente = distRoster(rng);
        } while (escolhaOponente == escolhaJogador);
    }

    Personagem& jogador = *roster[escolhaJogador];
    Personagem& oponente = *roster[escolhaOponente];

    std::cout << "\n=== SIMULACAO DE COMBATE ===\n";
    std::cout << jogador.getNome() << " (Voce) VS " << oponente.getNome() << " (Sistema)\n";

    int turno = 1;
    std::uniform_int_distribution<int> distGolpe(1, 3);

    while (jogador.estaVivo() && oponente.estaVivo()) {
        std::cout << "\n--- Turno " << turno << " ---\n";
        jogador.exibirStatus();
        oponente.exibirStatus();

        std::cout << "\nSua vez, " << jogador.getNome() << ":\n";
        jogador.mostrarMenuGolpes();
        int opcaoJogador = lerOpcao(1, 3);
        jogador.executarGolpe(oponente, opcaoJogador);

        if (!oponente.estaVivo()) break;

        std::cout << "\n" << oponente.getNome() << " (Sistema) age!\n";
        oponente.executarGolpe(jogador, distGolpe(rng));

        ++turno;
    }

    std::cout << "\n=== FIM DE COMBATE ===\n";
    if (!jogador.estaVivo()) {
        std::cout << jogador.getNome() << " esta FINALIZADO!\n";
        std::cout << "FATALITY!\n";
        std::cout << oponente.getNome() << " venceu! Vitoria do SISTEMA!\n";
    } else {
        std::cout << oponente.getNome() << " esta FINALIZADO!\n";
        std::cout << "FATALITY!\n";
        std::cout << jogador.getNome() << " venceu! Vitoria do USUARIO!\n";
    }

    return 0;
}
