#include <bits/stdc++.h>
using namespace std;

double eps = 1e-9;

struct point
{
    double x, y;
    point(double x = 0, double y = 0) : x(x), y(y){}
};

struct line
{
    double a, b, c;
    line(double a = 0, double b = 0, double c = 0) : a(a), b(b), c(c){};
    line(point p1, point p2)
    {
        double d = p1.x * p2.y - p1.y * p2.x;
        if(abs(d) < eps)
        {
            a = p1.y;
            b = -p1.x;
            c = 0.0;
        }
        else
        {
            a = (p1.y - p2.y)/d;
            b = (p2.x - p1.x)/d;
            c = 1.0;
        }
    }
};

double dist(point p, line l)
{
    return abs((l.a*p.x + l.b*p.y + l.c)/hypot(l.a, l.b));
}

vector<point> poly;
vector<line> edges;
double middle;
line axis;

double mincirc(double pos)
{
    point p = point(pos, middle);
    double d = 1e9;
    for(line l : edges)
        d = min(d, dist(p, l));
    return d;
}

double ts(double minx, double maxx)
{
    double low = minx, high = maxx;
    for(int i = 0; i < 200; i++)
    {
        double diff = (high - low)/3.0;
        double d1 = mincirc(low + diff), d2 = mincirc(low + 2*diff);
        if(d1 < d2)
            low += diff;
        else
            high -= diff;
    }
    return mincirc(low);
}

int main()
{
    int n;
    double maxy = -1e9, miny = 1e9, maxx = -1e9, minx = 1e9;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        double x, y;
        cin >> x >> y;
        maxy = max(y, maxy);
        miny = min(y, miny);
        maxx = max(x, maxx);
        minx = min(x, minx);
        poly.push_back(point(x, y));
    }
    middle = (maxy + miny)/2.0;
    axis = line(0, -1, middle);
    for(int i = 0; i < n; i++)
    {
        edges.push_back(line(poly[i], poly[(i + 1) % n]));
    }
    cout << fixed << setprecision(10) << ts(minx, maxx) << endl;
}