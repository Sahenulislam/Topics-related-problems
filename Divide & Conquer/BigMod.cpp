/*
     Given two integer a,b & mod
     calculate a^b;

     solution

     Example: a=5 b=6

                    5^6
                    |
                    5^3*5^3
                    |
                    5^2*5
                    |
                    5^1*5^1
                    |
                    5
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll BigMod(ll a,ll b,ll mod)
{
    if(b<1)return 1;
    if(b==1)return a;
    if(b%2==0)
    {
        ll tm=BigMod(a,b/2,mod);
        return ((tm%mod)*(tm%mod))%mod;
    }
    else return (a*(BigMod(a,b-1,mod)%mod))%mod;
}
int main()
{
    ll a,b,mod;
    cin>>a>>b>>mod;
    cout<<BigMod(a,b,mod)<<endl;
    return 0;
}
