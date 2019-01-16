#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long ans = 0;
    vector<int> sticks(n);
    for(int i = 0; i < n; i++)
        cin >> sticks[i];
    sort(sticks.begin(), sticks.end());
    long long m = sticks[n/2];
    for(int i = 0; i < n; i++)
        ans += abs(m - sticks[i]);
    cout << ans << endl;
}