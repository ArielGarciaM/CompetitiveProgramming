#include <bits/stdc++.h>
using namespace std;

int pos;

int res9(string s) {
    reverse(s.begin(), s.end());
    int tot = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '*')
            s[i] = '0';
        tot += s[i] - '0';
    }
    return tot % 9;
}

int main() {
    int a, b, p;
    string A, B, P;
    cin >> a >> b >> p >> A >> B >> P;
    int x = res9(A), y = res9(B), z = res9(P);
    x = (x * y)%9;
    z = (x - z)%9;
    if(z <= 0) z += 9;
    cout << z << endl;
}