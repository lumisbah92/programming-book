// Start Time:
#include<bits/stdc++.h>
using namespace std;
#define ff                first
#define ss                second
#define MX                10000000
#define ll                long long
#define pb                push_back
#define pi                acos(-1.0)
#define PQ                priority_queue
#define mod               1000000007
#define eps               1/1000000000
#define pii               pair<int,int>
#define pll               pair<ll,ll>
#define endl              "\n"
#define Fast              ios::sync_with_stdio(0)//; cin.tie(0); cout.tie(0)
#define bug(a)            cout<<#a<<":"<<a<<endl
#define TC(tc)            cout<<"Case "<<tc++<<": "
#define all(x)            (x).begin(),(x).end()
#define allr(x)           (x).rbegin(),(x).rend()
#define mem(a,b)          memset(a, b, sizeof(a))
#define double_print(x,a) cout<<fixed<<setprecision(x)<<a<<endl
// ll MOD(ll a, ll b){ return (a%mod + b%mod)%mod; }
int tc=1;
vector<bool>mark(MX+5);
vector<int>prime(664600);
int p=0;
void sieve()
{
    int lim=sqrt(MX)+1;
    for(int i=2; i<lim; i++)
    {
        if(!mark[i])
        {
            for(int j=i; j*i<=MX; j++)
                mark[i*j]=1;
        }
    }

    for(int i=2; i<=MX; i++)
    {
        if(!mark[i])
            prime[p++]=i;
    }
}

int NOD ( ll n )
{
    int sqrtn = sqrt ( n );
    int res = 1;
    for ( int i = 0; i < prime.size() && prime[i] <= sqrtn; i++ )
    {
        if ( n % prime[i] == 0 )
        {
            int p = 0;
            while ( n % prime[i] == 0 )
            {
                n /= prime[i];
                p++;
            }
            sqrtn = sqrt ( n );
            res *= p+1;
        }
    }
    if ( n != 1 )
        res *= 2;
    return res;
}

int main()
{
    sieve();
    Fast;
    int t;
    cin>>t;
    while(t--)
    {
        ll a,b;
        cin>>a>>b;
        TC(tc);
        if(a<(b*b))
            cout<<0<<endl;
        else
        {
            ll cnt=NOD(a);
            cnt/=2;
            for(int i=1; i<b; i++)
                if(a%i==0)
                    cnt--;
            cout<<cnt<<endl;
        }
    }

    return 0;
}
