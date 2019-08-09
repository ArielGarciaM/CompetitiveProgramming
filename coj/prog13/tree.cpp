#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 5e5 + 5;
int ct[MAXN];

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n;
    while(cin >> n) {
        vector<int> p(n - 2);
        for(auto &x : p) { cin >> x; ct[x]++; }
        set<ii> ans;
        priority_queue<int, vector<int>, greater<int>> leaves;
        for(int i = 1; i <= n; i++)
            if(!ct[i]) leaves.push(i);
        int pt = 0;
        while(pt < n - 2) {
            int u = leaves.top(); leaves.pop();
            int v = p[pt];
            ct[v]--;
            if(!ct[v])
                leaves.push(v);
            if(u > v)
                swap(u, v);
            ans.insert({u, v});
            pt++;
        }
        int u = leaves.top(); leaves.pop();
        int v = leaves.top(); leaves.pop();
        if(u > v)
            swap(u, v);
        ans.insert({u, v});
        for(auto e : ans)
            cout << e.first << " " << e.second << '\n';
    }
}