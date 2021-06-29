// Start Time: 20.29
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
#define Fast              ios::sync_with_stdio(0) //cin.tie(0); cout.tie(0)
#define bug(a)            cout<<#a<<":"<<a<<endl
#define TC(tc)            cout<<"Case "<<tc++<<": "
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

    ll t;
    cin>>t;
    while(t--)
    {
        ll a,b,k;
        cin>>a>>b>>k;

        if(a==b && k==1)
        {
            cout<<"NO\n";
            continue;
        }

        ll mn=0;
        ll gcd=__gcd(a,b);
        if(a!=gcd)
            mn++;
        if(b!=gcd)
            mn++;

        ll mx=0;
        for(int i=0; i<prime.size() && prime[i]*prime[i]<=a; i++)
        {
            while(a%prime[i]==0)
            {
                a/=prime[i];
                mx++;
            }
        }

        for(int i=0; i<prime.size() && prime[i]*prime[i]<=b; i++)
        {
            while(b%prime[i]==0)
            {
                b/=prime[i];
                mx++;
            }
        }

        if(a!=1)
            mx++;
        if(b!=1)
            mx++;

        if(k>=mn && k<=mx)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }

    return 0;
}

