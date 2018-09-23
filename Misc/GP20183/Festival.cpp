#include <bits/stdc++.h>
using namespace std;

struct intervalo
{
	int inicio;
	int fin;
	int val;
	int grupo;
	int compatible;
	bool operator<(const intervalo &in) const {return fin < in.fin;}
};

vector<intervalo> intervalos;

void bs(intervalo &in, int upper)
{
	if(intervalos[0].fin > in.inicio) return;
	int low = 0, high = upper;
	while(low < high)
	{
		int mid = (low + high + 1)/2;
		if(intervalos[mid].fin <= in.inicio) low = mid;
		else high = mid - 1;
	}
	in.compatible = low;
}

int main()
{
	int N;
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		int M;
		cin >> M;
		while(M--)
		{
			int ini, fin, val;
			cin >> ini >> fin >> val;
			intervalo in;
			in.inicio = ini;
			in.fin = fin;
			in.val = val;
			in.grupo = i;
			in.compatible = -1;
			intervalos.push_back(in);
		}
	}
	sort(intervalos.begin(), intervalos.end());
	int m = intervalos.size();
	for(int i = 0; i < m; i++) bs(intervalos[i], i - 1);
	//for(auto in : intervalos) cout << in.inicio << " " << in.fin << " " << in.val << " " << in.grupo << endl;
	long long dp[1024][1001];
	memset(dp, 0, sizeof(dp));
	for(int k = 0; k < m; k++)
	{
		intervalo in = intervalos[k];
		for(int bm = 0; bm < (1 << N); bm++)
		{
			if(k == 0) dp[bm][k] = ((1 << in.grupo) == bm) ? in.val : 0;
			else
			{
				if(in.compatible == -1)
				{
					long long good = ((1 << in.grupo) == bm) ? in.val : 0;
					dp[bm][k] = max(dp[bm][k - 1], good);
				}
				else 
				{
					dp[bm][k] = dp[bm][k - 1];
					if((1 << in.grupo) & bm)
					{
						if(dp[bm][in.compatible] > 0) dp[bm][k] = max(dp[bm][k], in.val + dp[bm][in.compatible]);
						if(dp[bm & ~(1 << in.grupo)][in.compatible] > 0) dp[bm][k] = max(dp[bm][k], in. val + dp[bm & ~(1 << in.grupo)][in.compatible]);
					}
				}
			}
		}
	}
	long long ans = (dp[(1 << N) - 1][m - 1]) ? dp[(1 << N) - 1][m - 1] : -1;
	cout << ans << endl;
}