#include <bits/stdc++.h>
using namespace std;

int ans = 0;

struct trie {
    char c;
    map<char, trie*> sons;

    trie(char c) : c(c){}

    void add(string &s, int pos = 0) {
        if(pos == s.length())
            sons['*'] = new trie('*');
        else {
            if(!sons.count(s[pos]))
                sons[s[pos]] = new trie(s[pos]);
            sons[s[pos]]->add(s, pos + 1);
        }
    }

    int dfs() {
        int d = (c == '*' ? 1 : 0);
        for(auto p : sons)
            d += p.second->dfs();
        if(sons.size() >= 2 || c == '$') {
            if(sons.count('*'))
                ans += d - 1;
            else
                ans += d;
        }
        return d;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin >> n) {
        ans = 0;
        trie tr('$');
        string s;
        for(int i = 0; i < n; i++) {
            cin >> s;
            tr.add(s);
        }
        tr.dfs();
        cout << fixed << setprecision(2) << (double)ans/(double)n << endl;
    }
}