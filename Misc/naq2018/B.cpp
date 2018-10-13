#include<bits/stdc++.h>
using namespace std;

int main()
{
    int p, q, s;
    cin >> p >> q >> s;
    int m = p*q/__gcd(p, q);
    cout << ((m > s) ? "no\n" : "yes\n");
}