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
            if(!mark[x])
                    cnt++;
        }

        TC(tc);
        cout<<cnt<<endl;
    }

    return 0;
}
