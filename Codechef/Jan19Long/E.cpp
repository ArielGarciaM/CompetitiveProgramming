#include <bits/stdc++.h>
using namespace std;

int good(int i, int j) {
    int a = i % 4, b = j % 4;
    if((a == 0 && b == 0) || (a == 2 && b == 2) || (a == 1 && b == 0) || (a == 3 && b == 2))
        return 1;
    if((a == 2 && b == 0) || (a == 0 && b == 2) || (a == 3 && b == 0) || (a == 1 && b == 2))
        return 2;
    if((a == 1 && b == 1) || (a == 3 && b == 3) || (a == 2 && b == 1) || (a == 0 && b == 3))
        return 3;
    return 4;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        if(n == 1) {
            cout << (m <= 2 ? 1 : 2) << endl;
            for(int i = 0; i < m; i++)
                cout << ((i % 4) <= 1 ? 1 : 2) << " ";
            cout << endl;
            continue;
        }
        if(m == 1) {
            cout << (n <= 2 ? 1 : 2) << endl;
            for(int i = 0; i < n; i++)
                cout << ((i % 4) <= 1 ? 1 : 2) << endl;
            continue;
        }
        if(n == 2) {
            cout << (m == 2 ? 2 : 3) << endl;
            for(int i = 0; i < 2; i++) {
                for(int j = 0; j < m; j++)
                    cout << (j % 3) + 1 << " ";
                cout << endl;
            }
            continue;
        }
        if(m == 2) {
            cout << (n == 2 ? 2 : 3) << endl;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < 2; j++)
                    cout << (i % 3) + 1 << " ";
                cout << endl;
            }
            continue;
        }
        cout << 4 << endl;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++)
                cout << good(i, j) << " ";
            cout << endl;
        }
    }
}