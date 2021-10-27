/*
    Given an array A and M container. Find minimum/M sub-array
    where maximum sub-array sum minimum possible.

    Ey problem e amra answer er upor binary search kore ber korte pari.
    ekhane ek ekta container/sub-array sum ke mid hishabe dhore check
    korte hobe je ey sum ta ans hote pare kina.
    jodi sub-array beshi hoye jay orthat mid er value kom hoy sub-array
    shonkha M theke bere jay tahole ekhaner ans count kora jabena. mid
    sub-array sum barate hobe.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF        9223372036854775806
#define MINF       -9223372036854775806

int main()
{
    ll t,tt=1;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        ll a[n+2];
        for(ll i=0; i<n; i++)cin>>a[i];
        ll left=0;
        ll right=1e18;
        ll mxx=INF;
        while(left<=right)
        {
            ll mx=-1,sum=0,cnt=0;
            ll mid=(left+right)/2;
            for(ll i=0; i<n; i++)
            {
                sum+=a[i];
                if(sum>mid)
                {
                    sum-=a[i];
                    mx=max(mx,sum);
                    cnt++;
                    sum=a[i];
                }
            }
            cnt++;
            mx=max(mx,sum);
            if(cnt<=m&&mx<mxx)
                mxx=mx;
            if(cnt<=m)
                right=mid-1;
            else
                left=mid+1;
        }
        cout<<"Case "<<tt++<<": "<<mxx<<endl;
    }
    return 0;
}
