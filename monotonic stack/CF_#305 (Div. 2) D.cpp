#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define pb push_back
#define in " "
int main()
{
    fast
    ll n;
    cin>>n;
    ll a[n+10];
    vector<ll>v;
    set<ll>st;
    for(ll i=1; i<=n; i++)
    {
        cin>>a[i];
        st.insert(a[i]);
    }

    for(auto x:st)
        v.pb(x);
    reverse(v.begin(),v.end());

    stack<pair<ll,ll>>stc1,stc2;
    stc1.push({0,0});
    vector<ll>v1,v2;

    for(ll i=1; i<=n; i++)
    {
        while(stc1.top().first>=a[i])
            stc1.pop();
        v1.pb(stc1.top().second);
        stc1.push({a[i],i});
    }

    stc2.push({0,n+1});
    for(ll i=n; i>=1; i--)
    {
        while(stc2.top().first>=a[i])
            stc2.pop();
        v2.pb(stc2.top().second);

        stc2.push({a[i],i});
    }

    reverse(v2.begin(),v2.end());

    map<ll,ll>mp;
    for(ll i=0; i<n; i++)
    {
        mp[a[i+1]]=max(mp[a[i+1]],v2[i]-v1[i]-1);
    }
    ll cnt=1;

    for(ll i=0; i<v.size(); i++)
    {
        for(ll j=cnt; j<=mp[v[i]]; j++)
        {
            cnt++;
            cout<<v[i]<<in;
        }
    }
    cout<<endl;
    return 0;
}

