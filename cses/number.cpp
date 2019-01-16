#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        long long x, y, z, w;
        cin >> y >> x;
        z = max(x, y);
        if(z % 2)
            w = x + z - y;
        else
            w = y + z - x;
        cout << (z - 1)*(z - 1) + w << endl;
    }
}