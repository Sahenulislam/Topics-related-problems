#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define Print(_Q) for(int i=0;i<_Q.size();i++){if(i+1==_Q.size())cout<<_Q[i]<<"\n";else cout<<_Q[i]<<" ";}
#define Sort(_Q) sort(_Q.begin(),_Q.end())
#define INF  9223372036854775806
#define MINF -9223372036854775806
#define sz(x) (ll)x.size()
#define gcd __gcd
#define yes "YES"
#define no  "NO"
#define pb  push_back
#define in  " "
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
const ll mxn=2e5+10;
vector<ll>g1[mxn+10],g2[mxn+10];

int main()
{
    fast
    ll t,tt=1;
    cin>>t;
    while(t--)
    {
        ll n,w;
        cin>>n>>w;
        ll a[n+10];
        vector<ll>v1,v2,vc1,vc2;
        for(ll i=0; i<n; i++)
            cin>>a[i];
        for(ll i=0; i<=n/2; i++)
        {
            v1.pb(a[i]);
        }
        for(ll i=n/2+1; i<n; i++)
        {
            v2.pb(a[i]);
        }
    

        ll x=1LL<<sz(v1);

        for(ll i=1; i<=x; i++)
        {

            ll ans=0;
            for(ll j=0; j<sz(v1); j++)
            {
                if(i&(1LL<<j))
                {
                    ans+=v1[j];
                }
            }
            if(ans<=w)
            {
                vc1.pb(ans);
            }
        }
        x=1LL<<sz(v2);
        for(ll i=1; i<=x; i++)
        {

            ll ans=0;
            for(ll j=0; j<sz(v2); j++)
            {
                if(i&(1LL<<j))
                {
                    ans+=v2[j];
                }
            }
            if(ans<=w)
            {
                vc2.pb(ans);
            }
        }

        sort(vc2.begin(),vc2.end());
        sort(vc1.begin(),vc1.end());
        ll fans=0;
        for(ll i=0; i<sz(vc1); i++)
        {
            ll k=w-vc1[i];
            ll ind=upper_bound(vc2.begin(),vc2.end(),k)-vc2.begin();
            fans+=ind;
        }
        cout<<"Case "<<tt++<<": "<<fans<<nl;
    }
    return 0;
}


