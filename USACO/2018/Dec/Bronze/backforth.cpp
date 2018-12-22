#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("backforth.in", "r", stdin);
    freopen("backforth.out", "w", stdout);
    vector<int> a(10), b(10);
    for(int i = 0; i < 10; i++)
        cin >> a[i];
    for(int i = 0; i < 10; i++)
        cin >> b[i];
    set<int> poss = {0};
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            poss.insert(b[j] - a[i]);
        }
    }
    for(int i1 = 0; i1 < 10; i1++) {
        for(int i2 = i1 + 1; i2 < 10; i2++) {
            for(int j1 = 0; j1 < 10; j1++) {
                for(int j2 = j1 + 1; j2 < 10; j2++) {
                    poss.insert(b[j1] + b[j2] - a[i1] - a[i2]);
                }
            }
        }
    }
    /*for(auto x : poss)
        cout << x << endl;*/
    cout << poss.size() << endl;
}