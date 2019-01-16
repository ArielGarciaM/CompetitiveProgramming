#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    multiset<int> ppl;
    for(int i = 0; i < n; i++) {
        int w;
        cin >> w;
        ppl.insert(w);
    }
    int rem = x, ct = 1, sf = 0;
    while(!ppl.empty()) {
        auto it = ppl.upper_bound(rem);
        if(it == ppl.begin() || sf == 2) {
            rem = x;
            sf = 0;
            ct++;
        }
        else {
            sf++;
            --it;
            rem -= *it;
            ppl.erase(it);
        }
    }
    cout << ct << endl;
}