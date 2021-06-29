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

    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;

    string mn;
    mn=s[0];
    while(mn.size()<k)
        mn+=mn;
    mn=mn.substr(0,k);

    string pref;
    pref+=s[0];
    for(int i=1; i<n; i++)
    {
        if(s[i]>s[0])
            break;
        pref+=s[i];

        string p;
        p=pref;
        while(p.size()<k)
            p+=p;
        p=p.substr(0,k);

        mn=min(mn,p);
    }

    cout<<mn<<endl;

    return 0;
}

