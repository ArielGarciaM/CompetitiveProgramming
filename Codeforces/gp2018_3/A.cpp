#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 1e5 + 10;
const ll MOD = 1e9 + 7;
int pf[MAXN];
ll B;

void sieve() {
    for(int p = 2; p < MAXN; p++) {
        if(pf[p]) continue;
        for(int m = p; m < MAXN; m += p) pf[m] = p;
    }
}

vector<ii> factor(int n) {
    vector<ii> res;
    while(n > 1) {
        int p = pf[n], ct = 0;
        while(n % p == 0) {
            n /= p;
            ct++;
        }
        res.push_back({p, ct});
    }
    return res;
}

ll sum(int dx) {
    auto f = factor(dx);
}

ll ans(ll bnd) {

}

ll m, n, l, r;

int main() {

}