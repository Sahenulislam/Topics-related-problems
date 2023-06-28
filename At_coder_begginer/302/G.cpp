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
    ll n;
    cin>>n;
    ll g[10][10];
    for(ll i=0;i<=7;i++)
    {
        for(ll j=0;j<=7;j++)
            g[i][j]=0;
    }
    ll a[n+10];
    ll b[n+10];
    for(ll i=0; i<n; i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b,b+n);
    for(ll i=0; i<n; i++)
    {
        g[b[i]][a[i]]++;
    }
    for(ll i=1; i<=4; i++)
        g[i][i]=0;
    ll ans=0;
    for(ll i=1; i<=4; i++)
    {
        for(ll j=1; j<=4; j++)
        {
            ll mn=min(g[i][j],g[j][i]);
            if(mn<=0)continue;
            ans+=mn;
            g[i][j]-=mn;
            g[j][i]-=mn;
        }
    }
    for(ll i=1; i<=4; i++)
    {
        for(ll j=1; j<=4; j++)
        {
            for(ll k=1; k<=4; k++)
            {
                ll mn=min({g[i][j],g[j][k],g[k][i]});
                if(mn<=0)continue;
                ans+=mn*2;
                g[i][j]-=mn;
                g[j][k]-=mn;
                g[k][i]-=mn;
            }
        }
    }

    for(ll i=1; i<=4; i++)
    {

        for(ll j=1; j<=4; j++)
        {
            for(ll k=1; k<=4; k++)
            {
                for(ll m=1; m<=4; m++)
                {
                    ll mn=min({g[i][j],g[j][k],g[k][m],g[m][i]});
                    if(mn<=0)continue;
                    ans+=mn*3;
                    g[i][j]-=mn;
                    g[j][k]-=mn;
                    g[k][m]-=mn;
                    g[m][i]-=mn;
                }
            }
        }
    }
    cout<<ans<<nl;

    return 0;
}
