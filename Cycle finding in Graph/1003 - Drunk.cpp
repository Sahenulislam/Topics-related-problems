#include <bits/stdc++.h>
using namespace std;
#define ll int
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
const ll mx=10005;
map<string,vector<string>>v;
map<string,int>visit;
ll x=0;
void dfs(string s)
{
    visit[s]=1;
    for(auto i:v[s])
    {
        if(visit[i]==1)
        {
            x=1;
            return;
        }
        else if(visit[i]==0)
        {
            visit[i]=1;
            dfs(i);
        }
    }
    visit[s]=2;

}
int main()
{
    ll t,tt=1;
    cin>>t;
    while(t--)
    {
        v.clear();
        visit.clear();
        x=0;
        ll n;
        cin>>n;
        for(ll i=0; i<n; i++)
        {
            string s1,s2;
            cin>>s1>>s2;
            v[s1].pb(s2);
            visit[s1]=0;
        }
        for(auto i:visit)
        {
            if(i.second==0)
            {
                dfs(i.first);
                if(x==1)
                    break;
            }
        }
        if(x==1)
            cout<<"Case "<<tt++<<": "<<"No"<<endl;
        else
            cout<<"Case "<<tt++<<": "<<"Yes"<<endl;

    }
    return 0;
}

