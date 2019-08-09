#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    a--;
    b--;
    c--;
    d--;
    string s;
    cin >> s;
    if(c > d) {
        swap(a, b);
        swap(c, d);
    }
    while(a < c || b < d) {
        if(b < d) {
            if(s[b + 1] == '.' && b + 1 != a) {
                b++;
                continue;
            }
            if(s[b + 2] == '.' && b + 2 != a) {
                b += 2;
                continue;
            }
        }
        if(a < c) {
            if(s[a + 1] == '.' && a + 1 != b) {
                a++;
                continue;
            }
            if(s[a + 2] == '.' && a + 2 != b) {
                a += 2;
                continue;
            }
        }
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
}