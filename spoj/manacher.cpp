#include <bits/stdc++.h>
using namespace std;

const int MAX = 5e5 + 5;
int p[2*MAX];

void manacher(string s) {
    int n = s.length(), l = -1, r = -1;
    for(int i = 0; i < n; i++) {
        if(i <= r)
            p[i] = min(r - i, p[l + r - i]);
        while(i + p[i] + 1 < n && i - p[i] - 1 >= 0 && s[i + p[i] + 1] == s[i - p[i] - 1])
            p[i]++;
        if(i + p[i] > r)
            l = i - p[i], r = i + p[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s, t = "*";
    cin >> n >> s;
    for(int i = 0; i < s.length(); i++)
        t += s[i], t += "*";
    manacher(t);
    //cout << t << endl;
    int mx = 0;
    for(int i = 0; i < t.length(); i++)
        mx = max(mx, p[i]);//cout << p[i] << " ";
    cout << mx << endl;
}