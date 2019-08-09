#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s;
    t = "";
    for(auto c : s)
        if(c >= 'A' && c <= 'Z')
            t += c;
    cout << t << endl;
}