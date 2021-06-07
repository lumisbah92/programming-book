/* Flare Up Like A Flame */
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
#define Fast              ios::sync_with_stdio(0); //cin.tie(0); cout.tie(0)
#define bug(a)            cout<<#a<<":"<<a<<endl
#define TC(tc)            cout<<"Case "<<tc++<<": "
#define all(x)            (x).begin(),(x).end()
#define allr(x)           (x).rbegin(),(x).rend()
#define Mul(a,b)          (a%mod * b%mod)%mod;
#define Add(a,b)          (a%mod * b%mod)%mod;
#define mem(a,b)          memset(a, b, sizeof(a))
#define double_print(x,a) cout<<fixed<<setprecision(x)<<a<<endl
ll tc=1;

ll n,m;
vector<ll>adj[MX];
ll tin[MX],low[MX],vis[MX],taken[MX];
ll timer=0,ArtPoint;

void dfs(int v, int p=-1)
{
    vis[v]=1;
    tin[v]=low[v]=timer++;
    int child=0;

    for(auto to:adj[v])
    {
        if(to==p)
            continue;

        if(vis[to])
        {
            low[v]=min(low[v],tin[to]);
            continue;
        }

        dfs(to,v);
        low[v]=min(low[v],low[to]);
        if(low[to]>=tin[v] && p!=-1)
        {
            if(!taken[v])
                ArtPoint++, taken[v]++;
        }
        child++;
    }

    if(p==-1 && child>1)
    {
        if(!taken[v])
            ArtPoint++, taken[v]++;
    }
}

void FindArtPoint()
{
    timer=0;
    for(int i=1; i<=n; i++)
    {
        if(!vis[i])
            dfs(i);
    }
}

void build()
{
    ArtPoint=timer=0;
    for(int i=0; i<=n; i++)
    {
        taken[i]=vis[i]=0;
        tin[i]=low[i]=-1;
        adj[i].clear();
    }
}

int main()
{
    Fast;


    return 0;
}
