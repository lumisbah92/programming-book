// Start Time:
#include<bits/stdc++.h>
using namespace std;
#define  ll                     long long
#define  pb                     push_back
#define  pii                    pair<int,int>
#define  pll                    pair<ll,ll>
#define  ff                     first
#define  ss                     second
#define  MX                     1000005
#define  endl                   "\n"
#define  mod                    1000000007
#define  eps                    1/1000000000
#define  pi                     acos(-1.0)
#define  PQ                     priority_queue
#define  mem(a,b)               memset(a, b, sizeof(a))
#define  bug(a)                 cout<<#a<<":"<<a<<endl
#define  all(x)                 (x).begin(),(x).end()
#define  allr(x)                (x).rbegin(),(x).rend()
#define  double_print(x,a)      cout<<fixed<<setprecision(x)<<a<<endl

struct Node
{
    ll sum,lazy;
} tree[4*MX];

void init(int node, int b, int e)
{
    if(b==e)
        tree[node].sum=tree[node].lazy=0;
    else
    {
        int left=node*2;
        int right=left+1;
        int mid=(b+e)/2;
        init(left,b,mid);
        init(right,mid+1,e);
        tree[node].sum=tree[left].sum+tree[right].sum;
        tree[node].lazy=0;
    }
}

void push_down(int node, int b, int e)
{
    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;

    if(tree[node].lazy!=-1)
    {
        tree[node].sum=(e-b+1)*tree[node].lazy;
        if(b!=e)
            tree[left].lazy=tree[right].lazy=tree[node].lazy;
        tree[node].lazy=-1;
    }
}

void update(int node, int b, int e, int i, int j, int val)
{
    push_down(node,b,e);
    if(b>j || e<i)
        return;
    if(b>=i && e<=j)
    {
        tree[node].lazy=val;
        push_down(node,b,e);
        return;
    }

    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;

    update(left,b,mid,i,j,val);
    update(right,mid+1,e,i,j,val);

    tree[node].sum=tree[left].sum+tree[right].sum;
}

ll query(int node, int b, int e, int i, int j)
{
    push_down(node,b,e);
    if(b>j || e<i)
        return 0;
    if(b>=i && e<=j)
        return tree[node].sum;

    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;

    ll p=query(left,b,mid,i,j);
    ll q=query(right,mid+1,e,i,j);
    return p+q;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int tc=1; tc<=t; tc++)
    {
        ll n,q;
        scanf("%lld %lld",&n ,&q);

        init(1,0,n-1);

        printf("Case %d:\n",tc);
        while(q--)
        {
            ll type;
            scanf("%lld",&type);
            if(type==1)
            {
                ll i,j,v;
                scanf("%lld %lld %lld",&i ,&j ,&v);
                update(1,0,n-1,i,j,v);
            }
            else
            {
                ll i,j;
                scanf("%lld %lld",&i ,&j);
                ll sum=query(1,0,n-1,i,j);
                ll tot=(j-i+1);
                if(sum%tot!=0)
                {
                    ll gcd=__gcd(sum,tot);
                    sum/=gcd;
                    tot/=gcd;
                    printf("%lld/%lld\n",sum,tot);
                }
                else
                    printf("%lld\n",sum/tot);
            }
        }
    }

    return 0;
}
