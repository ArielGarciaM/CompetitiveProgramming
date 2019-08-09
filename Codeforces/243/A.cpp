#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> v;

int val() {
    int pre = -10000000, bst = -10000000;
    for(int i = 0; i < n; i++) {
        pre = max(v[i] + pre, v[i]);
        bst = max(bst, pre);
    }
    return bst;
}

int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    pair<int, int> opt = {0, 0};
    int ans = -10000000, bst = -10000000;
    while(k--) {
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                swap(v[i], v[j]);
                int va = val();
                if(va > bst) {
                    bst = va;
                    opt = {i, j};
                }
                swap(v[i], v[j]);
            }
        }
        ans = max(ans, bst);
        swap(v[opt.first], v[opt.second]);
    }
    cout << ans << endl;
}