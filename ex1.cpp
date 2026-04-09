#include <iostream>
using namespace std;

// Protótipos das Funções
void validation(int age, bool auth, int level);

int main(int argc, char const *argv[])
{
    bool flag {0}, auth{0};
    int age{0}, level{0};
    while (flag == 0)
    {
        cout<<"Bem-vindo ao Gov.br\nDigite sua Idade: ";
        cin>>age;
        validation(age, auth, level);
        cout<<"\n\nDigite 0 se quiser tentar novamente\nDigite 1 se quiser parar\n";
        cin>>flag;
    }
    


    return 0;
}

// Implementação das Funções
void validation(int age, bool auth, int level)
{
    if (age < 16)
    {
        cout<<"Acesso negado\nIdade mínima inválida!\n";
    }
    if ((age == 16 || age == 17) && auth == 0)
    {
        cout<<"Você precisa de autorização\n";
        while(auth == 0)
        {
            cout<<"Você já tem a autorização?\nSe sim digite 1\nSe não digite 0\n";
            cin>>auth;
        }
        cout<<"Acesso autorizado!\nNível "<<level<<" aberto.\n";
    }

    if ((age == 16 || age == 17) && auth == 1)
    {
        cout<<"Acesso autorizado!\nDigite um dos seguintes níveis:\n(1) Básico\n(2) Intermediário\n(3) Total\n";
        cin>>level;
        if (level < 1 && level > 3)
        {   
            cout<<"Nível inválido!\n";
        }
        cout<<"Acesso autorizado!\nNível "<<level<<" aberto.\n";
    }

    if(age > 17)
    {
        cout<<"Digite um dos seguintes níveis:\n(1) Básico\n(2) Intermediário\n(3) Total\n";
        cin>>level; 
        if (level < 1 && level > 3)
        {   
            cout<<"Nível inválido!\n";
        }
        
    }
    
}