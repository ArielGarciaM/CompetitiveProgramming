#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> lens;
    string s;
    cin >> s;
    int cur = 1;
    for(int i = 0; i < s.length() - 1; i++) {
        if(s[i] == s[i + 1])
            cur++;
        else {
            lens.push_back(cur);
            cur = 1;
        }
    }
    lens.push_back(cur);
    cout << *(max_element(lens.begin(), lens.end())) << endl;
}