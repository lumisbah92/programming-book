#include<bits/stdc++.h>
#define MOD 1000000007
using ll =long long;
using namespace std;

char a[105],b[105];
string dp[105][105];

string fn(int i, int j)
{
    if(!a[i] || !b[j])
        return "";
    string &ans=dp[i][j];
    if(ans.size()) return ans;

    if(a[i]==b[j])
    {
        string temp;
        temp=a[i];
        temp+=fn(i+1,j+1);
        if(temp.size()>ans.size())
           ans=temp;
        else if(temp.size()==ans.size() && temp<ans)
            ans=temp;
    }
    else
    {
        string temp;
        temp=fn(i+1,j);
        if(temp.size()>ans.size())
           ans=temp;
        else if(temp.size()==ans.size() && temp<ans)
            ans=temp;

        temp=fn(i,j+1);
        if(temp.size()>ans.size())
           ans=temp;
        else if(temp.size()==ans.size() && temp<ans)
            ans=temp;
    }
    return ans;
}

int main()
{
    ll t,tc=1;
    cin>>t;
    while(t--)
    {
        scanf("%s %s",a,b);
        for(int i=0; a[i]; i++)
            for(int j=0; b[j]; j++)
                dp[i][j]="";

        cout<<"Case "<<tc++<<": ";
        string ans=fn(0,0);
        if(ans.size())
            cout<<ans<<endl;
        else
            cout<<":(\n";
    }
    return 0;
}
