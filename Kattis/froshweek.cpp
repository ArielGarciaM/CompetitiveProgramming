#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 2;

int n;
long long BIT[MAXN];

void update(int pos, long long val) {
    while(pos <= n){
        BIT[pos] += val;
        pos += pos & (-pos);
    }
}

long long sum(int pos) {
    long long ret = 0;
    while(pos > 0) {
        ret += BIT[pos];
        pos -= pos & (-pos);
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    vector<int> a(n), ca, sa;
    map<int, int> mp;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sa = a;
    sort(sa.begin(), sa.end());
    for(int i = 0; i < n; i++)
        mp[sa[i]] = i + 1;
    for(int i = 0; i < n; i++)
        ca.push_back(mp[a[i]]);
    long long ans = 0;
    for(int i = 1; i <= n; i++)
    {
        int x = ca[i - 1];
        ans += (i - sum(x) - 1);
        update(x, 1);
    }
    cout << ans << endl;
}