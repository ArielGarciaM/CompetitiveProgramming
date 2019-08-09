#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int k;
    cin >> s >> k;
    bool b = true;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] != s[s.length() - 1 - i]) {
            b = false;
            break;
        }
    }
    cout << (b ? "YES\n" : "NO\n");
}