#include<bits/stdc++.h>
using namespace std;
#define   ll          long long
#define   pb          push_back
#define   F           first
#define   S           second
#define   mk          make_pair
#define   all(v)      v.begin(),v.end()
#define   allr(v)     v.rbegin(),v.rend()
#define   cout(p)     cout<<p<<"\n"
#define   boo         bool ok=false
#define   print(ok)   cout<<(ok ? "NO\n" : "YES\n")
#define   Tc()        ll T,cs=0; cin>>T; hell: while(T--)
#define   Tanmoy      ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0)

const ll mod=1e9+7, MAX=2e6+10;
ll a[MAX], b[MAX], mp[MAX];

void init()
{
    a[0]=1;
    for(ll i=1; i<=1005; i++){
        a[i]=a[i-1]*i;
        a[i]%=mod;
    }
}

ll Bigmod(ll a, ll b)
{
    ll res=1;
    while(b){
        if(b&1)res=res*a%mod;
        a=a*a%mod;
        b/=2;
    }
    return res;
}

ll Inversemod(ll n)
{
    return Bigmod(n, mod-2);
}

ll nCr(ll n, ll r)
{
    ll res;
    res=a[n];
    res*=Inversemod(a[r]);
    res%=mod;
    res*=Inversemod(a[n-r]);
    res%=mod;

    return res;
}

int main()
{

   return 0;
}



