#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e10;
const int MAXN = 5e5;

struct node
{
    ll l, r, val;
    node(ll l = 0, ll r = 0, ll val = -INF) : l(l), r(r), val(val){}
};

node tree[2*MAXN + 2];
int pos[2*MAXN + 2];
int A[MAXN];

void build(int l, int r, int id = 1)
{
    tree[id] = node(l, r);
    if(l == r)
    {
        tree[id].val = A[l];
        pos[l] = id;
    }
    else
    {
        int m = (l + r)/2;
        build(1, m, 2*id);
        build(m + 1, r, 2*id + 1);
        tree[id].val = tree[2*id].val + tree[2*id + 1].val;
    }
}

ll query(int l, int r, int id = 1)
{
    
}

int main()
{
    
}