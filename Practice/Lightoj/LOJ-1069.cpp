#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,x=0,a,b;
    cin>>n;

    for(i=1; i<=n; i++)
    {
        cin>>a>>b;

        if(a>0)
        {
            if(b!=a)
                x+=abs(b-a)*4;
            x+=3;
            x+=5;
            x+=3;
            x+=(a*4);
            x+=3;
            x+=5;
        }
        else
            x=0;

        printf("Case %d: %d\n",i,x);
        x=0;
    }

    return 0;
}
