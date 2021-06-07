/**==============================================================*
*            "Bismillahir Rahmanir Raheem"                       *
*        Author          :  Misbah Uddin Tareq.                  *
*        Semester        :  5(C),CSE                             *
*        University      :  Leading University,Sylhet.           *
*===============================================================**/

#include<bits/stdc++.h>
using namespace std;
#define  ll                     long long
#define  pb                     push_back
#define  pii                    pair<int,int>
#define  pll                    pair<ll,ll>
#define  ff                     first
#define  ss                     second
#define  mxx                    100005
#define  endl                   "\n"
#define  mod                    1e9+7
#define  pi                     acos(-1.0)
#define  PQ                     priority_queue
#define  mem(a,b)               memset(a, b, sizeof(a))
#define  bug(a)                 cout<<#a<<":"<<a<<endl
#define  all(x)                 (x).begin(),(x).end()
#define  allr(x)                (x).rbegin(),(x).rend()
#define  double_print(x,a)      cout<<fixed<<setprecision(x)<<a<<endl


#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T>  using orderedSet =
    tree<T, null_type, less<T>,
    rb_tree_tag, tree_order_statistics_node_update>;

int main()
{
    ios::sync_with_stdio(0);
    //cin.tie(0);

    orderedSet<ll>st;
    ll q;
    cin>>q;
    while(q--)
    {
        char c;
        cin>>c;
        ll x;
        cin>>x;

        if(c=='I')
            st.insert(x);
        else if(c=='C')
            cout<<st.order_of_key(x)<<endl;
        else if(c=='K')
        {
            x--;
            if(x>=st.size())
                cout<<"invalid\n";
            else
            {
                ll p=*st.find_by_order(x);
                cout<<p<<endl;
            }
        }
        else if(c=='D')
        {
            if(st.size()>0)
            {
                auto p=st.lower_bound(x);
                if(*p==x)
                    st.erase(p);
            }
        }
    }

    return 0;
}

https://www.spoj.com/problems/ORDERSET/
