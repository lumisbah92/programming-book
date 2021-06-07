#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    int t,n,i,j,p;
    string s,a,b,c,d;
    vector<int>v,x,y,z;
    vector<string>w;
    cin>>t;

    for(j=1; j<=t; j++)
    {
        cin>>s;
        cin>>b;
        d="";
        for(i=0; i<s.size(); i++)
        {
            if(s[i]=='.')
            {
                p=stoi(a);
                v.push_back(p);
                a="";
                continue;
            }
            a+=s[i];
        }
        if(!a.empty())
        {
            p=stoi(a);
            v.push_back(p);
            a="";
        }

        for(i=0;i<v.size();i++)
        {
            while(v[i]!=0)
            {
                d+=((v[i]%2)+'0');
                v[i]/=2;
            }

            while(d.size()!=8)
                d+='0';
            reverse(d.begin(),d.end());

            if(i!=3)
                d+='.';
            c+=d;
            d="";
        }

       // cout<<c<<endl;
        if(c==b)
            cout<<"Case "<<j<<": Yes\n";
        else
            cout<<"Case "<<j<<": No\n";
        v.clear();
        c="";
        b="";
    }

    return 0;
}
