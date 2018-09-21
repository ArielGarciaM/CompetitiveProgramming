#include <bits/stdc++.h>
using namespace std;

int main()
{
	double u, v;
	cin >> u >> v;
	if(v <= 80.0) cout << "No hay multa\n";
	else cout << fixed << setprecision(2) << "$" << u * min(20.0, (10.0 + (v - 80.0)/8.0)) << endl;
}