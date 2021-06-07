#include<bits/stdc++.h>
using namespace std;
using ll =long long;
ll n,k,A[55],C[55],dp[55][1005];
const ll mod= 100000007;
ll MOD(ll a, ll b)
{
    return (a%mod+b%mod)%mod;
}

int rec(int idx,int val)
{
    if(val>k)
        return 0;
    if(val==k)
        return 1;
    if(idx>=n)
        return 0;

    ll &ret=dp[idx][val];
    if(~ret)
        return ret;
    ret=0;

    for(int i=1; i<=C[idx]; i++)
    {
        if(val+(i*A[idx]<=k))
            ret=MOD(ret, rec(idx+1,val+(i*A[idx])));
        else
            break;
    }
    ret=MOD(ret,rec(idx+1,val));
    return ret;
}

int main()
{
    int t,tc=1;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=0; i<n; i++)
            cin>>A[i];
        for(int i=0; i<n; i++)
            cin>>C[i];

        memset(dp,-1,sizeof dp);
        cout<<"Case "<<tc++<<": "<<rec(0,0)<<endl;
    }
}
