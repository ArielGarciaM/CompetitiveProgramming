#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e4 + 5;
int ctr[MAXN], ctc[MAXN];

int main() {
    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        int n;
        string s;
        cin >> n >> s;
        bool rev = false;
        if(s[0] == 'S') {
            rev = true;
            for(int i = 0; i < 2*n - 2; i++) {
                if(s[i] == 'S')
                    s[i] = 'E';
                else
                    s[i] = 'S';
            }
        }
        string res = "";
        int r = 0, c = 0;
        fill(ctr, ctr + n, 0);
        fill(ctc, ctc + n, 0);
        for(int i = 0; i < 2*n - 2; i++) {
            if(s[i] == 'E') {
                ctr[r]++;
                c++;
            }
            else {
                ctc[c]++;
                r++;
            }
        }
        if(ctr[n - 1] == 0) {
            for(int i = 0; i < n - 1; i++)
                res += 'S';
            for(int i = 0; i < n - 1; i++)
                res += 'E';
        }
        else {
            for(int i = 0; i < n - 1; i++) {
                if(ctr[i] == 0)
                    break;
                res += 'S';
            }
            for(int i = 0; i < n - 1; i++)
                res += 'E';
            while(res.size() < 2*n - 2)
                res += 'S';
        }
        if(rev) {
            for(int i = 0; i < 2*n - 2; i++) {
                if(res[i] == 'S')
                    res[i] = 'E';
                else
                    res[i] = 'S';
            }
        }
        cout << "Case " << tc << ": " << res << '\n';
    }
}