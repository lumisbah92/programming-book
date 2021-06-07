#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,i;
    string s,a;
    cin>>t;

    for(i=1;i<=t;i++)
    {
        cin>>s;
        a=s;
        reverse(s.begin(),s.end());

        if(s==a)
            printf("Case %d: Yes\n",i);
        else
            printf("Case %d: No\n",i);
    }

    return 0;
}

