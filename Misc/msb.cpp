#include <bits/stdc++.h>
using namespace std;

int msb(int n) {
    return 1 << (31 - __builtin_clz(n));
}

int main() {
    int n;
    cin >> n;
    cout << msb(n) << endl;
}