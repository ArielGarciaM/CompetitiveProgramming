#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<double> v(3);
    cin >> v[0] >> v[1] >> v[2];
    sort(v.begin(), v.end());
    double a = v[2], b = v[1], c = v[0];
    if(a >= b + c)
    {
        cout << "NAO FORMA TRIANGULO\n";
        return 0;
    }
    if(a*a == b*b + c*c)
        cout << "TRIANGULO RETANGULO\n";
    if(a*a > b*b + c*c)
        cout << "TRIANGULO OBTUSANGULO\n";
    if(a*a < b*b + c*c)
        cout << "TRIANGULO ACUTANGULO\n";
    if(a == b && a == c)
        cout << "TRIANGULO EQUILATERO\n";
    else if (a == b || b == c || c == a)
        cout << "TRIANGULO ISOSCELES\n";
}