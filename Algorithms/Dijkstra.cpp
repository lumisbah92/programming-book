#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
const ll mx=100005;

ll dis[mx],parent[mx];
vector<pair<ll,ll>>adj[mx];
ll k=0;

void dijkstra(ll s, ll des)
{
    priority_queue<pair<ll,ll>> pq;

    for(int i=0; i<mx; i++)
    {
        dis[i]=1e18;
    }

    pq.push({0ll,s});
    dis[s]= 0ll;
    parent[s]=0ll;
    k=0;

    while(!pq.empty())
    {
        ll u=pq.top().second;
        pq.pop();

        for(auto it:adj[u])
        {
            if(dis[u]+it.second<dis[it.first])
            {
                parent[it.first]=u;
                dis[it.first]=dis[u]+it.second;
                pq.push({-dis[it.first],it.first});

                if(it.first==des)
                    k=1;
            }
        }
    }
}

int main()
{
    ll n,m;
    cin>>n>>m;

    for(ll i=1; i<=m; i++)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }

    k=0;
    dijkstra(1ll,n);

    if(k==0)
        cout<<"-1\n";
    else
    {
        vector<ll>path;
        ll x=n;
        path.pb(x);
        while(x!=1ll)
        {
            x=parent[x];
            path.pb(x);
        }
        reverse(path.begin(),path.end());

        for(auto it:path)
            cout<<it<<" ";
        cout<<endl;
    }


    return 0;
}
