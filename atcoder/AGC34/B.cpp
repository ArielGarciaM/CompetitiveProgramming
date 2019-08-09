#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s;
    int i = 0, n = s.size();
    while(i < n) {
        if(s[i] != 'B') {
            t += s[i];
            i++;
        }
        else {
            if(i + 1 < n && s[i + 1] == 'C') {
                t += 'X';
                i += 2;
            }
            else {
                t += 'B';
                i++;
            }
        }
    }
    //cout << t << '\n';
    int aseg = 0;
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        if(t[i] == 'B' || t[i] == 'C')
            aseg = 0;
        if(t[i] == 'A')
            aseg++;
        if(t[i] == 'X')
            ans += aseg;
    }
    cout << ans << endl;
}