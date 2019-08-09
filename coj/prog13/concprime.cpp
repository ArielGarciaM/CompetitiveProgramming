#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e7 + 5;
int prime[MAXN];

void sieve() {
    prime[0] = prime[1] = 1;
    for(int p = 2; p < MAXN; p++) {
        if(!prime[p]) {
            for(int q = 2*p; q < MAXN; q += p) {
                prime[q] = p;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    sieve();
    int k;
    while(cin >> k) {
        string s;
        cin >> s;
        int n = s.size();
        bool bad = false;
        for(int i = 0; i < n; i += k) {
            string t = s.substr(i, k);
            int a = stoi(t);
            //cout << a << '\n';
            if(prime[a]) {
                bad = true;
                break;
            }
        }
        if(bad)
            cout << ":(\n";
        else
            cout << ":)\n";
    }
}