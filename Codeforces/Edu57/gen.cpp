#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.in", "w", stdout);
    int n = 200000;
    cout << n << endl;
    vector<int> v;
    for(int i = 0; i < n; i++)
        v.push_back(i + 1);
    random_shuffle(v.begin(), v.end());
    for(int i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << endl;
}