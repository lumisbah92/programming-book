// Start Time:
#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define MX 200005
#define ll long long
#define pb push_back
#define pi acos(-1.0)
#define PQ priority_queue
#define mod 1000000007
#define eps 1/1000000000
#define pii pair<int,int>
#define pll pair<ll,ll>
#define endl "\n"
#define Fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define bug(a) cout<<#a<<":"<<a<<endl
#define all(x) (x).begin(),(x).end()
#define allr(x) (x).rbegin(),(x).rend()
#define mem(a,b) memset(a, b, sizeof(a))
#define double_print(x,a) cout<<fixed<<setprecision(x)<<a<<endl

vector<ll>adj[505];
ll dis[505],vis[505],par[505],ans=1e9;
void bfs(int s)
{
    mem(dis,1e9);
    mem(vis,0);
    mem(par,0);
    queue<ll>q;
    q.push(s);
    vis[s]=1;
    dis[s]=0;
    while(!q.empty())
    {
        int s=q.front();
        q.pop();
        for(auto it:adj[s])
        {
            if(!vis[it])
            {
                vis[it]=1;
                dis[it]=dis[s]+1;
                par[it]=s;
                q.push(it);
            }
            else if(par[s]!=it)
                ans=min(ans,dis[s]+dis[it]+1);
        }
    }
}

int main()
{
    Fast;
    ll t,tc=1;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        while(m--)
        {
            ll u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        ans=1e9;
        for(int i=0; i<n; i++)
            bfs(i);

        cout<<"Case "<<tc++<<": "<<((ans!=1e9)?to_string(ans):"impossible")<<endl;

        for(int i=0; i<505; i++)
            adj[i].clear();
    }

    return 0;
}
