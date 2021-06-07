/// https://www.codechef.com/submit/complete/44095455

/* Flare Up Like A Flame */
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
#define Fast              ios::sync_with_stdio(0); //cin.tie(0); cout.tie(0)
#define bug(a)            cout<<#a<<":"<<a<<endl
#define TC(tc)            cout<<"Case "<<tc++<<": "
#define all(x)            (x).begin(),(x).end()
#define allr(x)           (x).rbegin(),(x).rend()
#define Mul(a,b)          (a%mod * b%mod)%mod;
#define Add(a,b)          (a%mod * b%mod)%mod;
#define mem(a,b)          memset(a, b, sizeof(a))
#define double_print(x,a) cout<<fixed<<setprecision(x)<<a<<endl
ll tc=1;

vector<ll>temparray(string pattern)
{
    vector<ll>lps(pattern.size());
    int index=0;

    for(int i=1; i<pattern.size(); )
    {
        if(pattern[index]==pattern[i])
        {
            lps[i]=index+1;
            index++;
            i++;
        }
        else
        {
            if(index!=0)
                index=lps[index-1];
            else
                lps[i]=index,i++;
        }
    }

    return lps;
}

ll kmp(string text, string pattern)
{
    ll ans=0,res=0,best=0;
    vector<ll>lps=temparray(pattern);
    int i=0,j=0;
    while(i<text.size())
    {
        if(text[i]==pattern[j])
        {
            i++;
            j++;
            best++;
        }
        else
        {
            if(j!=0)
                j=lps[j-1];
            else
                i++;
            best=0;
        }

        if(best>res)
            res=best, ans=i-j;

        if(j==pattern.size())
            break;
    }

    return ans;
}

int main()
{
    Fast;

    ll n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    b+=b;

    cout<<kmp(b,a)<<endl;

    return 0;
}


///////////////////////////////////////////////////
///https://codeforces.com/problemset/problem/126/B
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

ll n,vis[MX];
vector<ll>prefix(string s)
{
    vector<ll>lps(n);
    for(int i=1; i<n; i++)
    {
        ll j=lps[i-1];
        while(j>0 && s[i]!=s[j])
            j=lps[j-1];

        if(s[i]==s[j])
            j++;
        lps[i]=j;

        if(i<n-1)
            vis[j]=1;
    }

    return lps;
}

int main()
{
    Fast;

    string s;
    cin>>s;
    n=s.size();

    vector<ll>lps =prefix(s);
    vis[0]=1;
    ll idx=lps[n-1];

    while(idx && !vis[idx])
        idx=lps[idx-1];

    if(idx)
        cout<<s.substr(0,idx)<<endl;
    else
        cout<<"Just a legend\n";

    return 0;
}
