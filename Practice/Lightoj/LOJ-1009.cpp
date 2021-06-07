/**==============================================================*
*            "Bismillahir Rahmanir Raheem"                       *
*        Author          :  Misbah Uddin Tareq.                  *
*        Semester        :  5(C),CSE                             *
*        University      :  Leading University,Sylhet.           *
*===============================================================**/

#include<bits/stdc++.h>
using namespace std;
#define  ll                     long long
#define  pb                     push_back
#define  pii                    pair<int,int>
#define  pll                    pair<ll,ll>
#define  ff                     first
#define  ss                     second
#define  MX                     20005
#define  endl                   "\n"
#define  mod                    1e9+7
#define  pi                     acos(-1.0)
#define  PQ                     priority_queue
#define  mem(a,b)               memset(a, b, sizeof(a))
#define  bug(a)                 cout<<#a<<":"<<a<<endl
#define  all(x)                 (x).begin(),(x).end()
#define  allr(x)                (x).rbegin(),(x).rend()
#define  double_print(x,a)      cout<<fixed<<setprecision(x)<<a<<endl

vector<ll>adj[MX];
ll vis[MX],v=0,l=0;

void bfs(ll s)
{
    queue<ll>q;
    vis[s]=1;
    v++;
    q.push(s);
    while(!q.empty())
    {
        s=q.front();
        q.pop();
        for(auto it:adj[s])
        {
            if(!vis[it])
            {
                if(vis[s]==1)
                    vis[it]=2,l++;
                else
                    vis[it]=1,v++;
                q.push(it);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); //cin.tie(0);

    ll t;
    cin>>t;
    for(int tc=1; tc<=t; tc++)
    {
        ll n;
        cin>>n;
        set<ll>st;
        for(int i=0; i<n; i++)
        {
            ll u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
            st.insert(u);
            st.insert(v);
        }

        ll ans=0;
        mem(vis,0);
        for(auto it:st)
        {
            if(!vis[it])
            {
                v=0,l=0;
                bfs(it);
                ans+=max(v,l);
            }
        }

        cout<<"Case "<<tc<<": "<<ans<<endl;

        for(int i=0; i<MX; i++)
            adj[i].clear();
    }

    return 0;
}
