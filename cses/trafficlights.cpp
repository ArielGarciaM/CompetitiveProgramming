#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    map<int, int, greater<int>> segs;
    set<int> pts;
    int x, n;
    cin >> x >> n;
    segs[x] = 1;
    pts.insert(0);
    pts.insert(x);
    while(n--) {
        int p, upp, low;
        cin >> p;
        auto it = pts.lower_bound(p);
        upp = *it;
        --it;
        low = *it;
        segs[upp - low]--;
        if(segs[upp - low] == 0)
            segs.erase(upp - low);
        segs[p - low]++;
        segs[upp - p]++;
        pts.insert(p);
        cout << segs.begin()->first << " ";
    }
    cout << '\n';
}