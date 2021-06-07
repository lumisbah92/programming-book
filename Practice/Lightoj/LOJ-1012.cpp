#include<bits/stdc++.h>
using namespace std;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int visited[25][25];
char grid[25][25];
int n,m,cnt,x,y;

void init(int n,int m)
{
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=m; j++)
        {
            visited[i][j]=0;
            grid[i][j]='*';
        }
    }
}

int valid(int p, int q)
{
    if(p>=1 && q>=1 && p<=n && q<=m && (grid[p][q]=='.' || grid[p][q]=='@') && visited[p][q]==0)
        return true;
    return false;
}

void dfs(int x,int y)
{
    visited[x][y]=1;
    cnt++;

    for(int i=0; i<4; i++)
    {
        int p=x+dx[i];
        int q=y+dy[i];

        if(valid(p,q))
        {
            dfs(p,q);
        }
    }
}

int main()
{
    int t;
    cin>>t;
    for(int k=1; k<=t; k++)
    {
        cin>>m>>n;
        init(n,m);

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                cin>>grid[i][j];
                if(grid[i][j]=='@')
                    x=i,y=j;
            }
        }

        cnt=0;
        dfs(x,y);

        printf("Case %d: %d\n",k,cnt);
    }

    return 0;
}
