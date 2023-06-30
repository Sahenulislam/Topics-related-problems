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
    priority_queue<pair<ll,pair<ll,ll>>>q;
    set<ll>st;
    vector<ll>ans;
    for(ll i=0; i<n; i++)
    {
        cin>>a[i];
        q.push({0,{a[i],i}});
        st.insert(a[i]);
    }
    ll k=0;
    ll tot=0;
    while(!q.empty())
    {
        ll x=-q.top().first;
        ll y=q.top().second.first;
        ll i=q.top().second.second;
        q.pop();
        if(!st.count(y+1))
        {
            k++;
            st.insert(y+1);
            q.push({-x-1,{y+1,i}});
            ans.pb(y+1);
            tot+=abs(a[i]-(y+1));
        }
        if(k==m)break;
        if(!st.count(y-1))
        {
            k++;
            st.insert(y-1);
            q.push({-x-1,{y-1,i}});
            ans.pb(y-1);
            tot+=abs(a[i]-(y-1));
        }
        if(k==m)break;

    }
    cout<<tot<<nl;
    for(auto x:ans)
        cout<<x<<in;
    cout<<nl;
    return 0;
}
