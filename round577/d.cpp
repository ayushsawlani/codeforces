#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector <pair <ll,ll>> compress_array(pair <ll,ll> *a, ll n)
{
    vector <pair <ll,ll>> ans;
    ll i=0;
    ll c=1;
    while(i<n-1)
    {
        if(a[i].first!=a[i+1].first)
        {
            pair <ll,ll> temp;
            temp.first=a[i].first;
            temp.second=c;
            ans.push_back(temp);
            c=1;
        }
        else
        {
            c++;
        }
        i++;   
    }
    pair <ll,ll> temp;
    temp.first=a[i].first;
    temp.second=c;
    ans.push_back(temp);
    c=1;
    return ans;
}
vector <pair <ll,ll>> extremex(pair <ll,ll> *a, ll n)
{
    vector <pair <ll,ll>> ans;
    ll i=0;
    ll c=1;
    while(i<n-1)
    {
        if(a[i].first!=a[i+1].first)
        {
            pair <ll,ll> temp;
            temp.second=a[i].second;
            temp.first=a[i-c+1].second;
            ans.push_back(temp);
            c=1;
        }
        else
        {
            c++;
        }
        i++;   
    }
    pair <ll,ll> temp;
    temp.second=a[i].second;
    temp.first=a[i-c+1].second;
    ans.push_back(temp);
    c=1;
    return ans;
}
ll mod(ll x)
{
    if(x<0)
        x=((-1)*x);
    return x;
}
int main()
{
    ll n,m,k,q;
    cin>>n>>m>>k>>q;
    pair <ll,ll> treasures[k];
    for(ll i=0;i<k;i++)
    {
        cin>>treasures[i].first>>treasures[i].second;
    }
    set <ll> safe;
    for(ll i=0;i<q;i++)
    {
        ll temp;
        cin>>temp;
        safe.insert(temp);
    }
    sort(treasures,treasures+k);
    /*for(ll i=0;i<k;i++)
    {
        cout<<treasures[i].first<<" "<<treasures[i].second<<endl;
    }*/
    vector <pair <ll,ll>> ext=extremex(treasures,k);
    vector <pair <ll,ll>> row=compress_array(treasures,k);
    ll dp[ext.size()][2];
    dp[0][0]=ext[0].second-1;
    dp[0][1]=ext[0].first-1;
    auto just1=safe.lower_bound(1);
    auto just2=just1;
    if(just2!=safe.begin())
        just2--;
    if(just1==safe.end())
        just1--;
    if(row[0].first!=1)
    {
        dp[0][0]=min(mod((*just2)-1)+mod((*just2)-ext[0].second),mod((*just1)-1)+mod((*just1)-ext[0].second));
        dp[0][1]=min(mod((*just2)-1)+mod((*just2)-ext[0].first),mod((*just1)-1)+mod((*just1)-ext[0].first));
    }
    /*cout<<ext.size()<<" "<<row.size()<<endl;
    for(ll i=0;i<ext.size();i++)
    {
        cout<<ext[i].first<<" "<<ext[i].second<<endl;
    }
    cout<<endl;
    for(ll i=0;i<ext.size();i++)
    {
        cout<<row[i].first<<" "<<row[i].second<<endl;
    }*/
    for(ll i=0;i<ext.size()-1;i++)
    {
        just1=safe.lower_bound(ext[i].first);
        just2=just1;
        if(just2!=safe.begin())
        {
            just2--;
        }
        if(just1==safe.end())
            just1--;
        dp[i+1][0]=min(mod((*just2)-ext[i].first)+mod((*just2)-ext[i+1].second),mod((*just1)-ext[i].first)+mod((*just1)-ext[i+1].second));
        dp[i+1][1]=min(mod((*just2)-ext[i].first)+mod((*just2)-ext[i+1].first),mod((*just1)-ext[i].first)+mod((*just1)-ext[i+1].first));
        dp[i+1][0]+=dp[i][0];
        dp[i+1][1]+=dp[i][0];
        just1=safe.lower_bound(ext[i].second);
        just2=just1;
        if(just2!=safe.begin())
        {
            just2--;
        }
        if(just1==safe.end())
        {
            just1--;
        }
        dp[i+1][0]=min(dp[i+1][0],mod((*just2)-ext[i].second)+mod((*just2)-ext[i+1].second)+dp[i][1]);
        dp[i+1][0]=min(dp[i+1][0],mod((*just1)-ext[i].second)+mod((*just1)-ext[i+1].second)+dp[i][1]);
        dp[i+1][1]=min(dp[i+1][1],mod((*just2)-ext[i].second)+mod((*just2)-ext[i+1].first)+dp[i][1]);
        dp[i+1][1]=min(dp[i+1][1],mod((*just1)-ext[i].second)+mod((*just1)-ext[i+1].first)+dp[i][1]);
    }
    ll ans=min(dp[ext.size()-1][0],dp[ext.size()-1][1]);
    for(ll i=0;i<ext.size();i++)
    {
        ans+=(ext[i].second-ext[i].first);
    }
    ans+=row[ext.size()-1].first-1;
    cout<<ans<<endl;

}