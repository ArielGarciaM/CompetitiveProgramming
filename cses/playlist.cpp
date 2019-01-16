#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, mx = 0, j = 0;
    cin >> n;
    vector<int> songs;
    set<int> st;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        songs.push_back(x);
        while(st.count(x)) {
            st.erase(songs[j]);
            j++;
        }
        st.insert(x);
        mx = max(mx, (int)st.size());
    }
    cout << mx << endl;
}