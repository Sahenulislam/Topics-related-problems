/*
    given array a find maximum subsequence sum
    can't taking consecutive element;
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[10000][2],a[10000],n;
ll sub_sum(ll pos,ll pre)
{
    if(pos>n)return 0;
    else if(dp[pos][pre]!=-1)return dp[pos][pre];
    else if(pre==0)
    {
        ll val1=sub_sum(pos+1,0);
        ll val2=sub_sum(pos+1,1)+a[pos];
        return dp[pos][pre]=max(val1,val2);
    }
    else if(pre==1)
    {
        ll val1=sub_sum(pos+1,0);
        return dp[pos][pre]=val1;
    }
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(ll i=0;i<n;i++)cin>>a[i];
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<2;j++)
            {
                dp[i][j]=-1;
            }
        }
        cout<<sub_sum(0,0)<<endl;
    }
    return 0;
}
