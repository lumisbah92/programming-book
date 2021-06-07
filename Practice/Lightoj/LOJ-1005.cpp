#include<bits/stdc++.h>
using namespace std;
using ll =long long;

int n;
ll rec(int r, int c,int k)
{
    if(k>r || k>c)
        return 0;
    if(k==0)
        return 1;
    return c*rec(r-1,c-1,k-1)+rec(r-1,c,k);
}

int main()
{
    ll t,tc=1;
    cin>>t;
    while(t--)
    {
        ll k;
        cin>>n>>k;
        cout<<"Case "<<tc++<<": "<<rec(n,n,k)<<endl;
    }
}
