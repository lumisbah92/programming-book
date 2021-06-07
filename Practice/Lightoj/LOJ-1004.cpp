// Start Time:
#include<bits/stdc++.h>
using namespace std;
#define  ll                     long long
#define  pb                     push_back
#define  pii                    pair<int,int>
#define  pll                    pair<ll,ll>
#define  ff                     first
#define  ss                     second
#define  MX                     1000000
#define  endl                   "\n"
#define  mod                    1000000007
#define  eps                    1/1000000000
#define  pi                     acos(-1.0)
#define  PQ                     priority_queue
#define  mem(a,b)               memset(a, b, sizeof(a))
#define  bug(a)                 cout<<#a<<":"<<a<<endl
#define  all(x)                 (x).begin(),(x).end()
#define  allr(x)                (x).rbegin(),(x).rend()
#define  double_print(x,a)      cout<<fixed<<setprecision(x)<<a<<endl

int n,dp[205][205];
vector<int>v[205];

int fn(int idx, int pre)
{
    if(idx>(2*n-1))
        return 0;

    int &ret=dp[idx][pre];
    if(~ret) return ret;
    ret=0;

    if(v[idx].size()>v[idx-1].size())
    {
        if(pre+1<v[idx].size())
            ret=max(ret,max(v[idx][pre]+fn(idx+1,pre),v[idx][pre+1]+fn(idx+1,pre+1)));
        else
             ret=max(ret,v[idx][pre]+fn(idx+1,pre));
    }
    else
    {
         if(pre-1>=0 && pre>=0 && pre-1<v[idx].size() && pre<v[idx].size())
            ret=max(ret,max(v[idx][pre]+fn(idx+1,pre),v[idx][pre-1]+fn(idx+1,pre-1)));
        else if(pre>=0 && pre<v[idx].size())
             ret=max(ret,v[idx][pre]+fn(idx+1,pre));
        else if(pre-1>=0 && pre-1<v[idx].size())
            ret=max(ret,v[idx][pre-1]+fn(idx+1,pre-1));
    }

    return ret;
}

int main()
{
    //ios::sync_with_stdio(0); //cin.tie(0);

    int t;
    scanf("%d",&t);
    for(int tc=1; tc<=t; tc++)
    {
        scanf("%d",&n);
        mem(dp,-1);
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=i; j++)
            {
                ll x;
                cin>>x;
                v[i].pb(x);
            }
        }

        for(int i=1; i<=n-1; i++)
        {
            for(int j=1; j<=n-i; j++)
            {
                ll x;
                cin>>x;
                v[n+i].pb(x);
            }
        }

        int ans=fn(2,0)+v[1][0];
        printf("Case %d: %d\n",tc,ans);

        for(int i=0; i<205; i++)
            v[i].clear();
    }

    return 0;
}

