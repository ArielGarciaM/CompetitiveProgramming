#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;

const ll INF = 4e18;
ll A, B;
vector<ii> pts;

vi cfrac(ii f) {
    ll a = f.first, b = f.second;
    vi res;
    while(b != 0) {
        res.push_back(a/b);
        a %= b;
        swap(a, b);
    }
    return res;
}

ii compute(vi cont) {
    while(cont.back() == INF)
        cont.pop_back();
    if(cont.size() == 1)
        return {cont[0], 1};
    ll a = 1, b = cont.back();
    cont.pop_back();
    while(cont.size()) {
        a += cont.back()*b;
        cont.pop_back();
        if(cont.size())
            swap(a, b);
    }
    return {a, b};
}

ii bapp(vi c1, vi c2) {
    while(c1.size() < c2.size())
        c1.push_back(INF);
    while(c2.size() < c1.size())
        c2.push_back(INF);
    vi res;
    for(int i = 0; i < c1.size(); i++) {
        if(c1[i] == c2[i])
            res.push_back(c1[i]);
        else {
            res.push_back(min(c1[i], c2[i]) + 1);
            return compute(res);
        }
    }
}

bool fcomp(ii f1, ii f2) {
    return (f1.first * f2.second - f1.second * f2.first) < 0;
}

ii find(ll p, ll q, ll r, ll s) {
    /*
    // find smallest numerator a/b between r/s and p/q.
    // equiv to smallest denom b/a between q/p and s/r if applicable
    // r/s < a/b < p/q <=> q/p < b/a < s/r */
    //cout << r << "/" << s << ", " << p << "/" << q << endl;
    if(r == 0) {
        return {1, q/p + 1};
    }
    if(q == 0) {
        return {r/s + 1, 1};
    }
    ii ans = {INF, INF};
    auto c1 = cfrac({r, s}), c2 = cfrac({p, q});
    auto o1 = c1, o2 = c2;
    o1[o1.size() - 1]--;
    o1.push_back(1);
    o2[o2.size() - 1]--;
    o2.push_back(1);
    ii f = bapp(c1, c2);
    if(f.first < ans.first || (f.first == ans.first && f.second < ans.second))
        ans = f;
    f = bapp(c1, o2);
    if(f.first < ans.first || (f.first == ans.first && f.second < ans.second))
        ans = f;
    f = bapp(o1, c2);
    if(f.first < ans.first || (f.first == ans.first && f.second < ans.second))
        ans = f;
    f = bapp(o1, o2);
    if(f.first < ans.first || (f.first == ans.first && f.second < ans.second))
        ans = f;
    return ans;
}

int main() {
    int T;
    cin >> T;
    for(int tc = 1; tc <= T; tc++) {
        int n;
        cin >> n;
        pts.clear();
        pts.resize(n);
        for(int i = 0; i < n; i++) {
            ll x, y;
            cin >> x >> y;
            pts[i] = {x, y};
        }
        vector<ii> lower = {ii{0, 1}}, upper = {ii{1, 0}};
        bool can = true;
        for(int i = 1; i < n; i++) {
            ll dx = pts[i].first - pts[i - 1].first;
            ll dy = pts[i].second - pts[i - 1].second;
            if(dx >= 0 && dy >= 0)
                continue;
            if(dx <= 0 && dy <= 0) {
                can = false;
                break;
            }
            //a*dx > b*(-dy)
            if(dx > 0 && dy < 0)
                lower.push_back({-dy, dx});
            if(dx < 0 && dy > 0)
                upper.push_back({dy, -dx});
        }
        if(!can)
            cout << "Case #" << tc << ": IMPOSSIBLE\n";
        else {
            ii low = *max_element(lower.begin(), lower.end(), fcomp);
            ii high = *min_element(upper.begin(), upper.end(), fcomp);
            if(low.first*high.second >= low.second*high.first) {
                cout << "Case #" << tc << ": IMPOSSIBLE\n";
                continue;
            }
            ii ans = find(high.first, high.second, low.first, low.second);
            cout << "Case #" << tc << ": " << ans.first << " " << ans.second << '\n';
        }
    }
}