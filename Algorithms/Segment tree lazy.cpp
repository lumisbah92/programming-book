// Start Time:
#include<bits/stdc++.h>
using namespace std;
#define  ll                     long long
#define  pb                     push_back
#define  pii                    pair<int,int>
#define  pll                    pair<ll,ll>
#define  ff                     first
#define  ss                     second
#define  MX                     1000005
#define  endl                   "\n"
#define  mod                    1000000007
#define  eps                    1/1000000000
#define  pi                     acos(-1.0)
#define  PQ                     priority_queue
#define  mem(a,b)               memset(a, b, sizeof(a))
#define  bug(a)                 cout<<#a<<":"<<a<<endl
#define  all(x)                 (x).begin(),(x).end()
#define  allr(x)                (x).rbegin(),(x).rend()
#define  double_print(x,a)      cout<<fixed<<setprecision(x)<<a<<endl

vector<ll>prime;
ll mark[MX+5],arr[MX+5];

void sieve()
{
    ll n = MX;
    mark[1]=1;
    mark[0]=1;
    prime.pb(2);
    for(ll i=4; i<=n; i+=2)
        mark[i]=1;
    for(ll i=3; i<=n; i+=2)
    {
        if(!mark[i])
        {
            prime.pb(i);
            for(ll j=i*i; j<=n; j+=i*2)
                mark[j]=1;
        }
    }
}

ll lazy[500000],tree[500000];

void build(ll node, ll b, ll e)
{
    if(b==e)
        tree[node]=!mark[arr[b]];
    else
    {
        ll left=2*node;
        ll right=2*node+1;
        ll mid=(b+e)/2;
        build(left,b,mid);
        build(right,mid+1,e);
        tree[node]=tree[left]+tree[right];
    }
}

void update(ll node, ll b, ll e, ll l, ll r, ll val)
{
    if(lazy[node])
    {
        tree[node]=(e-b+1)*(!mark[lazy[node]]);
        if(b!=e)
        {
            lazy[2*node]=lazy[node];
            lazy[2*node+1]=lazy[node];
        }
        lazy[node]=0;
    }

    if(l>e || r<b)
        return;
    if(b>=l && e<=r)
    {
        tree[node]=(e-b+1)*(!mark[val]);
        if(b!=e)
        {
            lazy[2*node]=val;
            lazy[2*node+1]=val;
        }
        return;
    }

    ll left=2*node;
    ll right=2*node+1;
    ll mid=(b+e)/2;
    update(left,b,mid,l,r,val);
    update(right,mid+1,e,l,r,val);
    tree[node]=tree[left]+tree[right];
}

ll query(ll node, ll b, ll e, ll l, ll r)
{
    if(lazy[node])
    {
        tree[node]=(e-b+1)*(!mark[lazy[node]]);
        if(b!=e)
        {
            lazy[2*node]=lazy[node];
            lazy[2*node+1]=lazy[node];
        }
        lazy[node]=0;
    }

    if(l>e || r<b)
        return 0;
    if(b>=l && e<=r)
        return tree[node];

    ll left=2*node;
    ll right=2*node+1;
    ll mid=(b+e)/2;
    ll p1=query(left,b,mid,l,r);
    ll p2=query(right,mid+1,e,l,r);
    return (p1+p2);
}

int main()
{
    ios::sync_with_stdio(0); // cin.tie(0);

    sieve();
    ll t;
    cin>>t;
    for(int tc=1; tc<=t; tc++)
    {
        ll n,q;
        cin>>n>>q;
        for(int i=1; i<=n; i++)
            cin>>arr[i];
        build(1,1,n);
        cout<<"Case "<<tc<<":\n";
        while(q--)
        {
            ll type;
            cin>>type;
            if(!type)
            {
                ll l,r,val;
                cin>>l>>r>>val;
                update(1,1,n,l,r,val);
            }
            else
            {
                ll l,r;
                cin>>l>>r;
                cout<<query(1,1,n,l,r)<<endl;
            }
        }

        memset(arr,0,sizeof arr);
        memset(tree,0,sizeof tree);
        memset(lazy,0,sizeof lazy);
    }

    return 0;
}

