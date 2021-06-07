#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,i,j,x,a,b,c;
    map<int,string>mp;
    vector<int>v;
    string s;

    cin>>t;

    for(j=1; j<=t; j++)
    {
        cin>>n;
        while(n--)
        {
            cin>>s>>a>>b>>c;
            x=a*b*c;

            mp[x]=s;
            v.push_back(x);
        }
//
        sort(v.begin(),v.end());

        if(v[0]!=v[1])
            cout<<"Case "<<j<<": "<<mp[v[v.size()-1]]<<" took chocolate from "<<mp[v[0]]<<endl;
        else
            cout<<"Case "<<j<<": no thief\n";

        v.clear();
        mp.clear();
    }

    return 0;
}
