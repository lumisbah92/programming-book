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
#define mod               998244353
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

ll divisor[MX+5];

int main()
{
    Fast;

    ll n;
    cin>>n;

    for(int i=1; i<=n; i++) // calculating NOD(n);
    {
        for(int j=i; j<=n; j+=i)
        {
            divisor[j]=Add(divisor[j],1LL);
        }
    }

    ll dp[2*n+5],sum[2*n+5];
    dp[0]=1,sum[0]=1;
    for(int i=2; i<=2*n; i+=2)
    {
       dp[i]=Add(sum[i-2], (divisor[i/2]-1));
       sum[i]=Add(sum[i-2], dp[i]);
    }

    cout<<dp[2*n]<<endl;

    return 0;
}

// Editorial : https://www.youtube.com/watch?v=XulCw5C79l0
