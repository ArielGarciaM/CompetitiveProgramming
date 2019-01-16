#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input", "w", stdout);
    int n = 500000;
    cout << n << endl;
    for(int i = 0; i < n; i++) {
        if(i < 299999)
            cout << 500000 << " ";
        else
            cout << 300000 << " ";
    }
    cout << endl;
}