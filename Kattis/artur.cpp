#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

const int MAXN = 5005;
vector<int> adj[MAXN];
pair<ii, ii> seg[MAXN];
bool into[MAXN], seen[MAXN];
queue<int> ts;

double eval(pair<ii, ii> p, int x) {
    int x1 = p.first.first, y1 = p.first.second, x2 = p.second.first, y2 = p.second.second;
    if(x1 == x2)
        return max(y1, y2);
    // y - y1 = (y2 - y1)/(x2 - x1)(x - x1)
    return (((double)(y2 - y1))/((double)(x2 - x1)))*((double)(x - x1)) + y1;
}

bool higher(pair<ii, ii> p1, pair<ii, ii> p2, int x) {
    return (eval(p1, x) > eval(p2, x));
}

void dfs(int s) {
    if(seen[s])
        return;
    seen[s] = true;
    for(auto v : adj[s])
        dfs(v);
    ts.push(s);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 > x2) {
            swap(x1, x2);
            swap(y1, y2);
        }
        seg[i] = make_pair(ii{x1, y1}, ii{x2, y2});
    }
    for(int i = 1; i <= n; i++) {
        int l1 = seg[i].first.first, r1 = seg[i].second.first;
        for(int j = i + 1; j <= n; j++) {
            int l2 = seg[j].first.first, r2 = seg[j].second.first;
            if(min(r1, r2) < max(l1, l2))
                continue;
            int t = min(r1, r2);
            if(higher(seg[i], seg[j], t)) {
                adj[i].push_back(j);
                into[j] = true;
                //cout << i << "->" << j << endl;
            }
            else {
                adj[j].push_back(i);
                into[i] = true;
                //cout << j << "->" << i << endl;
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        if(!into[i])
            dfs(i);
    }
    while(!ts.empty()) {
        int x = ts.front();
        ts.pop();
        cout << x << " ";
    }
    cout << endl;
}