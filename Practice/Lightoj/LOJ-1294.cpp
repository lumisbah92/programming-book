#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    long long t,n,x,i,j,k,p,sum;
    cin>>t;

    for(i=1; i<=t; i++)
    {
        cin>>n>>x;

        p=n/2;
        sum=p*x;

        cout<<"Case "<<i<<": "<<sum<<"\n";
        p=0;
    }
//

    return 0;
}
