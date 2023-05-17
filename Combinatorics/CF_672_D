#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
ordered_set<pair<ll,ll>>st;


ll mod=998244353;

ll big_mod(ll a,ll b)
{
    if(b==0)return 1;
    if(b%2==0)
    {
        ll tm=big_mod(a,b/2);
        return ((tm%mod)*(tm%mod))%mod;
    }
    else return ((a%mod)*(big_mod(a,b-1)%mod))%mod;
}

const ll mx=3e5+10;
ll fac[mx+10];
void factorial()
{
    fac[0]=1;
    for(ll i=1; i<=mx; i++)
    {
        fac[i]=(fac[i-1]*i)%mod;
    }
}

ll ncr(ll n,ll r)
{
    return (fac[n]*((big_mod(fac[n-r],mod-2)*big_mod(fac[r],mod-2))%mod))%mod;
}


int main()
{
    fast
    factorial();
    ll n,k;
    cin>>n>>k;
    vector<pair<ll,ll>>v;
    for(ll i=0; i<n; i++)
    {
        ll x,y;
        cin>>x>>y;
        v.pb({y,x});
    }
    sort(v.begin(),v.end());
    ll g=1;
    for(auto [y,x]:v)
    {
        st.insert({x,g++});
    }
    ll ans=0;
    ll c=1e15;
    for(auto [y,x]:v)
    {
        auto m=st.order_of_key({y,c});
        if(m>=k)
        {
            ans+=ncr(m-1,k-1);
            ans%=mod;
        }
        st.erase(st.upper_bound({x,0}));
    }
    cout<<ans<<"\n";

}
