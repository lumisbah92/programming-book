#include<bits/stdc++.h>
using namespace std;
int main()
{

    long long int t,x1,y1,x2,y2,n,x,y,i,j;
    cin>>t;

    for(i=1;i<=t;i++)
    {
        cin>>x1>>y1>>x2>>y2;
        cin>>n;

        printf("Case %d:\n",i);

        while(n--)
        {
            cin>>x>>y;

            if((x>x1 && x<x2) && (y>y1 && y<y2))
                cout<<"Yes\n";
            else
                cout<<"No\n";
        }
    }

    return 0;
}
