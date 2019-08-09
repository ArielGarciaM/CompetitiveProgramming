#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.in", "w", stdout);
    int t = 100, n = 4;
    cout << t << '\n';
    while(t) {
        int prime = true;
        for(int d = 2; d*d <= n; d++) {
            if(n % d == 0)
                prime = false;
        }
        if(prime) { n++; continue; }
        t--;
        vector<int> v;
        for(int d = 2; d < n; d++) {
            if(n % d == 0)
                v.push_back(d);
        }
        cout << v.size() << '\n';
        for(int i = 0; i < v.size(); i++)
            cout << v[i] << " ";
        cout << '\n';
        n++;
    }
}