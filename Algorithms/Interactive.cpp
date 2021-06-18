#include <bits/stdc++.h>
using namespace std;
#define SC               scanf
#define PF               printf
#define ull              unsigned long long
#define ld               long double
#define F                first
#define S                second
#define pb               push_back
#define sort_a(a)        sort(a.begin(),a.end());
#define sort_d(a)        sort(a.rbegin(),a.rend());
#define READ(f)          freopen(f, "r", stdin)
#define WRITE(f)         freopen(f, "w", stdout)
#define rev(s)           reverse(s.begin(),s.end())
#define P(ok)            cout << (ok ? "YES\n": "NO\n")
#define Heart              ios_base :: sync_with_stdio(false); cin.tie(NULL);
#define ll long long
typedef pair< ll, ll>                   PII;
ll Ask(int i)
{
    cout<<"? "<< i << endl;
    ll n;
    cin >> n ;
    return n ;
}
void solve()
{
    ll n;
    cin >> n ;
    ll L, Ans = 1e9, R ;
    L = R = 1e9 ;
    ll Left = 1, Right = n ;
    while(Left <= Right)
    {
        ll Mid =  (Left + Right) >> 1 ;
        L = R = 1e9 ;
        Ans = Ask(Mid) ;
        if(Mid - 1)
            L = Ask(Mid - 1) ;
        if(Mid + 1 <= n)
            R = Ask(Mid + 1) ;
        if(Ans < L && Ans  < R)
        {
            Ans = Mid ;
            break ;
        }
        if(L < Ans)
        {
            Right = Mid - 1 ;
        }
        else
            Left = Mid + 1 ;
    }
    cout << "! " << Ans << endl ;
}
int main()
{
    Heart
    solve() ;

}
