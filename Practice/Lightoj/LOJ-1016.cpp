// Start Time:
#include<bits/stdc++.h>
using namespace std;
#define  ll                     long long
#define  pb                     push_back
#define  pii                    pair<int,int>
#define  pll                    pair<ll,ll>
#define  ff                     first
#define  ss                     second
#define  MX                     100005
#define  endl                   "\n"
#define  mod                    1e9+7
#define  pi                     acos(-1.0)
#define  PQ                     priority_queue
#define  mem(a,b)               memset(a, b, sizeof(a))
#define  bug(a)                 cout<<#a<<":"<<a<<endl
#define  all(x)                 (x).begin(),(x).end()
#define  allr(x)                (x).rbegin(),(x).rend()
#define  double_print(x,a)      cout<<fixed<<setprecision(x)<<a<<endl

int main()
{
    ios::sync_with_stdio(0); //cin.tie(0);

    ll t;
    cin>>t;
    for(ll tc=1; tc<=t; tc++)
    {
        ll n,w;
        cin>>n>>w;
        vector<ll>v;
        for(int i=0; i<n; i++)
        {
            ll x,y;
            cin>>x>>y;
            v.pb(y);
        }
        sort(all(v));
        ll cnt=1;
        ll last=v[0];
        for(int i=1; i<n; i++)
        {
            if(abs(v[i]-last)<=w)
                continue;
            else
            {
                cnt++;
                last=v[i];
            }
        }

        cout<<"Case "<<tc<<": "<<cnt<<endl;
    }

    return 0;
}

