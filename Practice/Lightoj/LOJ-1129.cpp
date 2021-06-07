// Start Time:
#include<bits/stdc++.h>
using namespace std;
#define  ll                     long long
#define  pb                     push_back
#define  pii                    pair<int,int>
#define  pll                    pair<ll,ll>
#define  ff                     first
#define  ss                     second
#define  MX                     1000000
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

struct node{

    bool endmark;
    node* next[10+1];
    node()
    {
        endmark = false;
        for(int i=0; i<10; i++)
            next[i]= NULL;
    }
} *root;

void insert(string str, int len)
{
    node* cur = root;
    for(int i=0; i<len; i++)
    {
        int id = str[i] - '0';
        if(cur->next[id] == NULL)
            cur->next[id] = new node();
        cur = cur->next[id];
    }
    cur->endmark = true;
}

bool search (string str, int len)
{
    node* cur = root;
    for(int i=0; i<len; i++)
    {
        int id = str[i] - '0';
        if(cur->endmark)
            return false;
        cur = cur->next[id];
    }
    return cur->endmark;
}

void del(node* cur)
{
    for(int i=0; i<10; i++)
        if(cur->next[i])
        del(cur->next[i]);
    delete(cur);
}

int main()
{
    //ios::sync_with_stdio(0); //cin.tie(0);

    int t;
    cin>>t;
    for(int tc=1; tc<=t; tc++)
    {
        root=new node();
        int n;
        cin>>n;
        vector<pair<int,string>>v;
        while(n--)
        {
            string s;
            cin>>s;
            int len=s.size();
            insert(s,len);
            v.pb({len,s});
        }

        sort(allr(v));
        int k=0;
        for(auto it:v)
        {
            if(!search(it.ss,it.ff))
            {
                k=1;
                break;
            }
        }

        if(k)
            cout<<"Case "<<tc<<": NO\n";
        else
            cout<<"Case "<<tc<<": YES\n";
        del(root);
    }

    return 0;
}
