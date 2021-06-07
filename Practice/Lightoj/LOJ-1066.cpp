#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
#define boundary(x,y) (x>=0 && y>=0 && x<n && y<n)

int dx[]= {0,0,1,-1};
int dy[]= {1,-1,0,0};

int vis[35][35],dis[35][35];
char grid[35][35];
int n;

int bfs(int x,int y, char ch)
{
    queue<pair<int,int>>q;
    q.push({x,y});
    vis[x][y]=1;
    dis[x][y]=0;
    grid[x][y]='.';

    while(!q.empty())
    {
        int a=q.front().first;
        int b=q.front().second;
        q.pop();

        for(int i=0; i<4; i++)
        {
            int xx=a+dx[i];
            int yy=b+dy[i];

            if(xx>=0 && yy>=0 && xx<n && yy<n && (grid[xx][yy]=='.' || grid[xx][yy]== ch) && vis[xx][yy]==0)
            {
                dis[xx][yy]=dis[a][b]+1;
                q.push({xx,yy});
                vis[xx][yy]=1;
                if(grid[xx][yy]==ch)
                    return dis[xx][yy];
            }
        }
    }

    return -1;
}

int main()
{
    int t;
    cin>>t;

    for(int p=1; p<=t; p++)
    {
        cin>>n;
        map<int,pair<int,int>>mp;
        int ans=0;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>grid[i][j];

                if(isalpha(grid[i][j]))
                {
                    mp[grid[i][j]-'A'] = {i,j};
                }
            }
        }

        int k=0;
        for(int i=0; i<mp.size()-1; i++)
        {
            char ch=(i+1)+'A';
            memset(vis,0,sizeof(vis));
            memset(dis,0,sizeof(dis));
            int temp=bfs(mp[i].first, mp[i].second, ch);
            ans+=temp;

            if(temp==-1)
            {
                k=1;
                printf("Case %d: Impossible\n",p);
                break;
            }
        }

        if(!k)
            printf("Case %d: %d\n",p,ans);
    }

    return 0;
}
