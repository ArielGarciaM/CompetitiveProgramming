#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
int z[100];

void zfunc(string s) {
    int m = s.length();
    int l = -1, r = -1;
    for(int i = 1; i < m; i++) {
        if(i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while(i + z[i] < m && s[z[i]] == s[i + z[i]])
            z[i]++;
        if(i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
}

int main() {
    string s = "abcdef$aababcabcdabcdeabcdef", t = "abra";
    zfunc(s);
    cout << s << endl;
    cout << "X ";
    for(int i = 1; i < s.length(); i++)
        cout << z[i] << " ";
    cout << endl;
}