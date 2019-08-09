#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int A[MAXN], B[MAXN];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> A[i];
    for(int i = 0; i < n; i++) {
        cin >> B[i];
        B[i] -= A[i];
    }
    map<int, int> cnt;
    for(int i = 0; i < n; i++)
        cnt[B[i]]++;
    int ans = 0;
    for(auto p : cnt)
        ans = max(ans, p.second);
    cout << ans << endl;
}