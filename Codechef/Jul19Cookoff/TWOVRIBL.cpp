#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll X = 0, Y = 0;
    vector<ll> choices;
    while(X < 1000000000) {
        ll P = sqrt(Y);
        while(P * P <= Y)
            P++;
        X = P;
        choices.push_back(X);
        Y += P*P;
    }
    //cout << choices.size();
    //for(auto x : choices)
    //    cout << x << " ";
    //cout << endl;
    int T;
    cin >> T;
    while(T--) {
        int x;
        cin >> x;
        int i = 0;
        for(;i < choices.size(); i++)
            if(choices[i] > x) break;
        cout << i << '\n';
    }
}