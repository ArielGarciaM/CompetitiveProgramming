#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, w, h;
    cin >> n >> w >> h;
    int bnd = w * w + h * h;
    while(n-- ){
        int x;
        cin >> x;
        if(x * x <= bnd)
            cout << "DA\n";
        else
            cout << "NE\n";
    }
}