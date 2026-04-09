#include <iostream>
using namespace std;
// Protótipos de funções
float caixa(float saldo);

int main(int argc, char const *argv[])
{
    float saldo{1000};
    caixa(saldo);

    return 0;
}

// Implementações de funções
float caixa(float saldo)
{
    int flag_menu{0};
    int own_choice{0};

    while (flag_menu == 0)
    {
        cout<<"Menu:\n1. Ver Saldo\n2. Depositar\n3. Sacar\n4. Sair\n";
        cin>>own_choice;

        if (own_choice == 4)
        {
            flag_menu = 1;
            cout<<"Obrigado por usar Camerino's Bank\n";
        }
        else if (own_choice == 1)
        {
            cout<<"Saldo: "<<saldo<<endl;
        }
        else if (own_choice == 2)
        {
            float quantia{0};
            cout<<"Digite a quantia que desejas depositar: ";
            cin>>quantia;

            while (quantia <= 0)
            {
                cout<<"Quantia inválida\nTente novamente.\n";
                cin>>quantia;
            }

            saldo += quantia;
            cout<<"Saldo atualizado: "<<saldo<<endl;
        }
        else if (own_choice == 3)
        {
            float quantia{0};
            cout<<"Digite a quantia que desejas sacar: ";
            cin>>quantia;

            while (quantia <= 0 || quantia > saldo)
            {
                cout<<"Quantia inválida\nTente novamente.\n";
                cin>>quantia;
            }

            saldo -= quantia;
            cout<<"Saldo atualizado: "<<saldo<<endl;
        }
        else
        {
            cout<<"Opção inválida!\n";
        }
    }

    return saldo;
}