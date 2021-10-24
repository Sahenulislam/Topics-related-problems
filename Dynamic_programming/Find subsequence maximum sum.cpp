/*
        Given an array A. Find maximum subsequence of array A.
        sequence sum= 1*A[0]+2*A[1]+3*A[3].......
        where -10^3<=A>=10^3.
        n^2 complexity accepted.

        Solution: Here array has negative value so we can't do
        greedy solution.

        we have 2 state
        1. array index
        2. previous sequence
        if we take this element the next element multiply (pre+1)*A[pos];
        complexity
        state 1. n
        state 2. n
        so 0(n^2);
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
ll dp[10000][1000],a[10000];
ll sub_sum(ll pos,ll prv)
{
    if(pos>n)return 0;
    else if(dp[pos][prv]!=-1)return dp[pos][prv];
    else
    {
        ll val1=sub_sum(pos+1,prv);
        ll val2=sub_sum(pos+1,prv+1)+(prv*a[pos]);
        return dp[pos][prv]=max(val1,val2);
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
        cout<<sub_sum(0,1)<<endl;
    }
    return 0;
}

