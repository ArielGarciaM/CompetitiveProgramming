#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

vi kmp(vi s) {
    vi pi(s.size());
    auto f = [&](int i, int j) { return (s[j] && s[i] != s[j]) || (!s[j] && s[i] && s[i] <= j); };
    
    for(int i = 1, j = 0; i < s.size(); i++) {
        while(j && f(i, j)) j = pi[j - 1];
        pi[i] = j += 1 - f(i, j);
    }
    return pi;
}

vi match(vi text, vi pat) {
    pat.push_back(-1);
    vi pi = kmp(pat), res;
    int j = 0;
    auto f = [&](int i, int j) { return (pat[j] && text[i] != pat[j]) || (!pat[j] && text[i] && text[i] <= j); };
    for(int i = 0; i < text.size(); i++) {
        while(j && f(i, j)) j = pi[j - 1];
        j += 1 - f(i, j);
        if(j == pat.size() - 1)
            res.push_back(i);
        //cout << j << " ";
    }
    //cout << endl;
    return res;
}

vi convert(string s) {
    map<char, int> prv;
    vi res;
    for(int i = 0; i < s.size(); i++) {
        res.push_back(prv.count(s[i]) ? i - prv[s[i]] : 0);
        prv[s[i]] = i;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s, t;
    cin >> s;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        t += 'a' + (x - 1);
    }
    vi vs = convert(s), vt = convert(t);
    vi pos = match(vs, vt);
    //for(auto x : vs)
    //    cout << x << " ";
    //cout << endl;
    //for(auto x : vt)
    //    cout << x << " ";
    //cout << endl;
    //if(pos.size() != 1)
        cout << pos.size() << endl;
    //else
    //    cout << s.substr(pos[0] - t.size() + 1, t.size()) << endl;
}