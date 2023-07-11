#include <bits/stdc++.h>
using namespace std;
#define ll int
const ll mxn=3e5+10;
vector<ll>g[mxn+10];
ll parent[mxn+10],level[mxn+10],st[mxn+10][26];
ll sub[mxn+10];
void dfs(ll u,ll p)
{
    for(auto v:g[u])
    {
        if(v!=p)
        {
            sub[v]=1;
            parent[v]=u;
            level[v]=level[u]+1;
            dfs(v,u);
            sub[u]+=sub[v];
        }
    }
}

void sparsetable(ll n)
{
    for(ll j=1; j<26; j++)
    {
        for(ll i=1; i<=n; i++)
        {
            st[i][j]=-1;
        }
    }
    for(ll i=1; i<=n; i++)
    {
        st[i][0]=parent[i];
    }
    for(ll j=1; (1<<j)<=n; j++)
    {
        for(ll i=1; i<=n; i++)
        {
            if(st[i][j-1]!=-1)
            {
                st[i][j]=st[st[i][j-1]][j-1];
            }
        }
    }
}

ll LCA(ll u,ll v)
{
    if(level[u]<level[v])
        swap(u,v);
    ll log=log2(level[u]);
    log++;
    for(ll j=log; j>=0; j--)
    {
        if(level[u]-(1<<j)>=level[v])
            u=st[u][j];
    }
    if(u==v)return u;
    for(ll j=log; j>=0; j--)
    {
        if(st[u][j]!=st[v][j])
        {
            u=st[u][j];
            v=st[v][j];
        }
    }
    return parent[u];
}
ll kthAncestor(ll u,ll k)
{
    ll log;
    while(k>0)
    {
        log=log2(k);
        u=st[u][log];
        k-=(1<<log);
    }
    return u;

}

int main()
{
    freopen("library.in","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,q;
        cin>>n>>q;
        for(ll i=0; i<n-1; i++)
        {
            ll u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        parent[1]=-1;
        level[1]=0;
        sub[1]=1;
        dfs(1,-1);
//        for(ll i=1;i<=n;i++)
//            cout<<sub[i]<<" ";
//        cout<<"\n";
        sparsetable(n);
        while(q--)
        {
            ll u,v;
            cin>>u>>v;
            if(u==v)
            {
                cout<<n<<"\n";
                continue;
            }
            ll lca=LCA(u,v);
            ll distance=level[u]+level[v]-(2*level[lca]);
            if(distance%2!=0){
                cout<<"0"<<"\n";
                continue;
            }
            distance=distance/2LL;
            ll x;
            ll ans=0;
            if(level[u]>level[v])
            {
                x=kthAncestor(u,distance);
                ans+=sub[x];
                x=kthAncestor(u,distance-1);
                ans-=sub[x];
            }
            else if(level[u]<level[v])
            {
                x=kthAncestor(v,distance);
                ans+=sub[x];
                x=kthAncestor(v,distance-1);
                ans-=sub[x];
            }
            else
            {
                ans=n;
                x=kthAncestor(v,distance-1);
                ans-=sub[x];
                x=kthAncestor(u,distance-1);
                ans-=sub[x];
            }
            cout<<ans<<"\n";
        }
        for(ll i=0; i<=n; i++)
        {
            g[i].clear();
            parent[i]=0;
            level[i]=0;
            sub[i]=0;

        }
    }
    return 0;
}
