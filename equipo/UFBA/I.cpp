#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 2;
const int INF = 1e9 + 1;

struct node
{
    int l, r, val;
    node(int l = 0, int r = 0, int val = -INF) : l(l), r(r), val(val){}
};

node tree[4*MAXN];
int pos[4*MAXN];

void build(int l, int r, int id = 1)
{
    tree[id] = node(l, r);
    if(l == r)
        pos[l] = id;
    else
    {
        int m = (l + r)/2;
        build(l, m, 2*id);
        build(m + 1, r, 2*id + 1);
    }
}

void update(int lf, int val)
{
    int id = pos[lf];
    tree[id].val = val;
    while(id > 0)
    {
        id /= 2;
        tree[id].val = max(tree[2*id].val, tree[2*id + 1].val);
    }
}

int query(int l, int r, int id = 1)
{
    node n = tree[id];
    if(n.r < l || n.l > r || l > r)
        return -INF;
    if(l <= n.l && n.r <= r)
        return n.val;
    return max(query(l, r, 2*id), query(l, r, 2*id + 1));
}

int bs(int lb, int ub, int bnd)
{
    if(lb > ub)
        return lb - 1;
    if(query(lb, lb) > bnd)
        return lb - 1;
    int low = lb, high = ub;
    while(low < high)
    {
        int mid = (low + high + 1) / 2;
        if(query(lb, mid) <= bnd)
            low = mid;
        else
            high = mid - 1;
    }
    return low;
}

int bs2(int lb, int ub, int bnd)
{
    if(lb > ub)
        return ub + 1;
    if(query(ub, ub) > bnd)
        return ub + 1;
    int low = lb, high = ub;
    while(low < high)
    {
        int mid = (low + high) / 2;
        if(query(mid, ub) <= bnd)
            high = mid;
        else
            low = mid + 1;
    }
    return high;
}

int main()
{
    int n, q;
    cin >> n >> q;
    int h[MAXN];
    for(int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }
    build(1, n - 1);
    for(int i = 1; i <= n - 1; i++)
    {
        update(i, abs(h[i + 1] - h[i]));
    }
    for(int i = 0; i < q; i++)
    {
        int t, p, H;
        cin >> t >> p >> H;
        if(t == 1)
        {
            h[p] = H;
            if(p > 1)
                update(p - 1, abs(h[p] - h[p - 1]));
            if(p < n)
                update(p, abs(h[p + 1] - h[p]));
        }
        else
        {
            int l = bs(p, n - 1, H);
            int u = bs2(1, p - 1, H);
            cout << l - u + 2 << endl;
        }
    }
}