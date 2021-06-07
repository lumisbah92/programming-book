#include<bits/stdc++.h>
#define MOD 1000000007
using ll =long long;
using namespace std;

int arr[15][15],dp[(1<<14)+5],n,allmask;

int Set(int mask, int pos)
{
    return mask=mask|(1<<pos);
}
bool check(int mask, int pos)
{
    return (bool) (mask&(1<<pos));
}

int fn(int mask)
{
    if(mask==allmask)
        return 0;

    int &ret=dp[mask];
    if(~ret) return ret;

    ret=1e9;
    for(int i=0; i<n; i++)
    {
        if(!check(mask,i))
        {
            int temp=arr[i][i];
            for(int j=0; j<n; j++)
            {
                if(check(mask,j))
                    temp+=arr[i][j];
            }
            ret=min(ret,temp+fn(Set(mask,i)));
        }
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
        allmask=(1<<n)-1;
        int ans=fn(0);
        cout<<"Case "<<tc++<<": "<<ans<<endl;
    }
    return 0;
}
