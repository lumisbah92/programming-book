// Start Time:
#include<bits/stdc++.h>
using namespace std;
#define  ll                     long long
#define  pb                     push_back
#define  pii                    pair<int,int>
#define  pll                    pair<ll,ll>
#define  ff                     first
#define  ss                     second
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

struct info
{
    ll prop,sum;
} tree[MX*3];

void update(int node, int b, int e, int i, int j, int x)
{
    if(i>e || j<b)
        return;
    if(b>=i && e<=j)
    {
        tree[node].sum += ((e-b+1)*x);
        tree[node].prop += x;
        return;
    }

    int left = node*2;
    int right = (node*2)+1;
    int mid = (b+e)/2;
    update(left, b, mid, i, j, x);
    update(right, mid+1, e, i, j, x);
    tree[node].sum = tree[left].sum + tree[right].sum + (e-b+1)*tree[node].prop;
}

ll query(int node, int b, int e, int i, int j, ll carry=0)
{
    if(i>e || j<b)
        return 0ll;
    if(b>=i &&  e<= j)
        return tree[node].sum + carry*(e-b+1);

    int left = node*2;
    int right = (node*2)+1;
    int mid = (b+e)/2;

    ll p1 = query(left, b, mid, i, j, carry + tree[node].prop);
    ll p2 = query(right, mid+1, e, i, j, carry + tree[node].prop);
    return p1+p2;
}

int main()
{
    int t;
    scanf("%d",&t);

    for(int tc=1; tc<=t; tc++)
    {
        int n,q;
        scanf("%d %d",&n,&q);
        printf("Case %d:\n",tc);
        while(q--)
        {
            int type;
            scanf("%d",&type);
            if(type==0)
            {
                int l,r,v;
                scanf("%d %d %d",&l,&r,&v);
                l++,r++;
                update(1,1,n,l,r,v);
            }
            else
            {
                int l,r;
                scanf("%d %d",&l,&r);
                l++,r++;
                printf("%lld\n",query(1,1,n,l,r,0ll));
            }
        }

        for(int i=0; i<=MX*3; i++)
            tree[i].prop=tree[i].sum=0;
    }

    return 0;
}
// Start Time:
#include<bits/stdc++.h>
using namespace std;
#define  ll                     long long
#define  pb                     push_back
#define  pii                    pair<int,int>
#define  pll                    pair<ll,ll>
#define  ff                     first
#define  ss                     second
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

struct info
{
    ll prop,sum;
} tree[MX*3];

void update(int node, int b, int e, int i, int j, int x)
{
    if(i>e || j<b)
        return;
    if(b>=i && e<=j)
    {
        tree[node].sum += ((e-b+1)*x);
        tree[node].prop += x;
        return;
    }

    int left = node*2;
    int right = (node*2)+1;
    int mid = (b+e)/2;
    update(left, b, mid, i, j, x);
    update(right, mid+1, e, i, j, x);
    tree[node].sum = tree[left].sum + tree[right].sum + (e-b+1)*tree[node].prop;
}

ll query(int node, int b, int e, int i, int j, ll carry=0)
{
    if(i>e || j<b)
        return 0ll;
    if(b>=i &&  e<= j)
        return tree[node].sum + carry*(e-b+1);

    int left = node*2;
    int right = (node*2)+1;
    int mid = (b+e)/2;

    ll p1 = query(left, b, mid, i, j, carry + tree[node].prop);
    ll p2 = query(right, mid+1, e, i, j, carry + tree[node].prop);
    return p1+p2;
}

int main()
{
    int t;
    scanf("%d",&t);

    for(int tc=1; tc<=t; tc++)
    {
        int n,q;
        scanf("%d %d",&n,&q);
        printf("Case %d:\n",tc);
        while(q--)
        {
            int type;
            scanf("%d",&type);
            if(type==0)
            {
                int l,r,v;
                scanf("%d %d %d",&l,&r,&v);
                l++,r++;
                update(1,1,n,l,r,v);
            }
            else
            {
                int l,r;
                scanf("%d %d",&l,&r);
                l++,r++;
                printf("%lld\n",query(1,1,n,l,r,0ll));
            }
        }

        for(int i=0; i<=MX*3; i++)
            tree[i].prop=tree[i].sum=0;
    }

    return 0;
}
// Start Time:
#include<bits/stdc++.h>
using namespace std;
#define  ll                     long long
#define  pb                     push_back
#define  pii                    pair<int,int>
#define  pll                    pair<ll,ll>
#define  ff                     first
#define  ss                     second
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

struct info
{
    ll prop,sum;
} tree[MX*3];

void update(int node, int b, int e, int i, int j, int x)
{
    if(i>e || j<b)
        return;
    if(b>=i && e<=j)
    {
        tree[node].sum += ((e-b+1)*x);
        tree[node].prop += x;
        return;
    }

    int left = node*2;
    int right = (node*2)+1;
    int mid = (b+e)/2;
    update(left, b, mid, i, j, x);
    update(right, mid+1, e, i, j, x);
    tree[node].sum = tree[left].sum + tree[right].sum + (e-b+1)*tree[node].prop;
}

ll query(int node, int b, int e, int i, int j, ll carry=0)
{
    if(i>e || j<b)
        return 0ll;
    if(b>=i &&  e<= j)
        return tree[node].sum + carry*(e-b+1);

    int left = node*2;
    int right = (node*2)+1;
    int mid = (b+e)/2;

    ll p1 = query(left, b, mid, i, j, carry + tree[node].prop);
    ll p2 = query(right, mid+1, e, i, j, carry + tree[node].prop);
    return p1+p2;
}

int main()
{
    int t;
    scanf("%d",&t);

    for(int tc=1; tc<=t; tc++)
    {
        int n,q;
        scanf("%d %d",&n,&q);
        printf("Case %d:\n",tc);
        while(q--)
        {
            int type;
            scanf("%d",&type);
            if(type==0)
            {
                int l,r,v;
                scanf("%d %d %d",&l,&r,&v);
                l++,r++;
                update(1,1,n,l,r,v);
            }
            else
            {
                int l,r;
                scanf("%d %d",&l,&r);
                l++,r++;
                printf("%lld\n",query(1,1,n,l,r,0ll));
            }
        }

        for(int i=0; i<=MX*3; i++)
            tree[i].prop=tree[i].sum=0;
    }

    return 0;
}
// Start Time:
#include<bits/stdc++.h>
using namespace std;
#define  ll                     long long
#define  pb                     push_back
#define  pii                    pair<int,int>
#define  pll                    pair<ll,ll>
#define  ff                     first
#define  ss                     second
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

struct info
{
    ll prop,sum;
} tree[MX*3];

void update(int node, int b, int e, int i, int j, int x)
{
    if(i>e || j<b)
        return;
    if(b>=i && e<=j)
    {
        tree[node].sum += ((e-b+1)*x);
        tree[node].prop += x;
        return;
    }

    int left = node*2;
    int right = (node*2)+1;
    int mid = (b+e)/2;
    update(left, b, mid, i, j, x);
    update(right, mid+1, e, i, j, x);
    tree[node].sum = tree[left].sum + tree[right].sum + (e-b+1)*tree[node].prop;
}

ll query(int node, int b, int e, int i, int j, ll carry=0)
{
    if(i>e || j<b)
        return 0ll;
    if(b>=i &&  e<= j)
        return tree[node].sum + carry*(e-b+1);

    int left = node*2;
    int right = (node*2)+1;
    int mid = (b+e)/2;

    ll p1 = query(left, b, mid, i, j, carry + tree[node].prop);
    ll p2 = query(right, mid+1, e, i, j, carry + tree[node].prop);
    return p1+p2;
}

int main()
{
    int t;
    scanf("%d",&t);

    for(int tc=1; tc<=t; tc++)
    {
        int n,q;
        scanf("%d %d",&n,&q);
        printf("Case %d:\n",tc);
        while(q--)
        {
            int type;
            scanf("%d",&type);
            if(type==0)
            {
                int l,r,v;
                scanf("%d %d %d",&l,&r,&v);
                l++,r++;
                update(1,1,n,l,r,v);
            }
            else
            {
                int l,r;
                scanf("%d %d",&l,&r);
                l++,r++;
                printf("%lld\n",query(1,1,n,l,r,0ll));
            }
        }

        for(int i=0; i<=MX*3; i++)
            tree[i].prop=tree[i].sum=0;
    }

    return 0;
}
