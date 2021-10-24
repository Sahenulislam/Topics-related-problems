#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
long long lcm(int a, int b)
{
    return (a / (__gcd(a, b))) * b;
}
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
#define endint "\n"
int main()
{
    ll n,t,sum=0;
    cin>>n>>t;
    ll a[n+10];
    for(ll i=0; i<n; i++)
    {
        cin>>a[i];
    }
    ll low=0;
    ll high=1e18;
    ll mid,m;
    ll mn=1e18;
    while(low<=high)
    {
        mid=(low+high)/2;
        m=0;
        for(ll i=0;i<n;i++)
        {
            if(m>1e18)break;
            m+=(mid/a[i]);
        }
        //cout<<mid<<in<<m<<in<<mn<<endl;
        if(m>=t)
        {
            mn=min(mn,mid);
        }
        if(m>=t)
            high=mid-1;
        else
            low=mid+1;
    }
    cout<<mn<<endl;
    return 0;
}

