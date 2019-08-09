#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    multiset<int> small, big;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    for(int i = 0; i < k; i++)
        big.insert(v[i]);
    while(small.size() < (k + 1)/2) {
        small.insert(*big.begin());
        big.erase(big.begin());
    }
    cout << *small.rbegin() << " ";
    cout.flush();
    for(int i = k; i < n; i++) {
        int x = v[i - k];
        if(x <= *small.rbegin())
            small.erase(small.find(x));
        else
            big.erase(big.find(x));
        x = v[i];
        if(small.size() && x <= *small.rbegin())
            small.insert(x);
        else
            big.insert(x);

        while(small.size() < (k + 1)/2) {
            small.insert(*big.begin());
            big.erase(big.begin());
        }

        while(small.size() > (k + 1)/2) {
            big.insert(*small.rbegin());
            small.erase(small.find(*small.rbegin()));
        }
        cout << *small.rbegin() << " ";
        cout.flush();
    }
    cout << '\n';
}