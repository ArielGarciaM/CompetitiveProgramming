#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        if(n == 4)
            cout << "4\n";
        if(n == 3)
            cout << "6\n";
        if(n == 2)
            cout << "2\n";
        if(n == 1)
            cout << "1\n";
        if(n > 4)
            cout << "0\n";
    }
}