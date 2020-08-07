#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll a,ll b){
	if(a%b==0)
		return b;
	else
		return gcd(b,a%b);
}
pair <ll,ll> simplify(pair <ll,ll> p)
{
    ll hcf=gcd(p.first,p.second);
    p.first=p.first/hcf;
    p.second=p.second/hcf;
    return p;
}
ll bs(pair <ll,ll> f,ll i,ll j, ll d)
{
    if(i==j)
        return i;
    else
    {
        ll m=(i+j)/2;
        if(m*f.second>f.first*d)
            return bs(f,i,m,d);
        else if(m*f.second<f.first*d)
            return bs(f,m+1,j,d);
    }
    
}
pair <ll,ll> dist(pair <ll,ll> p1, pair<ll,ll>p2)
{
    pair<ll,ll>ans;
    ans.first=(p1.first*p2.second-p2.first*p1.second);
    if(ans.first<0)
        ans.first=(-1)*(ans.first);
    ans.second=p1.second*p2.second;
    ans=simplify(ans);
    return ans;
}
pair <ll,ll> min_dist(pair <ll,ll> p1,pair <ll,ll>p2,pair <ll,ll> f)
{
    pair <ll,ll> d1=dist(f,p1);   
    pair <ll,ll> d2=dist(f,p2);
    if(d1.first*d2.second>d2.first*d1.second)
        return p2;
    else if(d1.first*d2.second<d2.first*d1.second)
        return p1;
    else
    {
        if(p1.second<p2.second)
            return p1;
        else if(p1.second>p2.second)
            return p2;
        else
        {
            if(p1.first<p2.first)
                return p1;
            else
            {
                return p2;
            }
            
        }
        
        
    }
    
    
}
int main()
{
    pair <ll,ll> f,p1,p2;
    ll n;
    cin>>f.first>>f.second>>n;
    f=simplify(f);
    if(f.second<=n)
    {
        cout<<f.first<<"/"<<f.second<<endl;
    }
    else
    {
        pair <ll,ll>ans;
        ans.first=1;
        ans.second=1;
        ll temp=(f.first)/(f.second);
        f.first-=(temp*f.second);
        for(ll b=n;b>=1;b--)
        {
            ll a1=bs(f,1,b,b);
            ll a2;
            if(a1*f.second>b*f.first)
                a2=a1-1;
            else
            {
                a2=a1+1;
            }
            pair<ll,ll>p1,p2;
            p1.first=a1;
            p1.second=b;
            p1=(simplify(p1));
            p2.first=a2;
            p2.second=b;
            p2=(simplify(p2));
            ans=min_dist(ans,p1,f);
            ans=min_dist(ans,p2,f);
                       
        }
        cout<<ans.first+temp*ans.second<<"/"<<ans.second<<endl;
    }
  
}