#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;

vi lis(vi S) {
    vi prev(S.size());
    vector<ii> res;
    for(int i = 0; i < S.size(); i++) {
        ii el {S[i], i};
        auto it = lower_bound(res.begin(), res.end(), ii {S[i] + 1 , 0});
        if(it == res.end()) {
            res.push_back(el);
            it = --res.end();
        }
        *it = el;
        prev[i] = (it == res.begin() ? 0 : (it - 1)->second);
    }
    int L = res.size(), cur = res.back().second;
    vi ans(L);
    while(L--)
        ans[L] = cur, cur = prev[cur];
    return ans;
}


int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    cout << (lis(v)).size() << endl;
}