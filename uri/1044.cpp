#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    bool div;
    if(a == 0 && b == 0)
        div = true;
    else if(a == 0 || b == 0)
        div = false;
    else
    {
        div = (a % b == 0 || b % a == 0) ? true : false;
    }
    cout << (div ? "Sao Multiplos\n" : "Nao sao Multiplos\n");
}