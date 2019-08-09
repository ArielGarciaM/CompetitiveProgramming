#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int ct2[5005][11], ct5[5005][11];

string add(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    if(a.size() < b.size())
        swap(a, b);
    while(b.size() < a.size())
        b += '0';
    string res;
    int carry = 0;
    for(int i = 0; i < a.size(); i++) {
        int x = a[i] - '0', y = b[i] - '0';
        if(x + y + carry < 10) {
            res += ('0' + (x + y + carry));
            carry = 0;
        }
        else {
            res += ('0' + (x + y + carry - 10));
            carry = 1;
        }
    }
    if(carry)
        res += '1';
    reverse(res.begin(), res.end());
    return res;
}

string mul5(string s) {
    string ttwo = add(s, s);
    string tfour = add(ttwo, ttwo);
    return add(s, tfour);
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    string s = "1";
    for(int i = 0; i < 5001; i++) {
        //cout << s << '\n';
        for(auto c : s)
            ct2[i][c - '0']++;
        ct2[i][10] = s.size();
        s = add(s, s);
    }
    s = "1";
    for(int i = 0; i < 5001; i++) {
        for(auto c : s)
            ct5[i][c - '0']++;
        ct5[i][10] = s.size();
        s = mul5(s);
    }
    int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        int d = min(a, b);
        a -= d;
        b -= d;
        if(a > 0 || a == b) {
            cout << ct2[a][0] + d << '\n';
            for(int i = 1; i < 10; i++)
                cout << ct2[a][i] << '\n';
            cout << ct2[a][10] + d << '\n';
        }
        else {
            cout << ct5[b][0] + d << '\n';
            for(int i = 1; i < 10; i++)
                cout << ct5[b][i] << '\n';
            cout << ct5[b][10] + d << '\n';
        }
    }
}