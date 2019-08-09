#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	while(cin >> N)
	{
	    int po;
	    cin >> po;
	    po = (1 << N) - po;
	    string s = "";
	    while(po > 1) {
	    	if(po % 2)
	    		s += 'R';
	    	else
	    		s += 'L';
	    	po /= 2;
	    }
	    reverse(s.begin(), s.end());
	    cout << "Instructions: " << s << '\n';
	}
}