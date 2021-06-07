#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t,n,x,i,j,a=0,b=0;
    cin>>t;
    string s;

    for(i=1; i<=t; i++)
    {
        cin>>n;
        a=0;
        cout<<"Case "<<i<<":\n";
        for(j=1; j<=n; j++)
        {
            cin>>s;
            if(s=="donate")
            {
                cin>>x;
                a+=x;
            }
            else
                cout<<a<<endl;
        }
    }

    return 0;
}
