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

/////////////////////////////////
bool isprime[MX+5];
vector<ll>prime;
ll p=0;
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
            for(int j=i*i; j<MX; j+=i)
                isprime[j]=false;
        }
    }
}
/////////////////////////////////////

bitset<MX>isprime;
vector<ll>prime;

void bitwise_sieve()
{
    isprime.set(); // making all bit 1/true;
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

//////////////////////////////////////////

int NOD ( int n )
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

//////////////////////////

int SOD( int n )
{
    int res = 1;
    int sqrtn = sqrt ( n );
    for ( int i = 0; i < prime.size() && prime[i] <= sqrtn; i++ )
    {
        if ( n % prime[i] == 0 )
        {
            int tempSum = 1;
            int p = 1;
            while ( n % prime[i] == 0 )
            {
                n /= prime[i];
                p *= prime[i];
                tempSum += p;
            }
            sqrtn = sqrt ( n );
            res *= tempSum;
        }
    }
    if ( n != 1 )
    {
        res *= ( n + 1 );
    }
    return res;
}


/////// Trailing Zeros ////////////

ll fn(ll n, ll x) // if not n factorial,then ans=min(fn(n,5),fn(n,2));
{
    ll cnt=0;
    while(n%x==0)
    {
        cnt++;
        n/=x;
    }
    return cnt;
}

ll cntFive(ll n)  // if n factorial
{
    ll p5=5,cnt=0;
    while(p5<=n)
    {
        cnt+=(n/p5);
        p5*=5;
    }
    return cnt;
}

ll cntTwo(ll n) // if n factorial
{
    ll p2=2,cnt=0;
    while(p2<=n)
    {
        cnt+=(n/p2);
        p2*=2;
    }
    return cnt;
}

/////////////////////////////////


vector <int> factors;
void factorize( int n )
{
    int sqrtn = sqrt ( n );
    for ( int i = 0; i < prime.size() && prime[i] <= sqrtn; i++ )
    {
        if (isprime[n])
            break;
        if ( n % prime[i] == 0 )
        {
            while ( n % prime[i] == 0 )
            {
                n /= prime[i];
                factors.push_back(prime[i]);
            }
            sqrtn = sqrt ( n );
        }
    }
    if ( n != 1 )
    {
        factors.push_back(n);
    }
}

///////////////////////////////////

long long extended_euclid(ll a, ll b, ll &x, ll &y)
{
    if(b==0)
    {
        x=1,y=0;
        return a;
    }

    ll x1,y1;
    ll d=extended_euclid(b,a%b,x1,y1);
    x=y1;
    y=x1-y1*(a/b);
    return d;
}

ll bigMod(ll b, ll p)
{
    ll ans=1;
    while(p)
    {
        if(p%2==1)
            ans=Mul(ans,b);
        b=Mul(b,b);
        p/=2;
    }

    return ans%mod;
}

long long modInverse(ll a, ll b)
{
    ll x, y;
    ll gcd=extended_euclid(a,b,x,y);

    if(gcd==1)
        return ((x%b)+b)%b;
    else
        return 1;
}

////////////////////////////////////////

ll phi[MX];
void euler_totient() {
    for(int i=0; i<MX; i++) phi[i]=i;
    for(int i=2; i<MX; i++) {
        if(phi[i]==i) {
            for(int j=i; j<MX; j+=i)
                phi[j]-=(phi[j]/i);
        }
    }
}

///////////////////////////////////////


int add(int x, int y)
{
    x += y;
    while(x >= MOD) x -= MOD;
    while(x < 0) x += MOD;
    return x;
}

int mul(int x, int y)
{
    return (x * 1ll * y) % MOD;
}

int binpow(int x, int y)
{
    int ans = 1;
    while(y > 0)
    {
        if(y % 2 == 1)
            ans = mul(ans, x);
        x = mul(x, x);
        y /= 2;
    }
    return ans;
}

int divide(int x, int y)
{
    return mul(x, binpow(y, MOD - 2));
}


//////////////////////////////////////////////////

ll power(ll x, ll y, ll p)
{
    ll res = 1;
    x = x % p;

    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

ll modInverse(ll n,ll p)
{
    return power(n, p - 2, p);
}

ll nCrModPFermat(ll n, ll r, ll p)
{
    if (n < r)
        return 0;
    if (r == 0)
        return 1;

    ll fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;

    return (fac[n] * modInverse(fac[r], p) % p* modInverse(fac[n - r], p) % p)% p;
}
////////////////////////////////////////////////////////////////

ll bigMod(ll b, ll p)
{
    ll ans=1;
    while(p)
    {
        if(p%2==1)
            ans=Mul(ans,b);
        b=Mul(b,b);
        p/=2;
    }

    return ans%mod;
}

ll nCr(ll n, ll r)
{
    if (n < r)
        return 0;
    if (r == 0)
        return 1;

    ll fact[n + 1];
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = Mul(fact[i - 1], i);

    ll y=Mul(bigMod(fact[r],mod-2), bigMod(fact[n-r],mod-2));
    return Mul(fact[n],y);
}

/////////////////////////////////////////////////////////////////

int main()
{
    sieve();
    Fast;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int cnt=0;
        for(int i=0; prime[i]<=n/2; i++)
        {
            int x=n-prime[i];
            if(!isprime[x])
                cnt++;
        }

        TC(tc);
        cout<<cnt<<endl;
    }

    return 0;
}
