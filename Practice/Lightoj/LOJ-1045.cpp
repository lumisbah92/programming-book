// Start Time:
#include<bits/stdc++.h>
using namespace std;
#define  ll                     long long
#define  pb                     push_back
#define  pii                    pair<int,int>
#define  pll                    pair<ll,ll>
#define  ff                     first
#define  ss                     second
#define  MX                     1000010
#define  endl                   "\n"
#define  mod                    1000000007
#define  eps                    1/1000000000
#define  pi                     acos(-1.0)
#define  PQ                     priority_queue
#define  mem(a,b)               memset(a, b, sizeof(a))
#define  bug(a)                 cout<<#a<<":"<<a<<endl
#define  all(x)                 (x).begin(),(x).end()
#define  allr(x)                (x).rbegin(),(x).rend()
#define  double_print(x,a)      cout<<fixed<<setprecision(x)<<a<<endl

double arr[MX];

int main()
{
    ios::sync_with_stdio(0); //cin.tie(0);

    for(ll i=1; i<=MX; i++)
        arr[i] = arr[i-1] + log10(i);

    ll t;
    cin>>t;
    for(int tc=1; tc<=t; tc++)
    {
        ll n,base;
        cin>>n>>base;

        ll ans= (arr[n]/log10(base))+1;

        cout<<"Case "<<tc<<": "<<ans<<endl;

    }

    return 0;
}
