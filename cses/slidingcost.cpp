#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, k;
    multiset<int> small, big;
    ll ssum = 0, bsum = 0;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    for(int i = 0; i < k; i++){
        big.insert(v[i]);
        bsum += v[i];
    }
    while(small.size() < (k + 1)/2) {
        small.insert(*big.begin());
        bsum -= *big.begin();
        ssum += *big.begin();
        big.erase(big.begin());
    }
    cout << bsum - ssum + (k % 2 ? *small.rbegin() : 0) << " ";
    for(int i = k; i < n; i++) {
        int x = v[i - k];
        if(x <= *small.rbegin()) {
            small.erase(small.find(x));
            ssum -= x;
        }
        else {
            big.erase(big.find(x));
            bsum -= x;
        }
        x = v[i];
        if(small.size() && x <= *small.rbegin()) {
            small.insert(x);
            ssum += x;
        }
        else {
            big.insert(x);
            bsum += x;
        }

        while(small.size() < (k + 1)/2) {
            small.insert(*big.begin());
            ssum += *big.begin();
            bsum -= *big.begin();
            big.erase(big.begin());
        }

        while(small.size() > (k + 1)/2) {
            big.insert(*small.rbegin());
            ssum -= *small.rbegin();
            bsum += *small.rbegin();
            small.erase(small.find(*small.rbegin()));
        }
        cout << bsum - ssum + (k % 2 ? *small.rbegin() : 0) << " ";
    }
    cout << '\n';
}