// https://codeforces.com/contest/1514/submission/114337876
// Start Time:
#include<bits/stdc++.h>
using namespace std;
#define ff                first
#define ss                second
#define MX                1000005
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
#define Add(a,b)          (a%mod + b%mod)%mod;
#define mem(a,b)          memset(a, b, sizeof(a))
#define double_print(x,a) cout<<fixed<<setprecision(x)<<a<<endl
ll tc=1;

int k,ans[MX],arr[MX],curMax=0;
int mp[MX],cnt[MX];
struct Query
{
    int index,l,r;
    bool operator<(const Query& other)
    {
        int block_own = l/k;
        int block_other = other.l/k;
        if(block_own == block_other)
            return r < other.r;
        return block_own < block_other;
    }
} query[MX];

void add(int index)
{
    cnt[mp[arr[index]]]--;
    mp[arr[index]]++;
    cnt[mp[arr[index]]]++;

    curMax=max(curMax, mp[arr[index]]);
}

void remove(int index)
{
    ll x=mp[arr[index]];
    cnt[mp[arr[index]]]--;
    mp[arr[index]]--;
    cnt[mp[arr[index]]]++;

    if(!cnt[x] && curMax == x)
        curMax = x-1;
}

int main()
{
    Fast;

    ll n,q;
    cin>>n>>q;
    for(int i=1; i<=n; i++)
        cin>>arr[i];
    k=sqrt(n);

    for(int i=1; i<=q; i++)
    {
        cin>>query[i].l>>query[i].r;
        query[i].index = i;
    }
    sort(query+1,query+q+1);

    int l=1,r=0;
    for(int i=1; i<=q; i++)
    {
        while(r<query[i].r)
            add(++r);
        while(l<query[i].l)
            remove(l++);
        while(r>query[i].r)
            remove(r--);
        while(l>query[i].l)
            add(--l);

        int total=query[i].r-query[i].l+1;
        int rem = total- curMax;
        int half = (total/2)+(total%2!=0);

        if(curMax <= half)
            ans[query[i].index] = 1;
        else
            ans[query[i].index]= total - 2*rem;
    }

    for(int i=1; i<=q; i++)
        cout<<ans[i]<<"\n";

    return 0;
}



/////////////////////////////////////////////////////////

https://codeforces.com/contest/86/submission/114343937
// Start Time:
#include<bits/stdc++.h>
using namespace std;
#define ff                first
#define ss                second
#define MX                1000005
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
#define Add(a,b)          (a%mod + b%mod)%mod;
#define mem(a,b)          memset(a, b, sizeof(a))
#define double_print(x,a) cout<<fixed<<setprecision(x)<<a<<endl
ll tc=1;

ll k,ans[MX],arr[MX],res=0;
ll mp[MX],cnt[MX];
struct Query
{
    ll index,l,r;
    bool operator<(const Query& other)
    {
        ll block_own = l/k;
        ll block_other = other.l/k;
        if(block_own == block_other)
            return r < other.r;
        return block_own < block_other;
    }
} query[MX];

void add(ll index)
{
    ll now=mp[arr[index]];
    res-=now*now*arr[index];

    mp[arr[index]]++;

    now=mp[arr[index]];
    res+=now*now*arr[index];
}

void remove(ll index)
{
    ll now=mp[arr[index]];
    res-=now*now*arr[index];

    mp[arr[index]]--;

    now=mp[arr[index]];
    res+=now*now*arr[index];
}

int main()
{
    Fast;

    ll n,q;
    cin>>n>>q;
    for(int i=1; i<=n; i++)
        cin>>arr[i];
    k=sqrt(n);

    for(int i=1; i<=q; i++)
    {
        cin>>query[i].l>>query[i].r;
        query[i].index = i;
    }
    sort(query+1,query+q+1);

    ll l=0,r=-1;
    for(int i=1; i<=q; i++)
    {
        while(r<query[i].r)
            add(++r);
        while(l<query[i].l)
            remove(l++);
        while(r>query[i].r)
            remove(r--);
        while(l>query[i].l)
            add(--l);

        ans[query[i].index]= res;
    }

    for(int i=1; i<=q; i++)
        cout<<ans[i]<<"\n";

    return 0;
}
