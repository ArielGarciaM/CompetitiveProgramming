#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while(cin >> n) {
        int a = 3*n, b = 2*n + 1, d = __gcd(a, b);
        a /= d;
        b /= d;
        if(b > 1)
            cout << a << "/" << b << '\n';
        else
            cout << a << '\n';
    }
}