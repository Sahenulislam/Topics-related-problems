#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

vector<ll>v[200010];
ll cost[200010];
void toplogical_sort(ll n)
{
    ll e=0,cnt=0;
    set<ll>st;
    for(ll i=1; i<=n; i++)
    {
        if(cost[i]==0)
            st.insert(i);
    }
    while(!st.empty())
    {
        set<ll>stt;
        for(auto i:st)
        {
            stt.insert(i);
        }
        st.clear();
        while(!stt.empty())
        {
            auto it=stt.begin();
            e++;
            for(ll i=0; i<v[*it].size(); i++)
            {
                ll m=v[*it][i];
                cost[m]--;
                if(cost[m]==0)
                {
                    if(m>*it)
                        stt.insert(m);
                    else if(*it!=m)
                        st.insert(m);
                }
            }
            stt.erase(it);
        }
        cnt++;
    }
    if(e==n)cout<<cnt<<endl;
    else cout<<"-1"<<endl;
}
int main()
{
    ll t;
    ll n,m,a,b;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(ll i=1; i<=n+5; i++)
        {
            cost[i]=0;
            v[i].clear();
        }
        for(ll i=1; i<=n; i++)
        {
            cin>>m;
            if(m==0)continue;
            for(ll j=1; j<=m; j++)
            {
                cin>>a;
                v[a].pb(i);
                cost[i]++;
            }
        }
        toplogical_sort(n);
    }
    return 0;
}

