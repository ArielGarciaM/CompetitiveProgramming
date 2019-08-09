#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	cin.ignore();
	while(t--) {
		string s;
		getline(cin, s);
		stringstream ss(s);
		vector<int> v, mp;
		int x;
		while(ss >> x)
			v.push_back(x);
		int mx = *max_element(v.begin(), v.end());
		for(int i = 0; i < v.size(); i++)
			if(v[i] == mx)
				mp.push_back(i);
		mp.push_back(v.size() - 1);
		int ans = 0;
		for(int i = 1; i < mp.size(); i += 2)
			ans += mp[i] - mp[i - 1] + 1;
		cout << ans << '\n';
	}
}