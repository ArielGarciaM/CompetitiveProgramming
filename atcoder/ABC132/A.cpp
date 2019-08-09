#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int ct[26];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    for(auto c : s)
        ct[c - 'A']++;
    for(int i = 0; i < 26; i++) {
        if(ct[i] != 0 && ct[i] != 2) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
}