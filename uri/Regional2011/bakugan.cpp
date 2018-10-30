#include <bits/stdc++.h>
using namespace std;

int main()
{
    int r;
    int m[10], l[10];
    while(cin >> r, r > 0)
    {
        int sm = 0, sl = 0;
        for(int i = 0; i < r; i++)
        {
            cin >> m[i];
            sm += m[i];
        }
        for(int i = 0; i < r; i++)
        {
            cin >> l[i];
            sl += l[i];
        }
        bool bm, bl;
        bool seen = false;
        for(int i = 2; i < r; i++)
        {
            bm = false;
            bl = false;
            if(!seen && m[i] == m[i - 1] && m[i] == m[i - 2])
            {
                bm = true;
                sm += 30;
            }
            if(!seen && l[i] == l[i - 1] && l[i] == l[i - 2])
            {
                bl = true;
                sl += 30;
            }
            if(bm || bl)
                seen = true;
        }
        if(sm > sl)
            cout << "M\n";
        if(sm == sl)
            cout << "T\n";
        if(sm < sl)
            cout << "L\n";
    }
}