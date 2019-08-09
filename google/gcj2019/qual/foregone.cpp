#include <bits/stdc++.h>
using namespace std;

int ct[10];
string s;

pair<string, string> solve() {
    string x = "", y = "";
    for(int i = 0; i < s.length(); i++) {
        int m = s[i] - '0';
        if(m == 5) {
            x += '2';
            y += '3';
        }
        else if(m == 0) {
            x += '0';
            y += '0';
        }
        else {
            x += (char)('0' + m - 1);
            y += '1';
        }
    }
    for(int i = 0; i < x.size(); i++) {
        if(x[i] != '0') {
            x = x.substr(i);
            break;
        }
    }
    for(int i = 0; i < y.size(); i++) {
        if(y[i] != '0') {
            y = y.substr(i);
            break;
        }
    }
    return {x, y};
}

int main() {
    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        cin >> s;
        fill(ct, ct + 10, 0);
        for(auto c : s)
            ct[c - '0']++;
        bool done = false;
        for(int i = 2; i < 10; i++) {
            if(ct[i] > 0) {
                auto r = solve();
                cout << "Case #" << tc << ": " << r.first << " " << r.second << '\n';
                done = true;
                break;
            }
        }
        if(done)
            continue;
        if(ct[1] == 1) {
            string r = "5";
            for(int i = 0; i < ct[0] - 1; i++)
                r += "0";
            cout << "Case #" << tc << ": " << r << " " << r << '\n';
            continue;
        }
        string r1 = "1";
        for(int i = 0; i < s.length() - 1; i++)
            r1 += "0";
        string r2;
        for(int i = 1; i < s.length(); i++) {
            if(s[i] == '1') {
                r2 = s.substr(i);
                break;
            }
        }
        cout << "Case #" << tc << ": " << r1 << " " << r2 << '\n';
    }
}