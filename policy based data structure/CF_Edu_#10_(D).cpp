#include <bits/stdc++.h>
using namespace std;
#define ll int
#define printv(x) for(ll i=0;i<x.size();i++){if(i+1==x.size())cout<<x[i]<<endl;else cout<<x[i]<<" ";}
#define printa(x,n) for(ll i=0;i<n;i++){if(i+1==n)cout<<x[i]<<endl;else cout<<x[i]<<" ";}
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define INF        9223372036854775806
#define MINF       -9223372036854775806
#define eps          1e-8
#define gcd __gcd
#define yes "YES"
#define no "NO"
#define pb push_back
#define si size()
#define in " "
#define mone "-1"
#define zero "0"
#define one "1"
#define PI acos(-1)
#define nl "\n"
#define siz(pir) (ll)pir.size()
#define vsort(vie)  sort(vie.begin(),vie.end())
const ll mod=1e9+7;
const double pi=2*acos(0.0);
ll lcm(ll a,ll b)
{
    return (a/(__gcd(a, b)))*b;
}

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
ordered_set<ll>st;

int main()
{
    fast
    ll n;
    cin>>n;
    vector<tuple<ll,ll,ll>>v;
    for(ll i=0; i<n; i++)
    {
        ll x,y;
        cin>>x>>y;
        v.pb({y,x,i});

    }
    vsort(v);
    ll en=0;
    vector<pair<ll,ll>>vc;
    for(ll i=0; i<siz(v); i++)
    {
        auto[y,x,c]=v[i];
        ll ans=st.order_of_key(x);
        vc.pb({c,en-ans});

        st.insert(x);
        en++;
    }
    vsort(vc);
    for(auto x:vc)
        cout<<x.second<<endl;
    return 0;
}
