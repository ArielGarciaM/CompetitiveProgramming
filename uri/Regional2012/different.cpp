#include <bits/stdc++.h>
using namespace std;

bool good(int n) {
    set<int> digs;
    while(n > 0) {
        if(digs.find(n % 10) != digs.end())
            return false;
        digs.insert(n % 10);
        n /= 10;
    }
    return true;
}

int main() {
    int num[5005];
    for(int i = 1; i < 5005; i++) {
        num[i] = num[i - 1] + (good(i) ? 1 : 0);
    }
    int n, m;
    while(cin >> n) {
        cin >> m;
        cout << num[m] - num[n - 1] << endl;
    }
}