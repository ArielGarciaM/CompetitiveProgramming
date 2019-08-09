#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while(cin >> n, n != -1) {
        int pre = 0, tot = 0, tra = 0;
        while(n--) {
            int c;
            cin >> c >> tra;
            tra -= pre;
            tot += c * tra;
            pre = pre + tra;
        }
        cout << tot << " miles\n";
    }
}