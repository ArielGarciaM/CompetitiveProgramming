#include <bits/stdc++.h>
using namespace std;

set<int> firsts = {1, 32, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};
set<int> firstsLp = {1, 32, 61, 92, 122, 153, 183, 214, 245, 275, 306, 336};

int solve()
{
    int curDay = 2, curYr = 1901, ans = 0;
    while(curYr <= 2000)
    {
        bool isLeap = (curYr % 400 == 0 || (curYr % 100 && !(curYr % 4)));
        int num = isLeap ? 366 : 365;
        for(int day = 1; day <= num; day++, curDay = (curDay + 1)%7)
        {
            if(curDay == 0)
            {
                if((isLeap && firstsLp.count(day)) || (!isLeap && firsts.count(day)))
                    ans++;
            }
        }
        curYr++;
    }
    return ans;
}

int main()
{
    cout << solve() << endl;
}