#include<bits/stdc++.h>
using namespace std;

struct node
{
    int l, r;
    long long val;
    node(int l = 0, int r = 0, long long val = 0) : l(l), r(r), val(val){}
};

const int MAXN = 1e5;
node tree[4*MAXN + 2];
int pos[MAXN + 2];

void build(int l, int r, vector<long long> &z, int id = 1)
{
    tree[id] = node(l, r);
    if(l == r)
    {
        tree[id].val = z[l];
        pos[l] = id;
    }
    else
    {
        build(l, (l + r)/2, z, 2*id);
        build((l + r)/2 + 1, r, z, 2*id + 1);
        tree[id].val = tree[2*id].val + tree[2*id + 1].val;
    }
}

long long query(int l, int r, int id = 1)
{
    node n = tree[id];
    if(n.l > r || n.r < l || l > r)
        return 0;
    if(n.r <= r && l <= n.l)
        return n.val;
    return query(l, r, 2*id) + query(l, r, 2*id + 1);
}

int n, lb = 2;
long long a;
long long x[100005], y[100005];
vector<long long> z(100005);

long long area(int f, int s)
{
    if(s > n)
        s -= n;
    if(f < s)
    {
        return query(f, s - 1) + x[s]*y[f] - x[f]*y[s];
    }
    if(s < f)
        return a - area(s, f);
    if(a > 0)
        return a;
    return query(1, n);
}

long long bs(int s)
{
    int low = lb, high = n - 2;
    while(low != high)
    {
        //cout << low << " " << high << endl;
        int mid = (low + high + 1)/2;
        long long ar = area(s, s + mid);
        if(ar <= a/2ll) low = mid;
        else high = mid - 1;
    }
    //cout << low << endl;
    lb = low - 1;
    return min(a - area(s, s + low), area(s, s + low + 1));
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
    }
    for(int i = 1; i < n; i++)
    {
        z[i] = x[i]*y[i + 1] - x[i + 1]*y[i];
    }
    z[n] = x[n]*y[1] - x[1]*y[n];
    build(1, n, z);
    a = 0;
    a = area(1, 1);
    long long ans = 0;
    for(int i = 1; i <= n; i++)
    {
        //cout << bs(i) << endl;
        ans = max(ans, bs(i));
    }
    cout << ans << " " << a - ans << endl;
    //cout << area(1, 4) << endl;
}