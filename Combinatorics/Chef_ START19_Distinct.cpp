#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define printv(x) for(ll i=0;i<x.size();i++){if(i+1==x.size())cout<<x[i]<<endl;else cout<<x[i]<<" ";}
#define printa(x,n) for(ll i=0;i<n;i++){if(i+1==n)cout<<x[i]<<endl;else cout<<x[i]<<" ";}
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define INF        9223372036854775806
#define MINF       -9223372036854775806
#define eps          1e-8
#define gcd __gcd
#define yes "YES"
#define no "NO"
#define pb push_back
#define si size()
#define in " "
#define mone "-1"
#define zero "0"
#define one "1"
#define PI acos(-1)
#define nl "\n"
#define siz(pir) (ll)pir.size()
const ll mod=1e9+7;
const double pi=2*acos(0.0);
ll lcm(ll a,ll b)
{
    return (a/(__gcd(a, b)))*b;
}
const ll mx=1e6+10;


int main()
{
    fast
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n+10];
        map<ll,ll>mp;
        for(ll i=0; i<n; i++)
        {
            cin>>a[i];
            mp[a[i]]++;
        }
        ll ans=0;
        for(auto x:mp)
        {
            ans+=ans*x.second;
            ans+=x.second;
            ans%=mod;
        }
        cout<<ans<<nl;

    }
    return 0;
}
