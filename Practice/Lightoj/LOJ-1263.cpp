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

vector<ll>adj[1005];
ll w[1005],vis[1005];
ll cnt=0,val=0;
void dfs(int s)
{
    vis[s]=1;
    cnt++;
    val+=w[s];
    for(auto it:adj[s])
    {
        if(!vis[it])
            dfs(it);
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
        ll sum=0;
        for(int i=1; i<=n; i++){
            cin>>w[i];
            sum+=w[i];
            }
        while(m--)
        {
            ll u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        ll avg=sum/n;
        int ok=1;
        for(int i=1; i<=n; i++)
        {
            if(!vis[i])
            {
                cnt=0,val=0;
                dfs(i);
                if(val%cnt!=0)
                {
                    ok=0;
                    break;
                }
                else
                {
                    if(avg!=(val/cnt))
                    {
                        ok=0;
                        break;
                    }
                }
            }
        }

        cout<<"Case "<<tc++<<": "<<(ok?"Yes":"No")<<endl;

        for(int i=0; i<1005; i++)
        {
            vis[i]=0;
            adj[i].clear();
        }

    }

    return 0;
}

