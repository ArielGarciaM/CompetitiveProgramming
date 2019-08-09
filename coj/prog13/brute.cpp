#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
int p[MAXN], w[MAXN], taken[MAXN], ans[MAXN], rel[MAXN], po[MAXN], intern[MAXN];

void test_case() {
    int n;
    cin >> n;
    vector<int> leaves, sl;
    for(int i = 1; i < n; i++) {
        int pa, wt;
        cin >> pa >> wt;
        p[i] = pa;
        w[i] = wt;
        intern[pa] = 1;
    }
    for(int i = 0; i < n; i++) {
        if(!intern[i]) {
            leaves.push_back(i);
            ans[i] = INT_MAX;
        }
    }
    do {
        memset(taken, 0, sizeof taken);
        memset(rel, 0, sizeof rel);
        for(auto v : leaves) {
            int u = v;
            while(true) {
                if(taken[u]) break;
                rel[v] += w[u];
                taken[u] = true;
                if(u == 0) break;
                u = p[u];
            }
        }
        sl = leaves;
        sort(sl.begin(), sl.end(), [&](int a, int b) { return rel[a] > rel[b]; });
        ans[sl[0]] = po[sl[0]] = 1;
        for(int i = 1; i < sl.size(); i++) {
            if(rel[sl[i]] < rel[sl[i - 1]])
                po[sl[i]] = i + 1;
            else
                po[sl[i]] = po[sl[i - 1]];
            ans[sl[i]] = min(ans[sl[i]], po[sl[i]]);
        }
    } while(next_permutation(leaves.begin(), leaves.end()));
    for(int i = 0; i < n; i++) {
        if(!intern[i])
            cout << i << " " << ans[i] << '\n';
    }
}

int main() {
    int t;
    cin >> t;
    while(t--)
        test_case();
}