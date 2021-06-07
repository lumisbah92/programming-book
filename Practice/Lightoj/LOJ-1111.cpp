#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
const ll mx=100005;

vector<ll>adj[mx];
ll vis[mx];
map<ll,ll>mp;

void dfs(ll u)
{
    vis[u]=1;
    mp[u]++;

    for(auto v:adj[u])
    {
        if(!vis[v])
        {
            dfs(v);
        }
    }
}

int main()
{
    ll t;
    cin>>t;

    for(ll tc=1; tc<=t; tc++)
    {
        ll k,n,m;
        cin>>k>>n>>m;

        vector<ll>v(k);
        for(int i=0; i<k; i++)
        {
            cin>>v[i];
        }

        while(m--)
        {
            ll u,v;
            cin>>u>>v;
            adj[u].pb(v);
        }

        ll ans=0,mxx=0;
        for(int i=0; i<k; i++)
        {
            memset(vis,0,sizeof vis);
            dfs(v[i]);
        }

        for(auto it:mp)
        {
            mxx=max(it.second,mxx);
        }

        for(auto it:mp)
        {
            if(it.second==mxx)
                ans++;
        }

        printf("Case %lld: %lld\n",tc,ans);
        mp.clear();

        for(int i=0; i<=mx; i++)
            adj[i].clear();
    }

    return 0;
}
