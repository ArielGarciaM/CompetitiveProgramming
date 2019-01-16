#include <bits/stdc++.h>
using namespace std;

int ct[5005], a[5005], col[5005];

int main() {
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int mcol = 0;
    for(int i = 0; i < n; i++) {
        ct[a[i]]++;
        col[i] = ct[a[i]];
        mcol = max(mcol, col[i]);
    }
    if(mcol > k) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    int pt = 0;
    while(mcol < k) {
        mcol++;
        col[pt++] = mcol;
    }
    for(int i = 0; i < n; i++)
        cout << col[i] << " ";
    cout << endl;
}