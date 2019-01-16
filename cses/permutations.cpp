#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    if(n == 1) {
        cout << 1 << endl;
        return 0;
    }
    if(n == 4) {
        cout << "2 4 1 3" << endl;
        return 0;
    }
    if(n < 5) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }
    int x = n;
    for(;x > 0; x -= 2)
        cout << x << " ";
    x = n - 1;
    for(;x > 0; x -= 2)
        cout << x << " ";
    cout << endl;
}