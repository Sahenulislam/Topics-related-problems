/*
    Given 2 number a,b  where 1<=a,b<=10^15
    multiply 2 number. Mod= 10^15

    Solution:
    In this problem we can't calculate a*b normally
    because a*b cross long long limit;


    we can solve this problem with divide & conquer plus addition:
    example:
    a=5 b=6
    5*6 means 5 adding 6 times or 6 adding 5 times

                5*6
                |
                5*3+5*3
                |
                5*2+5
                |
                5*1+5*1
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod=1e15;
ll multiply(ll a,ll b)
{
    if(b<=0)return 0;
    if(b==1) return a;
    if(b%2==0)
    {
        ll tm=multiply(a,b/2);
        cout<<tm<<endl;
        return ((tm%mod)+(tm%mod))%mod;
    }
    else
        return (a+(multiply(a,b-1))%mod)%mod;
}
int main()
{
    ll a,b;
    cin>>a>>b;
    cout<<multiply(a,b)<<endl;
    return 0;
}


