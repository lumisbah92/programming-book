#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back

/// direction array;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int n,m,cnt=0;
int vis[1010][1010],ans[1010][1010];
char grid[1010][1010];
vector<pair<int,int>>v;

void bfs(int x, int y)
{
    cnt=0;
    queue<pair<int,int>>q;
    q.push({x,y});
    vis[x][y]=1;
    if(grid[x][y]=='C')
        cnt=1;

    while(!q.empty())
    {
        pair<int,int>top;
        top=q.front();
        v.pb({top.first,top.second});
        q.pop();

        for(int i=0; i<4; i++)
        {
            int xx= top.first+dx[i];
            int yy= top.second+dy[i];

            if(xx>=0 && yy>=0 && xx<n && yy<m &&
               grid[xx][yy]!='#' && vis[xx][yy]==0)
            {
                if(grid[xx][yy]=='C')
                    cnt++;
                vis[xx][yy]=1;
                q.push({xx,yy});
            }
        }
    }
}

int main()
{
    int t;
    scanf("%d",&t);

    for(int k=1; k<=t; k++)
    {
        int q;
        scanf("%d %d %d",&n,&m,&q);
        getchar();
        memset(grid,'*',sizeof(grid));
        memset(ans,-1,sizeof(ans));
        memset(vis,0,sizeof(vis));

        for(int i=0; i<n; i++)
        {
            scanf("%s",grid[i]);
        }

        for(int i=0 ; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(ans[i][j]==-1)
                {
                    bfs(i,j);

                    for(int p=0; p<v.size(); p++)
                        ans[v[p].first][v[p].second]=cnt;
                    v.clear();
                }
            }
        }
//
        printf("Case %d:\n",k);

        while(q--)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            x--,y--;
            printf("%d\n",ans[x][y]);
        }
    }
}
