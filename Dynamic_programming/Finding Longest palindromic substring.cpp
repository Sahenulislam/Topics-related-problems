/*
    Given a string finding longest palindromic substring (s>=1000)

    Solve:
    In this problem we can use dp for finding palindrom.
    Firstly we find i to j a substring then check this
    substring is palindrom or not. if substring is pal-
    ndrom then return 1 or not return 0.

    *Time complexity:
    Check palindrom in dp 0(n^2)
    Al possible substring 0(n^2)

    Total complexity 0(n^2+n^2) not 0(n^4)
    because dp calculate only n^2 one time
    after calculation of dp then all call
    dp is 0(1) for memo_
    rization.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

string s;
ll dp[1005][1005];
ll lon_pa_sub(ll i,ll j)
{
    if(i>=j)return 1;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i]==s[j])
    {
        return dp[i][j]=lon_pa_sub(i+1,j-1);
    }
    else
    {
        return dp[i][j]=0;
    }
}
int main()
{
    cin>>s;
    ll mx=1;
    memset(dp,-1,sizeof(dp));
    for(ll i=0; i<s.size(); i++)
    {
        for(ll j=i+1; j<s.size(); j++)
        {
            if(lon_pa_sub(i,j)==1)
            {
                mx=max(mx,j+1-i);
            }
        }
    }
    cout<<mx<<endl;
    return 0;
}
