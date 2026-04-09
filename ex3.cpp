#include <iostream>
using namespace std;

int main()
{
    int num;
    cout << "Digite um número inteiro positivo: ";
    cin >> num;

    if (num <= 0)
    {
        cout << "Número inválido!\n";
        return 0;
    }

    int soma = 0;

    // Loop pelos divisores (até metade do número)
    for (int i = 1; i <= num / 2; i++)
    {
        if (num % i == 0)
        {
            soma += i;
        }

        // Regra: parar se ultrapassar
        if (soma > num)
        {
            break;
        }
    }

    // Verificação final
    if (soma == num)
    {
        cout << num << " é um número perfeito!\n";
    }
    else
    {
        cout << num << " não é um número perfeito.\n";
    }

    return 0;
}