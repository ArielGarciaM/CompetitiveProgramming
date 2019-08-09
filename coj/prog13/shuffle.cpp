#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while(tc--) {
        string s;
        cin >> s;
        string t;
        for(int i = 0; i < s.size(); i++) {
            if(!t.empty() && t[t.size() - 1] == s[i]) continue;
            t += s[i];
        }
        if(t[0] == 'b')
            cout << 2*(t.size()/2) << '\n';
        else
            cout << 1 + 2*((t.size() - 1)/2) << '\n';
    }
}