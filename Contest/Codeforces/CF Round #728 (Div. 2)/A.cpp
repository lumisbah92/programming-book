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

int main()
{
    Fast;

    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;

        ll ans[n+10];
        if(n%2!=0)
        {
            ans[1]=3;
            ans[2]=1;
            ans[3]=2;
            for(int i=4; i<=n; i+=2)
            {
                ans[i]=i+1;
                ans[i+1]=i;
            }
        }
        else
        {
            for(int i=1; i<=n; i+=2)
            {
                ans[i]=i+1;
                ans[i+1]=i;
            }
        }

        for(int i=1; i<=n; i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }

    return 0;
}

