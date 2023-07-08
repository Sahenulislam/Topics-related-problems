#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define print(x) for(int i=0;i<x.size();i++)cout<<x[i]<<" ";
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
ll dp[110][110][2][2];

ll recur(ll ev,ll od,ll x,ll tr)
{
    if(ev==0&&od==0&&x==0)return 1;
    if(ev==0&&od==0&&x==1)return 0;
    if(dp[ev][od][x][tr]!=-1)return dp[ev][od][x][tr];
    ll mx;
    if(tr==1)
    {
        mx=INF;
        if(ev!=0)
            mx=min(mx,recur(ev-1,od,x,0LL));
        if(od!=0)
            mx=min(mx,recur(ev,od-1,x,0LL));

    }
    else
    {
        mx=0;
        if(ev!=0)
            mx=max(mx,recur(ev-1,od,x,1LL));
        if(od!=0)
            mx=max(mx,recur(ev,od-1,x^1,1LL));

    }
    return dp[ev][od][x][tr]=mx;
}

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
        ll ev=0,od=0;
        for(ll i=0; i<n; i++)
        {
            cin>>a[i];
            if(a[i]%2==0)ev++;
            else od++;
        }
        memset(dp,-1,sizeof(dp));
        ll ans=recur(ev,od,0,0);
        if(ans==1)cout<<"Alice"<<nl;
        else cout<<"Bob"<<nl;
    }
    return 0;
}
