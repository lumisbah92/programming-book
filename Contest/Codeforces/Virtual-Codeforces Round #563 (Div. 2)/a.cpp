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

    ll n;
    cin>>n;
    vector<ll>v(2*n);
    for(auto &it:v)
        cin>>it;

    sort(all(v));
    ll sum=0,sum1=0;
    for(int i=0; i<n; i++)
        sum+=v[i];
    for(int i=n; i<2*n; i++)
        sum1+=v[i];
    
    if(sum==sum1)
    cout<<-1<<endl;
    else
    {
        for(auto it:v)
            cout<<it<<" ";
        cout<<endl;
    }

    return 0;
}