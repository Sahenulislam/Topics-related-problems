/*
    given a array.

    * choose k index value;
    * x=a[i1]&a[i2]...&a[ik];
    then a[i1]-=x; a[i2]-=x; a[ik]-=x;

    possible choose of k and calculate x; then,
    array theke x minus korle finaly amra full array
    er sob value zero korte parbo oy sob k er man print
    korte hobe etai ans;

                    example:  13 7 25 19
                    ekhane amra sob number er binary value ber korbo

                        32 16 8 4 2 1

                    13-     0 1 1 0 1
                    7-      0 0 1 1 1
                    25-     1 1 0 0 1
                    19-     1 0 0 1 1


         ans for example k: 1,2;
         because 1 element 13&13=13 so, a[0]-13=0,,,, evabe full array zero hoye jabe
         also 2 element another possible;
*/



#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
//fast
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n+10];
        for(ll i=0; i<n; i++)cin>>a[i];
        ll bit[32]= {0};
        for(ll i=0; i<n; i++)
        {
            ll j=1;
            while(a[i]!=0)
            {
                ll rem=a[i]%2;
                a[i]=a[i]/2;
                if(rem==1)
                    bit[j]++;
                j++;
            }
        }
        ll j;
        vector<ll>v;
        for(ll i=1; i<=n; i++)
        {
            for(j=1; j<32; j++)
            {
                if(bit[j]!=0&&bit[j]%i!=0)
                    break;
            }
            if(j==32)
                v.pb(i);
        }
        sort(v.begin(),v.end());
        for(ll i=0; i<v.size(); i++)
            cout<<v[i]<<in;
        cout<<endl;
    }
    return 0;
}
