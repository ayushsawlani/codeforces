#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector <pair <ll,ll>> compress_array(ll *a, ll n)
{
    vector <pair <ll,ll>> ans;
    ll i=0;
    ll c=1;
    while(i<n-1)
    {
        if(a[i]!=a[i+1])
        {
            pair <ll,ll> temp;
            temp.first=a[i];
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
    temp.first=a[i];
    temp.second=c;
    ans.push_back(temp);
    c=1;
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,q;
    cin>>n;
    cin>>q;
    ll *a=(ll*)(malloc(n*sizeof(ll)));
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    vector <pair  <ll,ll>> v=compress_array(a,n);
    set <ll> pitlist;
    map <ll,ll> right;
    ll i=1,j=v[0].second;
    while((i<v.size()-1)&&(j<n))
    {
        if((v[i].first<v[i-1].first)&&(v[i].first<v[i+1].first))
        {
            pitlist.insert(j-1);
            right[j-1]=j+v[i].second;
        }
        j+=v[i].second;
        i++;
    }
    ll len_pitlist=pitlist.size();
    map <ll,ll> min_array;
    if(len_pitlist>0)
    {
        auto it=pitlist.end();
        it--;
        min_array[*it]=right[(*it)];
        auto prev=it;
        it--;
        while(it!=pitlist.begin())
        {
            min_array[*it]=min(min_array[*(prev)],right[*it]);
            it--;
            prev--;
        }
        if(len_pitlist>1);
            min_array[(*it)]=min(min_array[(*prev)],right[(*it)]);
    }
    for(i=0;i<q;i++)
    {
        pair <ll,ll> interval;
        cin>>interval.first>>interval.second;
        interval.first--;
        interval.second--;
        auto up=pitlist.lower_bound(interval.first);
        if(up!=pitlist.end())
        {
            if((min_array[(*up)]<=interval.second)&&(interval.first<=(*up)))
            {
                cout<<"No";
            }
            else
            {
                cout<<"Yes";
            }
        }
        else 
        {
            cout<<"Yes";
        }
        cout<<endl;
    }
    
}