#include <bits/stdc++.h>
using namespace std;

string s;
int pi[105], aut[105][26];

void build() {
    aut[0][s[0] - 'a'] = 1;
    for(int i = 1; i <= s.size(); i++) {
        for(int c = 0; c < 26; c++) {
            if(s[i] == 'a' + c) aut[i][c] = i + 1;
            else aut[i][c] = aut[pi[i - 1]][c];
        }
    }
}

void kmp() {
    for(int i = 1; i < s.size(); i++) {
        int j = pi[i - 1];
        while(j && s[i] != s[j]) j = pi[j - 1];
        pi[i] = j + (s[i] == s[j]);
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    string t;
    cin >> t >> s;
    s += '$';
    kmp();
    for(int i = 0; i < s.size(); i++)
        cout << s[i] << " ";
    cout << '\n';
    for(int i = 0; i < s.size(); i++)
        cout << pi[i] << " ";
    cout << '\n';
    build();
    for(int i = 0; i < s.size(); i++) {
        for(int c = 0; c < 3; c++) {
            cout << i << " " << (char)('a' + c) << " -> " << aut[i][c] << '\n';
        }
    }
}