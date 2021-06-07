// Start Time:
#include<bits/stdc++.h>
using namespace std;
#define ff                first
#define ss                second
#define MX                1000005
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
#define TC(tc)            cout<<"Case "<<tc++<<":\n"
#define all(x)            (x).begin(),(x).end()
#define allr(x)           (x).rbegin(),(x).rend()
#define mem(a,b)          memset(a, b, sizeof(a))
#define double_print(x,a) cout<<fixed<<setprecision(x)<<a<<endl
// ll MOD(ll a, ll b){ return (a%mod + b%mod)%mod; }
ll tc=1;
int arr[MX],tree[4*MX];
void init(int n, int b,int e)
{
    if(b==e)
    {
        tree[n]=arr[b];
        return;
    }

    int left=2*n;
    int right=2*n+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[n]=min(tree[left],tree[right]);
}

int query(int n, int b,int e,int i,int j)
{
     if (i > e || j < b)
        return 1e9;
    if (b >= i && e <= j)
        return tree[n];

     int left=2*n;
    int right=2*n+1;
    int mid=(b+e)/2;

    int p1=query(left,b,mid,i,j);
    int p2=query(right,mid+1,e,i,j);
    return min(p1,p2);
}


int main()
{
    Fast;
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        for(int i=1; i<=n; i++)
        {
            cin>>arr[i];
        }
        init(1,1,n);

        TC(tc);
        while(q--)
        {
            int i,j;
            cin>>i>>j;
            cout<<query(1,1,n,i,j)<<endl;
        }
    }


    return 0;
}
