#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

//0 7 8 9 15 16 17 24

vector<vi> rebuild(vi &v) {
    if(v.size() == 1) {
        if(v[0] == 0)
            return vector<vi>(1);
        else
            return {};
    }
    int n = v.size();
    int d = v[n - 1] - v[n - 2];
    //cout << "candidate is " << d << ", " << n << " elements" << endl;
    vector<vi> res;
    // try positive
    queue<int> todo;
    vector<int> pass;
    for(int i = n - 1; i >= 0; i--) {
        if(todo.size() && todo.front() == v[i]) {
            pass.push_back(v[i]);
            todo.pop();
            //cout << "found " << v[i] << endl;
            continue;
        }
        todo.push(v[i] - d);
        //cout << "pushed " << v[i] - d << endl;
    }
    if(todo.empty() && pass.size() == n / 2) {
        reverse(pass.begin(), pass.end());
        auto poss = rebuild(pass);
        for(auto &v : poss) {
            v.push_back(d);
            res.push_back(v);
        }
    }
    todo = queue<int>();
    pass.clear();
    //try negative
    for(int i = 0; i < n; i++) {
        if(todo.size() && todo.front() == v[i]) {
            pass.push_back(v[i]);
            todo.pop();
            continue;
        }
        todo.push(v[i] + d);
    }
    if(todo.empty() && pass.size() == n / 2) {
        auto poss = rebuild(pass);
        for(auto &v : poss) {
            v.push_back(-d);
            res.push_back(v);
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(1 << n);
    for(auto &x : v) cin >> x;
    sort(v.begin(), v.end());
    auto ans = rebuild(v);
    for(auto &v : ans)
        sort(v.begin(), v.end());
    sort(ans.begin(), ans.end());
    auto it = unique(ans.begin(), ans.end());
    ans.resize(distance(ans.begin(), it));
    for(auto &x : ans) {
        for(int i = 0; i < n; i++) {
            if(i) cout << " ";
            cout << x[i];
        }
        cout << '\n';
    }
}