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

    ll k;
    cin>>k;
    string s;
    cin>>s;
    reverse(all(s));
    s='@'+s;
    ll n=s.size();

    ll ans[n+5]= {0};
    for(int i=n-1; i>=1; i--)
    {
        if(2*i+1>=n) // leaf node;
        {
            if(s[i]=='?')
                ans[i]=2;
            else
                ans[i]=1;
        }
        else
        {
            if(s[i]=='?')
                ans[i]=ans[2*i]+ans[2*i+1];
            else if(s[i]=='0')
                ans[i]=ans[2*i+1];
            else
                ans[i]=ans[2*i];
        }
    }

    ll q;
    cin>>q;
    while(q--)
    {
        ll pos;
        char ch;
        cin>>pos>>ch;
        pos=n-pos;
        s[pos]=ch;

        while(pos>0)
        {
            if(2*pos+1>=n) // leaf node;
            {
                if(s[pos]=='?')
                    ans[pos]=2;
                else
                    ans[pos]=1;
            }
            else
            {
                if(s[pos]=='?')
                    ans[pos]=ans[2*pos]+ans[2*pos+1];
                else if(s[pos]=='0')
                    ans[pos]=ans[2*pos+1];
                else
                    ans[pos]=ans[2*pos];
            }

            pos/=2;
        }

        cout<<ans[1]<<endl;
    }

    return 0;
}

