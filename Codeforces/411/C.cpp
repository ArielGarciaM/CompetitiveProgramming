#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int mc = 0;
const int MAXN = 3e5 + 5;
int ptr[MAXN], color[MAXN];
set<int> has[MAXN];
vector<int> of[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    fill(ptr, ptr + MAXN, 1);
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        int s;
        cin >> s;
        while(s--) {
            int x;
            cin >> x;
            of[x].push_back(i);
        }
    }

    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
    }

    for(int x = 1; x <= m; x++) {
        int col = 1;
        for(auto v : of[x])
            col = max(col, ptr[v]);
        color[x] = col;
        mc = max(mc, col);
        for(auto v : of[x]) {
            has[v].insert(col);
            while(has[v].count(ptr[v]))
                ptr[v]++;
        }
    }

    cout << mc << '\n';
    for(int x = 1; x <= m; x++)
        cout << color[x] << " ";
    cout << '\n';
}