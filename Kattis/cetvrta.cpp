#include <bits/stdc++.h>
using namespace std;

int main() {
    int x = 0, y = 0;
    for(int i = 0; i < 3 ; i++) {
        int a, b;
        cin >> a >> b;
        x ^= a;
        y ^= b;
    }
    cout << x << " " << y << endl;
}