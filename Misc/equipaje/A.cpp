#include <bits/stdc++.h>
using namespace std;

struct planet {
    int sunrise, sunset, len, time;
    planet(int l, int r, int s) {
        len = l;
        sunrise = r;
        sunset = s;
        time = 0;
    }
    void upd() {
        time = (time + 1) % len;
    }
    bool dark() {
        if(sunrise < sunset)
            return(time <= sunrise || sunset <= time);
        else
            return(time >= sunset && time <= sunrise);
    }
};

int main() {
    int n, mx = 0;
    cin >> n;
    vector<planet> planets;
    for(int i = 0; i < n; i++) {
        int h, r, t;
        cin >> h >> r >> t;
        planets.push_back(planet(h, r, t));
        mx = max(h, mx);
    }
    for(int i = 0; i < 1825*mx; i++) {
        bool alldark = true;
        for(int j = 0; j < n; j++) {
            if(!planets[j].dark())
                alldark = false;
            planets[j].upd();
        }
        if(alldark) {
            cout << i << endl;
            return 0;
        }
    }
    cout << "impossible\n";
}