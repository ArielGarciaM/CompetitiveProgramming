#include <bits/stdc++.h>
using namespace std;

int r1[3], r2[3], e1[3], e2[3];

void move(int dx1, int dy1, int dz1, int dx2, int dy2, int dz2) {
    cout << "(" << r1[0] << " " << r1[1] <<" " << r1[2] <<") (" << r2[0] << " " << r2[1] <<" " << r2[2] << ")\n";
    r1[0] += dx1;
    r1[1] += dy1;
    r1[2] += dz1;
    r2[0] += dx2;
    r2[1] += dy2;
    r2[2] += dz2;
}

int main() {
    int x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4;
    cin >> r1[0] >> r1[1] >> r1[2] >> e1[0] >> e1[1] >> e1[2];
    cin >> r2[0] >> r2[1] >> r2[2] >> e2[0] >> e2[1] >> e2[2];
    if(r1[0] == r2[0])
        move(1, 0, 0, 0, 0, 0);
    if(r1[1] == r2[1])
        move(0, 1, 0, 0, 0, 0);
    if(r1[2] == r2[2])
        move(0, 0, 1, 0, 0, 0);
    int gaxis;
    if(e1[0] != e2[0])
        gaxis = 0;
    if(e1[1] != e2[1])
        gaxis = 1;
    if(e1[2] != e2[2])
        gaxis = 2;
    while(r1[gaxis] != e1[gaxis] || r2[gaxis] != e2[gaxis]) {
        int d1 = 0, d2 = 0;
        if(r1[gaxis] < e1[gaxis])
            d1 = 1;
        if(r1[gaxis] > e1[gaxis])
            d1 = -1;
        if(r2[gaxis] < e2[gaxis])
            d2 = 1;
        if(r2[gaxis] > e2[gaxis])
            d2 = -1;
        if(gaxis == 0)
            move(d1, 0, 0, d2, 0, 0);
        if(gaxis == 1)
            move(0, d1, 0, 0, d2, 0);
        if(gaxis == 2)
            move(0, 0, d1, 0, 0, d2);
    }
    while(r1[0] != e1[0] || r1[1] != e1[1] || r1[2] != e1[2] || r2[0] != e2[0] || r2[1] != e2[1] || r2[2] != e2[2]) {
        int dx1 = 0, dy1 = 0, dz1 = 0, dx2 = 0, dy2 = 0, dz2 = 0;
        if(r1[0] != e1[0])
            dx1 = (r1[0] < e1[0] ? 1 : -1);
        else if(r1[1] != e1[1])
            dy1 = (r1[1] < e1[1] ? 1 : -1);
        else if(r1[2] != e1[2])
            dz1 = (r1[2] < e1[2] ? 1 : -1);
        if(r2[0] != e2[0])
            dx2 = (r2[0] < e2[0] ? 1 : -1);
        else if(r2[1] != e2[1])
            dy2 = (r2[1] < e2[1] ? 1 : -1);
        else if(r2[2] != e2[2])
            dz2 = (r2[2] < e2[2] ? 1 : -1);
        move(dx1, dy1, dz1, dx2, dy2, dz2);
    }
    cout << "(" << r1[0] << " " << r1[1] <<" " << r1[2] <<") (" << r2[0] << " " << r2[1] <<" " << r2[2] << ")\n";
}