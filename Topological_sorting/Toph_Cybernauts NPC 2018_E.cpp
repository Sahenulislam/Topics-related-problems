#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define INF        9223372036854775806
#define MINF       -9223372036854775806
#define gcd __gcd
#define yes "YES"
#define no "NO"
#define pb push_back
#define in " "
#define mone "-1"
#define zero "0"
#define one "1"
#define nl "\n"
pair<ll,ll>CORDINATE[8]= {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
const ll mod=1e9+7;
const double pi=2*acos(0.0);
ll lcm(ll a,ll b)
{
    return (a/(__gcd(a, b)))*b;
}
const ll mxn=200;
vector<ll>g[mxn+10];
ll degree[mxn+10];


int main()
{
    fast
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<string>vc;
        set<ll>st;
        for(ll i=0; i<n; i++)
        {
            string s;
            cin>>s;
            vc.pb(s);
            for(ll j=0; j<s.size(); j++)
                st.insert((s[j]-'0')+1);
        }
        for(ll i=1; i<n; i++)
        {
            string s=vc[i-1];
            string ss=vc[i];
            for(ll j=0; j<min(s.size(),ss.size()); j++)
            {
                if(s[j]!=ss[j])
                {
                    degree[(ss[j]-'0')+1]++;
                    g[(s[j]-'0')+1].pb((ss[j]-'0')+1);
                    break;
                }
            }
        }
        queue<ll>q;
        for(auto x:st)
        {
            if(degree[x]==0)
            {
                q.push(x);
            }
        }
        vector<ll>ans;
        while(!q.empty())
        {
            ll u=q.front();
            ans.pb(u);
            q.pop();
            for(auto v:g[u])
            {
                degree[v]--;
                if(degree[v]==0)
                {
                    q.push(v);
                }
            }
        }
        vector<char>tm;
        for(auto x:ans)
        {
            st.erase(x);
            char ch=((x-1)+'0');
            tm.pb(ch);
        }
        for(auto x:st)
        {
            char ch=((x-1)+'0');
            tm.pb(ch);
        }
        for(ll i=0;i<tm.size();i++)
        {
            if(i+1==tm.size())
            cout<<tm[i]<<endl;
            else cout<<tm[i]<<" ";
        }
        for(ll i=0; i<=mxn; i++)
        {
            degree[i]=0;
            g[i].clear();
        }
    }
    return 0;
}
