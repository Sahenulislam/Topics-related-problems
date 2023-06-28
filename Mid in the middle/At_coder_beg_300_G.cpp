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
const ll mod=1e9+7;
const double pi=2*acos(0.0);
ll lcm(ll a,ll b)
{
    return (a/(__gcd(a, b)))*b;
}
const ll mxn=1e6+10;


int main()
{
    fast
    ll n,p;
    cin>>n>>p;
    vector<ll>prime;
    for(ll i=2; i<=100; i++)
    {
        ll f=0;
        for(ll j=2; j*j<=i; j++)
        {
            if(i%j==0)
                f=1;
        }
        if(!f)prime.pb(i);
    }
    vector<ll>a,b;
    for(ll i=0; i<prime.size()&&prime[i]<=p; i++)
    {
        ll x=prime[i];
        if(a.size()<b.size())
        {
            vector<ll>temp;
            while(x<=n)
            {
                for(ll j=0; j<a.size(); j++)
                {
                    if(n/x>=a[j])
                        temp.pb(a[j]*x);
                }

                x*=prime[i];
            }
            for(auto c:temp)
                a.pb(c);
            x=prime[i];
            while(x<=n)
            {
                a.pb(x);
                x*=prime[i];
            }
        }
        else
        {
            vector<ll>temp;
            while(x<=n)
            {
                for(ll j=0; j<b.size(); j++)
                {

                    if(n/x>=b[j])
                        temp.pb(b[j]*x);
                }
                x*=prime[i];
            }
            for(auto c:temp)
                b.pb(c);
            x=prime[i];
            while(x<=n)
            {
                b.pb(x);
                x*=prime[i];
            }
        }

    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    ll ans=a.size()+b.size();
    for(auto x:a)
    {
        ll y=n/x;
        ans+=upper_bound(b.begin(),b.end(),y)-b.begin();
    }
    cout<<ans+1<<nl;
    return 0;
}
