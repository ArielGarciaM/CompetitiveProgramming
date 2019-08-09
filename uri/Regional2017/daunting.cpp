#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct seg {
    int l, r, c;
    bool operator< (const seg& o) const { return tie(l, r) < tie(o.l, o.r); }
};

const int MAX = 1e5 + 5;
set<seg> segs;
int cnt[MAX];

void add_seg(int l, int r, int c) {
    vector<seg> rem, add;
    auto it = segs.upper_bound({r + 1, 0, 0});
    --it;
    while(it->r >= l) {
        //cout << it->l << " " << it->r << endl;
        rem.push_back(*it);
        cnt[it->c] -= (it->r - it->l + 1);
        if(it->l < l)
            add.push_back({it->l, l - 1, it->c});
        if(it->r > r)
            add.push_back({r + 1, it->r, it->c});
        if(it == segs.begin()) break;
        --it;
    }
    add.push_back({l, r, c});
    while(rem.size()) {
        auto s = rem.back(); rem.pop_back();
        segs.erase(s);
    }
    while(add.size()) {
        auto s = add.back(); add.pop_back();
        segs.insert(s);
        cnt[s.c] += (s.r - s.l + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int l, c, n;
    cin >> l >> c >> n;
    segs.insert({0, l, 1});
    cnt[1] = l;
    for(int i = 0; i < n; i++) {
        int p, x;
        ll a, b;
        cin >> p >> x >> a >> b;
        ll s = cnt[p];
        ll m1 = (a + s*s)%((ll)l), m2 = (a + (s + b)*(s + b))%((ll)l);
        if(m1 > m2) swap(m1, m2);
        //cout << "decoded " << m1 << " " << m2 << " " << x << endl;
        /*for(int i = 0; i < c; i++)
            cout << cnt[i] << " ";
        cout << endl;*/
        add_seg(m1, m2, x);
        /*for(int i = 0; i < c; i++)
            cout << cnt[i] << " ";
        cout << endl;*/
    }
    cout << *max_element(cnt, cnt + (c + 1)) << endl;
}

/*
7 5 2
1 2 5 3
3 3 0 1

*/