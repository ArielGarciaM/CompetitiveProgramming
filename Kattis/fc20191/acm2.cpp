#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int curt = 0, pen = 0, tot = 0;
    vector<int> rem;
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if(i != k)
            rem.push_back(t);
        else {
            curt += t;
            if(curt <= 300) {
                tot++;
                pen += curt;
            }
        }
    }
    sort(rem.begin(), rem.end());
    for(auto t : rem) {
        curt += t;
        if(curt <= 300) {
            tot++;
            pen += curt;
        }
    }
    cout << tot << " " << pen << endl;
}