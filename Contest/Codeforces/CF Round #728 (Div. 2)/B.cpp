// Start Time:
#include<bits/stdc++.h>
using namespace std;
#define ff                first
#define ss                second
#define MX                1000000
#define ll                long long
#define pb                push_back
#define pi                acos(-1.0)
#define PQ                priority_queue
#define mod               1000000007
#define eps               1/1000000000
#define pii               pair<int,int>
#define pll               pair<ll,ll>
#define endl              "\n"
#define Fast              ios::sync_with_stdio(0) //cin.tie(0); cout.tie(0)
#define bug(a)            cout<<#a<<":"<<a<<endl
#define TC(tc)            cout<<"Case "<<tc++<<": "
#define all(x)            (x).begin(),(x).end()
#define allr(x)           (x).rbegin(),(x).rend()
#define Mul(a,b)          (a%mod * b%mod)%mod
#define Add(a,b)          (a%mod + b%mod)%mod
#define mem(a,b)          memset(a, b, sizeof(a))
#define double_print(x,a) cout<<fixed<<setprecision(x)<<a<<endl
ll tc=1;

ll ans=0;
vector<pll>adj[MX];
ll vis[MX],dis[MX];
void dfs(ll src)
{
    vis[src]=1;
    for(auto it:adj[src])
    {
        if(!vis[it.ff])
        {
            dis[it.ff]=dis[src]+it.ss;
            ans+=it.ss;
            ans-=dis[it.ff];
            if(src!=1)
            ans-=(dis[it.ff]-dis[src]);
            dfs(it.ff);
        }
    }
}

int main()
{
    Fast;

    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll d[n+5];
        for(int i=1; i<=n; i++)
            cin>>d[i];

        ll mx=1;
        for(int i=2; i<=n; i++)
        {
            if(d[mx]>=d[i])
                mx=1;
            adj[mx].pb({i,d[i]-d[mx]});
            mx=i;
        }

        ans=0;
        for(int i=0; i<=n; i++)
            dis[i]=vis[i]=0;
        dfs(1);
        cout<<ans<<endl;

        for(int i=0; i<=n; i++)
            adj[i].clear();
    }

    return 0;
}

