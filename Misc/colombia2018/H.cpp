#include <bits/stdc++.h>
using namespace std;

string days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

int leap(int n) {
    return (n/4 - 1866/4 - n/100 + 1866/100 + n/400 - 1866/400);
}

int main() {
    int n;
    cin >> n;
    int y = 1867 + n;
    cout << days[(n + leap(y))%7] << endl;
}