#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,i,j,k,t,st;
    int v[105];
    cin>>t;

    for(i=1; i<=t; i++)
    {
        cin>>n;
        memset(v,0,sizeof v);
        for(int k=2; k<=n; k++)
        {
            x=k;
            for(j=2; j*j<=x; j++)
            {
                while(x%j==0)
                {
                    v[j]++;
                    x/=j;
                }
            }
            if(x!=1)
                v[x]++;
        }

        st=0;

        cout<<"Case "<<i<<": "<<n<<" = ";

        for(int k=0; k<=n; k++)
        {
            if(v[k])
            {
                if(st)
                    printf(" * ");
                printf("%d (%d)",k,v[k]);
                st=1;
            }
        }

        printf("\n");
    }


    return 0;
}
