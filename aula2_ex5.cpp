#include <iostream>
#include <iomanip>
using namespace std;

// Protótipos
void aluno(string nome, int idade, float nota1, float nota2, float nota3);
float calcMedia(float nota1, float nota2, float nota3);

int main(int argc, char const *argv[])
{   
    string nome;
    int idade;
    float nota1, nota2, nota3;

    cout<<"Insira seu nome: ";
    getline(cin,nome);
    cout<<"Insira seu idade: ";
    cin >> idade;
    cout<<"Insira a nota da sua primeira prova: ";
    cin >> nota1;
    cout<<"Insira a nota da sua segunda prova: ";
    cin >> nota2;
    cout<<"Insira a nota da sua terceira prova: ";
    cin >> nota3;

    aluno(nome, idade, nota1, nota2, nota3);

    return 0;
}

void aluno(string nome, int idade, float nota1, float nota2, float nota3)
{   
    float nota = calcMedia(nota1,nota2, nota3);
    cout<<"Nome: "<< nome << "\n"
    << "idade: "<<fixed<<setprecision(2)<<idade<<"\n"
    << "Média Final: "<< nota<<endl;
}

float calcMedia(float nota1, float nota2, float nota3)
{
    float total = (nota1+nota2+nota3)/3;
    return total;
}