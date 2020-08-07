#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll n;
    cin>>n;
    pair <ll,ll> arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].first;
        arr[i].second=i;
    }
    sort(arr,arr + n);
    pair <ll,ll> ans[n];
    ll ans_count=0;
    ll p[n];
    ll p_count=1;
    p[0]=0;
    for(ll i=1;i<n;i++)
        if(arr[i].first!=arr[i-1].first)
            p[p_count++]=i;
    for(ll i=0;i<p_count-1;i++)
    {
        p[i]=p[i+1]-p[i];

    }
    p[p_count-1]=n-p[p_count-1];
    ll mi=0;
    ll pi=0;
    while(1)
    {   
        if(mi>=n)
            break;
        if(p[pi]==1)
        {
            ans[ans_count].first=arr[mi].first;
            ans[ans_count++].second=0;
        }
        else if(p[pi]==2)
        {
            ans[ans_count].first=arr[mi].first;
            ans[ans_count++].second=arr[mi+1].second-arr[mi].second;
        }
        else
        {
            int flag=0;
            for(ll i=mi+1;i<mi+p[pi]-1;i++)
            {
                if(2*arr[i].second!=arr[i-1].second+arr[i+1].second)
                {
                    flag=1;
                    break;
                }
            }
            if(!(flag))
            {
                ans[ans_count].first=arr[mi].first;
                ans[ans_count].second=arr[mi+1].second-arr[mi].second;
                ans_count++;
            }
        }
        mi+=p[pi];
        pi++;
    }
    cout<<ans_count<<endl;
    for(int i=0;i<ans_count;i++)
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
}