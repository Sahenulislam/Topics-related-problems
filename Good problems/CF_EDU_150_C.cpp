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
const ll mxn=2e5+10;
ll dp[mxn+10][8][3];
vector<ll>v{0,1,10,100,1000,10000};
string s;
ll recur(ll i,ll mx,ll f)
{
    if(i==-1)return 0;
    if(dp[i][mx][f]!=MINF)return dp[i][mx][f];
    ll ans=MINF;
    if(f)
    {
        ll tm=(s[i]-'A')+1;
        if(mx<=tm)ans=recur(i-1,max(mx,tm),f)+v[tm];
        else ans=recur(i-1,mx,f)-v[tm];
    }
    else
    {
        ll tm=(s[i]-'A')+1;
        if(mx<=tm)ans=max(ans,recur(i-1,max(mx,tm),f)+v[tm]);
        else ans=max(ans,recur(i-1,max(mx,tm),f)-v[tm]);
        for(ll j=1; j<=5; j++)
        {
            if(mx<=j)ans=max(ans,recur(i-1,max(mx,j),1LL)+v[j]);
            else ans=max(ans,recur(i-1,max(mx,j),1LL)-v[j]);
        }
    }
    return dp[i][mx][f]=ans;
}
int main()
{
    fast
    ll t;
    cin>>t;
    while(t--)
    {
        cin>>s;
        ll n=s.size();
        for(ll i=0; i<=n; i++)
        {
            for(ll j=0; j<=6; j++)
            {
                dp[i][j][0]=MINF;
                dp[i][j][1]=MINF;
            }
        }
        ll ans=recur(n-1,0,0);
        cout<<ans<<endl;
    }
    return 0;
}
