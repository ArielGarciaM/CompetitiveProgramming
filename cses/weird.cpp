#include <bits/stdc++.h>
using namespace std;

long long f(long long x) {
    if(x % 2)
        return 3*x + 1;
    return x/2;
}

int main() {
    long long n;
    cin >> n;
    cout << n << " ";
    while(n > 1) {
        n = f(n);
        cout << n << " ";
    }
    cout << endl;
}