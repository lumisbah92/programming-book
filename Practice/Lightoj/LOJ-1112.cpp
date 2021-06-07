#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
const ll mx=100005;

int arr[mx];
int tree[mx*3];

void init(int node, int b, int e)
{
    if(b==e)
    {
        tree[node]=arr[b];
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;

    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
}

int query(int node, int b, int e, int i, int j)
{
    if(i>e || j<b)
        return 0;
    if(b>=i && e<=j)
        return tree[node];

    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;

    int p1=query(left,b,mid,i,j);
    int p2=query(right,mid+1,e,i,j);
    return p1+p2;
}

void update1(int node, int b, int e,int i)
{
    if(b==e)
    {
        printf("%d\n",tree[node]);
        tree[node]=0;
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;

    if(i<=mid)
        update1(left,b,mid,i);
    else
        update1(right,mid+1,e,i);
    tree[node]=tree[left]+tree[right];
}

void update2(int node, int b, int e,int i,int v)
{
    if(b==e)
    {
        tree[node]+=v;
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;

    if(i<=mid)
        update2(left,b,mid,i,v);
    else
        update2(right,mid+1,e,i,v);
    tree[node]=tree[left]+tree[right];
}

int main()
{
    int t;
    scanf("%d",&t);

    for(int k=1; k<=t; k++)
    {
        int n,q;
        scanf("%d %d",&n,&q);

        for(int i=1; i<=n ; i++)
            scanf("%d",&arr[i]);
        init(1,1,n);

        printf("Case %d:\n",k);
        while(q--)
        {
            int x;
            scanf("%d",&x);

            if(x==1)
            {
                int i;
                scanf("%d",&i);
                i++;
                update1(1,1,n,i);
            }
            else if(x==2)
            {
                int i,v;
                scanf("%d %d",&i,&v);
                i++;
                update2(1,1,n,i,v);
            }
            else if(x==3)
            {
                int i,j;
                scanf("%d %d",&i,&j);
                i++,j++;
                printf("%d\n",query(1,1,n,i,j));
            }
        }
//
        memset(arr,0,sizeof arr);
        memset(tree,0,sizeof tree);
    }
}
