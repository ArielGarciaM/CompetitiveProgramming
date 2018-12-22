#include <bits/stdc++.h>
using namespace std;

int n, m, c;
vector<int> times;

bool can(int maxTime) {
    int reqBuses = 1, used = 1, waited = 0, fst = 0;
    for(int i = 1; i < n; i++) {
        waited = times[i] - times[fst];
        used++;
        if(waited > maxTime || used > c) {
            reqBuses++;
            used = 1;
            waited = 0;
            fst = i;
        }
    }
    return reqBuses <= m;
}

int main() {
    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);
    cin >> n >> m >> c;
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        times.push_back(t);
    }
    sort(times.begin(), times.end());
    int low = 0, high = 1e9;
    while(low != high) {
        int mid = (low + high)/2;
        if(can(mid))
            high = mid;
        else
            low = mid + 1;
    }
    cout << low << endl;
}