#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;

const int MAXN = 1e5 + 2;
vector<int> primes, adeq[MAXN];
map<int, int> pindices;
int factor[MAXN];

void buildtables()
{
    for(int x = 2; x < MAXN; x++)
    {
        adeq[pindices[factor[x]]].push_back(x);
        //cout << "x = " << x << " has biggest factor " << factor[x] << " added to array for " << pindices[factor[x]] << "-th prime " << endl;
    }
}

void sieve()
{
    int index = 0;
    for(int p = 2; p < MAXN; p++)
    {
        if(!factor[p])
        {
            pindices[p] = index;
            index++;
            primes.push_back(p);
            for(int q = p; q < MAXN; q += p)
                factor[q] = p;
        }
    }
    buildtables();
}

struct node
{
    int l, r, val;
    node(int l = 0, int r = 0, int val = 0) : l(l), r(r), val(val){}
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
        tree[id].val = tree[2*id].val + tree[2*id + 1].val;
    }
}

int query(int l, int r, int id = 1)
{
    node n = tree[id];
    if(l > r || n.l > r || n.r < l)
        return 0;
    if(l <= n.l && n.r <= r)
        return n.val;
    return query(l, r, 2*id) + query(l, r, 2*id + 1);
}

bool cmp(piii p1, piii p2)
{
    return p1.first.first > p2.first.first;
}

vector<piii> queries;

int main()
{
    int q;
    cin >> q;
    for(int i = 0; i < q; i++)
    {
        int n, k;
        cin >> n >> k;
        queries.push_back(make_pair(make_pair(k, n), i));
    }
    sort(queries.begin(), queries.end(), cmp);
    sieve();
    build(1, 100000);
    for(int x = 2; x < MAXN; x++)
    {
        update(x, 1);
    }
    int primeptr = primes.size() - 1;
    vector<pii> ans;
    for(piii p : queries)
    {
        int k = p.first.first, n = p.first.second;
        //cout << n << " " << k << endl;
        while(primeptr >= 0 && primes[primeptr] > k)
        {
            int p = pindices[primes[primeptr]];
            for(auto x : adeq[p])
            {
                //cout << "killed " << x << " with p = " << p << endl;
                update(x, 0);
            }
            primeptr--;
        }
        ans.push_back({p.second, query(2, n)});
    }
    sort(ans.begin(), ans.end());
    for(pii p : ans)
        cout << p.second << endl;
}