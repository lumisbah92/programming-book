// Start Time:
#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define MX 100005
#define ll long long
#define pb push_back
#define pi acos(-1.0)
#define PQ priority_queue
#define mod 1000000007
#define eps 1/1000000000
#define pii pair<int,int>
#define pll pair<ll,ll>
#define endl "\n"
#define Fast ios::sync_with_stdio(0)
#define bug(a) cout<<#a<<":"<<a<<endl
#define all(x) (x).begin(),(x).end()
#define allr(x) (x).rbegin(),(x).rend()
#define mem(a,b) memset(a, b, sizeof(a))
#define double_print(x,a) cout<<fixed<<setprecision(x)<<a<<endl

int sz;
int arr[100100];
int cum[378][200100];
int lazy[1001];

int query( int l, int r, int val )
{
    int lf = l/sz;
    int rt = r/sz;
    int ret = 0;

    if( lf == rt )
    {
        for( int i=l; i<=r; i++ )
            ret += (arr[i] + lazy[i/sz] == val);
        return ret;
    }

    for( int i=l; i<(lf + 1)*sz; i++ )
        ret += (arr[i] + lazy[i/sz] == val);
    for( int i=lf+1; i<rt; i++ )
        ret += cum[i][val-lazy[i]];
    for( int i=rt*sz; i<=r; i++)
        ret += (arr[i] + lazy[i/sz] == val);

    return ret;
}

void update( int l, int r, int val )
{
    int lf = l/sz;
    int rt = r/sz;
    if( lf == rt )
    {
        for( int i=l; i<=r; i++ )
        {
            cum[lf][arr[i]]--;
            arr[i] += val;
            cum[lf][arr[i]]++;
        }
        return;
    }
    for( int i=l; i<(lf + 1)*sz; i++ )
    {
        cum[i/sz][arr[i]]--;
        arr[i] += val;
        cum[i/sz][arr[i]]++;
    }

    for( int i=lf+1; i<rt; i++ )
        lazy[i] += val;

    for( int i=rt*sz; i<=r; i++)
    {
        cum[i/sz][arr[i]]--;
        arr[i] += val;
        cum[i/sz][arr[i]]++;
    }
    return;
}

int main()
{
    Fast;
    int t,tc=1;
    cin>>t;
    while( t-- )
    {
        memset(lazy, 0, sizeof lazy);
        memset(cum, 0, sizeof cum);
        int n,m;
        cin>>n>>m;
        sz = sqrt( n );

        for( int i=1; i<=n; i++ )
        {
            cin>>arr[i];
            cum[i/sz][arr[i]]++;
        }

        printf("Case %d:\n", tc++);
        while( m-- )
        {
            int type, l, r, val;
            cin>>type>>l>>r>>val;
            if(type == 1)
                update(l, r, val);
            else if(type == 2)
                printf("%d\n", query(l, r, val));
        }
    }
    return 0;
}
