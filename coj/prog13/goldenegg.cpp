#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline void test_case() {
    string s, word;
    char c;
    while(true) {
        getline(cin, s);
        if(s == "*")
            return;
        char en = s[s.size() - 1];
        if((en >= 'a' && en <= 'z') || (en >= 'A' && en <= 'Z'))
            s += '$';
        word = "";
        for(auto c : s) {
            if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
                word += c;
            else {
                reverse(word.begin(), word.end());
                int m = word.size();
                if(m > 1) {
                    if(word[m - 1] >= 'A' && word[m - 1] <= 'Z') {
                        word[m - 1] = word[m - 1] - 'A' + 'a';
                        word[0] = word[0] - 'a' + 'A';
                    }
                }
                cout << word;
                if(c != '$')
                    cout << c;
                word = "";
            }
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();
    while(t--) {
        test_case();
        if(t) cout << '\n';
    }
}

