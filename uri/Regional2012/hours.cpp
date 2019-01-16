#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> angs;
    for(int i = 0; i < 720; i += 2) {
        int hpos = 6*(i/12), mpos = 6*(i % 60);
        int d = abs(hpos - mpos);
        angs.insert(min(d, 360 - d));
    }
    int A;
    while(cin >> A) {
        if(angs.find(A) == angs.end())
            cout << "N\n";
        else
            cout << "Y\n";
    }
}