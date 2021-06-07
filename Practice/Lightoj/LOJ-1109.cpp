// Start Time:
#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define MX 300005
#define ll long long
#define pb push_back
#define pi acos(-1.0)
#define PQ priority_queue
#define mod 1000000007
#define eps 1/1000000000
#define pii pair<int,int>
#define pll pair<ll,ll>
#define endl "\n"
#define Fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define bug(a) cout<<#a<<":"<<a<<endl
#define TC(tc) cout<<"Case "<<tc++<<": "
#define all(x) (x).begin(),(x).end()
#define allr(x) (x).rbegin(),(x).rend()
#define mem(a,b) memset(a, b, sizeof(a))
#define double_print(x,a) cout<<fixed<<setprecision(x)<<a<<endl

vector<int>divv[1005];
bool cmp(pll a, pll b)
{
    if(a.ff==b.ff)
        return a.ss>b.ss;
    return a.ff<b.ff;
}

int main()
{
    Fast;
    for(int i=1; i<=1000; i++)
    {
        for(int j=1; j<=1000; j++)
        {
            if(j%i==0)
                divv[j].pb(i);
        }
    }

    vector<pll>v;
    for(int i=1; i<=1000; i++)
    {
        v.pb({divv[i].size(),i});
    }
    sort(all(v),cmp);

    ll t,tc=1;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        TC(tc);
        cout<<v[n-1].ss<<endl;
    }

    return 0;
}
