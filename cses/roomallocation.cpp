#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k = 0;
    cin >> n;
    vector<array<int, 3>> events;
    vector<int> room(n);
    set<int> available;
    for(int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        events.push_back({l, 1, i});
        events.push_back({r, 2, i});
    }
    sort(events.begin(), events.end());
    for(auto e : events) {
        if(e[1] == 1) {
            if(available.empty())
                room[e[2]] = ++k;
            else {
                room[e[2]] = *available.begin();
                available.erase(available.begin());
            }
        }
        else
            available.insert(room[e[2]]);
    }
    cout << k << '\n';
    for(int i = 0; i < n; i++)
        cout << room[i] << " ";
    cout << '\n';
}