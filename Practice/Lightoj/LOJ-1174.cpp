#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
const int mx=200;

vector<int>adj[mx];
void dijkstra(int s,int dis[])
{
    priority_queue<pair<int,int>> pq;
    for(int i=0; i<mx; i++)
        dis[i]=1e9;
    pq.push({0,s});
    dis[s]= 0;

    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();

        for(auto it:adj[u])
        {
            if(dis[u]+1<dis[it])
            {
                dis[it]=dis[u]+1;
                pq.push({-dis[it],it});
            }
        }
    }
}

int main()
{
    int t;
    cin>>t;

    for(int tc=1; tc<=t; tc++)
    {
        int n,r;
        cin>>n>>r;

        for(int i=0; i<r; i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        int s,d;
        int dis[mx],dis1[mx];
        cin>>s>>d;
        dijkstra(s,dis);
        dijkstra(d,dis1);

        int ans=0;
        for(int i=0; i<n; i++)
        {
            int x=dis[i]+dis1[i];
            ans=max(ans,x);
        }

        printf("Case %d: %d\n",tc,ans);

        for(int i=0; i<mx; i++)
        {
            adj[i].clear();
        }
    }

}
