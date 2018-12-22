#include <bits/stdc++.h>
using namespace std;

const int MAXN = 60;

int main()
{
    int n, A[MAXN];
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    int ans = n;
    for(int i = 0; i < n - 1; i++)
    {
        if(A[i] >= A[i + 1])
            ans--;
    }
    cout << ans << endl;
}