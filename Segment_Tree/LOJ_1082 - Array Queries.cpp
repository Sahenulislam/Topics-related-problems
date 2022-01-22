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
const ll mx=1e5;
ll a[mx+2],st[4*mx];
void build(ll cur,ll left,ll right)
{
    if(left==right)
    {
        st[cur]=a[left];
        return;
    }
    ll mid=(left+right)/2;
    build(cur*2,left,mid);
    build(cur*2+1,mid+1,right);
    st[cur]=min(st[cur*2],st[cur*2+1]);
}

ll query(ll cur,ll left,ll right,ll l,ll r)
{
    if(l>right||left>r)return INF;
    if(left>=l&&right<=r)return st[cur];
    ll mid=(left+right)/2;
    ll x=query(cur*2,left,mid,l,r);
    ll y=query(cur*2+1,mid+1,right,l,r);
    return min(x,y);
}
int main()
{
    ll t,tt=1;
    cin>>t;
    while(t--)
    {
        ll n,q,x,y,z;
        cin>>n>>q;
        for(ll i=0; i<n; i++)cin>>a[i];
        build(1,0,n-1);
        cout<<"Case "<<tt++<<":"<<endl;
        for(ll i=0; i<q; i++)
        {
            cin>>y>>z;
            y--,z--;
            ll m=query(1,0,n-1,y,z);
            cout<<m<<endl;
        }
    }
    return 0;
}


