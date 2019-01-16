#include <bits/stdc++.h>
using namespace std;

int main() {
    int fst = 0, snd = 0, both = 0;
    int t;
    cin >> t;
    while(t--) {
        fst = snd = both = 0;
        int n, a, b;
        cin >> n >> a >> b;
        while(n--) {
            int t;
            cin >> t;
            if(t % a == 0 && t % b == 0) {
                both++;
                continue;
            }
            if(t % a == 0)
                fst++;
            if(t % b == 0)
                snd++;
        }
        if(fst > snd) {
            cout << "BOB\n";
            continue;
        }
        if(snd > fst) {
            cout << "ALICE\n";
            continue;
        }
        cout << (both > 0 ? "BOB\n" : "ALICE\n");
        continue;
    }
}