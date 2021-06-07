/**==============================================================*
*            "Bismillahir Rahmanir Raheem"                       *
*        Author          :  Misbah Uddin Tareq.                  *
*        Semester        :  5(C),CSE                             *
*        University      :  Leading University,Sylhet.           *
*===============================================================**/

#include<bits/stdc++.h>
using namespace std;
#define  ll                     long long
#define  pb                     push_back
#define  pii                    pair<int,int>
#define  pll                    pair<ll,ll>
#define  ff                     first
#define  ss                     second
#define  mxx                    100005
#define  endl                   "\n"
#define  mod                    1e9+7
#define  pi                     acos(-1.0)
#define  PQ                     priority_queue
#define  mem(a,b)               memset(a, b, sizeof(a))
#define  bug(a)                 cout<<#a<<":"<<a<<endl
#define  all(x)                 (x).begin(),(x).end()
#define  allr(x)                (x).rbegin(),(x).rend()
#define  double_print(x,a)      cout<<fixed<<setprecision(x)<<a<<endl

map<int,vector<ll>>mp;
int n;
int dp[25][3];

int fn(int idx,int pre)
{
    if(idx==n+1)
        return 0;

    int &ret=dp[idx][pre];
    if(~ret) return ret;
    ret=0;

    if(pre==-1)
    {
        int a=mp[idx][0]+fn(idx+1,0);
        int b=mp[idx][1]+fn(idx+1,1);
        int c=mp[idx][2]+fn(idx+1,2);
        ret+=(min(a,min(b,c)));
    }
    else if(pre==0)
    {
        int a=mp[idx][1]+fn(idx+1,1);
        int b=mp[idx][2]+fn(idx+1,2);
        ret+=min(a,b);
    }
    else if(pre==1)
    {
        int a=mp[idx][0]+fn(idx+1,0);
        int b=mp[idx][2]+fn(idx+1,2);
        ret+=min(a,b);
    }
    else if(pre==2)
    {
        int a=mp[idx][1]+fn(idx+1,1);
        int b=mp[idx][0]+fn(idx+1,0);
        ret+=min(a,b);
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    //cin.tie(0);

    int t;
    cin>>t;
    for(int tc=1; tc<=t; tc++)
    {
        cin>>n;
        memset(dp,-1,sizeof dp);
        for(int i=1; i<=n; i++)
        {
            for(int p=1; p<=3; p++)
            {
                int x;
                cin>>x;
                mp[i].pb(x);
            }
        }

        printf("Case %d: %d\n",tc,fn(1,-1));

        mp.clear();
    }

    return 0;
}
