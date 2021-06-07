// Start Time:
#include<bits/stdc++.h>
using namespace std;
#define  ll                     long long
#define  pb                     push_back
#define  pii                    pair<int,int>
#define  pll                    pair<ll,ll>
#define  ff                     first
#define  ss                     second
#define  sqr(x)                 (x)*(x)
#define  MX                     100005
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

char s[MX];
struct Node
{
    ll sum,lazy;
} tree[4*MX];
void init(int node, int b, int e)
{
    if(b==e)
    {
        tree[node].sum=s[b]-'0';
        tree[node].lazy=0;
        return;
    }
    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;

    init(left,b,mid);
    init(right,mid+1,e);

    tree[node].sum=tree[left].sum+tree[right].sum;
    tree[node].lazy=0;
}

void push_down(int node, int b, int e)
{
    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;
    if(tree[node].lazy)
    {
        tree[left].sum+=(mid-b+1)*tree[node].lazy;
        tree[right].sum+=(e-mid)*tree[node].lazy;

        tree[left].lazy+=tree[node].lazy;
        tree[right].lazy+=tree[node].lazy;
        tree[node].lazy=0;
    }
}

void update(int node, int b, int e, int i, int j)
{
    if(b>j || e<i)
        return;
    if(b>=i && e<=j)
    {
        tree[node].sum+=(e-b+1)*1;
        tree[node].lazy++;
        return;
    }

    push_down(node,b,e);
    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;
    update(left,b,mid,i,j);
    update(right,mid+1,e,i,j);
    tree[node].sum=tree[left].sum+tree[right].sum;
}

ll query(int node, int b, int e, int i)
{
    if (i > e || i < b)
        return 0;
    if(b==e && b==i)
        return tree[node].sum;

    push_down(node,b,e);
    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;

    ll p=query(left,b,mid,i);
    ll q=query(right,mid+1,e,i);
    return p+q;
}

int main()
{
    ios::sync_with_stdio(0);  //cin.tie(0);

    int t;
    scanf("%d",&t);
    for(int tc=1; tc<=t; tc++)
    {
        scanf("%s",s);
        int n=strlen(s);
        init(1,0,n-1);

        int q;
        scanf("%d",&q);

        printf("Case %d:\n",tc);
        while(q--)
        {
            char c;
            getchar();
            scanf("%c",&c);
            if(c=='I')
            {
                int l,r;
                scanf("%d %d",&l ,&r);
                l--,r--;
                update(1,0,n-1,l,r);
            }
            else
            {
                int i;
                scanf("%d",&i);
                i--;
                printf("%lld\n",query(1,0,n-1,i)%2);
            }
        }
    }

    return 0;
}
