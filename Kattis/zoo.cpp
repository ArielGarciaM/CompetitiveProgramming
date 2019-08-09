#include <bits/stdc++.h>
using namespace std;

map<string, int> mp;

int main() {
    int n, tc = 0;
    while(cin >> n, n > 0) {
        tc++;
        cin.ignore();
        mp.clear();
        while(n--) {
            string s;
            getline(cin, s);
            for(auto &c : s) {
                if(c >= 'A' && c <= 'Z') {
                    c -= 'A';
                    c += 'a';
                }
            }
            string name;
            stringstream ss(s);
            while(ss >> name){}
            mp[name]++;
        }
        cout << "List " << tc << ":\n";
        for(auto p : mp)
            cout << p.first << " | " << p.second << '\n';
    }
}