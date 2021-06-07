#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j;
    string s,a,p="",q="";
    cin>>n;
    getchar();

    for(i=1; i<=n; i++)
    {
        getline(cin,s);
        getline(cin,a);

        for(j=0; j<s.size(); j++)
            s[j]=tolower(s[j]);

        for(j=0; j<s.size(); j++)
        {
            if(isalpha(s[j]))
                p+=s[j];
        }


        for(j=0; j<a.size(); j++)
            a[j]=tolower(a[j]);

        for(j=0; j<a.size(); j++)
        {
            if(isalpha(a[j]))
                q+=a[j];
        }
//
        sort(p.begin(),p.end());
        sort(q.begin(),q.end());

        if(p==q)
            printf("Case %d: Yes\n",i);
        else
            printf("Case %d: No\n",i);

        p="";
        q="";
    }

    return 0;
}
