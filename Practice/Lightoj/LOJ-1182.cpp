#include<bits/stdc++.h>
using namespace std;
int main ()
{
    long long n,x,a=0,i,y;
    cin>>n;

    for(i=1;i<=n;i++)
    {
        cin>>x;
        while(x!=0)
        {
            y=x%2;
            if(y==1)
                a++;
            x/=2;
        }
//
        if(a%2!=0)
            cout<<"Case "<<i<<": odd\n";
        else if(a%2==0)
            cout<<"Case "<<i<<": even\n";
        a=0;
    }

    return 0;
}
