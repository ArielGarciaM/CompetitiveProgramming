#include<bits/stdc++.h>
using namespace std;

const double eps = 1e-6;
const double INF = 1e9;

struct point
{
    double x, y;
    point(double x, double y) : x(x), y(y){}
    point operator+(const point &o)
    {
        return point(x + o.x, y + o.y);
    }
    bool operator!=(const point &o)
    {
        return (abs(x - o.x) > eps || abs(y - o.y) > eps);
    }
};

bool compRU(point p1, point p2)
{
    if(p1.x < p2.x - eps) return true;
    if(abs(p1.x - p2.x) < eps && p1.y < p2.y - eps) return true;
    return false;
}

bool compLD(point p1, point p2)
{
    if(p1.x > p2.x + eps) return true;
    if(abs(p1.x - p2.x) < eps && p1.y > p2.y + eps) return true;
    return false;
}

int main()
{
    int n;
    cin >> n;
    double xmax = -INF, xmin = INF, ymax = -INF, ymin = INF;
    vector<point> reds, blues;
    vector<point> rPoly, bPoly;
    for(int i = 0; i < n; i++)
    {
        int c;
        double x, y;
        cin >> x >> y >> c;
        xmax = max(x, xmax);
        xmin = min(x, xmin);
        ymax = max(y, ymax);
        ymin = min(y, ymin);
        point p = point(x, y);
        if(c == 1)
            blues.push_back(p);
        if(c == 2)
            reds.push_back(p);
    }
    sort(reds.begin(), reds.end(), compRU);
    point st = point(xmin, ymax) + point(-0.4, 1);
    bool fst = true, fstchain = false;
    rPoly.push_back(st);
    double prevx = -INF, sy = ymax + 0.9;
    for(point p : reds)
    {
        if(abs(p.x - prevx) > eps)
        {
            if(!fst)
            {
                if(rPoly.back() != point(prevx - 0.3, sy))
                    rPoly.push_back(point(prevx - 0.3, sy));
                if(rPoly.back() != point(p.x - 0.4, sy))
                    rPoly.push_back(point(p.x - 0.4, sy));
            }
            else
            {
                if(rPoly.back() != point(xmin - 0.4, sy))
                    rPoly.push_back(point(xmin - 0.4, sy));
                if(rPoly.back() != point(p.x - 0.4, sy))
                    rPoly.push_back(point(p.x - 0.4, sy));
            }
            fstchain = true;
        }

        if(fstchain)
            rPoly.push_back(p + point(-0.4, -0.1));
        else
            rPoly.push_back(p + point(-0.3, -0.1));
        rPoly.push_back(p + point(0.1, -0.1));
        rPoly.push_back(p + point(0.1, 0.1));
        rPoly.push_back(p + point(-0.3, 0.1));
        prevx = p.x;
        fst = false;
    }
    rPoly.push_back(point(prevx - 0.3, sy + 0.1));
    cout << rPoly.size() << endl;
    for(auto p : rPoly)
        cout << p.x << " " << p.y << endl;


    // Azules

    sort(blues.begin(), blues.end(), compLD);
    st = point(xmax, ymin) + point(0.4, -1);
    fst = true, fstchain = false;
    bPoly.push_back(st);
    prevx = -INF, sy = ymin - 0.9;
    for(point p : blues)
    {
        if(abs(p.x - prevx) > eps)
        {
            if(!fst)
            {
                if(bPoly.back() != point(prevx + 0.3, sy))
                    bPoly.push_back(point(prevx + 0.3, sy));
                if(bPoly.back() != point(p.x + 0.4, sy))
                    bPoly.push_back(point(p.x + 0.4, sy));
            }
            else
            {
                if(bPoly.back() != point(xmax + 0.4, sy))
                    bPoly.push_back(point(xmax + 0.4, sy));
                if(bPoly.back() != point(p.x + 0.4, sy))
                    bPoly.push_back(point(p.x + 0.4, sy));
            }
            fstchain = true;
        }
        else
            fstchain = false;

        if(fstchain)
            bPoly.push_back(p + point(0.4, 0.1));
        else
            bPoly.push_back(p + point(0.3, 0.1));
        bPoly.push_back(p + point(-0.1, 0.1));
        bPoly.push_back(p + point(-0.1, -0.1));
        bPoly.push_back(p + point(0.3, -0.1));
        prevx = p.x;
        fst = false;
    }
    bPoly.push_back(point(prevx + 0.3, sy - 0.1));
    cout << bPoly.size() << endl;
    for(auto p : bPoly)
        cout << p.x << " " << p.y << endl;
}