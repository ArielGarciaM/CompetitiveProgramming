#include <bits/stdc++.h>
using namespace std;

int n, D, R, A, toelim, money[100*100 + 100];
bool ded[100*100 + 100];
char c;

void test_case() {
    memset(ded, false, sizeof ded);
    vector<int> v(n);
    iota(v.begin(), v.end(), 1);
    for(int i = 1; i <= n; i++)
        money[i] = D;
    int cur = 1, turns = 0;
    toelim = -1;
    while(v.size()) {
        //for(auto x : v)
        //    cout << x << ' ';
        //cout << '\n';
        if(v.size() == 1) {
            v.pop_back();
            continue;
        }
        int sz = v.size();
        if(toelim != -1 && v.size() <= 2)
            break;
        int i = 0;
        for(i = 0; i < sz; i++)
            if(v[i] == cur) break;
        turns++;
        cin >> c >> R >> A;
        int next_pos = i;
        if(c == 'C')
            next_pos = (i + R) % sz;
        else
            next_pos = (i - R) % sz;
        if(next_pos < 0)
            next_pos += sz;
        //cout << "travel " << i << " " << next_pos << '\n';
        int u = v[next_pos];
        //cout << "going to " << u << '\n'; 
        if(toelim != -1) {
            for(int i = 0; i < sz; i++) {
                if(v[i] == toelim) {
                    v.erase(v.begin() + i);
                    break;
                }
            }
        }
        sz = v.size();
        toelim = -1;
        if(sz == 1) {
            v.pop_back();
            continue;
        }
        for(i = 0; i < sz; i++)
            if(v[i] == u) break;
        money[u] += A;
        cur = u;
        if(money[u] % 2) {
            toelim = u;
            //cout << "will kill " << u << '\n';
            continue;
        }
        else {
            int ri = (i + 1)%sz, le = (i + sz - 1) % sz;
            int a = v[ri], b = v[le];
            ded[a] = true;
            ded[b] = true;
            for(int i = 0; i < sz; i++) {
                if(v[i] == a) {
                    v.erase(v.begin() + i);
                    break;
                }
            }
            for(int i = 0; i < sz; i++) {
                if(v[i] == b) {
                    v.erase(v.begin() + i);
                    break;
                }
            }
        }
    }
    while(turns < n - 1)
        cin >> c >> R >> A;
    for(int i = 1; i <= n; i++)
        if(!ded[i]) cout << i << " " << money[i] << '\n';
}

int main() {
    while(cin >> n >> D)
        test_case();
}