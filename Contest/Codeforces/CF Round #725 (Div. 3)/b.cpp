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
        ll sum=0;
        vector<ll>v;
        for(int i=0; i<n; i++)
        {
            ll x;
            cin>>x;
            v.pb(x);
            sum+=x;
        }

        if(sum%n!=0)
        {
            cout<<-1<<endl;
            continue;
        }
        
        ll val=sum/n;
        ll ans=0;
        for(int i=0; i<n; i++)
        {
            if(v[i]>val)
                ans++;
        }

        cout<<ans<<endl;
    }

    return 0;
}