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

int n;
int arr[1050][1050],bit[1050][1050];
void update(int x, int y, int val)
{
    for(int i=x; i<=n; i+=(i&-i))
    {
        for(int j=y ; j<=n; j+=(j&-j))
        {
            bit[i][j]+=val;
        }
    }
}

ll sum(int x, int y)
{
    ll ans=0;
    for(int i=x ; i>0; i-=(i&-i))
    {
        for(int j=y ; j>0; j-=(j&-j))
        {
            ans+=bit[i][j];
        }
    }
    return ans;
}

int main()
{
    Fast;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        mem(arr,0);
        mem(bit,0);
        while(1)
        {
            string s;
            cin>>s;
            if(s=="END")
                break;
            else if(s=="SET")
            {
                int x,y,val;
                cin>>x>>y>>val;
                x++,y++;
                update(x,y,val-arr[x][y]);
                arr[x][y]=val;
            }
            else
            {
                int x1,y1,x2,y2;
                cin>>x1>>y1>>x2>>y2;
                x1++,y1++,x2++,y2++;
                cout<<sum(x2,y2)-sum(x1-1,y2)-sum(x2,y1-1)+sum(x1-1,y1-1)<<endl;
            }
        }
    }

    return 0;
}
