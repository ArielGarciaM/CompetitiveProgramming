#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, space;
    string s;
    int cnt=1;
    map<string, int> anim;
    vector<string> names;
    while(cin>>n, n!=0){
        cin.ignore();
        for(int i=0; i<n; i++){
            getline(cin, s);
            space=-1;
            for(int j=0; j<s.size(); j++){
                if(s[j]==' ') space=j;
                else s[j]=tolower(s[j]);
            }
            string s2=s.substr(space+1);
            anim[s2]++;
        }
        cout<<"List "<<cnt<<":\n";
        for(auto g:anim) cout<<g.first<<" | "<<g.second<<"\n";
        anim.clear();
        cnt++;
    }
}