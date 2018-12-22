#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    double amt, price;
    cin >> n >> amt;
    switch(n)
    {
        case 1:
            price = 4.00;
            break;
        case 2:
            price = 4.50;
            break;
        case 3:
            price = 5.00;
            break;
        case 4:
            price = 2.00;
            break;
        case 5:
            price = 1.50;
            break;
    }
    cout << "Total: R$ " << fixed << setprecision(2) << amt*price << endl;
}