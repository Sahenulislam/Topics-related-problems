#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define gcd __gcd
const ll mx=1e5;
ll seg[mx*4][26],a[mx+4];
ll x[30];
void build(ll cur,ll left,ll right)
{
    if(left==right)
    {
        seg[cur][a[left]]=1;
        return;
    }
    ll mid=(left+right)/2;
    build(cur*2,left,mid);
    build(cur*2+1,mid+1,right);
    for(ll i=1; i<=26; i++)
    {
        seg[cur][i]=max(seg[cur*2][i],seg[cur*2+1][i]);
    }
}

void update(ll cur,ll left,ll right,ll l,ll r,ll val)
{
    if(left>r||right<l)return;
    if(left>=l&&right<=r)
    {
        seg[cur][val]=1;
        return;
    }
    ll mid=(left+right)/2;
    update(cur*2,left,mid,l,r,val);
    update(cur*2+1,mid+1,right,l,r,val);
    for(ll i=1; i<=26; i++)
    {
        seg[cur][i]=max(seg[cur*2][i],seg[cur*2+1][i]);
    }
}
void query(ll cur,ll left,ll right,ll l,ll r)
{
    if(l>right||left>r)return;
    if(l<=left&&r>=right)
    {
        for(ll i=1; i<=26; i++)
        {
            if(seg[cur][i]==1)
                x[i]++;
        }
        return;
    }
    ll mid=(left+right)/2;
    query(cur*2,left,mid,l,r);
    query(cur*2+1,mid+1,right,l,r);
}
int main()
{
    ll t,tt=1;
    cin>>t;
    while(t--)
    {
        memset(seg,0,sizeof(seg));
        memset(a,0,sizeof(a));
        ll n,q;
        cin>>n>>q;
        string s;
        cin>>s;
        for(ll i=0; i<n; i++)
        {
            a[i]=(s[i]-'a')+1;
        }
        build(1,0,n-1);
        cout<<"Case "<<tt++<<":"<<endl;
        while(q--)
        {

            ll cnt=0,m,i,j;
            cin>>m;
            if(m==1)
            {
                char ch;
                cin>>i>>j>>ch;
                ll val=(ch-'a')+1;
                i--,j--;
                update(1,0,n-1,i,j,val);
            }
            else
            {
                memset(x,0,sizeof(x));
                cin>>i>>j;
                i--,j--;
                query(1,0,n-1,i,j);
                for(ll i=0; i<27; i++)
                    if(x[i])cnt++;
                cout<<cnt<<endl;
            }

        }
    }
    return 0;
}

