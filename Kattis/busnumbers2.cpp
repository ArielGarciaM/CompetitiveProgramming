#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> busNumbers, reps(1600002);
    for(int a = 1; a < 200; a++) {
        for(int b = a; b < 200; b++) {
            int s = a*a*a + b*b*b;
            if(s < reps.size())
                reps[s]++;
        }
    }
    for(int i = 1; i < reps.size(); i++) {
        if(reps[i] >= 2)
            busNumbers.push_back(i);
    }
    int m;
    cin >> m;
    if(m < 1729)
        cout << "none\n";
    else
        cout << *(upper_bound(busNumbers.begin(), busNumbers.end(), m) - 1);
}