#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,ans=0,i,x;
    cin>>t;

    for(i=1;i<=t;i++)
    {
        cin>>n;
        while(n--)
        {
            cin>>x;
            if(x>=0)
                ans+=x;
        }
        printf("Case %d: %d\n",i,ans);
        ans=0;
    }

    return 0;
}
