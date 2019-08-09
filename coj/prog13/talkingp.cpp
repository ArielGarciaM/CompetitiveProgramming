#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    set<char> vo = {'a','e','i','o','u'};
    int n;
    cin >> n;
    cin.ignore();
    while(n--) {
        string s, t;
        getline(cin, s);
        for(auto c : s) {
            t += c;
            if(vo.count(c)) {
                t += 'p';
                t += c;
            }
        }
        cout << t << '\n';
    }
}

