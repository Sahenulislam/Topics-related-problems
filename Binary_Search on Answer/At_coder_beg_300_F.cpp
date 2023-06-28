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
    ll n,m,k;
    cin>>n>>m>>k;
    string s;
    cin>>s;
    ll pre[n+10]= {0};
    for(ll i=1; i<=n; i++)
    {
        pre[i]=pre[i-1];
        if(s[i-1]=='x')pre[i]++;
    }
    ll ans=0;
    for(ll i=1; i<=n; i++)
    {
        ll left=1;
        ll right=n*m;
        while(left<=right)
        {
            ll mid=(left+right)/2;
            ll xx=0,br;
            if(mid>n)
            {
                br=mid-n;
                xx=(br/n)*pre[n];
                xx+=pre[n]-pre[i-1];
                xx+=pre[br%n];
            }
            else
                xx=pre[mid]-pre[i-1];
            if(xx<=k)
            {
                ans=max(ans,mid-i+1);
                left=mid+1;
            }
            else
                right=mid-1;
        }
    }
        cout<<ans<<nl;


    return 0;
}
