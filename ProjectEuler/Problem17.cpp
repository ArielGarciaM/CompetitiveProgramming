#include <bits/stdc++.h>
using namespace std;

string conv[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
string tens[10] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
string teens[10] = {"", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

string rep(int n)
{
    int c = n%10;
    n /= 10;
    int b = n%10;
    n /= 10;
    int a = n%10;
    string ans = "";
    if(a > 0)
    {
        ans += conv[a];
        ans += " hundred";
        ans += (b + c > 0) ? " and " : "";
    }
    if(b == 1)
    {
        ans += (c == 0) ? "ten" : teens[c];
    }
    else
    {
        ans += tens[b];
        ans += (b == 0 || c == 0) ? "" : "-";
        ans += (c > 0) ? conv[c] : "";
    }
    return ans;
}

string repEz(int n)
{
    int c = n%10;
    n /= 10;
    int b = n%10;
    n /= 10;
    int a = n%10;
    string ans = "";
    if(a > 0)
    {
        ans += conv[a];
        ans += "hundred";
        ans += (b + c > 0) ? "and" : "";
    }
    if(b == 1)
    {
        ans += (c == 0) ? "ten" : teens[c];
    }
    else
    {
        ans += tens[b];
        ans += (c > 0) ? conv[c] : "";
    }
    return ans;
}

int main()
{
    int ans = 0;
    for(int i = 1; i <= 1000; i++)
        ans += repEz(i).length();
    cout << ans << endl;
}