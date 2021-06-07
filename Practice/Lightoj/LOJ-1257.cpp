#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
const ll mx=30005;

vector<pair<ll,ll>>adj[mx];
ll vis[mx],dis[mx];
ll a,mxi=0;
void dfs(ll s)
{
    vis[s]=1;
    for(auto it:adj[s])
    {
        if(!vis[it.first])
        {
            dis[it.first]=dis[s]+it.second;
            if(mxi<dis[it.first])
            {
                a=it.first;
                mxi=dis[it.first];
            }
            dfs(it.first);
        }
    }
}

int main()
{
    ll t;
    scanf("%lld",&t);

    for(ll k=1; k<=t; k++)
    {
        ll n;
        scanf("%lld",&n);

        for(int i=0; i<n-1; i++)
        {
            ll u,v,w;
            scanf("%lld %lld %lld",&u,&v,&w);
            adj[u].pb({v,w});
            adj[v].pb({u,w});
        }

        memset(vis,0,sizeof vis);
        memset(dis,0,sizeof dis);
        mxi=0;
        dfs(0);

        memset(vis,0,sizeof vis);
        memset(dis,0,sizeof dis);
        mxi=0;
        dfs(a);

        vector<ll>dis_left;
        for(int i=0; i<n; i++)
            dis_left.pb(dis[i]);

        memset(vis,0,sizeof vis);
        memset(dis,0,sizeof dis);
        mxi=0;
        dfs(a);
//
        vector<ll>dis_right;
        for(int i=0; i<n; i++)
            dis_right.pb(dis[i]);

        printf("Case %lld:\n",k);
        for(int i=0; i<n; i++)
        {
            ll ans=max(dis_left[i],dis_right[i]);
            printf("%lld\n",ans);
        }

        for(int i=0; i<=mx; i++)
        {
            adj[i].clear();
        }

    }

    return 0;
}
