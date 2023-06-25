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
    ll n,m;
    cin>>n>>m;
    ll a[n+10];
    ll b[m+10];
    for(ll i=0; i<n; i++)
        cin>>a[i];
    for(ll i=0; i<m; i++)
        cin>>b[i];
    ll gc=0;
    for(ll i=1; i<n; i++)
    {
        gc=gcd(gc,abs(a[0]-a[i]));
    }
    for(ll i=0; i<m; i++)
    {
        cout<<gcd(gc,a[0]+b[i])<<in;
    }

    return 0;
}
