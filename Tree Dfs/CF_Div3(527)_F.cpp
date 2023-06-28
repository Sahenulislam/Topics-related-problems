#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll mxn=2e5+10;
vector<ll>g[mxn+10];
ll sub[mxn+10];
ll ans[mxn+10];
ll a[mxn+10];
ll n,tot=0;
void dfs(ll u,ll pa,ll dept)
{
    ans[1]+=dept*a[u];
    sub[u]=a[u];
    for(auto v:g[u])
    {
        if(v!=pa)
        {
            dfs(v,u,dept+1);
            sub[u]+=sub[v];
        }
    }
}
void dfs2(ll u,ll pa)
{
    for(auto v:g[u])
    {
        if(v!=pa)
        {
            ans[v]=ans[u]+tot-2*sub[v];
            dfs2(v,u);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    for(ll i=1; i<=n; i++)
    {
        cin>>a[i];
        tot+=a[i];
    }
    for(ll i=0; i<n-1; i++)
    {
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,-1,0);
    dfs2(1,-1);
    ll mx=ans[1];
    for(ll i=1; i<=n; i++)
    {
        mx=max(mx,ans[i]);
    }
    cout<<mx<<"\n";
    return 0;
}
