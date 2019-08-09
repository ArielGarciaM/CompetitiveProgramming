#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    s += '$';
    string t = "";
    for(int i = 0; i < s.length() - 1; i++)
        if(s[i] != s[i + 1])
            t += s[i];
    cout << t << endl;
}