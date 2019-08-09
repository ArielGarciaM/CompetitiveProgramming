#include <bits/stdc++.h>
using namespace std;

int main() {
	bitset<100001> sums;
	int n;
	cin >> n;
	sums[0] = 1;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		for(int w = 100000; w >= x; w--)
			if(sums[w - x]) sums.set(w);
	}
	cout << sums.count() - 1 << '\n';
	for(int i = 1; i <= 100000; i++)
		if(sums[i]) cout << i << " ";
	cout << '\n';
}
