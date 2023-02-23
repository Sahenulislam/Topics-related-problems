#include <bits/stdc++.h>
using namespace std;
#define ll int
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define gcd __gcd
#define pb push_back

const ll mxn=1e6+10;
ll isp[mxn+10];
vector<ll>prime;
void siv()
{
    for(ll i=0; i<=mxn; i++)isp[i]=0;
    for(ll i=4; i<=mxn; i+=2)isp[i]=1;
    isp[0] = isp[1] = 1;
    for(ll i=3; i*i<=mxn; i+=2)
    {
        if(isp[i]==0)
        {
            for(ll j=i*i; j<=mxn; j+=(i+i))
                isp[j]=1;
        }
    }
    prime.pb(2);
    for(ll i=3; i<=mxn; i+=2)
    {
        if(isp[i]==0)
            prime.pb(i);
    }

}
vector<ll>fact[mxn+10];
void PrimeFactorial()
{
    for(ll i=1;i<=mxn;i++)
    {
        ll x=i;
        for(ll j=0;prime[j]*prime[j]<=x;j++)
        {
            if(x%prime[j]==0)
            {
                fact[i].pb(prime[j]);
                while(x%prime[j]==0)
                {
                    x/=prime[j];
                }
            }
        }
        if(x>1)
            fact[i].pb(x);
    }
}
ll mp[mxn+10];

int main()
{
    siv();
    PrimeFactorial();
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n+10];
        for(ll i=0; i<n; i++)cin>>a[i];
        ll ans=1,k=0;
        for(ll i=0; i<n; i++)
        {
            ll f=0;
            vector<ll>v;
            for(auto x:fact[a[i]])
                v.pb(x);
            for(auto x:v)
            {
                mp[x]++;
                if(mp[x]==2)
                    f=2;
            }
            while(f==2)
            {
               for(auto x:fact[a[k]])
               {
                   mp[x]--;
               }
               f=0;
               for(auto x:v)
               {
                   if(mp[x]==2)
                    f=2;
               }
               k++;
            }
            ans=max(ans,i-k+1);
        }
        if(ans==1)
            cout<<"-1"<<"\n";
        else
            cout<<ans<<"\n";
        for(ll i=0; i<=mxn; i++)
            mp[i]=0;
    }
}
