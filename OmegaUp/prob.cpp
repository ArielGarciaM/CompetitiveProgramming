#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e3 + 5;
const int INF = 1e9;

struct node
{
	int l, r, mx, mn;
	node(int l = 0, int r = 0, int mx = 0, int mn = INF) : l(l), r(r), mx(mx), mn(mn){}
};

node tree[4*MAXN];
int pos[4*MAXN];

void build(int l, int r, int id = 1)
{
	tree[id] = node(l, r);
	if(l == r)
	{
		pos[l] = id;
	}
	else
	{
		build(l, (l + r)/2, 2*id);
		build((l + r)/2 + 1, r, 2*id + 1);
	}
}

void update(int lf, int val)
{
	int id = pos[lf];
	tree[id].mx = tree[id].mn = val;
	while(id > 0)
	{
		id /= 2;
		tree[id].mx = max(tree[2*id].mx, tree[2*id + 1].mx);
		tree[id].mn = min(tree[2*id].mn, tree[2*id + 1].mn);
	}
}

int queryMax(int l, int r, int id = 1)
{
	node n = tree[id];
	if(r < n.l || l > n.r || l > r)
		return 0;
	if(l <= n.l && n.r <= r)
		return n.mx;
	return max(queryMax(l, r, 2*id), queryMax(l, r, 2*id + 1));
}

int queryMin(int l, int r, int id = 1)
{
	node n = tree[id];
	if(r < n.l || l > n.r || l > r)
		return INF;
	if(l <= n.l && n.r <= r)
		return n.mn;
	return min(queryMin(l, r, 2*id), queryMin(l, r, 2*id + 1));
}

int main()
{
	int n;
	vector<pair<int, int>> A;
	vector<int> B(2005);
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		A.push_back({x, i + 1});
	}
	sort(A.begin(), A.end());
	for(int i = 0; i < n; i++)
	{
		auto p = A[i];
		B[p.second] = i + 1;
	}
	int ans = 0;
	int lis[2050], lds[2050];
	for(int i = 2; i <= n; i++)
	{
		int mlis = 1, mlds = 1;
		build(1, n - i + 1);
		lis[0] = 0;
		lis[1] = 1;
		update(B[i], 1);
		for(int j = i + 1; j <= n; j++)
		{
			if(B[j] > B[i])
			{
				lis[j - i + 1] = max(mlis, 1 + queryMax(1, B[j] - 1));
				mlis = max(lis[j - i + 1], mlis);
				update(B[j], j - i + 1);
			}
		}
		build(1, n - i + 1);
		lds[0] = 0;
		lds[1] = 1;
		update(B[i], 1);
		for(int j = i + 1; j <= n; j++)
		{
			if(B[j] < B[i])
			{
				lds[j - i + 1] = max(mlds, 1 + queryMax(B[j] + 1, n));
				mlds = max(lds[j - i + 1], mlds);
				update(B[j], j - i + 1);
			}
		}
		ans = max(ans, mlis + mlds);
	}
	cout << ans << endl;
}