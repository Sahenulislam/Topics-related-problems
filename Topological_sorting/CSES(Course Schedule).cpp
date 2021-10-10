#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

vector<ll>v[100010];
ll cost[100010];
void toplogical_sort(ll n)
{
    vector<ll>vv;
    queue<ll>q;
    for(ll i=1; i<=n; i++)
    {
        if(cost[i]==0)
            q.push(i);
    }
    while(!q.empty())
    {
        ll a=q.front();
        q.pop();
        vv.pb(a);
        for(ll i=0; i<v[a].size(); i++)
        {
            ll m=v[a][i];
            cost[m]--;
            if(cost[m]==0)
            {
                q.push(m);
            }
        }
    }
    if(vv.size()==n)
    {
        for(ll i=0;i<vv.size();i++)cout<<vv[i]<<" ";
        cout<<endl;
    }
    else cout<<"IMPOSSIBLE"<<endl;
}
int main()
{
    ll n,m,a,b;
    cin>>n>>m;
    for(ll i=0; i<m; i++)
    {
        cin>>a>>b;
        v[a].pb(b);
        cost[b]++;
    }
    toplogical_sort(n);
    return 0;
}

