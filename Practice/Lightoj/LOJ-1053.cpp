#include<bits/stdc++.h>
using namespace std;
int main()
{
   long long int t,i,a,b,c,x[5];

   cin>>t;

   for(i=1;i<=t;i++)
   {
        cin>>x[0]>>x[1]>>x[2];
        sort(x,x+3);

        if(( (x[0]*x[0]) + (x[1]*x[1]) ) == (x[2]*x[2]) )
            cout<<"Case "<<i<<": yes\n";
        else
            cout<<"Case "<<i<<": no\n";
   }

    return 0;
}
