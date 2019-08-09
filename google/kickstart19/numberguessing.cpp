#include <bits/stdc++.h>
using namespace std;

string query(int x) {
    cout << x << '\n';
    cout.flush();
    string res;
    cin >> res;
    if(res == "WRONG_ANSWER")
        exit(0);
    return res;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int lo, hi, n;
        cin >> lo >> hi >> n;
        lo++;
        while(true) {
            int mi = (lo + hi)/2;
            string s = query(mi);
            if(s == "CORRECT")
                break;
            if(s == "TOO_SMALL")
                lo = mi + 1;
            else
                hi = mi - 1;
        }
    }
}