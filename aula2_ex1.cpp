#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    string name;
    int idade{0};

    cout<<"Insira seu nome: ";
    getline(cin,name);
    cout<<"Insira sua idade: ";
    cin >> idade;

    cout<<"Nome: "<<name<<"\n"<<"Idade: "<<idade<<endl;
    return 0;
}

