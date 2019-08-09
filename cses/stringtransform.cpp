#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	string sorted = s;
	sort(sorted.begin(), sorted.end());
	int n = s.length();
	vector<int> pos[30];
	int pd = 0;
	for(int i = 0; i < n; i++) {
		if(s[i] == '#')
			pd = i;
		else
			pos[s[i] - 'a'].push_back(i);
	}
	vector<int> pt(30), to(1000005);
	for(int i = 1; i < n; i++) {
		int d = sorted[i] - 'a';
		to[i] = pos[d][pt[d]++];
	}
	int cu = pd;
	string ans = "";
	while(ans.length() < n - 1) {
		ans += sorted[cu];
		cu = to[cu];
	}
	cout << ans << '\n';
}