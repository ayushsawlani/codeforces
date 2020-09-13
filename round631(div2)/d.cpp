#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mod 1000000007
#define inarr(i,arr,n); for(ll i=0;i<n;i++) cin >> arr[i];
#define outarr(i,arr,n); for(ll i=0;i<n;i++) cout<<arr[i]<<' ';
#define swap(a,b,t) {t=a;a=b;b=t;}
#define ve vector
#define sz(a) (int)((a).size())
#define fi first
#define se second
#define pa pair
#define fastio  {ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}
#define ll long long int
#define fr(i, a, b) for (int i = a; i < b; i++)
#define frn(i, a, b) for (int i = a; i > b; i--)
#define mk make_pair
#define setvector(vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 1e18;
ll fast_expo(ll a, ll n, ll m)
{
	int ans=1;
	while(n>0)
	{
		if(n%2==1)
			ans=(ans*a)%m;
		a=(a*a)%m;
		n=n/2;
	}
	return ans;
}
int main()
{
    //fastio
    ll t;
    cin>>t;
    while(t--)
    {
        ll d,m;
        cin>>d>>m;
        ll x=log2(d);
        ll dp[66][64]={0};
        fr(i,0,64)
        {
            dp[1][i]=fast_expo(2,i,m);
        }
        fr(i,2,65)
        {
            fr(j,i-1,64)
            {
                ll sum=0;
                fr(k,0,j)
                {
                    sum+=(dp[i-1][k]*fast_expo(2,j,m));
                    sum%=m;
                }
                dp[i][j]=sum;
            }
        }
        ll ans=0;
        fr(i,1,65)
        {
            fr(j,0,x)
            {
                ans+=dp[i][j];
                ans%=m;
            }
        }
        fr(i,2,65)
        {
            ll sum=0;
            fr(j,0,x)
            {
                sum+=dp[i-1][j];
                sum%=m;
            }
            ans+=(sum*(d-pow(2,x)+1));
            ans%=m;
        }
        ans+=d-pow(2,x)+1;
        ans%=m;
        if(x==0)
            ans=1;
        ans%=m;
        cout<<ans<<endl;
    }
}