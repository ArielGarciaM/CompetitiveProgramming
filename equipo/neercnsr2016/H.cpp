#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("hash.in", "r", stdin);
    freopen("hash.out", "w", stdout);
    vector<string> ans;
    string s1 = "ed", s2 = "fE";
    int k;
    cin >> k;
    for(int i = 0; i < k; i++) {
        string t = "";
        int m = i;
        for(int d = 0; d < 15; d++) {
            t += (m % 2 ? s1 : s2);
            m /= 2;
        }
        ans.push_back(t);
    }
    for(auto s : ans)
        cout << s << endl;
}