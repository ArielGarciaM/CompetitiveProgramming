#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	int curr = M;
	int A[54];
	for(int i = 0; i < N; i++) cin >> A[i];
	for(int i = 0; i < N - 1; i++)
	{
		if(A[i] >= A[i + 1]) continue;
		curr = (curr/A[i])*(A[i + 1]) + (curr%A[i]);
	}
	cout << curr - M << endl;
}