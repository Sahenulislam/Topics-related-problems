/*
        The number of relative primes in a given interval
        given interval [1,r] and number n. calculated number which are relative prime
        or co_prime of n.

        Ey problem e amra ulta kaj korte pari sheta holo n er sob prime factor diye
        r ke divide korle ja ashbe oboshy ta n er relative prime na finally eta ke r
        theke minus korlei ans peye jabo.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
#define endl "\n"
ll LCM(ll a,ll b)
{
    return (a/(__gcd(a, b)))*b;
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,r;
        cin>>n>>r;
        vector<ll>v;
        for(ll i=2; i*i<=n; i++)      // prime Factorizetion of n
        {
            if(n%i==0)
            {
                v.pb(i);
                while(n%i==0)
                {
                    n/=i;
                }
            }
        }
        if(n>1)
            v.pb(n);
        ll k=1<<v.size();
        vector<vector<ll>>vm;
        for(ll i=0;i<k;i++)          // Bit_masking of all combination
        {
            vector<ll>temp;
            for(ll j=0;j<v.size();j++)
            {
                if(i&(1<<j))
                {
                    temp.pb(v[j]);
                }
            }
            vm.pb(temp);
        }
        ll ans=0;
        for(ll i=0;i<vm.size();i++)     // inclusion_exclusion
        {
            ll lcm=1;
            for(ll j=0;j<vm[i].size();j++)
            {
                lcm=LCM(lcm,vm[i][j]);
            }
            if(vm[i].size()==0)continue;
            ll d=r/lcm;
            if(vm[i].size()%2==0)
                ans-=d;
            else
                ans+=d;
        }
        cout<<r-ans<<endl;           // all number r - all number whose are did not relative prime
    }
    return 0;
}

