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

ll comp(pair<pair<ll,ll>,ll>p,pair<pair<ll,ll>,ll>q)
{
    ll x1=p.first.first;
    ll y1=p.first.second;
    ll x2=q.first.first;
    ll y2=q.first.second;
    if(x2*(x1+y1)==x1*(x2+y2))
        return p.second<q.second;
    else
        return x2*(x1+y1)<x1*(x2+y2);
}

int main()
{
    fast
    ll n;
    cin>>n;
    vector<pair<pair<ll,ll>,ll>>v;
    for(ll i=1;i<=n;i++)
    {
        ll a,b;
        cin>>a>>b;
        v.pb({{a,b},i});

    }
    sort(v.begin(),v.end(),comp);
    for(auto x:v)
    {
        cout<<x.second<<in;
    }



    return 0;
}
