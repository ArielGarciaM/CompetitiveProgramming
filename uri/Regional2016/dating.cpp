#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<double> rad;
    for(int i = 0; i < n; i++)
    {
        double d;
        cin >> d;
        rad.push_back(d);
    }
    sort(rad.begin(), rad.end());
    vector<double> srad;
    for(int i = 0; i < n; i += 2)
        srad.push_back(rad[i]);
    for(int i = n - (n % 2) - 1; i >= 0; i -= 2)
        srad.push_back(rad[i]);
    double pi = acos(-1);
    double sum = 0.0;
    for(int i = 0; i < n - 1; i++)
    {
        sum += srad[i]*srad[i + 1];
    }
    sum += srad[n - 1]*srad[0];
    cout << fixed << setprecision(3) << sum*sin(2.0*pi/((double)n))/2.0 << endl;
}