#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("easy.in", "r", stdin);
    freopen("easy.out", "w", stdout);
    string s, ans = "";
    cin >> s;
    bool fst = true;
    if(s[0] != '-' && s[0] != '+') {
        s = "+" + s;
        fst = false;
    }
    int i = 0;
    while(i < s.length()) {
        if(s[i] == '+') {
            ans += '+';
            i++;
            while(i < s.length() && s[i] != '+' && s[i] != '-') {
                ans += s[i];
                i++;
            }
        }
        else {
            ans += '-';
            i++;
            ans += s[i];
            i++;
            if(i == s.length() || s[i] == '-' || s[i] == '+')
                continue;
            while(s[i] == '0') {
                if(i + 1 == s.length() || s[i + 1] == '+' || s[i + 1] == '-')
                    break;
                ans += '+';
                ans += s[i];
                i++;
            }
            ans += '+';
            while(i < s.length() && s[i] != '+' && s[i] != '-') {
                ans += s[i];
                i++;
            }
        }
    }
    if(fst)
        cout << ans << endl;
    else
        cout << ans.substr(1) << endl;
}