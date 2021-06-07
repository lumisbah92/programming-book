// Start Time:
#include<bits/stdc++.h>
using namespace std;
#define ff                first
#define ss                second
#define MX                300005
#define ll                long long
#define pb                push_back
#define pi                acos(-1.0)
#define PQ                priority_queue
#define mod               1000000007
#define eps               1/1000000000
#define pii               pair<int,int>
#define pll               pair<ll,ll>
#define endl              "\n"
#define Fast              ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define bug(a)            cout<<#a<<":"<<a<<endl
#define TC(tc)            cout<<"Case "<<tc++<<": "
#define all(x)            (x).begin(),(x).end()
#define allr(x)           (x).rbegin(),(x).rend()
#define mem(a,b)          memset(a, b, sizeof(a))
#define double_print(x,a) cout<<fixed<<setprecision(x)<<a<<endl
// ll MOD(ll a, ll b){ return (a%mod + b%mod)%mod; }
int tc=1;

int isDivisible(string a, int b)
{
    ll num=0;
    for(int i=0; i<a.size(); i++)
    {
        if(a[i]=='-') continue;

        num=num*10+(a[i]-'0');
        num%=b;
    }
    return num;
}

int main()
{
    Fast;
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        int b;
        cin>>a>>b;

        int rem=isDivisible(a,b);
        TC(tc);
        if(rem==0)
            cout<<"divisible\n";
        else
            cout<<"not divisible\n";
    }

    return 0;
}
