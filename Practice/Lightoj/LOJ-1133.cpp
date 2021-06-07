#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t,n,m,x,i,j,a,p,q;
    vector<long long int>v;
    char c;
    cin>>t;

    for(j=1;j<=t;j++)
    {
        cin>>n>>m;

        while(n--)
        {
            cin>>x;
            v.push_back(x);
        }

        while(m--)
        {
            cin>>c;

            if(c=='S')
            {
                getchar();
                cin>>a;

                for(i=0;i<v.size();i++)
                {
                    v[i]+=a;
                }
            }

            else if(c=='M')
            {
                cin>>a;
                for(i=0;i<v.size();i++)
                {
                    v[i]*=a;
                }
            }
            else if(c=='D')
            {
                cin>>a;
                for(i=0;i<v.size();i++)
                {
                    v[i]/=a;
                }
            }
            else if(c=='R')
                reverse(v.begin(),v.end());
            else if(c=='P')
            {
                cin>>p>>q;
                swap(v[p],v[q]);
            }
        }
//
        printf("Case %d:\n",j);
        for(i=0;i<v.size();i++)
        {
            if(i!=v.size()-1)
                cout<<v[i]<<" ";
            else
                cout<<v[i]<<endl;
        }

        v.clear();
    }

    return 0;
}
