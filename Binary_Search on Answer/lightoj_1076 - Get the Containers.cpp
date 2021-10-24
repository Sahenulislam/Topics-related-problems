#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1999999999999
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
