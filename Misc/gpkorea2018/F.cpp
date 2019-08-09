#include <bits/stdc++.h>
using namespace std;

bool seen[5005];
int gdy[5005];
vector<int> v;

int mex() {
    memset(seen, false, sizeof(seen));
    for(auto x : v)
        seen[x] = true;
    for(int i = 0; i < 5005; i++)
        if(!seen[i])
            return i;
}

int main() {
    gdy[1] = gdy[0] = 0;
    for(int n = 2; n <= 5000; n++) {
        v.clear();
        for(int m = 0; m <= n - 2; m++)
            v.push_back(gdy[m]^gdy[n - 2 - m]);
        gdy[n] = mex();
    }
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        cout << (gdy[n] ? "First\n" : "Second\n");
    }
}