// Start Time:
#include<bits/stdc++.h>
using namespace std;
#define  ll                     long long
#define  pb                     push_back
#define  pii                    pair<int,int>
#define  pll                    pair<ll,ll>
#define  ff                     first
#define  ss                     second
#define  MX                     30005
#define  endl                   "\n"
#define  mod                    1e9+7
#define  pi                     acos(-1.0)
#define  PQ                     priority_queue
#define  mem(a,b)               memset(a, b, sizeof(a))
#define  bug(a)                 cout<<#a<<":"<<a<<endl
#define  all(x)                 (x).begin(),(x).end()
#define  allr(x)                (x).rbegin(),(x).rend()
#define  double_print(x,a)      cout<<fixed<<setprecision(x)<<a<<endl

vector<pll>adj[MX];
ll vis[MX],dis[MX];
ll p,mx=-1;
void dfs(ll s)
{
    vis[s]=1;
    for(auto it:adj[s])
    {
        if(!vis[it.ff])
        {
            dis[it.ff]=dis[s]+it.ss;
            if(dis[it.ff]>mx)
            {
                p=it.ff;
                mx=dis[it.ff];
            }
            dfs(it.ff);
        }
    }
}

int main()
{
    //ios::sync_with_stdio(0); //cin.tie(0);

    ll t;
    cin>>t;
    for(ll tc=1; tc<=t; tc++)
    {
        ll n;
        cin>>n;
        for(int i=1; i<=n-1; i++)
        {
            ll u,v,w;
            cin>>u>>v>>w;
            adj[u].pb({v,w});
            adj[v].pb({u,w});
        }

        mx=-1;
        mem(vis,0);
        mem(dis,0);
        dfs(0);
        mem(vis,0);
        mem(dis,0);
        mx=-1;
        dfs(p);

        cout<<"Case "<<tc<<": "<<mx<<endl;

        for(ll i=0; i<MX; i++){
            adj[i].clear();
            vis[i]=dis[i]=0;
        }
    }

    return 0;
}
