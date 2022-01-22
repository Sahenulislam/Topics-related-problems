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
    st[cur]=st[cur*2]+st[cur*2+1];
}

ll query(ll cur,ll left,ll right,ll l,ll r)
{
    if(l>right||left>r)return 0;
    if(left>=l&&right<=r)return st[cur];
    ll mid=(left+right)/2;
    ll x=query(cur*2,left,mid,l,r);
    ll y=query(cur*2+1,mid+1,right,l,r);
    return (x+y);
}
void update(ll cur,ll left,ll right,ll pos,ll val,ll ty)
{
    if(pos>right||left>pos)return;
    if(left>=pos&&right<=pos)
    {
        if(ty==1)
            st[cur]=val;
        else
            st[cur]+=val;
        return;
    }
    ll mid=(left+right)/2;
    update(cur*2,left,mid,pos,val,ty);
    update(cur*2+1,mid+1,right,pos,val,ty);
    st[cur]=st[cur*2]+st[cur*2+1];
}
int main()
{
    ll t,tt=0;
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
            cin>>x;
            if(x==1)
            {
                cin>>y;
                ll m=query(1,0,n-1,y,y);
                cout<<m<<endl;
                update(1,0,n-1,y,0,1);
            }
            else if(x==2)
            {
                cin>>y>>z;
                update(1,0,n-1,y,z,2);
            }
            else
            {
                cin>>y>>z;
                ll m=query(1,0,n-1,y,z);
                cout<<m<<endl;
            }
        }
    }
    return 0;
}

