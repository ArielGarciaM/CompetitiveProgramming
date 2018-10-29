#include <bits/stdc++.h>
using namespace std;

int ord(int a, int b)
{
    while(__gcd(a, b) > 1)
        b /= __gcd(a, b);
    if(b == 1)
        return 0;
    int n = a % b, ex = 1;
    while(n % b != 1)
    {
        n = (n * a) % b;
        ex++;
    }
    return ex;
}

int main()
{
    int mx = 0;
    for(int d = 2; d < 1000; d++)
    {
        mx = max(mx, ord(10, d));
    }
    cout << mx << endl;
}