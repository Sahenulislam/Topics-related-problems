#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define INF        9223372036854775806
#define MINF       -9223372036854775806
#define eps          1e-8
#define gcd __gcd
#define yes "YES"
#define no "NO"
#define pb push_back
#define si size()
#define in " "
#define mone "-1"
#define zero "0"
#define one "1"
#define PI acos(-1)
#define endl "\n"


int main()
{
    ll t,tt=1;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        ll a[n+2];
        for(ll i=0; i<=n; i++)
            cin>>a[i];
        k++;
//        if(k-2==0)
//        {
//            cout<<max(a[0],a[n])<<endl;
//            continue;
//        }
        //k-=2;
        ll left=0;
        ll right=1e18;
        ll mxx=INF,d=INF;
        vector<ll>vv;
        while(left<=right)
        {
            vector<ll>v;
            ll sum=0,cnt=0;
            ll mid=(left+right)/2;
            for(ll i=0; i<=n; i++)
            {
                sum+=a[i];
                if(sum>mid)
                {
                    sum-=a[i];
                    v.pb(sum);
                    cnt++;
                    sum=a[i];
                }
            }
            cnt++;
            v.pb(sum);
            if(cnt<=k&&mid<mxx)
            {
                vv.clear();
                mxx=mid;
                vv=v;
            }
            if(cnt<=k)
                right=mid-1;
            else left=mid+1;
        }
        cout<<"Case "<<tt++<<": "<<max(max(mxx,a[0]),a[n])<<endl;
        //cout<<a[0]<<endl;
        for(ll i=0; i<vv.size(); i++)
        {
            cout<<vv[i]<<endl;
        }
        //cout<<a[n]<<endl;
    }
    return 0;
}

