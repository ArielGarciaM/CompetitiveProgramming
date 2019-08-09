#include <bits/stdc++.h>
using namespace std;

int cnt[3000];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        for(int i = x; i <= y; i++)
            cnt[i]++;
    }
    for(int i = 1; i < 3000; i++) {
        cnt[i] += cnt[i - 1];
    }
    for(int i = 180; i < 3000; i++) {
        if(cnt[i] - cnt[i - 180] > 90) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
}