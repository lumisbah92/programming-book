#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,p,q,x,i,j,ans=0,sum=0;
    vector<int>v;
    cin>>t;

    for(i=1;i<=t;i++)
    {
        cin>>n>>p>>q;
        while(n--)
        {
            cin>>x;
            v.push_back(x);
        }
        sort(v.begin(),v.end());

        for(j=0;j<v.size();j++)
        {
            sum+=v[j];
            if(sum>q)
                break;
            ans++;
        }
//
        int mn=min(ans,p);
        printf("Case %d: %d\n",i,mn);
        sum=0;
        ans=0;
        v.clear();
    }

}
