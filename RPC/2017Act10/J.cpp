#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> v = {"ioiiiooo", "ioiiooio", "ioioiioo", "ioioioio", "ioiioioo", "iiiioooo", "iiiooioo", "iioiiooo", "iioioioo", "iiioiooo", "iiioooio", "iioiooio", "iiooioio", "iiooiioo"};
    sort(v.begin(), v.end());
    int t;
    cin >> t;
    while(t--) {
        string s, t;
        cin >> s >> t;
        cout << "Output for " << s << " " << t << '\n' << "[\n";
        for(auto pat : v) {
            stack<char> st;
            string an = "";
            int pt = 0;
            for(auto c : pat) {
                if(c == 'i')
                    st.push(s[pt++]);
                else
                    an += st.top(), st.pop();
            }
            if(an == t) {
                for(int i = 0; i < 8; i++) {
                    cout << pat[i];
                    cout << ((i == 7) ? '\n' : ' ');
                }
            }
        }
        cout << "]\n";
    }
}