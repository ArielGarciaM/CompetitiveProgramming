#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
pair<bool, bool> states[MAXN]; // Can you be leg, can you be chest.
vector<int> children[MAXN];
int ans = 0;

void dfs(int s) {
    int freesons = children[s].size();
    bool trymid = false;
    for(auto v : children[s]) {
        dfs(v);
        if(states[v].second) {
            ans++;
            freesons--;
        }
        else {
            if(states[v].first)
                trymid = true;
        }
    }
    if(freesons >= 2)
        states[s].first = true;
    if(freesons >= 3 && trymid)
        states[s].second = true;
}

int main() {
    int n;
    cin >> n;
    for(int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        children[x].push_back(i);
    }
    dfs(1);
    cout << ans << endl;
}