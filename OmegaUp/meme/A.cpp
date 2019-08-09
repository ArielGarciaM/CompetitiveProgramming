#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

bool descape(string &s) {
    string t;
    bool escaping = false;
    for(auto c : s) {
        if(escaping) {
            escaping = false;
            if(c == 'x') {
                t += 'x';
                continue;
            }
            if(c == 'p') {
                t += '$';
                continue;
            }
            return false;
        }
        if(c == 'x')
            escaping = true;
        else
            t += c;
    }
    if(escaping)
        return false;
    if(s == t)
        return false;
    s = t;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    set<string> seqs;

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'x') break;
        if(i == s.size() - 1) seqs.insert(s);
    }

    while(descape(s))
        seqs.insert(s);

    cout << seqs.size() << '\n';
    if(seqs.empty())
        cout << "NOSTRING\n";
    else
        cout << *seqs.begin() << '\n';
}