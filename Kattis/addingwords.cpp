#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int, string> tos;
    map<string, int> toi;
    string s;
    while(getline(cin, s)) {
        stringstream ss(s);
        string type;
        ss >> type;
        if(type == "clear") {
            tos.clear();
            toi.clear();
        }
        if(type == "def") {
            string tok;
            int val;
            ss >> tok >> val;
            if(toi.count(tok))
                tos.erase(toi[tok]);
            toi[tok] = val;
            tos[val] = tok;
        }
        if(type == "calc") {
            bool known = true;
            string tok, op, ans = "";
            int sgn = 0, val = 0;
            while(ss >> tok >> op) {
                ans += tok;
                ans += ' ';
                ans += op;
                ans += ' ';
                if(!toi.count(tok))
                    known = false;
                if(!known)
                    continue;
                if(sgn == 0)
                    val += toi[tok];
                if(sgn == 1)
                    val -= toi[tok];
                if(op == "+")
                    sgn = 0;
                if(op == "-")
                    sgn = 1;
                if(op == "=")
                    break;
            }
            if(!known || !tos.count(val))
                ans += "unknown";
            else
                ans += tos[val];
            cout << ans << endl;
        }
    }
}