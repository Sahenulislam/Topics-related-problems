#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define gcd __gcd
const ll mx=1e5;
ll seg[mx*4],lazy[mx*4],a[mx+4];
void PushDown(ll cur,ll left,ll right)
{
    if(lazy[cur]!=-1)
    {
        seg[cur]=(right+1-left)*lazy[cur];
        if(left!=right)
        {
            lazy[cur*2]=lazy[cur];
            lazy[cur*2+1]=lazy[cur];
        }
    }
    lazy[cur]=-1;
}
void update(ll cur,ll left,ll right,ll l,ll r,ll val)
{
    if(lazy[cur]!=-1)PushDown(cur,left,right);
    if(l>right||left>r)return;
    if(l<=left&&r>=right)
    {
        lazy[cur]=val;
        PushDown(cur,left,right);
        return;
    }
    ll mid=(left+right)/2;
    update(cur*2,left,mid,l,r,val);
    update(cur*2+1,mid+1,right,l,r,val);
    seg[cur]=seg[cur*2]+seg[cur*2+1];
}
ll query(ll cur,ll left,ll right,ll l,ll r)
{
    if(lazy[cur]!=-1)PushDown(cur,left,right);
    if(l>right||left>r)return 0;
    if(l<=left&&r>=right)
    {
        PushDown(cur,left,right);
        return seg[cur];
    }
    ll mid=(left+right)/2;
    ll x=query(cur*2,left,mid,l,r);
    ll y=query(cur*2+1,mid+1,right,l,r);
    return (x+y);
}
int main()
{
    ll t,tt=1;
    cin>>t;
    while(t--)
    {
        memset(seg,0,sizeof(seg));
        memset(lazy,-1,sizeof(lazy));
        memset(a,0,sizeof(a));
        ll n,q;
        cin>>n>>q;
        cout<<"Case "<<tt++<<":"<<endl;
        while(q--)
        {
            ll ch;
            cin>>ch;
            ll i,j,val;
            if(ch==1)
            {
                cin>>i>>j>>val;
                update(1,0,n-1,i,j,val);
            }
            else
            {
                cin>>i>>j;
                ll sum=query(1,0,n-1,i,j);
                ll gc=gcd(sum,j+1-i);
                if(gc==(j+1-i))
                {
                    cout<<sum/gc<<endl;
                }
                else
                {
                    cout<<sum/gc<<"/"<<(j+1-i)/gc<<endl;
                }
            }
        }
    }
    return 0;
}

