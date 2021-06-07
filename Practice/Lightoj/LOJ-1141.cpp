#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
const ll mx=10005;

vector<int>prime;
int mark[mx];
void sieve()
{
    ll n=10000;
    prime.pb(2);

    for(int i=4; i<=n; i+=2)
        mark[i]=1;
    for(int i=3; i<=n; i+=2)
    {
        if(!mark[i])
        {
            prime.pb(i);
            if(i*i<=n)
            {
                for(int j=i*i; j<=n; j+=i*2)
                    mark[j]=1;
            }
        }
    }
}

vector<int>v;
void div_prime(ll n)
{
    for(int i=0; prime[i]*prime[i]<=n; i++)
    {
        while(n%prime[i]==0)
        {
            v.pb(prime[i]);
            n/=prime[i];
        }
    }
//
    if(n>1)
        v.pb(n);
}

int vis[mx],dis[mx];
int bfs(int src,int des)
{
    queue<int>q;
    memset(vis,0,sizeof vis);
    memset(dis,0,sizeof dis);
    q.push(src);
    vis[src]=1;
    dis[src]=0;

    while(!q.empty())
    {
        int top=q.front();
        q.pop();

        if(top==des)
            return dis[top];

        if(!mark[top])
            continue;
        div_prime(top);

        for(int i=0; i<v.size(); i++)
        {
            int x=top+v[i];
            if(!vis[x] && x<=des)
            {
                vis[x]=1;
                dis[x]=dis[top]+1;
                q.push(x);
            }
        }
        v.clear();
    }

    return -1;
}


int main()
{
    sieve();

    int t;
    cin>>t;
    for(int tc=1; tc<=t; tc++)
    {
        int a,b;
        cin>>a>>b;
        printf("Case %d: %d\n",tc,bfs(a,b));
    }

    return 0;
}
