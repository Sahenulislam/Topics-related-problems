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
const ll mxn=1e7+10;
ll sp[mxn+10];
void siv()
{
    for(ll i=1; i<=mxn; i++)
        sp[i]=i;
    for(ll i=2; i*i<=mxn; i++)
    {
        if(sp[i]==i)
        {
            for(ll j=i; j<=mxn; j+=i)
            {
                if(sp[j]==j)
                    sp[j]=i;
            }
        }
    }

}

int main()
{
    fast
    siv();
    ll t;
    cin>>t;
    while(t--)
    {
        ll x,y;
        cin>>x>>y;
        ll dif=y-x;
        if(dif==1)
        {
            cout<<mone<<nl;
            continue;
        }
        if(gcd(x,y)>1)
        {
            cout<<zero<<nl;
            continue;
        }
        vector<ll>prime;
        while(dif!=1)
        {
            prime.pb(sp[dif]);
            dif/=sp[dif];
        }
        ll ans=INF;
        for(auto m:prime)
        {
            ans=min(ans,m-(x%m));
        }
        cout<<ans<<nl;


    }
    return 0;
}
