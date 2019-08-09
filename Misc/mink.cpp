#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int n;
vi sums;

vi build(int start) {
    vector<int> result({start});
    map<int, int> active;
    for(auto x : sums)
        active[x]++;
    while(result.size() < n) {
        int elem = active.begin()->first - start;
        for(auto x : result) {
            active[elem + x]--;
            if(active[elem + x] == 0)
                active.erase(elem + x);
        }
        result.push_back(elem);
    }
    return result;
}

int main() {
    cin >> n;
    for(int i = 0; i < n*(n - 1)/2; i++) {
        int s;
        cin >> s;
        sums.push_back(s);
    }
    sort(sums.begin(), sums.end());
    for(int i = 2; i < n; i++) {
        vi candidate = build((sums[0] + sums[1] - sums[i]) / 2);
        vi pairwise;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                pairwise.push_back(candidate[i] + candidate[j]);
            }
        }
        sort(pairwise.begin(), pairwise.end());
        if(pairwise == sums) {
            for(int i = 0; i < n; i++)
                cout << candidate[i] << '\n';
            return 0;
        }
    }
}