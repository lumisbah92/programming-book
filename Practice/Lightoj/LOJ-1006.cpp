#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
const ll m=10000007;

ll a,b,c,d,e,f;
ll dp[10005];

ll fn(ll n)
{
    if(n==0)
        return a;
    if(n==1)
        return b;
    if(n==2)
        return c;
    if(n==3)
        return d;
    if(n==4)
        return e;
    if(n==5)
        return f;

    if(dp[n]!=-1)
        return dp[n];
    else
    {
        dp[n]=(fn(n-1)%m + fn(n-2)%m + fn(n-3)%m + fn(n-4)%m + fn(n-5)%m + fn(n-6)%m)%m;
        return dp[n];
    }
}

int main()
{
    ll t;
    cin>>t;

    for(ll k=1; k<=t; k++)
    {
        memset(dp,-1,sizeof dp);
        ll n;
        cin>>a>>b>>c>>d>>e>>f>>n;
        printf("Case %lld: %lld\n",k,fn(n)%m);
    }

    return 0;
}
