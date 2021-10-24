/*
        Given an array A. Find maximum subsequence of array A.
        sequence sum= A[0]-A[1]+A[3]-A[4].......
        where -10^6<=A>=10^6.
        n complexity accepted.

        Solution: Here array has negative value so we can't do
        greedy solution.

        we have 2 state
        1. array index
        2. count sequence
        if we take this element count sequence is 0 so sum+=-a[pos];
        else 1 sum+=a[pos];
        complexity
        state 1. n
        state 2. 2
        so 0(n);
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
ll dp[10000][2],a[10000];
ll sub_sum(ll pos,ll cnt)
{
    if(pos>n)return 0;
    else if(dp[pos][cnt]!=-1)return dp[pos][cnt];
    else if(cnt==0)
    {
        ll val1=sub_sum(pos+1,0);
        ll val2=sub_sum(pos+1,1)+a[pos];
        return dp[pos][cnt]=max(val1,val2);
    }
    else if(cnt==1)
    {
        ll val1=sub_sum(pos+1,1);
        ll val2=sub_sum(pos+1,0)-a[pos];
        return dp[pos][cnt]=max(val1,val2);
    }
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(ll i=0;i<n;i++)
            cin>>a[i];
        for(ll i=0;i<=n+2;i++)
        {
            for(ll j=0;j<=n+2;j++)
            {
                dp[i][j]=-1;
            }
        }
        cout<<sub_sum(0,0)<<endl;
    }
    return 0;
}


