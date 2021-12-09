#include <bits/stdc++.h>
using namespace std;
#define ll int
map<string,vector<string>>v;
map<string,int>visit;
ll x=0;
void dfs(string s)
{
    visit[s]=1; //starting process
    for(auto i:v[s])
    {
        if(visit[i]==1) // cycle find because without finish process excess second time
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
    visit[s]=2; //finish process

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
        for(auto i:visit)  // for disconnected component
        {
            if(i.second==0) // not visited
            {
                dfs(i.first);
                if(x==1) // cycle find
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

