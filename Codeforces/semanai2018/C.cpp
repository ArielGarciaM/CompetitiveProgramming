#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, s;
    cin >> n >> s;
    s %= 26;
    s = 26 - s;
    cin.ignore();
    string line;
    for(int l = 0; l < n; l++)
    {
        getline(cin, line);
        for(int i = 0; i < line.length(); i++)
        {
            char c = line[i];
            if((c >= 'a' && c <= 'z'))
            {
                line[i] = 'a' + (c - 'a' + s)%26;
            }
            if((c >= 'A' && c <= 'Z'))
            {
                line[i] = 'A' + (c - 'A' + s)%26;
            }
        }
        cout << line << endl;
    }
}