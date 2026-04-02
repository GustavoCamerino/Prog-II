#include <iostream>
#include <iomanip>
using namespace std;

// Protótipos
void PessoaConta(string nome, float salario);

int main(int argc, char const *argv[])
{   
    string nome;
    float salario;

    cout<<"Insira seu nome: ";
    getline(cin,nome);
    cout<<"Insira seu salário: ";
    cin >> salario;

    PessoaConta(nome, salario);

    return 0;
}

void PessoaConta(string nome, float salario)
{
    cout<<"Nome: "<< nome << "\n"
    << "Salário: "<<fixed<<setprecision(2)<<salario<<endl;
}