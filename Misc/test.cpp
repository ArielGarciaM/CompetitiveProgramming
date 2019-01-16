#include <bits/stdc++.h>
using namespace std;

const int OPS = 5e8;
const int MOD = 1e9 + 7;

int main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int x = rng();
    for(int i = 0; i < OPS; i++)
        x ^= 33498398;
    cout << x << endl;
}