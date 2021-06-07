#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
const ll mx=30005;

int dx[]= {1,-1,0,0};
int dy[]= {0,0,1,-1};

char grid[500][500];
int vis[500][500],dis[500][500];
int n,m;
int px,py,dex,dey;
vector<pair<int,pair<int,int>>>v;

void bfs(int sx, int sy)
{
    queue<pair<int,int>>q;
    v.clear();
    memset(vis,0,sizeof vis);
    memset(dis,0,sizeof dis);
    q.push({sx,sy});
    vis[sx][sy]=1;
    dis[sx][sy]=0;

    while(!q.empty())
    {
        int topx=q.front().first,topy=q.front().second;
        q.pop();

        for(int k=0; k<4; k++)
        {
            int x=dx[k]+topx;
            int y=dy[k]+topy;

            if(grid[x][y]!='#' && !vis[x][y])
            {
                dis[x][y]=dis[topx][topy]+1;
                vis[x][y]=1;

                if(grid[x][y]=='*')
                    v.pb({dis[x][y],{x,y}});
                else
                    q.push({x,y});
            }
        }
    }

}


int bfs1(int sx, int sy, int desx, int desy)
{
    queue<pair<int,int>>q;
    memset(vis,0,sizeof vis);
    memset(dis,0,sizeof dis);
    q.push({sx,sy});
    vis[sx][sy]=1;
    dis[sx][sy]=0;

    while(!q.empty())
    {
        int topx=q.front().first,topy=q.front().second;
        q.pop();

        for(int k=0; k<4; k++)
        {
            int x=dx[k]+topx;
            int y=dy[k]+topy;

            if(grid[x][y]!='#' && !vis[x][y] && grid[x][y]!='*')
            {
                dis[x][y]=dis[topx][topy]+1;
                vis[x][y]=1;

                if(grid[x][y]==grid[desx][desy])
                    return dis[x][y];

                q.push({x,y});
            }
        }
    }

    return -1;
}


int main()
{
    int t;
    cin>>t;

    for(int tc=1; tc<=t; tc++)
    {
        cin>>m>>n;
        int star_cnt=0;
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                cin>>grid[i][j];

                if(grid[i][j]=='P')
                    px=i,py=j;
                if(grid[i][j]=='D')
                    dex=i,dey=j;
                if(grid[i][j]=='*')
                    star_cnt++;
            }
        }

        vector<int>ans;
        vector<pair<int,pair<int,int>>>star,star1;
        bfs(dex,dey);
        star=v;

        bfs(px,py);
        star1=v;
        if(star1.size()>0 && star.size()>0 && star_cnt>1)
        {
            sort(star.begin(),star.end());
            int nod=star[0].first;
            int a=star[0].second.first;
            int b=star[0].second.second;
            for(int i=0; i<star1.size(); i++)
            {
                int c=star1[i].second.first;
                int d=star1[i].second.second;
                int nop=star1[i].first;
                if(a==c && b==d)
                    ans.pb(nod+nop+2);
                else
                    ans.pb(nod+nop+1);
            }
        }
        if(star.size()>0 &&  star1.size()==0)
        {
            int star_to_p=bfs1(star[0].second.first,star[0].second.second,px,py);
            if(star_to_p!=-1 && star_cnt>1)
                ans.pb(star_to_p+star[0].first+2);
        }

        if(star.size()==0 && star1.size()>0)
        {
            for(int i=0; i<star1.size(); i++)
            {
                int a=star1[i].second.first;
                int b=star1[i].second.second;
                int star_to_d=bfs1(a,b,dex,dey);
                if(star_to_d!=-1 && star_cnt>1)
                    ans.pb(star_to_d+star1[i].first+2);
            }
        }


        int p_to_d=bfs1(px,py,dex,dey);
        if(p_to_d!=-1)
            ans.pb(p_to_d);


//
        printf("Case %d: ",tc);

        if(ans.size()>0)
        {
            sort(ans.begin(),ans.end());
            cout<<ans[0]<<endl;
        }
        else
            cout<<"impossible"<<endl;

        memset(grid,'1',sizeof grid);

    }

    return 0;
}
