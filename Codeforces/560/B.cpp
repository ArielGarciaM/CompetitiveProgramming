#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v) cin >> x;
    sort(v.begin(), v.end());
    int day = 1;
    for(int i = 0; i < n; i++) {
        if(v[i] < day) continue;
        day++;
    }    
    cout << day - 1 << endl;
}