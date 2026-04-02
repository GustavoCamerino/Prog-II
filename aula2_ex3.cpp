#include <iostream>
using namespace std;

// Protótipos
void getNumbers(float a, float b, float c);

int main(int argc, char const *argv[])
{
    float a,b,c;
    cout << "Digite os números A, B e C: "<<endl;
    cin>>a>>b>>c;
    getNumbers(a,b,c);
    return 0;
}

void getNumbers(float a, float b, float c)
{
    cout << "Primeiro número: " << a << "\n" 
         << "Segundo número: " << b << "\n" 
         << "Terceiro número: " << c << endl;
}