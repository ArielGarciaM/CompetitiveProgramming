#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

int main() {
    cout << fixed << setprecision(20);
    long long n, m, k;
    cin >> m >> n >> k;
    if(n < k)
        cout << ((ld)n)/((ld)k) << endl;
    else
        cout << ((ld)(k - 1))/((ld)k) + ((ld)(n - k + 1))/((ld)(k*(n - k + 1 + m))) << endl;
}