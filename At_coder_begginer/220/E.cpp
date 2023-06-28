#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define INF        9223372036854775806
#define MINF       -9223372036854775806
#define gcd __gcd
#define yes "YES"
#define no "NO"
#define pb push_back
#define in " "
#define mone "-1"
#define zero "0"
#define one "1"
#define nl "\n"
pair<ll,ll>CORDINATE[8]= {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
const ll mod=998244353;
const double pi=2*acos(0.0);
ll lcm(ll a,ll b)
{
    return (a/(__gcd(a, b)))*b;
}
const ll mxn=1e6+10;

ll big_mod(ll a,ll b)
{
    if(b==0)return 1;
    else if(b==1)return a;
    if(b%2==0)
    {
        ll tm=big_mod(a,b/2);
        return ((tm%mod)*(tm%mod))%mod;
    }
    else return ((a%mod)*(big_mod(a,b-1)%mod))%mod;
}
ll mul(ll a,ll b)
{
    return (a*b)%mod;
}

int main()
{
    fast
    ll n,d;
    cin>>n>>d;
    ll ans=0;
    for(ll i=1; i<=n-d; i++)
    {
        ans+=mul(big_mod(2LL,d),big_mod(2LL,i-1));
        ans%=mod;
    }
    for(ll i=1; i<=d-1; i++)
    {
        if(i<n&&d-i<n)
        {
            ans+=mul(big_mod(2LL,n-max(i,d-i))-1,mul(big_mod(2LL,i-1),big_mod(2LL,d-i-1)));
            ans%=mod;
        }

    }
    cout<<mul(2LL,ans)<<nl;
    return 0;
}
