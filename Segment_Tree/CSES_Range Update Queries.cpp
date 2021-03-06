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

const ll mx=2e5;
ll a[mx+2];
struct
{
    ll sum;
    ll prop;
} str[mx*4];

void build(ll node,ll left,ll right)
{
    if(left==right)
    {
        str[node].sum=a[left];
        str[node].prop=0;
        return;
    }
    ll mid=(left+right)/2;
    build(node*2,left,mid);
    build(node*2+1,mid+1,right);
    str[node].sum=str[node*2].sum+str[node*2+1].sum;
}

void update(ll node,ll left,ll right,ll l,ll r,ll val)
{
    if(left>r||right<l)
        return;
    if(left>=l&&right<=r)
    {
        str[node].sum+=(right+1-left)*val;
        str[node].prop+=val;
        return;
    }
    ll mid=(left+right)/2;
    update(node*2,left,mid,l,r,val);
    update(node*2+1,mid+1,right,l,r,val);
    str[node].sum=str[node*2].sum+str[node*2+1].sum+((right+1-left)*str[node].prop);
}

ll query(ll node,ll left,ll right,ll l,ll r,ll carry=0)
{
    if(left>r||right<l)return 0;
    if(left>=l&&right<=r)return str[node].sum+(right+1-left)*carry;
    ll mid=(left+right)/2;
    ll p=query(node*2,left,mid,l,r,carry+str[node].prop);
    ll q=query(node*2+1,mid+1,right,l,r,carry+str[node].prop);
    return (p+q);
}
int main()
{
    ll n,q;
    cin>>n>>q;
    for(ll i=0;i<n;i++)cin>>a[i];
    build(1,0,n-1);
    while(q--)
    {
        ll x;
        cin>>x;
        if(x==1)
        {
            ll left,right,val;
            cin>>left>>right>>val;
            left--,right--;
            update(1,0,n-1,left,right,val);
        }
        else
        {
            ll left,right;
            cin>>left;
            left--;
            ll ans=query(1,0,n-1,left,left,0);
            cout<<ans<<endl;
        }
    }
    return 0;
}
