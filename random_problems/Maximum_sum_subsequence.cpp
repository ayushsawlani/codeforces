#include <bits/stdc++.h>
using namespace std;
#define M (ll)(1e9+7)
#define ll long long
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n];
        for(ll i=0;i<n;i++)
        {
            cin>>a[i];
        }
        ll max_incl_n[n];
        ll max_incl_1[n];
        max_incl_n[n-1]=a[n-1];
        ll sum=a[n-1];
        for(ll i=1;i<n;i++)
        {
            sum+=a[n-i-1];
            max_incl_n[n-i-1]=max(sum,max_incl_n[n-i]);
        }
        sum=a[0];
        max_incl_1[0]=a[0];
        for(ll i=1;i<n;i++)
        {
            sum+=a[i];
            max_incl_1[i]=max(sum,max_incl_1[i-1]);
//            cout<<max_incl_1[i]<<endl;
        }

        ll max_sum_sub_start[n];
        max_sum_sub_start[0]=a[0];
        ll curr=a[0];
        for(ll i=1;i<n;i++)
        {
            curr=max(curr+a[i],a[i]);
            max_sum_sub_start[i]=max(max_sum_sub_start[i-1],curr);
         //   cout<<max_sum_sub_start[i]<<endl;
        }
        curr=a[n-1];
        ll max_sum_sub_end[n];
        max_sum_sub_end[n-1]=a[n-1];
        for(ll i=1;i<n;i++)
        {
            curr=max(curr+a[n-i-1],a[n-i-1]);
            max_sum_sub_end[n-i-1]=max(max_sum_sub_end[n-i],curr);
           // cout<<max_sum_sub_end[n-i-1]<<endl;
        }
        for(ll i=0;i<n;i++)
        {
            ll ans=(-1*(INT64_MAX));
            if(i>0)
                ans=max(ans,max_sum_sub_start[i-1]);
            ans=max(ans,max_sum_sub_end[i]);
            if(i>0)
                ans=max(max_incl_1[i-1]+max_incl_n[i],ans);
            cout<<ans<<" ";
        }
        cout<<endl;
    }
}