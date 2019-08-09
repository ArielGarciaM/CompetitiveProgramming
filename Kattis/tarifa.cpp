#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, n;
    cin >> x >> n;
    int t = (n + 1)*x;
    while(n--){
        int y;
        cin >> y;
        t -= y;
    }
    cout << t << endl;
}