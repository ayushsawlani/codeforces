#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
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
ll fast_expo(ll a, ll n)
{
	ll ans=1;
	while(n>0)
	{
		if(n%2==1)
			ans=(ans*a)%M;
		a=(a*a)%M;
		n=n/2;
	}
	return ans;
}
ll bs(ll x,ll i,ll j,ll sum,ll threshold)
{
    if(i==j)
    {
        return i;
    }
    else if(i<j) 
    {
        ll m;
        if((i+j)%2==0)
            m=(i+j)/2;
        else
            m=((i+j)/2)+1;
        if(m>=threshold)
        {
            return bs(x,i,m-1,sum,threshold);
        }
        else
        {
            if(sum%((ll)pow(x,m))==0)
                return bs(x,m,j,sum,threshold);
            else
            {
                return bs(x,i,m-1,sum,threshold);
            }
        }
        
    }
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll n,x;
    cin>>n>>x;
    ll threshold=0;
    while(pow(x,threshold)<pow(10,15))
    {
        threshold++;
    }
    ll a[n];
    ll power=0,_sum=0;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
      //  a[i]=0;
        power+=a[i];
    }
    sort(a,a+n);
    vector <pair<ll,ll>> v=compress_array(a,n);
    power-=v[v.size()-1].first;
    _sum=v[v.size()-1].first;
    for(ll i=0;i<v.size();i++)
    {
        v[i].first=a[n-1]-v[i].first;
    }
    sort(v.begin(),v.end());
    ll count=0,sum=0;
    ll diff=threshold;
    for(ll i=0;i<v.size()-1;i++)
    {
        diff=v[i+1].first-v[i].first;
        if(diff<threshold)
        {
            if((v[i].second+sum)%((ll)pow(x,diff))!=0)
                break;
        }
        else
        {
            break;
        }
        count++;
        sum=(v[i].second+sum)/pow(x,diff);
    }
    if(count==v.size()-1)
    {
        power+=v[count].first+min(bs(x,0,threshold,sum+v[count].second,threshold),_sum-v[count].first);
    }
    else
    {
        ll addition=bs(x,0,diff,sum+v[count].second,threshold);
        power+=v[count].first+addition;
        
    }
   cout<<fast_expo(x,power)<<endl;
}