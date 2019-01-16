#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    if(n % 4 == 1 || n % 4 == 2) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    if(n % 4 == 0) {
        cout << n/2 << endl;
        for(int m = 0; 4*m < n; m++) {
            cout << 4*m + 1 << " " << 4*m + 4 << " ";
        }
        cout << endl << n/2 << endl;
        for(int m = 0; 4*m < n; m++) {
            cout << 4*m + 2 << " " << 4*m + 3 << " ";
        }
        cout << endl;
    }
    if(n % 4 == 3) {
        cout << n/2 << endl;
        cout << 3 << " ";
        for(int m = 1; 4*m < n; m++)
            cout << 4*m << " " << 4*m + 3 << " ";
        cout << endl << (n + 1)/2 << endl;
        cout << 1 << " " << 2 << " ";
        for(int m = 1; 4*m < n; m++)
            cout << 4*m + 1 << " " << 4*m + 2 << " ";
        cout << endl;
    }
}