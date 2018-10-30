/*
    Author: Ariel Garcia

    Idea: We can compute partial values of the xor for each interval [0, r], then the interval [l, r]
    gives xor equal to 0 only if [0, r] and [0, l - 1] give the same xor. So we want to minimize the sum
    of ct[x]*(ct[x] + 1)/2, where ct[x] is the number of occurences of x in the partial xors. By flipping
    a[i] and a[i + 1] we can flip the i-th partial value and leave the others unaffected. Then we can force
    the minimum by forcing x and complement(x) to have as close to equal counts as possible for each x.
*/
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int a[200005], partial[200005];
    long long n, k;
    cin >> n >> k;
    int x = (1 << k) - 1;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    partial[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        partial[i] = partial[i - 1] ^ a[i];
    }
    long long ans = n*(n + 1ll)/2ll;
    map<int, int> ct;
    for(int i = 0; i <= n; i++)
    {
        ct[min(partial[i], x - partial[i])]++;
    }
    for(auto p : ct)
    {
        int m = p.second;
        if(m % 2 == 0)
        {
            long long b = m/2;
            ans -= b*(b - 1);
        }
        else
        {
            long long b = (m - 1)/2;
            ans -= b*b;
        }
    }
    cout << ans << endl;
}