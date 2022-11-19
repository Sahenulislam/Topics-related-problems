#include<bits/stdc++.h>
using namespace std;
#define ll long long

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
ordered_set<pair<ll,ll>>st;
ordered_set<pair<ll,ll>>ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,tt=1;
    cin>>t;
    while(t--)
    {
        ll n,q;
        cin>>n>>q;
        st.insert({1,n});
        ll p=1;
        ans.insert({n,p++});
        cout<<"Case "<<tt++<<": "<<endl;
        while(q--)
        {
            char ch;
            ll x;
            cin>>ch>>x;
            if(ch=='F')
            {
                cout<<(*ans.find_by_order(x-1)).first<<endl;

            }
            else
            {
                auto k=st.upper_bound({x,0});
                k--;
                ll x1=k->first;
                ll y1=k->second;
                st.insert({x1,x});
                st.insert({x+1,y1});
                ans.erase(ans.lower_bound({y1-x1+1,0}));
                ans.insert({x-x1+1,p++});
                ans.insert({y1-x,p++});
                st.erase(k);
            }
        }
        st.clear();
        ans.clear();

    }
    return 0;

}
