#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    map<string, int> co;
    co["Cruisers"] = 0;
    co["Battleships"] = 1;
    co["Destroyers"] = 2;

    string s, t;
    int x, y, a, b;
    while(cin >> s >> x) {
        cin >> t >> y;
        a = co[s], b = co[t];
        if(a == b) {
            if(x == y)
                cout << "Draw\n";
            else if(x > y)
                cout << "Tobby\n";
            else
                cout << "Naebbirac\n";
        }
        if(a == (b + 2) % 3) {
            if(y >= 2*x)
                cout << "Naebbirac\n";
            else
                cout << "Tobby\n";
        }
        if(a == (b + 1)  % 3) {
            if(x >= 2*y)
                cout << "Tobby\n";
            else
                cout << "Naebbirac\n";
        }
    }
}