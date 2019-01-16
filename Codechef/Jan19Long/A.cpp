#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while(t--) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        string t;
        bool f = false;
        while(ss >> t) {
            if(t == "not")
                f = true;
        }
        cout << (f ? "Real Fancy" : "regularly fancy") << endl;
    }
}