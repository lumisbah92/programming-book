// Start Time:
#include<bits/stdc++.h>
using namespace std;
#define ff                first
#define ss                second
#define MX                1000000
#define ll                long long
#define pb                push_back
#define pi                acos(-1.0)
#define mod               1000000007
#define eps               1/1000000000
#define pii               pair<int,int>
#define pll               pair<ll,ll>
#define Fast              ios::sync_with_stdio(0) //cin.tie(0); cout.tie(0)
#define all(x)            (x).begin(),(x).end()
#define allr(x)           (x).rbegin(),(x).rend()
#define Mul(a,b)          (a%mod * b%mod)%mod
#define Add(a,b)          (a%mod + b%mod)%mod
#define mem(a,b)          memset(a, b, sizeof(a))
#define double_print(x,a) cout<<fixed<<setprecision(x)<<a<<endl
ll tc=1;

bool isprime[MX+5];
vector<ll>prime;
void sieve()
{
    for(int i=0; i<MX; i++)
        isprime[i]=true;
    isprime[0]=false,isprime[1]=false;

    for(int i=0; i<MX; i++)
    {
        if(isprime[i])
        {
            prime.pb(i);
            for(int j=i*2; j<MX; j+=i)
                isprime[j]=false;
        }
    }
}

int main()
{
    Fast;

    sieve();

    ll n;
    cin>>n;
    ll arr[n+5];

    ll x=1;
    for(int i=0; prime[i]<=n; i++)
    {
        for(int j=prime[i]; j<=n; j+=prime[i])
            arr[j]=x;
        x++;
    }

    for(int i=2; i<=n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    return 0;
}
