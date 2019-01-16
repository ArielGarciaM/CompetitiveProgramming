#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

int main() {
    int n, m;
    cin >> n >> m;
    vector<ii> a(n), b(m);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = {x, i};
    }
    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;
        b[i] = {x, i};
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for(int i = 0; i < n; i++)
        cout << a[i].second << " " << b[0].second << endl;
    for(int j = 1; j < m; j++)
        cout << a[n - 1].second << " " << b[j].second << endl;
}