#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n, k;
    scanf("%d.%d", &n, &k);
    m = 100*n + k;
    cout << 36000/__gcd(m, 36000) << endl;
}