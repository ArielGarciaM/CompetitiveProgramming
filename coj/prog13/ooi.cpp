#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 5e6 + 5;
string entity[MAXN];
int lev[MAXN], dep[MAXN], out[MAXN], ptr[MAXN];
vector<int> rev[MAXN];

struct obj {
    int l, d;
    string e;
    bool operator< (const obj &o) const { return tie(l, d, e) < tie(o.l, o.d, o.e); }
};
vector<obj> ans;

void dfs(int s) {
    //cout << "DFSsing from " << s << '\n';
    lev[s] = 1;
    stack<int> st({s});
    while(!st.empty()) {
        int i = st.top();
        //cout << entity[i] << " " << lev[i] << " " << ptr[i] << '\n';
        bool visit = false;
        for(;ptr[i] < rev[i].size(); ptr[i]++) {
            int v = rev[i][ptr[i]];
            if(!lev[v]) {
                st.push(v);
                lev[v] = 1;
                visit = true;
                break;
            }
        }
        if(visit) continue;
        if(ptr[i] == rev[i].size()) {
            for(auto x : rev[i]) lev[i] = max(lev[i], 1 + lev[x]);
            st.pop();
        }
    }
}

void test_case(int n) {
    fill(lev, lev + 2*n, 0);
    fill(dep, dep + 2*n, 0);
    fill(ptr, ptr + 2*n, 0);
    fill(out, out + 2*n, 0);
    for(int i = 0; i < 2*n; i++)
        rev[i].clear();
    map<string, int> conv;
    int cu = 0;
    for(int i = 0; i < n; i++) {
        string x, y;
        cin >> x >> y;
        if(!conv.count(x)) {
            conv[x] = cu;
            entity[cu] = x;
            cu++;
        }
        if(!conv.count(y)) {
            conv[y] = cu;
            entity[cu] = y;
            cu++;
        }
        int a = conv[x], b = conv[y];
        rev[b].push_back(a);
        dep[b]++;
        out[a]++;
    }
    //for(int i = 0; i < cu; i++)
    //    cout << entity[i] << " " << rev[i].size() << endl;
    for(int i = 0; i < cu; i++)
        if(!out[i]) dfs(i);
    for(int i = 0; i < cu; i++)
        ans.push_back({lev[i], dep[i], entity[i]});
    sort(ans.begin(), ans.end());
    for(auto a : ans)
        cout << a.l << "." << a.d << " " << a.e << '\n';
    ans.clear();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while(cin >> n)
        test_case(n);
}