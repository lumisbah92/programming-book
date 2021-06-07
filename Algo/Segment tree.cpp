// Start Time:
#include<bits/stdc++.h>
using namespace std;
#define ff                first
#define ss                second
#define MX                500005
#define ll                long long
#define pb                push_back
#define pi                acos(-1.0)
#define PQ                priority_queue
#define mod               1000000007
#define eps               1/1000000000
#define pii               pair<int,int>
#define pll               pair<ll,ll>
#define endl              "\n"
#define Fast              ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define bug(a)            cout<<#a<<":"<<a<<endl
#define TC(tc)            cout<<"Case "<<tc++<<": "
#define all(x)            (x).begin(),(x).end()
#define allr(x)           (x).rbegin(),(x).rend()
#define MOD(a,b)          (a%mod * b%mod)%mod;
#define mem(a,b)          memset(a, b, sizeof(a))
#define double_print(x,a) cout<<fixed<<setprecision(x)<<a<<endl

ll arr[MX],tree[4*MX];

void init(ll n, ll b, ll e)
{
    if(b==e)
    {
        tree[n]=arr[b];
        return;
    }

    ll mid=(b+e)/2;
    init(2*n,b,mid);
    init(2*n+1,mid+1,e);
    tree[n]=tree[2*n]+tree[2*n+1];
}

void update(ll n, ll b, ll e, ll i, ll val)
{
    if (i > e || i < b)
        return;
    if (b >= i && e <= i)
    {
        tree[n] = val;
        return;
    }

    ll mid=(b+e)/2;
    update(2*n,b,mid,i,val);
    update(2*n+1,mid+1,e,i,val);
    tree[n]=tree[2*n]+tree[2*n+1];
}

ll query(ll n, ll b, ll e, ll i, ll j)
{
    if (i > e || j < b)
        return 0;
    if (b >= i && e <= j)
        return tree[n];
    ll mid=(b+e)/2;

    ll p1=query(2*n,b,mid,i,j);
    ll p2=query(2*n+1,mid+1,e,i,j);
    return (p1+p2);
}


int main()
{
    ll n,q;
    cin>>n>>q;
    for(int i=1; i<=n; i++)
        cin>>arr[i];

    while(q--)
    {

    }


    return 0;
}
