#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,x,i,j,r1,r2,c1,c2;
    cin>>n;

    for(i=1; i<=n; i++)
    {
        cin>>r1>>c1>>r2>>c2;
        if(abs(r1-r2)==abs(c1-c2))
            printf("Case %d: 1\n",i);
        else if(((abs(r2-r1))%2==0 && (abs(c2-c1))%2==0)
                || ((abs(r2-r1))%2!=0 && (abs(c2-c1))%2!=0))
            printf("Case %d: 2\n",i);
        else
            printf("Case %d: impossible\n",i);
    }

    return 0;
}
