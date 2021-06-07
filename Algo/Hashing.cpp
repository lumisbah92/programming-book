/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int mod = 1000000021, base = 907, sz = 1e6 + 5;
int tc, casee = 1;
ll Hash[sz], mp[sz], Hash1[sz];
string s, x, y, z;

void pre() {
    mp[0] = 1;
    for(int i = 1; i < sz; i++) {
        mp[i] = (mp[i - 1] * base) % mod;
    }
}

ll compute_hash(string s) {
    ll hash_val = 0;
    for(int i = 0; i < s.size(); i++) {
        hash_val = (hash_val * base + (s[i] - 'a' + 1)) % mod;
        Hash[i + 1] = hash_val;
    }
    return hash_val;
}

ll compare(int l, int r) {
    ll rht = Hash[r], lft = (Hash[l - 1] * mp[r - l + 1]) % mod;
    return (rht - lft + mod) % mod;
}


int main() {
    pre();
    string s;
    cin >> s;
    cout<<compute_hash(s)<<endl;;

    return 0;
}


//////////////////////////////////////////



const long long MOD1=1000000007;
const long long MOD2=1000000009;
const ll N=1e5+6;
const ll B=33;
ll pw1[N+1];
ll pw2[N+1];
ll inv1[N+1];
ll inv2[N+1];
ll Hash1[N+1];
ll Hash2[N+1];

long long mul(long long a,long long b,long long mod)
{
    long long res=(a%mod*b%mod)%mod;
    if(res<0)
        res+=mod;
    return res;
}

long long power(long long a, long long b,long long mod)
{
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res =mul(res,a,mod);
        a = mul(a,a,mod);
        b >>= 1;
    }
    return res%mod;
}

void precal()
{
    pw1[0]=1;
    for(ll i=1; i<N; i++)
    {
        pw1[i]=mul(pw1[i-1],B,MOD1);
    }
    inv1[0]=1;
    ll pw_inv1=power(B,MOD1-2,MOD1);

    for(ll i=1; i<N; i++)
        inv1[i]=mul(inv1[i-1],pw_inv1,MOD1);

    pw2[0]=1;
    for(ll i=1; i<N; i++)
    {
        pw2[i]=mul(pw2[i-1],B,MOD2);
    }
    inv2[0]=1;
    ll pw_inv2=power(B,MOD2-2,MOD2);

    for(ll i=1; i<N; i++)
        inv2[i]=mul(inv2[i-1],pw_inv2,MOD2);

}

long long add(long long a,long long b,long long mod)
{
    long long res=(a%mod+b%mod)%mod;
    if(res<0)
        res+=mod;
    return res;
}

void build(string s)
{
    ll n=s.size();
    for(ll i=0; i<n; i++)
    {
        Hash1[i]=add(((i==0)?0:Hash1[i-1]),mul(s[i]-'a'+1,pw1[i],MOD1),MOD1);
    }
    for(ll i=0; i<n; i++)
    {
        Hash2[i]=add(((i==0)?0:Hash2[i-1]),mul(s[i]-'a'+1,pw2[i],MOD2),MOD2);
    }

}

pll get_hash(ll x,ll y)
{
    ll res1=add(Hash1[y],-((x==0)?0:Hash1[x-1]),MOD1);
    res1=mul(res1,inv1[x],MOD1);
    ll res2=add(Hash2[y],-((x==0)?0:Hash2[x-1]),MOD2);
    res2=mul(res2,inv2[x],MOD2);
    return {res1,res2};
}

/////////////////////////////////////////////////////////////////


/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int mod = 1e9 + 7, base = 907, sz = 4e5 + 100;
int tc;
ll Hash[sz], mp[sz], Hash1[sz], Hash2[sz];

void pre() {
    mp[0] = 1;
    for(int i = 1; i < sz; i++) {
        mp[i] = (mp[i - 1] * base) % mod;
    }
}

void compute_hash(string s) {
    ll hash_val = 0;
    for(int i = 0; i < s.size(); i++) {
        hash_val = (hash_val * base + (s[i] - 'a' + 1)) % mod;
        Hash[i + 1] = hash_val;
    }
}

ll compare(int l, int r) {
    ll rht = Hash[r], lft = (Hash[l - 1] * mp[r - l + 1]) % mod;
    return (rht - lft + mod) % mod;
}

void compute_hash1(string s) {
    ll hash_val = 0;
    for(int i = 0; i < s.size(); i++) {
        hash_val = (hash_val * base + (s[i] - 'a' + 1)) % mod;
        Hash1[i + 1] = hash_val;
    }
}

ll compare1(int l, int r) {
    ll rht = Hash1[r], lft = (Hash1[l - 1] * mp[r - l + 1]) % mod;
    return (rht - lft + mod) % mod;
}

void compute_hash2(string s) {
    ll hash_val = 0;
    for(int i = 0; i < s.size(); i++) {
        hash_val = (hash_val * base + (s[i] - 'a' + 1)) % mod;
        Hash2[i + 1] = hash_val;
    }
}

ll compare2(int l, int r) {
    ll rht = Hash2[r], lft = (Hash2[l - 1] * mp[r - l + 1]) % mod;
    return (rht - lft + mod) % mod;
}

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    pre();
    cin >> tc;
    while(tc--) {
        string a, b, c; cin >> a >> b >> c;
        compute_hash1(c);
        string s = a + b;
        compute_hash(s);
        int Ans = INT_MAX, n = s.size(), m = c.size();
        ll val_c = compare1(1, m);
        for(int i = 1; i <= n - m + 1; i++) {
            ll cur = compare(i, i + m - 1);
            if(cur == val_c) {
                Ans = n;
                break;
            }
        }
        if(Ans != INT_MAX) {
            cout << Ans << endl;
            continue;
        }
        compute_hash(a);
        compute_hash2(b);
        int x = a.size(), y = b.size();

        vector < int > pref, suf;

        for(int i = x; i >= max(0, x - m + 1); i--) {
            ll cur = compare(i, x);
            ll cur1 = compare1(1, x - i + 1);
            if(cur == cur1) {
                suf.push_back(x - i + 1);
            }
        }

        for(int i = 1; i <= min(m, y); i++) {
            ll cur = compare2(1, i);
            ll cur1 = compare1(m - i + 1, m);
            if(cur == cur1) {
                pref.push_back(i);
            }
        }
        for(auto i : pref) {
            int cur = i, baki = m - cur;
            Ans = min(Ans, n + (m - cur));
            auto pos = lower_bound(suf.begin(), suf.end(), baki) - suf.begin();
            pos--;
            if(pos < 0)continue;
            cur += suf[pos];
            Ans = min(Ans, n + (m - cur));
        }

        for(auto i : suf) {
            int cur = i, baki = m - cur;
            Ans = min(Ans, n + (m - cur));
            auto pos = lower_bound(pref.begin(), pref.end(), baki) - pref.begin();
            pos--;
            if(pos < 0)continue;
            cur += pref[pos];
            Ans = min(Ans, n + (m - cur));
        }

        if(Ans == INT_MAX)Ans = x + y + m;

        cout << Ans << endl;

    }

    return 0;
}

//////////////////////////////////////////////////////
https://codeforces.com/contest/126/submission/118367797
// Start Time:
#include<bits/stdc++.h>
using namespace std;
#define ff                first
#define ss                second
#define MX                1000005
#define ll                long long
#define pb                push_back
#define pi                acos(-1.0)
#define PQ                priority_queue
#define mod               1000000007
#define eps               1/1000000000
#define pii               pair<int,int>
#define pll               pair<ll,ll>
#define endl              "\n"
#define Fast              ios::sync_with_stdio(0) //cin.tie(0); cout.tie(0)
#define bug(a)            cout<<#a<<":"<<a<<endl
#define TC(tc)            cout<<"Case "<<tc++<<": "
#define all(x)            (x).begin(),(x).end()
#define allr(x)           (x).rbegin(),(x).rend()
#define Mul(a,b)          (a%mod * b%mod)%mod
#define Add(a,b)          (a%mod + b%mod)%mod
#define mem(a,b)          memset(a, b, sizeof(a))
#define double_print(x,a) cout<<fixed<<setprecision(x)<<a<<endl
ll tc=1;


ll Hash[MX], mp[MX],base=31;
void pre()
{
    mp[0] = 1;
    for(int i = 1; i < MX; i++)
        mp[i] = (mp[i - 1] * base) % mod;
}

void compute_hash(string s)
{
    ll hash_val = 0;
    for(int i = 0; i < s.size(); i++)
    {
        hash_val = (hash_val * base + (s[i] - 'a' + 1)) % mod;
        Hash[i + 1] = hash_val;
    }
}

ll compare(int l, int r)
{
    ll rht = Hash[r], lft = (Hash[l - 1] * mp[r - l + 1]) % mod;
    return (rht - lft + mod) % mod;
}

int main()
{
    Fast;

    pre();

    string s;
    cin>>s;
    ll n=s.size();
    compute_hash(s);

    vector<ll>v[30];
    for(int i=0; i<n; i++)
        v[s[i]-'a'].pb(i+1);

    ll idx=-1;
    for(int i=1; i<=n; i++)
    {
        ll val=compare(1,i);
        ll val1=compare(n-i+1,n);
        if(val==val1)
        {
            ll calc=i-1;
            for(auto j:v[s[0]-'a'])
            {
                if(j+calc<n)
                {
                    ll now=compare(j, j+calc);
                    if(now==val && j>1)
                    {
                        idx=i;
                        break;
                    }
                }
                else
                    break;
            }
        }
    }

    if(idx!=-1)
        cout<<s.substr(0,idx)<<endl;
    else
        cout<<"Just a legend\n";

    return 0;
}

