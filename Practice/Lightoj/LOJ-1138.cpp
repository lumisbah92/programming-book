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

int n;
int NumOfTraillingZeros(int x)
{
    int cnt=0,div=5;
    while((x/div)>0)
    {
        cnt+=x/div;
        div=div*5;
    }
    return cnt;
}

int bs(int l, int r)
{
    int ans=-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        int x=NumOfTraillingZeros(mid);
        if(x==n)
            ans=mid;

        if(x<n) l=mid+1;
        else r=mid-1;
    }
    return ans;
}

int main()
{
    Fast;
    int t,tc=1;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int x=bs(1,1e9);
        TC(tc);
        if(x!=-1)
            cout<<x<<endl;
        else
            cout<<"impossible\n";
    }

    return 0;
}
