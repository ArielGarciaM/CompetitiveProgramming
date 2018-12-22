#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
int A[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> A[i];
    int len = 1, turns = 0;
    set<pair<int, int>> nxt, segs;
    for(int i = 1; i < n; i++) {
        if(A[i] == A[i + 1])
            len++;
        else {
            nxt.insert({-len, i - len + 1});
            segs.insert({i - len + 1, len});
            len = 1;
        }
    }
    nxt.insert({-len, n - len + 1});
    segs.insert({n - len + 1, len});
    while(!nxt.empty()) {
        turns++;
        pair<int, int> p = *(nxt.begin()), op = {p.second, -p.first};
        nxt.erase(nxt.begin());
        auto it = segs.find(op);
        auto itl = it, ith = it;
        bool fuse = true;
        if(it != segs.begin())
            itl--;
        else
            fuse = false;
        ith++;
        if(ith == segs.end()) {
            fuse = false;
        }
        if(fuse) {
            if(A[itl->first] != A[ith->first])
                fuse = false;
        }
        if(!fuse) {
            segs.erase(it);
            continue;
        }
        pair<int, int> p1 = *ith, p2 = *itl;
        pair<int, int> p3 = {p2.first, p1.second + p2.second};
        segs.erase(itl, ++ith);
        segs.insert(p3);
        nxt.erase({-p1.second, p1.first});
        nxt.erase({-p2.second, p2.first});
        nxt.insert({-p3.second, p3.first});
    }
    cout << turns << endl;
}