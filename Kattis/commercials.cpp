#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 3;
int arr[MAXN];

int main()
{
    int n, p;
    cin >> n >> p;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    long long mn = 0, s = 0, best = 0;
    for(int i = 0; i < n; i++)
    {
        s = s + arr[i] - p;
        best = max(best, s - mn);
        mn = min(mn, s);
    }
    cout << best << endl;
}