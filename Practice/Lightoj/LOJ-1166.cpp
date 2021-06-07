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
        ll n;
        cin>>n;
        ll arr[n+5],pos[n+5];
        for(int i=1; i<=n; i++){
            cin>>arr[i];
            pos[arr[i]]=i;
        }
        ll cnt=0;
        for(int i=1; i<=n; i++)
        {
            if(arr[i]!=i)
            {
                cnt++;
                ll x=arr[i];
                swap(arr[i],arr[pos[i]]);
                pos[x]=pos[i];
            }
        }

        cout<<"Case "<<tc<<": "<<cnt<<endl;
    }

    return 0;
}

