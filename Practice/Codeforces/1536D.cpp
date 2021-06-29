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
        ll b[n];
        for(int i=0; i<n; i++)
            cin>>b[i];

        set<ll>st;
        st.insert(b[0]);
        ll last=b[0],ok=1;
        for(int i=1; i<n; i++)
        {
            if(b[i]==last)
                continue;

            ll l=-INT_MAX,r=INT_MAX;
            auto it=st.upper_bound(last);
            if(it!=st.end())
                r=*it;
            it=st.lower_bound(last);
            if(it!=st.begin())
                it--,l=*it;

            last=b[i];
//            cout<<endl;
//            bug(last);
//            bug(l);
//            bug(r);
//            cout<<endl;
            if(last<l || last>r)
            {
                ok=0;
                break;
            }
            st.insert(last);
        }

        if(ok)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }

    return 0;
}

