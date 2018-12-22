#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-7;

int main()
{
    double a, b, c;
    cin >> a >> b >> c;
    if(abs(a) < eps || b*b - 4*a*c < eps)
    {
        cout << "Impossivel calcular\n";
    }
    else
    {
        double disc = sqrt(b*b - 4*a*c);
        cout << fixed << setprecision(5);
        cout << "R1 = " << (-1.0*b + disc)/(2.0 * a) << endl;
        cout << "R2 = " << (-1.0*b - disc)/(2.0 * a) << endl;
    }
}