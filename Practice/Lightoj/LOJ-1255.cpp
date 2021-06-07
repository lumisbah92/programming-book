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

ll cnt=0;
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

void kmp(string text, string pattern)
{
    vector<ll>lps=temparray(pattern);
    int i=0,j=0;

    while(i<text.size())
    {
        if(text[i]==pattern[j])
        {
            i++;
            j++;
        }
        else
        {
            if(j!=0)
                j=lps[j-1];
            else
                i++;
        }

        if(j==pattern.size())
        {
            cnt++;
        }
    }
}

int main()
{
    Fast;

    ll t;
    cin>>t;
    for(ll k=1; k<=t; k++)
    {
        string text,pattern;
        cin>>text>>pattern;
        cnt=0;
        kmp(text,pattern);

        printf("Case %lld: %lld\n",k,cnt);
    }

    return 0;
}
