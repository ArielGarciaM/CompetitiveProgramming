#include<bits/stdc++.h>
using namespace std;

int phi(int n)
{
   int res = 0;
   for(int i = 1; i <= n; i++)
   {
      if(__gcd(n, i) == 1)
         res++;
   }
   return res;
}

int main()
{
   string s;
   cin >> s;
   int n = s.length();
   vector<int> divs;
   for(int i = 1; i < n; i++)
   {
      if(!(n % i))
         divs.push_back(i);
   }
   int res = 0;
   for(auto d : divs)
   {
      bool valido;
      for(int inicio = 0; inicio < d; inicio++)
      {
         valido = true;
         for(int j = inicio, k = 0; k < n/d; j = (j + d)%n, k++)
         {
            if(s[j] == 'P')
            {
               valido = false;
               //break;
            }
         }
         if(valido)
            break;
      }
      if(valido)
         res += phi(n/d);
   }
   cout << res << endl;
}