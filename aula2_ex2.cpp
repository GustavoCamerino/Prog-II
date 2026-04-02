#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    string name;
    int idade{0};
    float altura{0.0};

    cout<<"Insira seu nome: ";
    getline(cin,name);
    cout<<"Insira sua idade: ";
    cin >> idade;
    cout<<"Insira sua altura: ";
    cin >> altura;



    cout<<"Nome: "<<name<<"\n"<<"Idade: "<<idade<<"\nAltura: "<<idade<<endl;
    return 0;
}

