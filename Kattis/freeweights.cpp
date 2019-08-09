#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a, b;

bool check(int m) {
    int lst = -1;
    for(int i = 0; i < n; i++) {
        if(a[i] <= m)
            continue;
        if(lst == -1) {
            lst = a[i];
            continue;
        }
        if(lst != a[i])
            return false;
        lst = -1;
    }
    if(lst != -1)
        return false;
    lst = -1;
    for(int i = 0; i < n; i++) {
        if(b[i] <= m)
            continue;
        if(lst == -1) {
            lst = b[i];
            continue;
        }
        if(lst != b[i])
            return false;
        lst = -1;
    }
    if(lst != -1)
        return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    a.resize(n), b.resize(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];
    int lo = 0, hi = 1e9;
    while(lo < hi) {
        int mi = (lo + hi)/2;
        if(check(mi))
            hi = mi;
        else
            lo = mi + 1;
    }
    cout << lo << endl;
}