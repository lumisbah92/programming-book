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

int main()
{
    Fast;

    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll>v;
        ll mn=1e10,mx=0,i1,i2;
        for(int i=1; i<=n; i++)
        {
            ll x;
            cin>>x;
            v.pb(x);
            if(x>mx)
            {
                mx=x;
                i1=i;
            }
            if(x<mn)
            {
                mn=x;
                i2=i;
            }
        }

        ll a=max(i1,i2);
        ll b=max(n-i1+1,n-i2+1);
        ll c=min(i1+n-i2+1,i2+n-i1+1);

        cout<<min(a,min(b,c))<<endl;
    }

    return 0;
}