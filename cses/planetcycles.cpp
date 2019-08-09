#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
int f[MAXN], mark[MAXN];

void dfs(int s) {
	if(mark[s] > 0)
		return;
	if(mark[s] == 0) {
		int cur = f[s], sz = 1;
		while(cur != s) {
			sz++;
			cur = f[cur];
		}
		cur = f[s];
		while(cur != s) {
			mark[cur] = sz;
			cur = f[cur];
		}
		mark[s] = sz;
	}
	if(mark[s] > 0)
		return;
	mark[s] = 0;
	if(mark[f[s]] <= 0)
		dfs(f[s]);
	if(mark[s] == 0)
		mark[s] = mark[f[s]] + 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	fill(mark, mark + MAXN, -1);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> f[i];
	for(int i = 1; i <= n; i++)
		dfs(i);
	for(int i = 1; i <= n; i++)
		cout << mark[i] << " ";
	cout << '\n';
}
