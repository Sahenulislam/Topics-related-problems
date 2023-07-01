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
    ll a[n+10];
    for(ll i=0; i<n; i++)
    {
        cin>>a[i];
    }
    string s;
    cin>>s;
    ll prem[n+10][5];
    ll prex[n+10][5];
    for(ll i=0; i<=n; i++)
    {
        for(ll j=0; j<=4; j++)
        {
            prem[i][j]=0;
            prex[i][j]=0;
        }
    }
    for(ll i=0; i<s.size(); i++)
    {
        if(s[i]=='M')
        {
            prem[i][a[i]]++;
        }
        else if(s[i]=='X')
        {
            prex[i][a[i]]++;
        }
        for(ll j=0; j<=2; j++)
        {
            if(i!=0)
            {
                prem[i][j]+=prem[i-1][j];
                prex[i][j]+=prex[i-1][j];
            }
        }
    }
    ll ans=0;
    for(ll i=0; i<n; i++)
    {
        if(s[i]!='E')continue;
        for(ll j=0; j<=2; j++)
        {
            for(ll k=0; k<=2; k++)
            {
                set<ll>st{0,1,2,3};
                if(st.count(a[i]))
                    st.erase(a[i]);
                if(st.count(j))
                    st.erase(j);
                if(st.count(k))
                    st.erase(k);
                ll tm=*st.begin();
                ans+=prem[i][j]*(prex[n-1][k]-prex[i][k])*tm;
            }
        }
    }
    cout<<ans<<nl;
    return 0;
}
