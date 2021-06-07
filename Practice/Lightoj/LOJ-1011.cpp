#include<bits/stdc++.h>
#define MOD 1000000007
using ll =long long;
using namespace std;

int arr[17][17],dp[17][(1<<16)+5],n;

int Set(int mask, int pos)
{
    return mask=mask|(1<<pos);
}
bool check(int mask, int pos)
{
    return (bool) (mask&(1<<pos));
}

int fn(int i, int mask)
{
    if(i>=n)
        return 0;
    int &ret=dp[i][mask];
    if(~ret) return ret;

    for(int j=0; j<n; j++)
    {
        if(!check(mask,j))
            ret=max(ret,arr[i][j]+fn(i+1,Set(mask,j)));
    }

    return ret;
}

int main()
{
    ll t,tc=1;
    cin>>t;
    while(t--)
    {
        cin>>n;
        memset(dp,-1,sizeof dp);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>arr[i][j];
            }
        }

        int ans=fn(0,0);
        cout<<"Case "<<tc++<<": "<<ans<<endl;
    }
    return 0;
}
