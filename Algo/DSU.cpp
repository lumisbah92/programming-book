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

ll par[MX];
ll Find(ll r)
{
    if(r==par[r])
        return r;
    else
        return par[r]=Find(par[r]);
}

bool Union(ll u, ll v)
{
    ll par_u=Find(u);
    ll par_v=Find(v);

    if(par_u == par_v)
        return false;
    par[par_u]=par_v;
    return true;
}

int main()
{
    Fast;

    ll n,m;
    cin>>n>>m;
    for(ll i=1; i<=n; i++)
        par[i]=i;

    while(m--)
    {
        string s;
        ll u,v;
        cin>>s>>u>>v;
        if(s=="union")
            Union(u,v);
        else
        {
            ll par_u=Find(u);
            ll par_v=Find(v);

            if(par_u == par_v)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
    }

    return 0;
}
