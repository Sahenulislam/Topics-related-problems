#include <bits/stdc++.h>
using namespace std;
#define MAXN   1000005
 #define ll int
ll spf[MAXN];

void sieve()
{
    spf[1] = 1;
    for (ll i=2; i<MAXN; i++)
        spf[i] = i;
    for (ll i=4; i<MAXN; i+=2)
        spf[i] = 2;

    for (ll i=3; i*i<MAXN; i++)
    {
        if (spf[i] == i)
        {
            for (ll j=i*i; j<MAXN; j+=i)
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}

vector<int>v[1000001];
int vis[1000001];
int main() {
    // your code goes here
    for(int i=2;i<=1000000;i++)
    {
        if(v[i].empty())
        {
            for(int j=i;j<=1000000;j+=i)
            {
                v[j].push_back(i);
            }
        }
    }
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int ans = 1,last=0;
        for(int i=0;i<n;i++)
        {
            for(auto &x:v[a[i]])
            {
                if(vis[x])
                    last = max(last, vis[x]);
                vis[x] = i + 1;
            }
            ans = max(ans, i - last + 1);
        }
        if(ans==1)ans=-1;
        cout<<ans<<endl;
        memset(vis,0,sizeof(vis));

    }
    return 0;
}
