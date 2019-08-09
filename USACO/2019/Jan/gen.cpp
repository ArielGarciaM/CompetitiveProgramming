#include <bits/stdc++.h>
using namespace std;

int main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    freopen("sleepy.in", "w", stdout);
    int n = 10;
    vector<int> v;
    for(int i = 1; i <= n; i++)
        v.push_back(i);
    shuffle(v.begin(), v.end(), rng);
    cout << n << endl;
    for(int i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << endl;
}