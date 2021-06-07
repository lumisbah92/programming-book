#include<bits/stdc++.h>
using namespace std;
#define pi 2*acos(0.0)
int main()
{
    int t,i;
    double r,ac,as,ans;
    cin>>t;

    for(i=1;i<=t;i++)
    {
        cin>>r;
        ac=pi*r*r;
        as=4*r*r;
        ans=as-ac;

        printf("Case %d: %.2lf\n",i,ans+pow(10,-9));
    }

    return 0;
}
