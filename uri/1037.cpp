#include <bits/stdc++.h>
using namespace std;

int main()
{
    double d;
    cin >> d;
    if(d < 0.0 || d > 100.0)
    {
        cout << "Fora de intervalo\n";
        return 0;
    }
    if(d <= 25.0)
    {
        cout << "Intervalo [0, 25]\n";
        return 0;
    }
    if(d <= 50.0)
    {
        cout << "Intervalo (25, 50]\n";
        return 0;
    }
    if(d <= 75.0)
    {
        cout << "Intervalo (50, 75]\n";
        return 0;
    }
    cout << "Intervalo (75, 100]\n";
    return 0;
}