#include <bits/stdc++.h>
using namespace std;

const double pi = 3.14159;

int main()
{
    double a, b, c;
    cin >> a >> b >> c;
    cout << fixed << setprecision(3);
    cout << "TRIANGULO: " << a*c*0.5 << endl;
    cout << "CIRCULO: " << pi*c*c << endl;
    cout << "TRAPEZIO: " << (a + b)*c*0.5 << endl;
    cout << "QUADRADO: " << b*b << endl;
    cout << "RETANGULO: " << a*b << endl;
}