#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back

int dx[]= {0,0,1,-1};
int dy[]= {1,-1,0,0};

bool vis[25][25];
int dis[25][25];
char grid[25][25];
int n,m;
int ax,ay,bx,by,cx,cy,hx,hy;

void bfs(int sx,int sy)
{
    queue<pair<int,int>>q;
    q.push({sx,sy});
    memset(vis,0,sizeof(vis));
    memset(dis,100,sizeof(dis));
    vis[sx][sy]=1;
    dis[sx][sy]=0;

    while(!q.empty())
    {
        pair<int,int>top;
        top=q.front();
        q.pop();
        int top_dis=dis[top.first][top.second];

        for(int i=0; i<4; i++)
        {
            int x=top.first+dx[i];
            int y=top.second+dy[i];

            if(x>=0 && y>=0 && x<n && y<m &&
                    grid[x][y]!='#' && grid[x][y]!='m' && vis[x][y]==0)
            {
                dis[x][y]=min(top_dis+1,dis[x][y]);
                q.push({x,y});
                vis[x][y]=1;
            }
        }
    }
}

int main()
{
    int t;
    cin>>t;
    for(int k=1; k<=t; k++)
    {
        cin>>n>>m;
        memset(grid,'*',sizeof(grid));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cin>>grid[i][j];

                if(grid[i][j]=='a')
                    ax=i,ay=j;
                if(grid[i][j]=='b')
                    bx=i,by=j;
                if(grid[i][j]=='c')
                    cx=i,cy=j;
                if(grid[i][j]=='h')
                    hx=i,hy=j;
            }
        }

        bfs(hx,hy);

       int a=dis[ax][ay];
       int b=dis[bx][by];
       int c=dis[cx][cy];

       int ans=max(a,max(b,c));
       printf("Case %d: %d\n",k,ans);
    }

    return 0;
}
