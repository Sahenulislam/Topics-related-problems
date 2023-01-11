
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define fi first
#define se second
#define pb push_back
#define Fin freopen("input.txt","r",stdin)
#define Fout freopen("outut.txt","w",stdout)
#define NN "\n"
#define SS " "
#define pll pair<ll,ll>
#define All(x) x.begin(),x.end()
#define zz(v) (ll)v.size()
#define test() int TT; for(int TK=1;TK<=TT;TK++)
#define pcs cout<<"Case "<<TK<<": ";



#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define at(X) find_by_order(X)
#define lessThan(X) order_of_key(X)
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

const ll MD = 1e9+7;
const ll MM = 1e5+10;
const double PI = acos(-1.0);
const ll mxn=1e5+10;
ll isp[mxn+10];
vector<ll>prime;
vector<ll>v[mxn+10];
ll fr[mxn+10];
void siv()
{
    isp[1]=1;
    for(ll i=4; i<=mxn; i+=2)isp[i]=1;
    for(ll i=3; i*i<=mxn; i+=2)
    {
        if(isp[i]==0)
        {
            for(ll j=i*i; j<=mxn; j+=(i+i))
            {
                isp[j]=1;
            }
        }
    }
    prime.pb(2);
    for(ll i=3; i<=mxn; i+=2)
    {
        if(isp[i]==0)
            prime.pb(i);
    }
}

const ll mod=1e9+7;
ll big_mod(ll a,ll b)
{
    if(b==0)return 1;
    else if(b==1)return a;
    if(b%2==0)
    {
        ll tm=big_mod(a,b/2);
        return ((tm%mod)*(tm%mod))%mod;
    }
    else return ((a%mod)*(big_mod(a,b-1)%mod))%mod;
}

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    siv();
    ll n;
    cin>>n;
    ll a[n+10];
    for(ll i=0; i<n; i++)
        cin>>a[i];
    for(ll i=0; i<n; i++)
    {
        for(ll j=0; prime[j]*prime[j]<=a[i]&&j<prime.size(); j++)
        {
            if(a[i]%prime[j]==0)
            {
                v[i].pb(prime[j]);
                while(a[i]%prime[j]==0)
                {
                    a[i]/=prime[j];
                }
            }
        }
        if(a[i]>1)v[i].pb(a[i]);
    }
    map<ll,ll>mp;
    for(ll i=0; i<n; i++)
    {
        if(v[i].size()==0)continue;
        ll k=1<<v[i].size();
        for(ll mask=0; mask<=k; mask++)
        {
            ll x=1,cnt=0;
            for(ll j=0; j<v[i].size(); j++)
            {
                if(mask&(1<<j))
                {
                    cnt++;
                    x*=v[i][j];
                }
            }
            if(x!=1)
            {
                //cout<<x<<" "<<cnt<<endl;
                fr[x]++;
                mp[x]=cnt;
            }
        }
    }
    ll ans=big_mod((ll)2,n)-1;
    for(auto it:mp)
    {
        ll x=it.first;
        ll cnt=it.second;
        //cout<<x<<" "<<cnt<<endl;
        if(cnt%2!=0)
        {
            ans-=big_mod((ll)2,fr[x])-1;
            ans+=mod;
            ans%=mod;
        }
        else
        {
            ans+=big_mod((ll)2,fr[x])-1;
            ans%=mod;
        }

    }
    cout<<ans<<endl;
    return 0;
}

