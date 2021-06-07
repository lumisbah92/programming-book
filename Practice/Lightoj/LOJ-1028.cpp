// Start Time:
#include<bits/stdc++.h>
using namespace std;
#define  ll                     long long
#define  pb                     push_back
#define  pii                    pair<int,int>
#define  pll                    pair<ll,ll>
#define  ff                     first
#define  ss                     second
#define  MX                     1000000
#define  endl                   "\n"
#define  mod                    1000000007
#define  pi                     acos(-1.0)
#define  PQ                     priority_queue
#define  mem(a,b)               memset(a, b, sizeof(a))
#define  bug(a)                 cout<<#a<<":"<<a<<endl
#define  all(x)                 (x).begin(),(x).end()
#define  allr(x)                (x).rbegin(),(x).rend()
#define  double_print(x,a)      cout<<fixed<<setprecision(x)<<a<<endl

vector<ll>prime;
ll mark[MX+5];

void sieve()
{
    ll n = MX;
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

ll NOD(ll n)
{
    ll nod=1;
    for(ll i=0; i<prime.size() && prime[i]*prime[i]<=n; i++)
    {
        ll x=0;
        while(n%prime[i]==0)
        {
            n/=prime[i];
            x++;
        }
        nod*=(x+1);
    }

    if(n>1)
        nod*=2;
    return nod;
}

int main()
{
    ios::sync_with_stdio(0); //cin.tie(0);

    sieve();
    ll t;
    cin>>t;
    for(int tc=1; tc<=t; tc++)
    {
        ll n;
        cin>>n;

        ll ans=NOD(n)-1; // minus 1,becouse problem wants base 2 to infinity.but NOD have divisor 1

        cout<<"Case "<<tc<<": "<<ans<<endl;

    }

    return 0;
}
