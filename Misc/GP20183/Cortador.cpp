#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b)
{
	return a.first < b.first;
}

bool compSnd(pair<int, int> a, pair<int, int> b)
{
	return a.second < b.second;
}

struct node
{
	int l;
	int r;
	int val;
	node(int l = 0, int r = 0, int val = 0) : l(l), r(r), val(val){}
};

node st[400005];
int pos[400005];

void build(int l, int r, int id)
{
	st[id] = node(l, r);
	if(l == r)
		pos[l] = id;
	else
	{
		build(l, (l + r)/2, 2*id);
		build((l + r)/2 + 1, r, 2*id + 1);
	}
}

void update(int lf)
{
	int id = pos[lf];
	node &n = st[id];
	n.val = 1;
	while(id > 0)
	{
		id /= 2;
		st[id].val = st[2*id].val + st[2*id + 1].val;
	}
}

int query(int l, int r, int id)
{
	node n = st[id];
	if(r < n.l || l > n.r || l > r) return 0;
	if(l <= n.l && n.r <= r) return n.val;
	return query(l, r, 2*id) + query(l, r, 2*id + 1);
}

long long inversions(vector<int> &perm)
{
	int n = perm.size();
	build(1, n, 1);
	long long res = 0;
	for(int i = 0; i < n; i++)
	{
		update(perm[i]);
		res += query(perm[i] + 1, n, 1);
	}
	return res;
}

int main()
{
	int x, y;
	cin >> x >> y;
	long long H, V;
	cin >> H >> V;
	vector<pair<int, int>> cuts;
	for(int i = 0; i < H; i++)
	{
		cin >> x >> y;
		cuts.push_back({x, y});
	}
	sort(cuts.begin(), cuts.end(), compSnd);
	for(int i = 0; i < cuts.size(); i++)
		cuts[i].second = i + 1;
	sort(cuts.begin(), cuts.end(), comp);
	vector<int> ends;
	for(auto p : cuts)
		ends.push_back(p.second);
	long long ans = (H + 1)*(V + 1);
	ans += inversions(ends);
	cuts.clear();
	ends.clear();
	for(int i = 0; i < V; i++)
	{
		cin >> x >> y;
		cuts.push_back({x, y});
	}
	sort(cuts.begin(), cuts.end(), compSnd);
	for(int i = 0; i < cuts.size(); i++)
		cuts[i].second = i + 1;
	sort(cuts.begin(), cuts.end(), comp);
	for(auto p : cuts)
		ends.push_back(p.second);
	ans += inversions(ends);
	cout << ans << endl;
}