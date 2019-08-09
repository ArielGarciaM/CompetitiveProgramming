#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string, int> days = {
        {"Monday", 0}, {"Tuesday", 1}, {"Wednesday", 2}, {"Thursday", 3}, {"Friday", 4}, {"Saturday", 5}, {"Sunday", 6}
    };

    int n, x;
    string name;
    cin >> n >> name>> x;
    int d = days[name], ans = 0;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if(d < 5 && a >= x)
            ans++;
        d++;
        if(d >= 7) d -= 7;
    } 
    cout << ans << '\n';
}