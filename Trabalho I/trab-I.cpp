#include <iostream>
using namespace std;

#define linhas 4
#define colunas 3

struct matriz
{
    float m[linhas][colunas];
    string vendedores[linhas] = {"Ricardo", "Paulo", "Thiago", "Gustavo"};
    string meses[colunas] = {"Janeiro", "Fevereiro", "Marco"};

    void menu()
    {
        int escolha;

        do
        {
            cout << "\n1 - Preencher\n2 - Mostrar\n3 - Total\n4 - Consultar vendedor\n0 - Sair\nEscolha: ";
            cin >> escolha;

            if (escolha == 1)
            {
                for (int i = 0; i < linhas; i++)
                {
                    cout << "\n" << vendedores[i] << ":\n";
                    for (int j = 0; j < colunas; j++)
                    {
                        cout << meses[j] << ": ";
                        cin >> m[i][j];
                    }
                }
            }

            else if (escolha == 2)
            {
                for (int i = 0; i < linhas; i++)
                {
                    cout << "\n" << vendedores[i] << ":\n";
                    for (int j = 0; j < colunas; j++)
                        cout << "  " << meses[j] << ": R$ " << m[i][j] << "\n";
                }
            }

            else if (escolha == 3)
            {
                for (int i = 0; i < linhas; i++)
                {
                    float total = 0;
                    for (int j = 0; j < colunas; j++)
                        total += m[i][j];
                    cout << vendedores[i] << ": R$ " << total << "\n";
                }
            }

            else if (escolha == 4)
            {
                for (int i = 0; i < linhas; i++)
                    cout << (i + 1) << " - " << vendedores[i] << "\n";

                int v;
                cout << "Numero do vendedor: ";
                cin >> v;
                v--;

                if (v < 0 || v >= linhas)
                {
                    cout << "Invalido!\n";
                }
                else
                {
                    float total = 0;
                    cout << "\n" << vendedores[v] << ":\n";
                    for (int j = 0; j < colunas; j++)
                    {
                        cout << "  " << meses[j] << ": R$ " << m[v][j] << "\n";
                        total += m[v][j];
                    }
                    cout << "  Total: R$ " << total << "\n";
                }
            }

            else if(escolha == 5)
            {
                float maior = m[0][0];
                int vend = 0;
                int mes = 0;

                for (int i = 0; i < linhas; i++)
                {
                    for (int j = 0; j < colunas; j++)
                    {
                        if (m[i][j] > maior)
                        {
                            maior = m[i][j];
                            vend = i;
                            mes = j;
                        }
                    }
                }

                cout << "\nMaior venda encontrada:\n";
                cout << "Vendedor: " << vendedores[vend] << endl;
                cout << "Mes: " << meses[mes] << endl;
                cout << "Valor: R$ " << maior << endl;
            }

        } while (escolha != 0);

        cout << "Ate logo!\n";
    }
};

int main()
{
    matriz tabela;
    tabela.menu();
    return 0;
}